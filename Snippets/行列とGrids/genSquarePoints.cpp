//Takes in a point and returns vector<pair<int, int>> containing all points relative to og point that form a 
//square given an initial dx & dy between og_point and one other point n.b. always rotating in same direction
vector<pair<int, int>> generateSquarePoints(int x, int y, int dx, int dy) {
    pair<int, int> p1, p2, p3, p4;
    
    p1 = mp(x, y);
    p2 = mp(p1.first + dx, p1.second + dy);
    p3 = mp(p2.first - dy, p2.second + dx);
    p4 = mp(p3.first - dx, p3.second - dy);
    
    // p1 = mp(x,y);
    // p2 = mp(x+dx,y+dy);
    // p3 = mp(x+dx-dy,y+dy+dx);
    // p4 = mp(x-dy,y+dx);

    vector<pair<int, int>> points = {p1, p2, p3, p4};
    return points;
}



