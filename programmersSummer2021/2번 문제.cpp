#include <string>
#include <vector>
#include<algorithm>

using namespace std;
struct Node {
    int id, time, vip;
};
bool oper(Node n1, Node n2) {
    if (n1.vip < n2.vip) return true;
    else if (n1.vip == n2.vip) {
        if (n1.time < n2.time)return true;
        else if (n1.time == n2.time) {
            if (n1.id < n2.id)return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer;
    vector<Node> res[1002];
    int getMin = 10001;
    for (int i = 0; i < t.size(); i++) {
        res[t[i]].push_back({ i, t[i], r[i] });
        if (getMin > t[i])getMin = t[i];
    }
    for (int i = getMin; i < 1001; i++) {
        if (answer.size() == t.size())break;
        if (res[i].size() == 0)continue;
        if (res[i].size() > 1 && i == 1000) {
            sort(res[i].begin(), res[i].end(), oper);
            for (int j = 0; j < res[i].size(); j++) {
                answer.push_back(res[i][j].id);
            }
        }
        else if (res[i].size() > 1) {
            sort(res[i].begin(), res[i].end(), oper);
            answer.push_back(res[i][0].id);
            for (int j = 1; j < res[i].size(); j++) {
                res[i + 1].push_back({ res[i][j].id, res[i][j].time, res[i][j].vip });
            }
        }
        else if (res[i].size() == 1) answer.push_back(res[i][0].id);
    }
    return answer;
}
int main(void) {
    solution({ 10000,10000,999 }, { 0,1,2 });
}
