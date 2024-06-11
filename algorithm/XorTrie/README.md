```cpp=
class xorTrie {
public:
    xorTrie() {
        child.resize(2);
    }

    void insert(int v) {
        xorTrie *cur = this;
        for (int i = 63; i >= 0; --i) {
            bool b = v>>i&1;
            if (!cur->child[b])
                cur->child[b] = new xorTrie();
            cur = cur->child[b];
        }
    }

    long maxXor(long v) {
        xorTrie *cur = this;
        long ret = 0;
        for (int i = 63; i >= 0; --i) {
            if (!cur)
                break;
            bool b = v & (1<<i);
            if (cur->child[!b]) {
                ret |= (1LL<<i);
                cur = cur->child[!b];
            } else {
                cur = cur->child[b];
            }
        }
        return ret;
    }
};
```

[ref](https://leetcode.com/problems/maximum-xor-of-two-non-overlapping-subtrees/discuss/2848513/Two-vs.-One-Pass)