int countUniqueSubstrings(const string& s) {
    set<string> unique_substrings;
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = 1; j <= s.size() - i; ++j) {
            unique_substrings.insert(s.substr(i, j));
        }
    }
    return unique_substrings.size();
}





