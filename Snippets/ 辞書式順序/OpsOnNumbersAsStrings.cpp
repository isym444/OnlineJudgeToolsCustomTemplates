// Function to remove leading zeros
std::string removeLeadingZeros(const std::string& str) {
    size_t nonZero = str.find_first_not_of('0');
    return (nonZero != std::string::npos) ? str.substr(nonZero) : "0";
}

// Function to subtract two numbers represented as strings
std::string subtractStrings(const std::string& num1, const std::string& num2) {
    std::string a = num1;
    std::string b = num2;

    // Ensure 'a' is the larger number
    bool negative = false;
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        std::swap(a, b);
        negative = true;
    }

    std::string result;
    int carry = 0;
    int diff = 0;
    
    // Reverse the strings to simplify the loop
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (size_t i = 0; i < a.length(); ++i) {
        int digitA = a[i] - '0';
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;

        diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(diff + '0');
    }

    // Remove leading zeros and reverse back
    std::reverse(result.begin(), result.end());
    result = removeLeadingZeros(result);

    return negative ? "-" + result : result;
}