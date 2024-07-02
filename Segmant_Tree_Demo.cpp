/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
#define init                                                                   \
  ll count = 0, zz, t;                                                         \
  cin >> t;                                                                    \
  while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl " "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)
#define printsep cout << "\n ---------- \n"
#define printdot cout << " --- "
#define dot " --- "

#define v(all) v.begin(), v.end()
#define printarr(arr, in, n)                                                   \
  cout << ed;                                                                  \
  for (ll i = in; i < n; i++)                                                  \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define print(arr, n)                                                          \
  cout << ed;                                                                  \
  for (ll i = 0; i < n; i++)                                                   \
    cout << arr[i] << " ";                                                     \
  cout << ed;
#define printvc(vc)                                                            \
  cout << ed;                                                                  \
  for (auto x : vc)                                                            \
    cout << x << " ";                                                          \
  cout << ed;
// #define printvc(vc)  for(auto x:vc)cout<<x<<".";
// #define printvc(vc,in,n)  cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<"
// ";cout<<ed;

#define srt(arr, n) sort(ara, ara + n);
#define srtvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v,x) find(v.begin(), v.end(),x);

// string binary = bitset<8>(n).to_string();
// unsigned long decimal =bitset<8>(binary).to_ulong();

/// solve starts here--------------------------------

const int N = 2e5 + 5;
ll segmantTree[4 * N];

void build(ll arr[], ll rootPos, ll l, ll r) {
  if (l == r) {
    segmantTree[rootPos] = arr[l];
    return;
  }

  ll m = (l + r) / 2;
  build(arr, rootPos * 2, l, m);
  build(arr, rootPos * 2 + 1, m + 1, r);

  segmantTree[rootPos] =
      min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
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
  // if(l<=pos && pos<=m)
  else
    update(rootPos * 2 + 1, m + 1, r, pos, newValue);

  segmantTree[rootPos] =
      min(segmantTree[rootPos * 2], segmantTree[rootPos * 2 + 1]);
  return;
}

ll query(ll rootPos, ll l, ll r, ll L, ll R) {
  if (r < L || R < l)
    if (L > R || l > r || l > R || r < L)
      return LONG_LONG_MAX;
  if (L <= l && r <= R)
    return segmantTree[rootPos];
  else {
    ll m = (l + r) / 2;
    ll ql = query(rootPos * 2, l, m, L, R);
    ll qr = query(rootPos * 2 + 1, m + 1, r, L, R);

    return min(ql, qr);
  }
}

int main() {
  fast init {
    //  count++;
    ll i, j, m, x, y, d, p = 0, q = 0, n = 0, rest = 0, k, ans = 0, flag = -1,
                         sum = 0, bef_even_pos = 0, bef_odd_pos = 0;
    ll mini = lmax, maxi = -1, dif = 0, total = 0, same = 0, plus = 0,
       minus = 0, zero = 0;
    ll piv = 1, rem = 0, fix = 0, flex = 0, change = 0, prev = -1, l = 0, r = 0,
       lval, rval, now = 0, mid;

    // string s,s1="",s2="",res1="",res2="",chk1="",chk2="",chk3="",chk4="";
    // string pivs="",rems="";

    vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
    // vector<pair<ll,ll>> vp;

    // pair<ll,ll> pr,pr1,pr2;
    // set<ll> st,st1,st2,ms,ldiff,rdiff;
    // priority_queue <ll> pq,pq1,pq2;
    // stack<ll> stck,stck1,stck2;
    map<ll, ll> mp, mp1, mp2, done, del, strt;

    // Point pa,pb,pt[n];
    // Node pa,pb,pt[n];

    // cout<<"-----------------yess"<<endl;

    cin >> n >> m;
    // n=s.size();
    ll arr[n], arr1[n], arr2[n], number[n], cost[n], forsum[n], backsum[n];
    // vec ps1(n),ps2(n);
    // vec cnt(n+1),end_sum(n+1);

    ans = 0;
    ll l1 = 0, l2 = 0, l3 = 0;
    ll f1 = 1, f2 = 1, f3 = 1;

    //----------------------------------------------
    ll q, n;
    cin >> n >> q;

    ll arr[n + 1];
    forr(i, 1, n + 1) { cin >> arr[i]; }

    build(arr, 1, 1, n);

    forr(i, 0, q) {
      ll k, a, b;
      cin >> k >> a >> b;

      if (k == 1) {
        update(1, 1, n, a, b);
      }
      if (k == 2) {
        cout << query(1, 1, n, a, b) << endl;
      }
    }
  }
}
