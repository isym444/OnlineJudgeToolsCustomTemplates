int countDigits(int n) {
    if (n == 0) return 1; // Special case for 0
    return std::floor(std::log10(std::abs(n))) + 1;
}