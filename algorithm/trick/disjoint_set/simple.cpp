#include <bits/stdc++.h>

using namespace std;

/*
        0
      /   \
    1       2
  /   \    /  \
3      4  5    6

*/

vector<int> parent = {0, 0, 0, 1, 1, 2, 2};

int findParent1(int x) {
	while (x != parent[x])
		x = parent[x];

	return x;
}

int findParent2(int x) {
	if (x != parent[x])
		parent[x] = findParent2(x); // 把 parent[x] 往上搬
	return parent[x];
}

int main() {
}
