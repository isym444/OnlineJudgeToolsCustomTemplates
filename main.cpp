<%!
    import json
    import os
    import platform
    import shutil
    from logging import getLogger

    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator.topcoder as topcoder
    import onlinejudge_template.generator.about as about
    import onlinejudge_template.generator.hook as hook
%>\
<%
    logger = getLogger(__name__)
    data["config"]["rep_macro"] = "REP"
    data["config"]["long_long_int"] = "long long"
    if platform.system() == "Linux" and "clang" not in os.environ.get("CXX", "g++"):
        include = "\n".join([
            "#include <bits/stdc++.h>",
            '#include <atcoder/all>'
            ])
    else:
        include = "\n".join([
            "#include <iostream>",
            "#include <string>",
            "#include <vector>",
            "#include <cstdio>",
            "#include <algorithm>",
            "#include <iostream>",
            "#include <vector>",
            "#include <string>",
            "#include <utility>",
            "#include <queue>",
            "#include <array>",
            "#include <climits>",
            "#include <cmath>",
            "#include <set>",
            "#include <map>",
            "#include <bitset>",
            "#include <deque>",
            "#include <numeric>",
            "#include <assert.h>",
            "#include <cassert>",
            "#include <unordered_map>",
            "#include <type_traits> // For std::is_floating_point",
            "#include <cmath> // For std::ceil",
            "#include <iomanip>",
            '#include <unordered_set>',
            '#include <functional>',
            '#include <type_traits>',
            '#include <chrono>',
            '#include <list>',
            '#include <complex>',
            '#include <atcoder/all>'
        ])
    if not shutil.which("clang-format"):
        logger.warning("clang-format is not installed. If you want to generate well-formatted code, please install it. If you use Ubuntu, you can run $ sudo apt install clang-format")
    else:
        format_config = {
            "BasedOnStyle": "Google",
            "IndentWidth": 4,
            "ColumnLimit": 9999,
            "ForEachMacros": ["REP", "REP3", "REP_R", "REP3R"],
        }
        hook.register_filter_command(["clang-format", "--style", json.dumps(format_config)], data=data)
%>\
${include}

using namespace std;
using namespace atcoder;


/*/---------------------------Looping helpers----------------------/*/
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
// #define rep(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define fo(from_0_to_non_incl_to) for(int i=0;i<from_0_to_non_incl_to;i++)
//h CAREFUL if you put an expression as an argument it will give bugs, better assign expression to variable then put that in the foi() as argument
#define foi(from,non_incl_to) for(int i=from;i<(non_incl_to);i++)
#define foii(non_incl_to) for(int i=0;i<(non_incl_to);i++)
#define foj(from,non_incl_to) for(int j=from;j<(non_incl_to);j++)
#define fojj(non_incl_to) for(int j=0;j<(non_incl_to);j++)
#define fok(from,non_incl_to) for(int k=from;k<(non_incl_to);k++)
#define fokk(non_incl_to) for(int k=0;k<(non_incl_to);k++)
#define fol(from,non_incl_to) for(int l=from;l<(non_incl_to);l++)
#define foll(non_incl_to) for(int l=0;l<(non_incl_to);l++)
#define fa(x, dataStructure) for(auto &x : dataStructure)
#define fx(dataStructure) for(auto &x : dataStructure)

/*/---------------------------Abbreviations----------------------/*/
// #define ll long long
#define ll __int128
#define sz(x) (int)(x).size()
#define fi first
#define sec second
#define se second

#define ALL(x) ::std::begin(x), ::std::end(x)
#define all(a) a.begin(),a.end()
#define rng(a) a.begin(),a.end()
//#define gcd __gcd
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define nyan ios::sync_with_stdio(false);cin.tie(nullptr);cout<<fixed<<setprecision(15);
ll INF=LLONG_MAX;

/*/---------------------------Data Structures----------------------/*/
typedef pair<ll, ll> pl;
//N.b. next() for next node in list, insert(iterator, value) "inserts" value at position right before iterator
typedef list<ll> dll;
using pll = pair<ll,ll>;
using pi = pair<int,int>;
typedef vector<ll> vll;
typedef std::vector<std::vector<ll>> vvll;

template<typename T> using vc = vector<T>;
template<typename T> using vc = vector<T>;
using vl = vc<ll>;

//max heap priority queue i.e. top() gives largest value
typedef priority_queue<ll> maxpq;
//min heap priority queue i.e. top() gives smallest value
typedef priority_queue<ll, vector<ll>, greater<ll>> minpq;

//multiset provides automatic ordering on insertion but unlike set, keeps duplicate/multiple items of same value
//n.b. set also provides autoamtic ordering on insertion n.b. maps are also sorted automatically on insertion according to key order
//.count(x) O(num_of_x+logN)
//.find(x) O(logN) -> so use find over count if possible
//.insert(x) O(logN) -> inserts s.t. sorted order is maintained
//.erase(x) O(logN)
//begin() O(logN)
typedef multiset<ll> msll;
//doing mymultiset.erase(x) will erase all
#define mserasesingle(mymultiset, x) mymultiset.erase(mymultiset.find(x))
#define mseraseall(mymultiset, x) mymultiset.erase(x)
//find smallest and biggest elements O(1)
#define msmin(mymultiset) *mymultiset.begin()
#define msmax(mymultiset) *mymultiset.rbegin()

/*/---------------------------Misc----------------------/*/
//Makes % get floor remainder (towards -INF) and make it always positive
#define MOD(x,y) (x%y+y)%y
// #define print(p) cout<<p<<endl
#define prmap(m) {for(auto i: m) cout<<(i.fi)<<i.sec<<endl}
#define pra(a) {for(auto i: a) cout<<i<<endl;}
#define prm(a) {for(auto i: a) pra(i) cout<<endl;}
#define vecsum(vectorName) accumulate((vectorName).begin(), (vectorName).end(), 0)
#define isvalid(checking,min_boundary,max_boundary) (0<=checking and checking<max_boundary)

/*/---------------------------Base Conversions----------------------/*/
//#define itobin(x) bitset<32> bin(x)
#define itobin(intToConvertTo32BitBinaryNum) std::bitset<32>(intToConvertTo32BitBinaryNum)
#define bintoi(binaryNum32BitToConvertToInt) binaryNum32BitToConvertToInt.to_ulong()
#define binstoi(binaryStringToConvertToInt) stoi(binaryStringToConvertToInt, nullptr, 2)
#define binstoll(binaryStringToConvertToInt) stoll(binaryStringToConvertToInt, nullptr, 2)

/*/---------------------------Bits----------------------/*/
#define setbits(decimalnumber) __builtin_popcountll(decimalnumber)


/*/---------------------------Strings----------------------/*/
#define stringSplice(str, i, j) (str).erase(i, j) //j is the length of string to erase starting from index i
#define string_pop_back(str) (str).pop_back()
#define substring(str, i, j) (str).substr(i, j) //j is the length of substring from i

/*/---------------------------Custom Hash----------------------/*/
// gp_hash_table<long long, int, custom_hash> safe_hash_table;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

/*/---------------------------IO(Debugging)----------------------/*/

// __int128 I/O:
inline istream &operator>>(istream &is, __int128 &v) {
    string s; is >> s; v = 0; bool neg = (!s.empty() && s[0] == '-');
    for (int i = neg; i < (int)s.size(); i++) v = v * 10 + (s[i] - '0');
    if (neg) v = -v; return is;
}
inline ostream &operator<<(ostream &os, __int128 v) {
    if (v == 0) return os << "0";
    bool neg = (v < 0); if (neg) { os << '-'; v = -v; }
    string s; while (v > 0) { s.push_back(char('0' + int(v % 10))); v /= 10; }
    reverse(s.begin(), s.end()); return os << s;
}

// Vector reading:
template<class T> inline istream &operator>>(istream &is, vector<T> &V) { for (auto &e : V) is >> e; return is; }

// Container printing:
template<class OStream,class T> inline OStream &operator<<(OStream &os,const vector<T> &vec){os<<'[';for(auto &v:vec)os<<v<<',';os<<']';return os;}
template<class OStream,class T,size_t sz> inline OStream &operator<<(OStream &os,const array<T,sz> &arr){os<<'[';for(auto &v:arr)os<<v<<',';os<<']';return os;}
template<class OStream,class T,class TH> inline OStream &operator<<(OStream &os,const unordered_set<T,TH>& st){os<<'{';for(auto &v:st)os<<v<<',';os<<'}';return os;}
template<class OStream,class T> inline OStream &operator<<(OStream &os,const deque<T> &dq){os<<"deq[";for(auto &v:dq)os<<v<<',';os<<']';return os;}
template<class OStream,class T> inline OStream &operator<<(OStream &os,const set<T> &st){os<<'{';for(auto &v:st)os<<v<<',';os<<'}';return os;}
template<class OStream,class T> inline OStream &operator<<(OStream &os,const multiset<T> &st){os<<'{';for(auto &v:st)os<<v<<',';os<<'}';return os;}
template<class OStream,class T> inline OStream &operator<<(OStream &os,const unordered_multiset<T> &st){os<<'{';for(auto &v:st)os<<v<<',';os<<'}';return os;}
template<class OStream,class T,class U> inline OStream &operator<<(OStream &os,const pair<T,U> &pa){return os<<'('<<pa.first<<','<<pa.second<<')';}
template<class OStream,class TK,class TV> inline OStream &operator<<(OStream &os,const map<TK,TV> &mp){os<<'{';for(auto &m:mp)os<<m.first<<"=>"<<m.second<<',';os<<'}';return os;}
template<class OStream,class TK,class TV,class TH> inline OStream &operator<<(OStream &os,const unordered_map<TK,TV,TH> &mp){os<<'{';for(auto &m:mp)os<<m.first<<"=>"<<m.second<<',';os<<'}';return os;}
template<class OStream,class T,size_t rows,size_t cols> inline OStream &operator<<(OStream &os,T (&arr)[rows][cols]){os<<'[';for(size_t i=0;i<rows;i++){if(i>0)os<<',';os<<'[';for(size_t j=0;j<cols;j++){if(j>0)os<<',';os<<arr[i][j];}os<<']';}os<<']';return os;}

// Tuple printing/reading:
template<class... T> inline istream &operator>>(istream &is, tuple<T...> &tpl){ std::apply([&is](auto &&... args){ ((is >> args), ...); }, tpl); return is; }
template<class OStream,class... T> inline OStream &operator<<(OStream &os,const tuple<T...> &tpl){os<<'(';std::apply([&os](auto &&... args){((os<<args<<','),...);},tpl);return os<<')';}

void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
    freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
    freopen((name + ".out").c_str(), "w", stdout);
    }
}

/*/---------------------------Custom library - most used only----------------------/*/


/*/---------------------------Syntax hints for mint once import mint.cpp----------------------/*/
//n.b. it is a data type so declare variablesas: mint x;
// to convert any other data type such as int or ll to mint, do: mint(x);
// when you want to access the value of a mint, use x.val()
// e.g. modint998244353 a = modint998244353(x); // `a` now represents `x` modulo 998244353
// using mint = modint998244353;
// Custom operator<< for modint998244353
// How to use the ACL modular exponentiation function?
// e.g. to do pow(10,6)
// mint(10).pow(6)

// //uncomment this code to allow dbg / ostream to handle mint
// std::ostream& operator<<(std::ostream& os, const mint& m) {
//     return os << m.val();
// }

#ifdef isym444_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << COLOR_RESET << std::endl
#define dbgif(cond, x) ((cond) ? std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl : std::cerr)
#else
#define dbg(x) ((void)0)
#define dbgif(cond, x) ((void)0)
#endif

ll midpoint(ll L, ll R){
    return (L+(R-L)/2);
}

template<typename T, typename U>
auto ceildiv(T n, U d) -> decltype(n / d + 0) {
    static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "ceildiv requires arithmetic types");

    if constexpr (std::is_floating_point<T>::value || std::is_floating_point<U>::value) {
        // Handle case where either n or d is a floating-point number
        return static_cast<decltype(n / d + 0)>(std::ceil(n / static_cast<double>(d)));
    } else {
        // Handle case where both n and d are integers
        return (n + d - 1) / d;
    }
}

/* ll ceildiv(ll n, ll d){
return((n+d-1)/d);
}
*/
/* ll floordiv(ll n, ll d){
ll x = (n%d+d)%d;
return ((n-x)/d);
}
 */
template<typename T, typename U>
auto floordiv(T n, U d) -> decltype(n / d + 0) {
    static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "floordiv requires arithmetic types");

    if constexpr (std::is_floating_point<T>::value || std::is_floating_point<U>::value) {
        // Handle case where either n or d is a floating-point number
        // Perform the division as floating-point operation and use std::floor to round down
        return static_cast<decltype(n / d + 0)>(std::floor(n / static_cast<double>(d)));
    } else {
        // Handle case where both n and d are integers
        // Original logic for floor division with integers
        T x = (n % d + d) % d;
        return (n - x) / d;
    }
}

template <class T> std::vector<T> sort_unique(std::vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
//index of the first occurrence of x. If x is not present in the vector, it returns the index where x can be inserted while keeping the vector sorted
template <class T> int indlb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
//index immediately after the last occurrence of x. If x is not present, like the lower bound, it returns the index where x can be inserted to maintain order
template <class T> int indub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }

/*/---------------------------Useful Graph Visualizer----------------------/*/
//https://csacademy.com/app/graph_editor/

//h INSERT CODE SNIPPETS HERE
/*/---------------------------INSERT CODE SNIPPETS HERE----------------------/*/



/*/---------------------------OJ tools automatic I/O parsing----------------------/*/
${cplusplus.declare_constants(data)}
% if topcoder.is_topcoder(data):
<% solve_function = topcoder.class_name(data) + "()." + topcoder.method_name(data) %>\
class ${topcoder.class_name(data)} {
public:
    ${cplusplus.return_type(data)} ${topcoder.method_name(data)}(${cplusplus.formal_arguments(data)}) {
    }
};
% else:
<% solve_function = "solve" %>\
${cplusplus.return_type(data)} solve(${cplusplus.formal_arguments(data)}) {
    /* vis.assign(n+1, false);
    g.assign(n+1, vector<ll>());
    wg.assign(n + 1, vector<pair<ll,ll>>());
    parent.assign(n+1, -1); */
}
% endif

int main() {
    std::ios::sync_with_stdio(false);
    setIO("");
    std::cin.tie(nullptr);
    // sets precision of output of floating point numbers to x number of decimal places
    cout << fixed << setprecision(11);
    unordered_map<long long, int, custom_hash> safe_map;
${cplusplus.read_input(data)}
    auto ${cplusplus.return_value(data)} = ${solve_function}(${cplusplus.actual_arguments(data)});
${cplusplus.write_output(data)}


    /*/---------------------------Syntax hints once import various Snippets----------------------/*/
    /* genprimes(1e5); */

    /* //run the bfs and output order of traversed nodes (for loop is only used for non-connected graphs)
    for (int i = 0; i < n; i++) {
        if (!v[i])
            bfs(i);
    }
    
    //Use for problems where you have to go up,down,left,right. Do x+i & y+j and i&j will test all 4 directions. Do x+i+1 & y+j+1 if 0 indexed
    wasd(
        //cout << "Use this for problems where you have to go up, down, left right" << endl;
    ) */

    return 0;
}
