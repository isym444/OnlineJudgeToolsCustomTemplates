
string itobins(ll n) {
    if (n == 0) return "0";

    string binary = "";
    while (n > 0) {
        binary += (n % 2) ? '1' : '0';
        n /= 2;
    }

    reverse(binary.begin(), binary.end()); // Reverse to get the correct order
    return binary;
}

string dtobx(ll decimalNumber, ll base) {
    if (base < 2 || base > 36) {
        return "Invalid base";
    }

    string result = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;

        // Convert remainder to corresponding character
        if (remainder >= 10) {
            result += 'A' + (remainder - 10);
        } else {
            result += '0' + remainder;
        }

        decimalNumber /= base;
    }

    // Reverse the string as the result is calculated in reverse order
    reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}

int stringToBinary(const std::string& s, char charAsOne) {
    int x = 0;
    for (int j = 0; j < s.length(); j++) {
        x = 2 * x + (s[j] == charAsOne);
    }
    return x;
}