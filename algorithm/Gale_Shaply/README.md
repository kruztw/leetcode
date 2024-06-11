```cpp=
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (prefer[w][i] == m1)
            return true;
        if (prefer[w][i] == m)
           return false;
    }
}

void stableMarriage(vector<vecotr<int>> &prefer) {
    vector<int> wPartner(N, -1);
    vector<int> mFree(N);

    for (int i = 0; i < N; ++i)
        mFree[i] = i;

    while (mFree.size()) {
        int m = mFree.back();

        for (int i = 0; i < N; i++) {
            int w = prefer[m][i];
            if (wPartner[w-N] == -1) {
                wPartner[w-N] = m;
                mFree.pop_back();
                break;
            } else {
                int m1 = wPartner[w-N];
                if (!wPrefersM1OverM(prefer, w, m, m1)) {
                    wPartner[w-N] = m;
                    mFree.back() = m1;
                    break;
                }
            }
        }
    }

    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << wPartner[i] << endl;
}
```