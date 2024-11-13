//3 points to right angle
ll ax, ay, bx, by, cx, cy;
cin >> ax >> ay >> bx >> by >> cx >> cy;
ll AB2 = (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
ll BC2 = (cx-bx)*(cx-bx)+(cy-by)*(cy-by);
ll CA2 = (cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);

if(AB2+BC2==CA2||AB2+CA2==BC2||BC2+CA2==AB2){
    cout << "Yes" << endl;
    return 0;
}

cout << "No" << endl;