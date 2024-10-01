```cpp=
class BIT {    
public:
    BIT(vector<int> &nums) {
        int n = nums.size();
        orig.resize(n + 1);
        data.resize(n + 1); // 從 data[1] 開始放 !! (a)
        for (int i = 0; i < n; ++i)
            update(i, nums[i]);
    }
    
    void update(int i, long long val) {
        ++i; // 題目從 0 開始, 要 +1
        long long diff = val - orig[i];
        orig[i] = val;
        for (; i < data.size(); i += (i&-i)) // i = 0 會進入無窮迴圈, 所以 (a)
            data[i] += diff;
    }
    
    long long queryRange(int i, int j) {
        return query(j) - query(i-1);
    }
    
    long long query(int i) {
        ++i; // 題目從 0 開始, 要 +1
        long long ret = 0;
        for (; i > 0; i -= (i&-i))
            ret += data[i];
        return ret;
    }
    
private:
    //int lowbit(int x) { return x & (-x); } // 參考用
    vector<long long> orig, data;
};

BIT bit(nums);
bit.query(3);
bit.queryRange(2, 5);
bit.update(i, 1);
```

## partial max

### query
```cpp=
class BIT {
 public:
  BIT(int n) {
    data.resize(n+1);
  }

  void update(int i, int v) {
    ++i;
    for (; i < data.size(); i+=i&-i)
      data[i] = max(data[i], v);
  }

  int query(int i) {
    ++i;
    int ret = 0;
    for (; i; i-=i&-i)
      ret = max(ret, data[i]);
    return ret;
  }

private:
  vector<int> data;
};
```

### range query
```cpp=
class BIT {
public:
    BIT(vector<int> &nums) {
        n = 1;
        while (n < nums.size())// nums 從 n+1 開始放(最下層)
            n *= 2;

        seg.resize(n*2 + 1);
        for (int i = 0; i < nums.size(); ++i)
            update(i, nums[i]);
    }
    
    int query (int l, int r) { // [l,r]
        int ret = 0;
        for (l += n, r += n; l <= r; l/=2, r/=2) {
            ret = max(ret, seg[l++]);
            ret = max(ret, seg[r--]);
        }
        return ret;
    }
    
    void update(int index, int val) {
        index += n;
        seg[index] = val;
        for (; index > 1; index/=2)
            seg[index/2] = max(seg[index], seg[index^1]);
    }
    
private:
    vector<int> seg;
    int n;
};
```

[leetcode 2921](https://leetcode.com/problems/maximum-profitable-triplets-with-increasing-prices-ii)
[leetcode 2736](https://leetcode.com/problems/maximum-sum-queries/description/)
