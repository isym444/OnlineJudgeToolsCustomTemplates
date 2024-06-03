
bool isBitSet(int number, int bitPosition) {
    return (number & (1 << bitPosition)) != 0;
}

vector<ll> getSetBitPositions(ll num) {
    std::vector<ll> setBitPositions;
    ll position = 0;

    while (num != 0) {
        if (num & 1) {
            setBitPositions.push_back(position);
        }
        num >>= 1;
        position++;
    }

    return setBitPositions;
}

//from binary indexes 0->60 (R to L), tells you length of repeating pattern, number of consecutive ones & zeros
//ssmb is number you want to compare against i.e. if you want to calculate number of times set bits coincide 
//in binary representation of ssmb and all numbers from 0->N
void setBitsAtBinaryIndex(string ssmb, ll N){
    N++;
    foi(0,60){
            if(ssmb[59-i]=='1'){
                // dbg(i);
                ll lengthOfRepeatingPattern = ipow(2,i+1);
                // dbg(lengthOfRepeatingPattern);
                ll consecutiveOnes = lengthOfRepeatingPattern/2;
                // dbg(consecutiveOnes);
                ll consecutiveZeros = consecutiveOnes;
                ll numberOfOnesInRepeatingPattern = lengthOfRepeatingPattern/2;
                ll remainder = MOD(N,lengthOfRepeatingPattern);
                ll numberOfCompleteRepeatingPatternsUpToN = (N-remainder)/lengthOfRepeatingPattern;
                ans+=numberOfCompleteRepeatingPatternsUpToN*numberOfOnesInRepeatingPattern;
                // dbg(numberOfCompleteRepeatingPatternsUpToN);
                if(remainder>consecutiveZeros){
                    // dbg(remainder);
                    remainder-=consecutiveZeros;
                    ans+=remainder;
                }
            }
        }
}