```cpp=
#define PI 3.14159265
double get_angle(int dx, int dy) {
    return atan2(dy, dx) * 180 / PI;
}
```

[ref](https://leetcode.com/problems/maximum-number-of-visible-points/)