#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<math.h>
using namespace std;
string s, tmp;
int arr[100000], maxi;
queue<int> q;
int main(void) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2;i < sqrt(100000); i++) {
		if (arr[i] == 1)continue;
		for (int j = i + i; j < 100000; j += i) {
			arr[j] = 1;
		}
	}
	while(true){
		cin >> s;
		if (s == "0") break;
		maxi = 0;
		int length = 0;
		for (int i = 0; i < s.length(); i++) {
			tmp = "";
			if (s.length() - i - 1 < length)break;
			for (int j = i; j < s.length(); j++) {
				tmp += s[j];
				if (stoi(tmp) > 100000)break;
				if (arr[stoi(tmp)] != 1 && maxi < stoi(tmp)) {
					maxi = stoi(tmp);
					length = tmp.size();
				}
			}
		}
		q.push(maxi);
	}
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}