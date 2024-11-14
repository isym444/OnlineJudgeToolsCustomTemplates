
/* Segment tree (point updates + range queries):
Range Queries: Such as sum, minimum, maximum, etc., over a segment of an array in 𝑂(log 𝑛) time.
Point Updates: Update the value at a specific index in O(logn) time.

Lazy Segment tree (range updates + range queries):
+Handling Range Updates: Allows updates over a range of indices to be applied lazily and 
efficiently, postponing the actual update until necessary. This makes it possible to perform range updates in 
O(logn) time.

Fenwick (binary indexed) tree (point updates + prefix sum queries)
O(log n)
 */



// Lazy seg tree usage:
//Initialization:
ll op(long f,long x){return f+x;}       // Defines the operation for the segment tree (sum operation).
ll e(){return 0L;}                      // Defines the identity element for the segment tree (0 for sum, 0 for xor, 0 for GCD, 1 for LCM, 1 for multiplication, INF for min, -INF for max).

vector<ll>A(N);                     // Create a vector to hold the initial value at each element of segment tree.

atcoder::lazy_segtree<ll,op,e,ll,op,op,e>seg(A); // Initialize a lazy segment tree with the array A.

//Point query:
seg.get(b);              // Get the current number at index `b`.

//Range query:
seg.prod(l, r);         // Returns the sum (or the result of the op function) of all elements in the range [l, r), i.e., from index l to index r-1.

//Point set with specific value:
seg.set(b, (ll)0);                   // Set the number of balls in box `b` to 0.

//Range update with op function
seg.apply(0, N, x);             // Update with `x` across all indexes using op function to update each index


//NOTE on lazy_segtree initialization:
/* First Template Parameter (long):

Type of the segment tree's data elements.
In this case, long is the type of the values stored in the segment tree nodes. Each node in the segment tree will store a long integer value.
Second Template Parameter (op):

Binary operation function used for combining two elements.
The op function defines how two segments of the tree are combined. Here, it performs an addition (op(long f, long x) { return f + x; }), which means the segment tree is used to perform range sum queries.
Third Template Parameter (e):

Identity element function for the operation defined in op.
The e function returns the identity element for the operation. For addition, the identity element is 0 (e() { return 0L; }), meaning adding 0 to any number will not change its value. This is important for initializing and propagating values in the segment tree.
Fourth Template Parameter (long):

Type of the lazy propagation values.
This defines the type of the value used for lazy updates. Since we want to propagate increments to range updates, it is also a long in this case.
Fifth Template Parameter (op):

Binary operation function used to apply lazy updates.
This is the same op function used earlier. It defines how a lazy value (in this case, an increment) should be applied to a segment's value. Since our operation is addition, it just adds the lazy value to the segment's value.
Sixth Template Parameter (op):

Composition function for combining lazy values**.
This defines how to combine two lazy values. Since our lazy values are increments (additions), the operation to combine two increments is also addition. Thus, the same op function is reused.
Seventh Template Parameter (e):

Identity element for the lazy propagation values.
This defines the identity element for the lazy operation, which again is 0 for addition (meaning no increment). */