auto find = [&](auto&& self, int x) -> int {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = self(self, parent[x]);
    }
};