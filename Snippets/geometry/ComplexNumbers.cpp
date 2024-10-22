#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

using C = complex<double>;  // C represents complex numbers
C inC() {
  double x, y;
  cin >> x >> y;  // Read the x and y coordinates
  return C(x,y);  // Return as complex number C(x, y)
}

int main() {
  int n;
  cin >> n;  // Read number of vertices N
  C s = inC();  // Read coordinates of p_0
  C t = inC();  // Read coordinates of p_{N/2}

  C o = (s+t)/2.0;  // Calculate the center (midpoint between p_0 and p_{N/2})
  double PI = acos(-1);  // Define the value of π
  double rad = 2*PI/n;  // Calculate the angle between consecutive vertices (2π/N)
  
  C r(cos(rad), sin(rad));  // Rotation factor using Euler's formula
  C ans = o + (s-o)*r;  // Rotate p_0 around the center by angle rad to get p_1
  
  printf("%.10f %.10f\n", ans.real(), ans.imag());  // Output coordinates of p_1
  return 0;
}
