/* 
1- Find the remainder of n by moduling it with 4. 
2- If rem = 0, then XOR will be same as n. 
3- If rem = 1, then XOR will be 1. 
4- If rem = 2, then XOR will be n+1. 
5- If rem = 3 ,then XOR will be 0.
 How does this work? 
When we do XOR of numbers, we get 0 as the XOR value just before a multiple of 4. This keeps repeating before every multiple of 4. 

Number Binary-Repr  XOR-from-1-to-n


1         1                [0001]
2        10              [0011]
3        11              [0000]  <—– We get a 0
4       100            [0100]  <—– Equals to n
5       101            [0001]
6       110            [0111]
7       111             [0000]  <—– We get 0
8      1000         [1000]  <—– Equals to n
9      1001          [0001]
10     1010          [1011]
11     1011           [0000] <—— We get 0
12     1100         [1100] <—— Equals to n  
 */

// XOR of 1 to N in O(1)
ll computeXOR(ll n) {
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else // n % 4 == 3
        return 0;
}