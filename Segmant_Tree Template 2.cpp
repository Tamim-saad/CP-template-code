//max prefix sum queries cses solution

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

using ll = long long;

struct Node {
  ll maxPrefixSum;
  ll totalSum;

  Node() {
    maxPrefixSum = 0;
    totalSum = 0;
  }
};

class SegmentTree {
public:
  vector<ll> v;
  vector<Node> tree;
  ll n;

  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
    v.resize(n);
  }

  void merge(ll root, ll a, ll b) {
    tree[root].totalSum = tree[a].totalSum + tree[b].totalSum;
    tree[root].maxPrefixSum =
        max(tree[a].maxPrefixSum, tree[a].totalSum + tree[b].maxPrefixSum);
  }

  void build(ll rootPos, ll l, ll r) {
    if (l == r) {
      tree[rootPos].maxPrefixSum = max(0LL, v[l]);
      tree[rootPos].totalSum = v[l];
      return;
    }

    ll m = (l + r) / 2;
    build(rootPos * 2 + 1, l, m);
    build(rootPos * 2 + 2, m + 1, r);

    merge(rootPos, 2 * rootPos + 1, 2 * rootPos + 2);
  }

  void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
    if (pos < l || pos > r)
      return;
    if (l == r) {
      v[l] = newValue;
      tree[rootPos].maxPrefixSum = max(0LL, v[l]);
      tree[rootPos].totalSum = v[l];
      return;
    }

    ll m = (l + r) / 2;
    update(rootPos * 2 + 1, l, m, pos, newValue);
    update(rootPos * 2 + 2, m + 1, r, pos, newValue);

    merge(rootPos, 2 * rootPos + 1, 2 * rootPos + 2);
  }

  Node queryNode(ll rootPos, ll l, ll r, ll L, ll R) {
    if (R < l || L > r) {
      return Node();
    }
    if (L <= l && r <= R) {
      return tree[rootPos];
    }

    ll m = (l + r) / 2;
    Node left = queryNode(rootPos * 2 + 1, l, m, L, R);
    Node right = queryNode(rootPos * 2 + 2, m + 1, r, L, R);

    Node result;
    result.totalSum = left.totalSum + right.totalSum;
    result.maxPrefixSum =
        max(left.maxPrefixSum, left.totalSum + right.maxPrefixSum);
    return result;
  }

  ll query(ll rootPos, ll l, ll r, ll L, ll R) {
    return queryNode(rootPos, l, r, L, R).maxPrefixSum;
  }
};

int main() {
  ll q, n;
  cin >> n >> q;

  SegmentTree st(n);
  for (ll i = 0; i < n; i++) {
    cin >> st.v[i];
  }

  st.build(0, 0, n - 1);

  for (ll i = 0; i < q; i++) {
    ll k, a, b;
    cin >> k >> a >> b;

    if (k == 1) {
      st.update(0, 0, n - 1, a - 1, b); // Updated to handle value `b`
    }
    if (k == 2) {
      cout << st.query(0, 0, n - 1, a - 1, b - 1) << endl;
    }
  }

  return 0;
}
