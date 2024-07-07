```cpp=
class Trie {
public:
    Trie() {
        childs.resize(26);
        end_ = false;
    }
    
    ~Trie() {
        for (auto x: childs)
            delete x;
    }

    void insert(string &s) {
        Trie *cur = this;
        for (char c: s) {
            if (!cur->childs[c-'a'])
                cur->childs[c-'a'] = new Trie();
            cur = cur->childs[c-'a'];
        }
    }

    bool search(string &s) {
        Trie *cur = this;
        for (char c: s) {
            if (!cur->childs[c-'a'])
                return false;
            cur = cur->childs[c-'a'];
        }
        return cur->end_;
    }
private:
    vector<Trie *> childs;
    bool end_;
};

Trie root;
root.insert("apple");
root.search("apple");
```
