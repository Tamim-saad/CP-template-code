#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// Custom comparator: Sort by second value (ID) first, then by first value
// (actual value)
struct custom_compare {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    if (a.second == b.second) {
      return a.first < b.first; // If IDs are equal, sort by value
    }
    return a.second < b.second; // Sort by ID first
  }
};


// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>

typedef tree<pair<int, int>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

// Define indexed_multiset with the custom comparator
// typedef tree<pair<int, int>, null_type, custom_compare, rb_tree_tag,
// tree_order_statistics_node_update> indexed_multiset;





int main() {
  indexed_multiset ms;
  int idx = 0; // Unique identifier for each element

  // Insert elements with unique IDs
  ms.insert({5, idx++}); // Insert (5, 0) [Time Complexity: O(log n)]
  ms.insert({5, idx++}); // Insert (5, 1) [Time Complexity: O(log n)]
  ms.insert({7, idx++}); // Insert (7, 2) [Time Complexity: O(log n)]
  ms.insert({3, idx++}); // Insert (3, 3) [Time Complexity: O(log n)]

  // Printing all elements after insertion
  //  cout << "Elements in indexed_multiset (sorted by second value, then by
  //  first "
  //          "value):"
  //       << endl;
  cout << "Elements in indexed_multiset (sorted by default lexicographical "
          "order):"
       << endl;
  for (auto it = ms.begin(); it != ms.end(); ++it) {
    cout << "(" << it->first << ", " << it->second << ") ";
  }

  cout << endl;

  // Find by order example
  auto element_by_order =
      ms.find_by_order(2); // 2nd index (0-based) [Time Complexity: O(log n)]
  cout << "Element at index 2: (" << element_by_order->first << ", "
       << element_by_order->second << ")" << endl;
  // Output: (5, 1) because it's the third element in the sorted order

  // Order of key example
  int order =
      ms.order_of_key({5, -1}); // Number of elements strictly smaller than
  {
    5,
        // -1} [Time Complexity: O(log n)]
        cout << "Number of elements smaller than 5: " << order << endl;
    // Output: 1, because only {3, 3} is smaller than {5, -1}

    // Lower bound example
    auto lower = ms.lower_bound(
        {5, -1}); // First element >= {5, -1} [Time Complexity: O(log n)]
    cout << "Lower bound for 5: (" << lower->first << ", " << lower->second
         << ")" << endl;
    // Output: (5, 0) because it's the first occurrence of 5

    //   Upper bound example
    //  auto upper = ms.upper_bound({5, -1});
    auto upper = ms.upper_bound({5, INT_MAX});
    // First element > {5, -1} [Time Complexity: O(log n)]
    cout << "Upper bound for 5: (" << upper->first << ", " << upper->second
         << ")" << endl;
    // Output: (7, 2) because it's the first element greater than 5

    // Erase by key (this will remove the first instance of 5 with ID 0)
    ms.erase(
        ms.find({5, 0})); // Erase the element {5, 0} [Time Complexity: O(log
      n)]

  // Printing all elements after erasing
  cout << "Elements after erasing (5, 0):" << endl;
      for (auto it = ms.begin(); it != ms.end(); ++it) {
        cout << "(" << it->first << ", " << it->second << ") ";
      }
      cout << endl;

      return 0;
  }

  //------------------------------------sliding window median example in cses
  // #include <bits/stdc++.h>
  // using namespace std;
  // #include <ext/pb_ds/assoc_container.hpp>
  // using namespace __gnu_pbds;

  // // template <typename Key, typename Mapped, typename Compare, typename Tag,
  // //           typename Policy>
  // // class tree;

  // #define ll long long
  // typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
  //              tree_order_statistics_node_update>
  //     indexed_multiset;

  // int main() {
  //   ll n, ans, k, ind = 0;
  //   cin >> n >> k;

  //   indexed_multiset ms;

  //   vector<ll> v, nums;
  //   for (ll i = 1; i <= n; i++) {
  //     int x;
  //     cin >> x;
  //     nums.emplace_back(x);
  //     if (i <= k) {
  //       ms.insert({x, ind++});
  //     }
  //   }

  //   vector<ll> vans(n - k + 1);

  //   vans[0] = ms.find_by_order((k - 1) / 2)->first;
  //   for (ll i = k; i < n; i++) {
  //     ms.erase({nums[i - k], i - k});
  //     ms.insert({nums[i], ind++});

  //     // for (auto x : ms) {
  //     // cout << x.first << " ";
  //     // }
  //     // cout << endl;

  //     vans[i - k + 1] = ms.find_by_order((k - 1) / 2)->first;
  //   }

  //   // cout << " ---- " << endl;

  //   for (auto x : vans)
  //     cout << x << " ";

  //   return 0;
  // }
