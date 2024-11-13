
// template<typename CharT, typename Traits, typename T>
// ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
//     return (out << val << " ");
// }
// template<typename CharT, typename Traits, typename T1, typename T2>
// ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
//     return (out << "(" << val.first << "," << val.second << ") ");
// }
// template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
// ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
//     out << "[ ";
//     for(auto&& elem : cont) _containerprint(out, elem);
//     return (out << "]");
// }
// template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
//     return (out << "(" << val.first << "," << val.second << ") ");
// }
// template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
//     static priority_queue<P, Q, R> U;
//     U = M;
//     out << "{ ";
//     while(!U.empty())
//         out << U.top() << " ", U.pop();
//     return (out << "}");
// }
// template<class P> ostream& operator << (ostream& out, queue<P> const& M){
//     static queue<P> U;
//     U = M;
//     out << "{ ";
//     while(!U.empty())
//         out << U.front() << " ", U.pop();
//     return (out << "}");
// }
// template<typename CharT, typename Traits>
// ostream& operator << (std::basic_ostream<CharT, Traits> &out, vector<vector<ll>> const &matrix) {
//     for (auto &row : matrix) {
//         out << row << "\n";
//     }
//     return out;
// }