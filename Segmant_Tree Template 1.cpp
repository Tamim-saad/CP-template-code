//range minimum queries cses solution

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
public:
  vector<ll> segmantTree;
  vector<ll> v;  // Internal vector for the segment tree
  ll size;

  SegmentTree(vector<ll>& input) {
    v = input;
    size = 4 * v.size();
    segmantTree.resize(size);
  }

  // Merging function
  ll merge(ll leftVal, ll rightVal) {
    return min(leftVal, rightVal);
  }

  void build(ll rootPos, ll l, ll r) {
    if (l == r) {
      segmantTree[rootPos] = v[l];
      return;
    }

    ll m = (l + r) / 2;
    build(rootPos * 2 + 1, l, m);
    build(rootPos * 2 + 2, m + 1, r);

    segmantTree[rootPos] = merge(segmantTree[rootPos * 2 + 1], segmantTree[rootPos * 2 + 2]);
  }

  void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
    if (pos < l || pos > r)
      return;
    if (l == r) {
      segmantTree[rootPos] = newValue;
      v[l] = newValue;  // Update internal vector
      return;
    }

    ll m = (l + r) / 2;
    if (l <= pos && pos <= m)
      update(rootPos * 2 + 1, l, m, pos, newValue);
    else
      update(rootPos * 2 + 2, m + 1, r, pos, newValue);

    segmantTree[rootPos] = merge(segmantTree[rootPos * 2 + 1], segmantTree[rootPos * 2 + 2]);
  }

  ll query(ll rootPos, ll l, ll r, ll L, ll R) {
    if (r < L || R < l)
      return LONG_LONG_MAX;
    if (L <= l && r <= R)
      return segmantTree[rootPos];

    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2 + 1, l, m, L, R);
    ll qr = query(rootPos * 2 + 2, m + 1, r, L, R);

    return merge(ql, qr);
  }
};

int main() {
  ll q, n;
  cin >> n >> q;

  vector<ll> input(n);
  for (ll i = 0; i < n; i++) {
    cin >> input[i];
  }

  SegmentTree st(input);
  st.build(0, 0, n - 1);

  for (ll i = 0; i < q; i++) {
    ll k, a, b;
    cin >> k >> a >> b;

    if (k == 1) {
      st.update(0, 0, n - 1, a, b);  // 0-based indexing
    }
    if (k == 2) {
      cout << st.query(0, 0, n - 1, a, b) << endl;  // 0-based indexing
    }
  }
  return 0;
}
