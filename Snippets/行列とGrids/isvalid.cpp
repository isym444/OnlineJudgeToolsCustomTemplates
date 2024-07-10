
// #define isvalid(x_plus_i,max_boundary_n,y_plus_j,max_boundary_m) (0<=x_plus_i and x_plus_i<max_boundary_n and 0<=y_plus_j and y_plus_j<max_boundary_m)
#define isvalid(x_value,y_value,min_valid_x,max_valid_x,min_valid_y,max_valid_y) (min_valid_x<=x_value and x_value<max_valid_x and min_valid_y<=y_value and y_value<max_valid_y)
#define isvalidsingle(value,min_valid_value,max_valid_value) (min_valid_value<=value and value<max_valid_value)

//#define gcd __gcd