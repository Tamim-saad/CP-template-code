//cses - Josephus Problem II solution :
//------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>
// class tree;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

int main() {
  int n, ans, j;
  cin >> n >> j;
  int currentNumber = n;
  int innerStart = 2;

  indexed_set st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }
  int ind = j % st.size();

  while (!st.empty()) {
    int killed = *st.find_by_order(ind);
    cout << killed << " ";
    st.erase(killed);
    if (!st.empty())
      ind = ((ind % st.size() + j) % st.size());
  }
  return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------
//link to understand:
https://chatgpt.com/share/66f4ff68-1ffc-8012-89f6-048bfb5b3e97

