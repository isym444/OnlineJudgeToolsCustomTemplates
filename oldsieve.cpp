const int MAXN = 2 * 100000 + 10; // Adjust the size as per the problem constraints
//smallest prime factor
std::vector<int> spf(MAXN);

//Sieve of Eratosthenes to precompute the smallest prime factor of each number
void spfsieve() {
    //initializes smallest prime factor for 1 as 1
    spf[1] = 1;
    //initially treats every number as a prime and assigns the smallest prime factor as itself
    for (int i = 2; i < MAXN; ++i) {
        spf[i] = i;
    }
    //all even numbers' smallest prime factor is 2. This sets this for all even numbers
    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }
    //calculates upper limit to which we need to check for primes (optimization)
    //because factors come in pairs e.g. N = 36, its factors are (1, 36), (2, 18), (3, 12), (4, 9), and (6, 6)
    //so after sqrt(N) the pairs will switch and and won't find any further new factors
    //Factors of a number come in pairs, with one factor being less than or equal to the square root of the number,
    //and the other being greater than or equal to the square root.
    int limit = std::ceil(std::sqrt(MAXN));
    for (int i = 3; i < limit; i+=2) {
        //checks if i is still marked as it's own smallest prime factor
        //indicating that it is still prime 
        //because we have iterated through all smaller numbers beforehand so if not a multiple of any of those
        //then by definition it must be prime
        if (spf[i] == i) {
            //start from i*i as spf for smaller numbers than this would be marked by smaller numbers than i (if not prime)
            for (int j = i * i; j < MAXN; j += i) {
                //if smallest prime factor of j is still set as itself i.e. spf not yet been set
                //then set spf as i
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

//Function to return the prime factorization of a number (is unique for every number)
//make sure to call spfsieve() before calling this function so spf values are prepopulated
std::unordered_map<int, int> fact(int x) {
    std::unordered_map<int, int> pfactors;
    while (x != 1) {
        //if the smallest prime factor of x has not yet been added to pfactors
        //  then set p^1
        //if the smallest prime factor of x has already been added to pfactors
        //  then set p^(prev exponent+1)
        if (pfactors.find(spf[x]) == pfactors.end()) {
            pfactors[spf[x]] = 1;
        } else {
            pfactors[spf[x]] += 1;
        }
        //while x!=1, divide x by its smallest prime factor
        x = x / spf[x];
    }
    return pfactors;
}
