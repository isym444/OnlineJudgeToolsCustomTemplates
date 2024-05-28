int digit_to_int(char c) { return c - '0'; }
int lowercase_to_int(char c) { return c - 'a'; }
int uppercase_to_int(char c) { return c - 'A'; }
template <typename Func, typename Seq>
auto transform_to_vector(const Func &f, const Seq &s) {
    std::vector<std::invoke_result_t<Func, typename Seq::value_type>> v;
    v.reserve(std::size(s)), std::transform(std::begin(s), std::end(s), std::back_inserter(v), f);
    return v;
}
template <typename T, typename Seq>
auto copy_to_vector(const Seq &s) {
    std::vector<T> v;
    v.reserve(std::size(s)), std::copy(std::begin(s), std::end(s), std::back_inserter(v));
    return v;
}
template <typename Seq>
Seq concat(Seq s, const Seq &t) {
    s.reserve(std::size(s) + std::size(t));
    std::copy(std::begin(t), std::end(t), std::back_inserter(s));
    return s;
}
std::vector<int> digit_str_to_ints(const std::string &s) {
    return transform_to_vector(digit_to_int, s);
}
std::vector<int> lowercase_str_to_ints(const std::string &s) {
    return transform_to_vector(lowercase_to_int, s);
}
std::vector<int> uppercase_str_to_ints(const std::string &s) {
    return transform_to_vector(uppercase_to_int, s);
}
template <typename Seq>
std::vector<Seq> split(const Seq s, typename Seq::value_type delim) {
    std::vector<Seq> res;
    for (auto itl = std::begin(s), itr = itl;; itl = ++itr) {
        while (itr != std::end(s) and *itr != delim) ++itr;
        res.emplace_back(itl, itr);
        if (itr == std::end(s)) return res;
    }
}
// Overload of split function to handle C-style strings
std::vector<std::string> split(const char* s, char delim) {
    return split(std::string(s), delim);
}