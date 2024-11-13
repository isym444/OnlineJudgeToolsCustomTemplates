
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

//Works even for N > 1e8
//https://atcoder.jp/contests/abc363/submissions/56220823
string findNthPalindrome(ll N){
    if(N==1){
        return "0";
    }

    N--;

    //find number of numbers in current block
    for(int i = 1;;i++){
        ll numInBlock=9;
        numInBlock*=pow(10,((i-1)/2));
        if(N>numInBlock){
            N-=numInBlock;
            continue;
        }
        N+=((numInBlock/9)-1);
        string sN = to_string(N);
        // dbg(sN);
        string OGsN = sN;
        reverse(sN.begin(), sN.end());
        if(i%2==1){
            OGsN.pop_back();
        }
        return OGsN+sN;
    }
}