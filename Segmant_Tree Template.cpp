#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  vector<int> tree;
  vector<int> v;
  int n;

  // Build the segment tree
  void build(int node, int start, int end) {
    if (start == end) {
      // Leaf node will contain a single element
      tree[node] = v[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node + 1, start, mid);
      build(2 * node + 2, mid + 1, end);
      // Internal node will be the sum/min/max of the two child nodes
      tree[node] =
          tree[2 * node + 1] +
          tree[2 * node + 2]; // Modify this based on operation (sum/min/max)
    }
  }

  // Update the element at a specific position
  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      // Leaf node, update value
      v[idx] = val;
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (start <= idx && idx <= mid) {
        update(2 * node + 1, start, mid, idx, val);
      } else {
        update(2 * node + 2, mid + 1, end, idx, val);
      }
      // Update the internal node after updating the child nodes
      tree[node] =
          tree[2 * node + 1] +
          tree[2 * node + 2]; // Modify this based on operation (sum/min/max)
    }
  }

  // Query the segment tree for a range
  int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      // Range represented by a node is completely outside the given range
      return 0; // Modify this based on operation (for min use INT_MAX, for sum
                // use 0)
    }
    if (L <= start && end <= R) {
      // Range represented by a node is completely inside the given range
      return tree[node];
    }

    // Range represented by a node is partially inside and partially outside the
    // given range
    int mid = (start + end) / 2;
    int leftQuery = query(2 * node + 1, start, mid, L, R);
    int rightQuery = query(2 * node + 2, mid + 1, end, L, R);
    return leftQuery +
           rightQuery; // Modify this based on operation (sum/min/max)
  }

public:
  // Constructor to initialize the segment tree
  SegmentTree(vector<int> &input) {
    v = input;
    n = v.size();
    tree.resize(4 * n);
    build(0, 0, n - 1);
  }

  // Function to call update operation
  void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

  // Function to call range query operation
  int query(int L, int R) { return query(0, 0, n - 1, L, R); }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  SegmentTree segTree(v);

  for (int i = 0; i < q; i++) {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 1) {            // Update operation
      segTree.update(a - 1, b); // Adjust for 0-based indexing
    } else if (type == 2) {     // Range query
      cout << segTree.query(a - 1, b - 1)
           << endl; // Adjust for 0-based indexing
    }
  }

  return 0;
}
