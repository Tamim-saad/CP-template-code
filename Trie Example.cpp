/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

#define forr(i, a, b) for (int i = a; i < b; i++)
#define forrev(i, a, b) for (int i = a; i >= b; i--)

const int N = 2e5 + 5;
int trie[30 * N][2] = {0}, cnt = 0;

void insert(int xr) {
  int node = 0;

  forrev(i, 31, 0) {
    int bit = (xr >> i) & 1;

    if (!trie[node][bit])
      trie[node][bit] = ++cnt;

    node = trie[node][bit];
  }
}

int search(int xr) {
  int ans = 0;
  int node = 0;

  forrev(i, 31, 0) {
    int bit = (xr >> i) & 1;

    if (trie[node][bit ^ 1]) {
      ans += 1 << i;
      node = trie[node][bit ^ 1];
    } else {
      node = trie[node][bit];
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  int x, ans = 0, xor_so_far = 0;

  insert(xor_so_far);

  forr(i, 1, n + 1) {
    cin >> x;
    xor_so_far ^= x;

    insert(xor_so_far);
    ans = max(ans, search(xor_so_far));
  }

  cout << ans << endl;
}
