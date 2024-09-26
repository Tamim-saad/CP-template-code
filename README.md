# My-CP-Resources

#Customized_Ordered_Set
Let’s dive deeper into the code and explanation for the indexed_set from the Policy-based Data Structures (PBDS), particularly focusing on its components, functionality, and why it is chosen over other structures.

Code Breakdown (Detailed):
cpp
Copy code
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
We’ll go through each part of this code, focusing on how indexed_set works and why it's used in the Josephus Problem II.

1. #include <bits/stdc++.h>
This header file includes most of the commonly used C++ libraries in one go. It simplifies competitive programming by avoiding the need to individually include headers like <iostream>, <vector>, <set>, etc. It’s especially useful in coding competitions where time is limited. However, it’s not recommended for large-scale projects since it may increase compile time unnecessarily.

2. #include <ext/pb_ds/assoc_container.hpp>
This line includes the PBDS (Policy-based Data Structures) library, which is an extension of the C++ Standard Template Library (STL). PBDS provides more advanced containers and data structures that are not available in the usual C++ STL. These data structures can handle more complex operations like ordered indexing, set-like behavior, and associative arrays with better efficiency.

PBDS Overview:
The PBDS library offers several types of trees and hash tables, among other things. In this case, we are using a tree-based data structure that allows for indexed operations.

3. using namespace __gnu_pbds;
This line imports everything from the __gnu_pbds namespace, allowing you to access its contents directly without having to write __gnu_pbds:: every time. The PBDS library lives under this namespace, and we will access its features, like the tree data structure, from here.

4. using namespace std;
This is the standard C++ namespace that includes standard library features like cout, cin, vector, set, etc. It’s typical in C++ programs for convenience so that you don’t need to prefix every standard library feature with std::.

5. The typedef statement
cpp
Copy code
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
This is the key part where we create a type alias for a specialized data structure, referred to as indexed_set. Let’s break this down fully:

What is tree?
The tree structure is a template provided by PBDS, and it represents a balanced binary search tree with additional features that allow it to support operations such as indexing elements.

The template has the following syntax:

cpp
Copy code
template<typename Key, typename Mapped, typename Compare, typename Tag, typename Policy>
class tree;
Each of these parameters in tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> represents something specific:

int: The key type stored in the tree. In this case, integers will be stored.

Example: If you insert the values 10, 20, and 30 into the tree, they will be stored and organized in a sorted manner (since it’s a binary search tree).

null_type: Specifies that no additional mapped values will be stored alongside the key. Unlike a map where keys are associated with values, here we only store the keys.

Example: In map<int, string>, the key might be an integer (e.g., 1) and the value might be a string (e.g., "One"). But here, we only store int values (keys) without any associated data.

less<int>: This is a comparator function that ensures the keys are ordered in ascending order. If you wanted the keys in descending order, you could use greater<int> instead.

Example: If you insert 30, 10, and 20, the tree will automatically sort and store them in the order 10, 20, 30.

rb_tree_tag: This specifies the underlying tree type. rb_tree_tag uses a Red-Black Tree, which is a type of self-balancing binary search tree. It guarantees that the height of the tree remains logarithmic relative to the number of elements, ensuring efficient insertions, deletions, and lookups.

Red-Black Tree properties ensure:

The tree remains balanced.
Insertions, deletions, and lookups happen in O(log n) time.
tree_order_statistics_node_update: This is the policy that enables two additional operations on the tree:

find_by_order(k): Returns an iterator to the k-th smallest element (0-indexed).
Example: If the tree contains {10, 20, 30}, find_by_order(1) will return an iterator to 20 (the 1st smallest element).
order_of_key(x): Returns the number of elements that are strictly less than x.
Example: If the tree contains {10, 20, 30}, order_of_key(20) will return 1, since only 10 is strictly smaller than 20.
6. Why use indexed_set in the Josephus Problem II?
The Josephus Problem requires removing every k-th person in a circle until only one person remains. Efficiently managing the remaining people and accessing the k-th person is key. Here’s why indexed_set is the right choice:

Problem Characteristics:
You need to eliminate people in a circular fashion.
After each elimination, the next person must be selected in constant or logarithmic time.
Efficient deletion and dynamic position tracking is required.
Why indexed_set?
Efficient Random Access:

With find_by_order(), you can directly access the k-th smallest person, which represents the person to be removed.
Example:

cpp
Copy code
indexed_set s = {1, 2, 3, 4, 5};
cout << *s.find_by_order(2) << endl; // Output: 3 (the 2nd person in sorted order)
Efficient Deletion:

Deletion from a red-black tree takes O(log n) time. After removing a person, you can continue accessing elements by index using find_by_order() without needing to rebuild the structure.
Example:

cpp
Copy code
s.erase(s.find_by_order(2)); // Removes the person in the 2nd position.
Efficient Counting:

The order_of_key() function can be used to count how many elements are less than a given person, which is useful when determining which person to eliminate next in a circular fashion.
Why not use other data structures?
vector: A vector allows random access by index, but deleting elements shifts all subsequent elements, making deletions O(n) in the worst case. This inefficiency would add up over multiple deletions.

set: A standard set ensures order and uniqueness but does not provide efficient index-based access. You cannot directly access the k-th smallest element without manually iterating, which is slower than the logarithmic time find_by_order() in an indexed_set.

map: Like set, map provides an ordered structure, but it’s inefficient for this task as it doesn’t support index-based access.

Summary:
indexed_set combines the advantages of a set (sorted order, fast deletion) with the benefits of random access like in a vector.
For the Josephus Problem, you need to efficiently select and delete people from a dynamic list, which requires random access by index and efficient removal.
PBDS’s tree_order_statistics_node_update allows you to efficiently solve the problem in O(n log n) time by ensuring fast access and updates as the list of people changes.
