#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<math.h>
using namespace std;
vector<string> user_id;
vector<string> banned_id;
//불량 사용자  -->  프로도
// 개인정보를 위해 일부 문자를 *로 바꿈 
// banned_id에서 user_id가 나올 수 있는 모든 경우의 수,,,,?
//2 4
//4 2
//3 6 1
int visit2[88888888];
int visit[8];
int dat[8];
int length;
int res;
vector<int> cnt[8];
string ans;
void dfs(int val) {
    if (val == length) {
        string tmp = ans;
        sort(tmp.begin(), tmp.end());
        if (visit2[stoi(tmp)] == 1)return;
        visit2[stoi(tmp)] = 1;
        res++;
        cout << ans << endl;
        return;
    }
    for (int j = 0; j < cnt[val].size(); j++) {
        if (visit[cnt[val][j]]== 1)continue;
        visit[cnt[val][j]] = 1;
        ans += to_string(cnt[val][j] + 1);
        dfs(val + 1);
        ans.erase(ans.size() - 1, 1);
        visit[cnt[val][j]] = 0;
    }

}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    length = banned_id.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (banned_id[i].length() == user_id[j].length()) {
                for (int k = 0; k < banned_id[i].length(); k++) {
                    if (banned_id[i][k] != '*') {
                        if(banned_id[i][k] != user_id[j][k]) break;
                    }
                    if (k == banned_id[i].length() - 1) { cnt[i].push_back(j); dat[j]++; }
                }
            }
        }
    }

    dfs(0);
    answer = res;
    return answer;
}
int main(void) {
    string tmp = "";
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        user_id.push_back(tmp);
    }
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        banned_id.push_back(tmp);
    }
    cout << solution(user_id, banned_id);
}