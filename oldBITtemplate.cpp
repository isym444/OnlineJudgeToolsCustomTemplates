
//Use fenwick_tree above instead
template <class T> struct BIT {
    T UNITY_SUM = 0;
    vector<T> dat;
    
    // [0, n)
    // Declare BIT (N elements initialized to 0) by doing:
    // BIT< long  long > bit (N);
    // fenwick tree is held in a vector<T> called dat
    BIT(int n, T unity = 0) : UNITY_SUM(unity), dat(n, unity) { }
    
    //allows reinitialization of the tree resetting all elements to unity sum
    void init(int n) {
        dat.assign(n, UNITY_SUM);
    }
    
    // a is 0-indexed
    // use add to add array item 'x' to index 'a' in Fenwick tree
    // n.b. index 'a' in Fenwick tree represents a range of responsibility
    // i.e. holds a prefix sum for a particular range of original array
    // this range of responsibility is determined by index 'a's binary representation
    // it is responsible for E elements below it
    // where E is the index of its LSB where index is from R->L of binary number
    // e.g. 11010 LSB index is 2
    inline void add(int a, T x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            dat[i] = dat[i] + x;
    }
    
    // Get sum over range [0, a), where a is 0-indexed
    inline T sum(int a) {
        T res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res = res + dat[i];
        return res;
    }
    
    // Get sum over range [a, b), where a and b are 0-indexed
    inline T sum(int a, int b) {
        return sum(b) - sum(a);
    }
    
    // debug
    // prints the values of original array after modifications
    void print() {
        for (int i = 0; i < (int)dat.size(); ++i)
            cerr << sum(i, i + 1) << ",";
        cerr << endl;
    }
};