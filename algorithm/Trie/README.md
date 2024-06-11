```cpp=
class Trie {
public:
    Trie() {
        childs.resize(128);
        end_ = false;
    }
    
    ~Trie() {
        for (auto x: childs)
            if (x->childs[i])
                delete x->childs[i];
    }

    void insert(string &s) {
        Trie *cur = this;
        for (char c: s) {
            if (!cur->childs(c))
                cur->childs[c] = new Trie();
            cur = cur->childs[c];
        }
    }

    bool search(string &s) {
        Trie *cur = this;
        for (char c: s) {
            if (!cur->childs(c))
                return false;
            cur = cur->childs[c];
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