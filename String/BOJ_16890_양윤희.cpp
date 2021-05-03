#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
//시간 초과......
string apple, love;
char ans[300001];
int s, e;
int main(void) {
	cin >> apple >> love;
	sort(apple.begin(), apple.end());
	sort(love.begin(), love.end(), greater<int>());
	int length = apple.size();


	e = length - 1;
	for (int i = 1; i <= length / 2; i++) {
		//구사과 차례
		if (apple[0] < love[0] || i == length / 2) { //구사과의 제일 작은 숫자가 큐브의 제일 큰 숫자보다 작으면 맨 앞에다가 삽입
			ans[s] = apple[0];
			apple.erase(0, 1);
			s++;
		}
		else {
			ans[e] = apple[apple.size() - 1];
			e--;
			apple.erase(apple.size() - 1, 1);
		}

		//큐브차례
		if (love[0] >= apple[0] || i == length / 2) {
			ans[s] = love[0];
			love.erase(0, 1);
			s++;
		}
		else {
			ans[e] = love[love.size() - 1];
			e--;
			love.erase(love.size() - 1, 1);
		}
	}

	for (int i = 0; i < length; i++) {
		cout << ans[i];
	}
}