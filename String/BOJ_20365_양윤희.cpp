#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, bcount, rcount, ans, i;
string s;
int main(void) {
	cin >> n >> s;
	ans = 1;
	for (i = n-1; i >= 0; i--) {
		if (s[0] == s[i])break;
	}
	if (i != n - 1)ans++;
	for (int j = 1; j < i; j++) {
		if (s[0] != s[j]){
			ans++;
			int k = j;
			for (k = j; k < i; k++) {
				if (s[k] != s[j]) break;
			}
			j = k;
		}
	}
	cout << ans;
}