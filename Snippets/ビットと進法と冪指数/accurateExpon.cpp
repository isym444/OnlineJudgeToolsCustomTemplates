// use instead of pow when dealing with large numbers as pow() uses floating point arithmetic, which will give wrong results for large numbers
// this allows it to deal with powering decimal numbers etc
// but if you are powering large integers then use ipow which uses int/long long only for accuracy
long long ipow(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

