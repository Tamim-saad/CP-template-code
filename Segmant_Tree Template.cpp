#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
public:
  vector<ll> segmantTree;
  ll size;

  SegmentTree(ll n) {
    size = 4 * n + 5;
    segmantTree.resize(size);
  }

  void build(vector<ll> &v, ll rootPos, ll l, ll r) {
    if (l == r) {
      segmantTree[rootPos] = v[l];
      return;
    }

    ll m = (l + r) / 2;
    build(v, rootPos * 2, l, m);
    build(v, rootPos * 2 + 1, m + 1, r);

    segmantTree[rootPos] =
        min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  }

  void update(ll rootPos, ll l, ll r, ll pos, ll newValue) {
    if (pos < l || pos > r)
      return;
    if (l == r) {
      segmantTree[rootPos] = newValue;
      return;
    }

    ll m = (l + r) / 2;
    if (l <= pos && pos <= m)
      update(rootPos * 2, l, m, pos, newValue);
    else
      update(rootPos * 2 + 1, m + 1, r, pos, newValue);

    segmantTree[rootPos] =
        min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  }

  ll query(ll rootPos, ll l, ll r, ll L, ll R) {
    if (r < L || R < l)
      return LONG_LONG_MAX;
    if (L <= l && r <= R)
      return segmantTree[rootPos];

    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2, l, m, L, R);
    ll qr = query(rootPos * 2 + 1, m + 1, r, L, R);

    return min(ql, qr);
  }
};

int main() {
  ll q, n;
  cin >> n >> q;

  vector<ll> v(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
  }

  SegmentTree st(n);
  st.build(v, 1, 1, n);

  for (ll i = 0; i < q; i++) {
    ll k, a, b;
    cin >> k >> a >> b;

    if (k == 1) {
      st.update(1, 1, n, a, b);
    }
    if (k == 2) {
      cout << st.query(1, 1, n, a, b) << endl;
    }
  }
  return 0;
}
