/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define init             \
    ll count = 0, zz, t; \
    cin >> t;            \
    while (t--)
#define ld long double
#define ed "\n"
#define eb emplace_back
#define con continue
#define bre break
#define pl "  "
#define size size()
#define mpr make_pair
#define vec vector<ll>
#define lmax LONG_LONG_MAX
#define lmin LONG_LONG_MIN
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrev(i, a, b) for (ll i = a; i >= b; i--)

// #define v.all v.begin(),v.end()
#define printarr(arr, in, n)    \
    cout << ed;                 \
    for (ll i = in; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << ed;
#define print(arr, n)          \
    cout << ed;                \
    for (ll i = 0; i < n; i++) \
        cout << arr[i] << " "; \
    cout << ed;
#define printyn(flag)        \
    if (flag == 0)       \
        cout << "NO\n";  \
    else                 \
        cout << "YES\n"; \

#define printvc(vc)       \
    cout << ed;           \
    for (auto x : vc)     \
        cout << x << " "; \
    cout << ed;
// #define printvc(vc)  for(auto x:vc)cout<<x<<".";
// #define printvc(vc,in,n)  cout<<ed;for(ll i=in;i<n;i++)cout<<arr[i]<<" ";cout<<ed;

#define srt(arr, n) sort(ara, ara + n);
#define srtvc(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
// #define find(v,x) find(v.begin(), v.end(),x);

struct Point
{
    ld x, y;

public:
    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator/(const ld k) const
    {
        return Point(x / k, y / k);
    }
};

pair<ld, ld> getCrossPoint(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2)
{
    ld x, y;
    x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    return make_pair(x, y);
}

ld len(Point a, Point b)
{
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld area(Point a, Point b, Point c)
{
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

bool validParenthesisCheck(string s)
{
    stack<char> st;
    forr(i, 0, s.size)
    {
        if (s[i] == '(')
        {
            st.push('(');
            con;
        }
        if (st.empty() == true || !(s[i] == ')' && st.top() == '('))
            return false;
        st.pop();
    }
    if (st.empty() == true)
        return true;
    else
        return false;
}

bool isprime(ll n)
{
    ll k = sqrt(n);
    forr(i, 0, k)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll lcm(ll arr[], ll n)
{
    ll ans = arr[0];
    forr(i, 1, n)
    {
        ans = ((arr[i] * ans)) / (__gcd(arr[i], ans));
    }
    return ans;
}

ll gcd(ll arr[], ll n)
{
    ll ans = arr[0];
    forr(i, 1, n)
    {
        ans = __gcd(arr[i], ans);
    }
    return ans;
}

// string binary = bitset<8>(n).to_string();
// unsigned long decimal =bitset<8>(binary).to_ulong();

const ll N = 1005;
vector<vec> adj_list(N);
ll par[N];
map<ll, ll> vis;
map<ll, ll> ans_list;
ll gv[N];
map<ll, ll> color;
int timee = 0;

map<ll, ll> cat;

vec lst;

void dfs(ll curr)
{
    timee++;
    gv[timee] = curr;

    forr(i, 0, adj_list[curr].size)
    {
        if (par[curr] != adj_list[curr][i])
        {
            dfs(adj_list[curr][i]);
        }
    }
    return;
}

/// solve starts here--------------------------------

ll step[N];

void ber_kor()
{
    // number[0]=N;

    forr(i, 0, 1005)
    {
        step[i] = 1005;
    }
    step[1] = 0;

    forr(i, 1, 1005)
    {
        // step[i]=N;
        forr(j, 1, i + 1)
        {

            if (i + i / j < 1005)
                step[i + (i / j)] = min(step[i] + 1, step[i + (i / j)]);
        }
    }
}

ll knapSackRec(ll W, ll wt[], ll val[], ll i, ll **dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)
    {

        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else
    {
        // Store value in a table before return
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val,
                                            i - 1, dp),
                       knapSackRec(W, wt, val, i - 1, dp));

        // Return value of table after storing
        return dp[i][W];
    }
}

ll knapSack(ll n, ll W, ll wt[], ll val[])
{
    // double poller to declare the
    // table dynamically
    ll **dp;
    dp = new ll *[n];

    // loop to create the table dynamically
    for (ll i = 0; i < n; i++)
        dp[i] = new ll[W + 1];

    // loop to initially filled the
    // table with -1
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    fast
    init
    {
        count++;
        ll i, j, k, x, y, z, p , q , r, m , n , l , r,  l1, l2, r1, r2, ans , flag , sum ;
        ll mini = lmax, maxi = -1, piv , piv1 , piv2 , rem , now , mid;
        //ll  dif = 0, change = 0, total = 0, same = 0, plus = 0, minus = 0, zero = 0;

        string s, s1 = "", s2 = "";
        //string res1 = "", res2 = "", chk1 = "", chk2 = "", chk3 = "", chk4 = "", pivs = "", rems = "";

        cin >> n;
        //n = s.size;

        ll arr[n];
        // number[n], cost[n], forsum[n], backsum[n];

        vector<ll> v, v1, v2, vans, vpos, vlen, vsum, vdif;
        vector<pair<ll, ll>> vpr;
        // vector<vec> vdarr(n, vec(10, 0));


        pair<ll, ll> pr, pr1, pr2;
        set<ll> st, st1, st2, ms, ldiff, rdiff;
        priority_queue<ll> pq, pq1, pq2;
        stack<ll> stck, stck1, stck2;
        map<int, ll> mp, mp1, mp2;
        queue<ll> vq[10],vq1,vq2;
        

        // Point pa,pb,pt[n];
        // Node pa,pb,pt[n];

        // cout<<"-----------------yess"<<endl;

        ans=0;
        piv=0;
        flag=0;
        sum=0;


        // cout<<LONG_MAX<<endl;
        //  cout<<(n|(n>>1))<<endl;
        //  return 0;


        forr(i,0,n)
        {
            cin>>x;
            arr[i]=x;

            if(maxi<x)
            {
                piv=i;
                maxi=x;
            }
        }
        l=p=maxi;

        // ll current_min=n+1, upper_limit=n+1;
        
        i=piv+1;
        while(i<n)
        {
            l=l^arr[i];
            p=max(p,l);
            cout<<"----"<<p<<pl<<l<<endl;
            i++;
        }

        i=piv-1;
        l=q=maxi;
        while(i>=0)
        {
            l=l^arr[i];
            q=max(q,l);
            cout<<"----"<<q<<pl<<l<<endl;
            i--;
        }

        

        

    
        // }
        //ans=(((((2|4)|12)|1)));

        cout<<max(p,q)<<endl;
        // ans = 0;
    }
}
