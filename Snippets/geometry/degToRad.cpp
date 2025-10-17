#include <cmath>

// constexpr double PI = 3.14159265358979323846;
const double PI = acos(-1); // Define the value of π

double degToRad(double degrees)
{
    return degrees * PI / 180.0;
}

double radToDeg(double radians)
{
    return radians * 180.0 / PI;
}