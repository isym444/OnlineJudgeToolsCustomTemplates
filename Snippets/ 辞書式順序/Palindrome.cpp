
bool isPalindrome(const std::string& s) {
    int start = 0;
    int end = s.length() - 1;

    while(start < end) {
        // Skip non-alphanumeric characters
        while(start < end && !isalnum(s[start])) start++;
        while(start < end && !isalnum(s[end])) end--;

        // Check for palindrome, ignoring case
        if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool isPalindrome(long long n) {
    if (n < 0) return false; // Negative numbers are not considered palindromes

    long long reversed = 0, original = n, remainder;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return original == reversed;
}