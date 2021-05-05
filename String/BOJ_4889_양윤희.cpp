#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;
string s;
int i = 1, answer, l, r;
int main(void) {
	while (true) {
		answer = 0, r = 0, l = 0;
		cin >> s;
		if (s[0] == '-')break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{')r++;
			else l++;
			if (l > r) {
				answer++;
				r++;
				l--;
			}
		}
		if (r > s.size() / 2)answer += r- (s.size() / 2);
		

		cout << i << ". " << answer << endl;
		i++;
	}
}