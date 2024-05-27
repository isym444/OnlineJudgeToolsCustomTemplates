
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