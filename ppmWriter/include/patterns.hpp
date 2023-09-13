#include <vector> //may not need this
#include <math.h>

typedef std::vector<int> Color;
Color mandlebrot(int x, int y, int width, int height);
Color julia(int x, int y, int width, int height);
Color squares(int x, int y, int width, int height);
Color checkers(int x, int y, int width, int height);