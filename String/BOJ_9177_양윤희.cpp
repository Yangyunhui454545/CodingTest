#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
int n;
string one, two, three;
bool flag;
struct Node {
	int i1, i2, i3;
};
queue<Node> q;
int visit[201][201];
bool same() {
	q.push({ 0, 0, 0 });
	while (!q.empty()) {

		int i1 = q.front().i1;
		int i2 = q.front().i2;
		int i3 = q.front().i3;
		q.pop();

		for (int i = i3; i < three.size(); i++) {
			if (one[i1] == three[i] && three[i] == two[i2]) {
				if (visit[i1][i2] == 1)  break; 
				visit[i1][i2] = 1;
				q.push({ i1+1, i2, i + 1 });
				q.push({ i1, i2+1, i + 1 });
				break;
			}
			visit[i1][i2] = 1;
			if (three[i] == one[i1]) {
				i1++;
			}
			else if (three[i] == two[i2]) {
				i2++;
			}
			else {
				break;
			}
		}
		if (i1==one.size() && i2 ==two.size()) {
			while (!q.empty()) q.pop();
			return true;
		}
	}
	return false;
}
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> one >> two >> three;
		flag = true;
		flag = same();

		cout << "Data set ";
		cout << i;
		cout << ": ";
		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}