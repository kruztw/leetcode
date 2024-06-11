```cpp=
struct Treap {
    Treap *l, *r;
    long long priority, key, size;
    Treap(long long key) : l(nullptr), r(nullptr), priority(rand()), key(key), size(1) {}
    void update() {
        size = 1;
        if (l) size += l->size;
        if (r) size += r->size;
    }
};

Treap *merge(Treap *l, Treap *r) {
    if (!l || !r) return l ? l : r;
    if (l->priority <= r->priority) {
        l->r = merge(l->r, r);
        l->update();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->update();
        return r;
    }
}

// split t into l and r
void split(Treap *t, long long k, Treap *&l, Treap *&r) {
    if (!t) l = r = nullptr;
    else if (t->key <= k) {
        l = t;
        split(t->r, k, l->r, r);
        l->update();
    } else {
        r = t;
        split(t->l, k, l, r->l);
        r->update();
    }
}

void insert(Treap *&t, long long key) {
    Treap *l, *r;
    split(t, key, l, r);
    t = merge(l, merge(new Treap(key), r));
}
```