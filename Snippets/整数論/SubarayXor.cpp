
//https://atcoder.jp/contests/abc365/submissions/56364300

int main(){
    ll N;
    cin >> N;
    vll A(N);
    cin >> A;

    ll ans=0;

    foi(0,30){
        ll cumxor=0;
        ll n0=1;
        ll n1=0;
        ll sum=0;

        fx(A){
            ll temp = x&(1<<i);
            // dbg(mt(x,x&(1<<i)));
            if(temp>1) temp=1;
            cumxor=cumxor^temp;
            if(cumxor==1){
                sum+=n0;
                n1++;
            }
            if(cumxor==0){
                sum+=n1;
                n0++;
            }
        }
        // sum--;
        // dbg(sum);
        ans+=(sum<<i);
    }
    dbg(ans);
    fx(A){
        ans-=x; //because answer considers subarrays of length 1 but problem considers only subarrays of length > 1
    }
    cout << ans << endl;

    return 0;
}


// int main() {
//     int N;
//     // Read the number of elements in the array
//     cin >> N;
//     vector<int> A(N);
//     // Read the array elements
//     cin >> A;

//     ll ret = 0;  // Initialize the result to 0
//     // Loop over each bit position from 0 to 29
//     REP(d, 2) {
//         ll n0 = 1, n1 = 0;  // Counters for subarrays (number of subarrays ending in 0 and ending in 1)
//         ll sum = 0;  // Sum for current bit position

//         ll cs = 0;  // Cumulative XOR status for current bit position
//         // Iterate over the array elements
//         dbg(mt(n0,n1,sum,cs));
//         for (int a : A) {
//             // Check if the d-th bit is set in the current element
//             // dbg(mp(a,a&(1<<d)));
//             if (a & (1 << d)) {
//                 cs ^= 1;  // Toggle the cumulative XOR status
//             }

//             // Update the sum based on the current cumulative XOR status
//             if (cs) sum += n0, ++n1;  // If the cumulative XOR is 1
//             else sum += n1, ++n0;  // If the cumulative XOR is 0
//             dbg(mt(n0,n1,sum,cs));
//         }
//         // Add the contribution of the current bit position to the result
//         ret += sum << d;
//         dbg(ret);
//         cerr << endl;
//     }

//     // Subtract each element from the result
//     REP(i, N) ret -= A.at(i);

//     // Output the final result
//     cout << ret << '\n';
// }
