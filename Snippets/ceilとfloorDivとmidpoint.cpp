
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