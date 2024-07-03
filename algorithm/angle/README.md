```cpp=
#define PI 3.14159265
double getAngle(int dx, int dy) { // angle between (0,0) and (dx,dy)
    return atan2(dy, dx) * 180 / PI;
}

getAngle(dx1, dy1) - getAngle(dx2, dy2);
```

[ref](https://leetcode.com/problems/maximum-number-of-visible-points/)
