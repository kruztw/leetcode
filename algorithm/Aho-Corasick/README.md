```
struct TrieNode {
    TrieNode *sfx = nullptr;
    TrieNode *dict = nullptr; // point to the word end node
    array<TrieNode*, 26> child{};
    int word_id = -1;
};

TrieNode trieNode[(int)5e4 + 5];
TrieNode *curr;

class Trie {
public:
    int cnt = 0;
    TrieNode *newTrieNode() {
        trieNode[cnt] = TrieNode();
        return &trieNode[cnt++];
    }
    void init(TrieNode *root, vector<string>& words, vector<int> &costs) {
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *u = root;
            for (auto c : words[i]) {
                if (!u->child[c - 'a'])
                    u->child[c - 'a'] = newTrieNode();
                u = u->child[c - 'a'];
            }
            if (u->word_id < 0 || costs[i] < costs[u->word_id])
                u->word_id = i;
        }
    
        queue<TrieNode*> q;
        q.push(root);
        while (!q.empty()) {
            TrieNode *u = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) {
                auto v = u->child[i];
                if (!v)
                    continue;
    
                TrieNode *p = u->sfx;
                while (p != root && !p->child[i])
                    p = p->sfx;
    
                if (u != root && p->child[i]) {
                    v->sfx = p->child[i];
                } else {
                    v->sfx = root;
                }

                v->dict = v->sfx->word_id >= 0 ? v->sfx : v->sfx->dict;
                q.push(v);
            }
        }
        curr = root;
    }

    vector<int> suffixesAfterAppending(TrieNode *root, char letter) {
        TrieNode *start = root;
        while (curr != root && !curr->child[letter - 'a'])
            curr = curr->sfx;

        if (curr->child[letter-'a']) {
            curr = curr->child[letter - 'a'];
            start = curr->word_id >= 0 ? curr : curr->dict;
        }

        vector<int> ret;
        while (start != root) {
            ret.push_back(start->word_id);
            start = start->dict;
        }
        return ret;
    }
};

int dp[(int)1e5 + 5];

class Solution {
public:
    int minimumCost(string &target, vector<string>& words, vector<int>& costs) {
        int n = target.size();

        Trie *trie = new Trie();
        TrieNode *root = trie->newTrieNode();
        root->sfx = root->dict = root;
        trie->init(root, words, costs);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1e9;
            for (int j : trie->suffixesAfterAppending(root, target[i - 1]))
                dp[i] = min(dp[i], dp[i - words[j].size()] + costs[j]);
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }
};
```

[leetcode 3213](https://leetcode.com/problems/construct-string-with-minimum-cost/solutions/5431950/monster-problem-4-nsqrtn-trie-aho-corasick-dp/)
