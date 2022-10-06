// target: "aaabb" => 3a, 2b

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s = "aaabb";
	
	char prev = s[0];
	int cnt = 0;
	s.push_back('\xff');

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != prev) {
			cout << cnt << prev << ", ";
			cnt = 0;
		}

		++cnt;
		prev = s[i];
	}

	cout << endl;

	return 0;
}
