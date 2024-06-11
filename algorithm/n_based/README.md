## convertion
```cpp=
// base 可以是負的
vector<int> convert(int x, int base) {
    vector<int> ret;

    while (x) {
        int div = x/base + (x%base < 0);
        int mod = x - base*div; // 餘數一定要是正數
        ret.push_back(mod);
        x = (x - mod)/base;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
```

## add
```cpp=
// ps: n != 0 1 -1
vector<int> ret;
int x = 0, base = -2;
int p1 = arr1.size()-1, p2 = arr2.size()-1;
        
while (p1 >= 0 || p2 >= 0 || x) {
    if (p1 >= 0)
        x += arr1[p1--];
    if (p2 >= 0)
        x += arr2[p2--];
            
    int div = x/base + (x%base < 0);
    int mod = x - base*div;
    x = (x-mod)/base;
    ret.push_back(mod);
}
        
while (ret.size() > 1 && ret.back() == 0)
    ret.pop_back();
        
reverse(res.begin(), res.end());
return res;
```