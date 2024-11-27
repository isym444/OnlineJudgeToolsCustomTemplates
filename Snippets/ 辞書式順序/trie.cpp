// long long nC2(int n) {
//     return static_cast<long long>(n) * (n - 1) / 2;
// }

#define rep(i,n) for (int i = 0; i < (n); ++i)

// FROM THIS ATCODER PROBLEM: https://atcoder.jp/contests/abc353/tasks/abc353_e
// Trie structure to organize strings by their prefixes
// Building Trie: O(L), where L is length of all strings
struct Trie {
  struct Node {
    map<char,int> to;  // Map from character to child node (index of the child node in the vector<Node> d of the Trie.)
    int cnt;           // Count of strings ending at this node
    Node(): cnt(0) {}  // Initialize with 0
  };
  vector<Node> d;      // The Trie as a vector of nodes (tree structure is made by which nodes point to which other nodes)
//   Trie(): d(1) {}      // Start with one root node
    Trie() {
        d = vector<Node>(1); // Start with one root node. Default value of Node is given by Node constructor
    }

  // Add a string to the Trie
  void add(const string& s) {
    int v = 0;               // Start at the root node
    for (char c : s) {       // Traverse each character in the string
      if (!d[v].to.count(c)) {   // If no child for `c`, create a new node
        d[v].to[c] = d.size();   // Map `c` to the new node
        d.push_back(Node());     // Add the new node
      }
      v = d[v].to[c];         // Move to the next node
    }
    d[v].cnt++;               // Increment count for the terminal node
  }

  ll ans;                     // Stores the total LCP sum for all pairs
  int dfs(int v) {
    int res = d[v].cnt;       // Start with strings ending at this node
    for (auto p : d[v].to) {  // Process all children n.b. p is pair<key,value>
      res += dfs(p.second);   // Add result of DFS on child nodes
    }
    // if (v) ans += res * (ll)(res - 1) / 2; // Compute pair contributions
    // res at this point now represents all complete strings passing through this node on the way to the root
    if (v) ans += nC2((ll)res); // Compute pair contributions: for this length of prefix substring (up to v), add to ans number of pairs that can be made with strings passing through this node e.g. if 3 eventual complete strings pass through this node, then each of 3C2 (3) pairs contributes 1 to the ans at this length of common substring. If the overall longest common substring for all pairs is longer, then at next node, each pair will also contribute 1 extra to the answer. Thus the ans gets contribution of LONGEST common substring for each pair.
    return res;               // Return total strings passing through this node
  }

  ll solve() {
    ans = 0;                  // Initialize answer
    dfs(0);                   // Start DFS from the root
    return ans;               // Return the result
  }
};

void traverse(int v, const vector<Trie::Node>& nodes, string prefix) {
    // Print the current node
    cout << "Node at '" << prefix << "': cnt = " << nodes[v].cnt << ", children = ";
    for (auto child : nodes[v].to) {
        cout << "'" << child.first << "' ";
    }
    cout << endl;

    // Recursively traverse each child node
    for (auto child : nodes[v].to) {
        traverse(child.second, nodes, prefix + child.first);
    }
}

int main() {
  int n;
  cin >> n;                   // Read number of strings
  Trie t;                     // Create a Trie
  rep(i,n) {                  // Insert all strings into the Trie
    string s;
    cin >> s;
    t.add(s);
  }
    // traverse(0, t.d, "");  // Start from root node (index 0) with an empty prefix
    dbg(t.d[0].to);
  ll ans = t.solve();         // Solve using the Trie
  cout << ans << endl;        // Print the result
  return 0;
}
