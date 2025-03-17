struct Trie {
  struct Node {
    map<char,int> to;
    int cnt;
    int cntStartWithPrefix;
    Node(): cnt(0) {}
  };

  vector<Node> d;

  Trie() {
        d = vector<Node>(1);
    }

  void add(const string& s) {
    int v = 0;
    for (char c : s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }
};


auto dfs = [&](int v)->int{
    if(d[v].to.empty()){
        return(d[v].cnt);
    }
    for(auto [c, u]: d[v].to){

        d[v].cntStartWithPrefix += dfs(u);
    }
    
    return d[v].cntStartWithPrefix;
};

dfs(0);








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
