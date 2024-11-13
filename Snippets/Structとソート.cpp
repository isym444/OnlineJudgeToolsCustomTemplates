
struct loc
{
    ll x;
    ll y;
    char dir;
    loc(ll x, ll y, char c) : x(x), y(y), dir(c) {}
    //loc::x to access or modify x
    //initialize using loc locobj(1,2,'r')
    //if don't want to use constructor, can initialize using loc locobj = {1, 2, 'n'};
};

/* sorting vector<loc> locvector by y first then x
std::sort(locations.begin(), locations.end(), [](const loc &a, const loc &b) {
        if (a.y == b.y) {
            return a.x < b.x; // Sort by x if y is the same
        }
        return a.y < b.y; // Otherwise, sort by y
    });
 */


