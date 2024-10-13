#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

using ll = long long;

class FenwickTree {
public:
  vector<ll> ftree;
  ll n;

  FenwickTree(ll n) {
    this->ftree.resize(n + 1, 0);
    this->n = n;
  }

  void update(ll ind, ll val) {
    for (ll i = ind; i <= n; i += i & -i) {
      ftree[i] += val;
    }
  }

  ll query(ll ind) {
    ll sum = 0;
    for (ll i = ind; i > 0; i -= i & -i) {
      sum += ftree[i];
    }
    return sum;
  }

  ll rangeQuery(ll start, ll end) { return query(end) - query(start - 1); }
};

int main() {
  fast;
  ll n, k, x, y, type;
  cin >> n >> k;
  vector<ll> v(n + 1, 0);
  FenwickTree ftree(n);

  // Initialize Fenwick Tree with input values
  for (ll i = 1; i <= n; i++) {
    cin >> x;
    v[i] = x;
    ftree.update(i, x);
  }

  for (ll i = 0; i < k; i++) {
    cin >> type >> x >> y;
    if (type == 1) {
      // Update operation: Update the Fenwick Tree by the difference
      ftree.update(x, y - v[x]);
      v[x] = y; // Update the stored value in the array
    } else if (type == 2) {
      // Range sum query: Output the sum from x to y
      cout << ftree.rangeQuery(x, y) << endl;
    }
  }

  return 0;
}
