
vector<ll> genAlphabetPlaceholder()
{
    vector<ll> f(26);
    iota(f.begin(), f.end(), 0);
    return f;
}

vector<char> genAlphabet()
{
    vector<char> alphabet(26);
    iota(alphabet.begin(), alphabet.end(), 'a');
    return alphabet;
}

// emojis
const string EMO_LEG = u8"\U0001F9B5"; // 🦵
