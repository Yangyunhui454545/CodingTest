#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct Node {
    int price;
    int time;
};
bool oper(Node n1, Node n2) {
    if (n1.time < n2.time)return true;
    else return false;
}
vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;
    vector<Node>res;
    string t = "", tt = "", ttt="", c="", p="";
    int j = 7;
    for (int i = 0;i < data.size(); i++) {
        j = 7; p = "", c = "", t = "";
        for (j = 6; j < data[i].size(); j++) {
            if (data[i][j] == ' ')break;
            p += data[i][j];
        }
        for (j = j + 6; j < data[i].size(); j++) {
            if (data[i][j] == ' ')break;
            c += data[i][j];
        }
        for (j = j + 6; j < data[i].size(); j++) {
            if (data[i][j] == ' ')break;
            t += data[i][j];
        }
        tt = t.substr(0, 8);
        if (code == c && tt == day) {
            ttt = t.substr(8);
            res.push_back({ stoi(p), stoi(ttt) });
        }
    }
    sort(res.begin(), res.end(), oper);
    for (int i = 0; i < res.size(); i++) {
        answer.push_back(res[i].price);
    }
    return answer;
}
int main(void) {
    solution("012345", "20190620", { "price=80 code=987654 time=2019062113" ,"price=90 code=012345 time=2019062014"
        ,"price=120 code=987654 time=2019062010","price=110 code=012345 time=2019062009",
        "price=95 code=012345 time=2019062111" });
}