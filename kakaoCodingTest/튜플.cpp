#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<math.h>
using namespace std;
string s;
int dat[100001];

//순서가 있는 모음 중복가능, 
//집합으로 묶었을때는 원소의 순서가 상관없다
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tup[100];
    s.erase(0, 2);
    int index = 0;
    int length = s.size();
    string tmp = " ";
    for (int i = 0; i < length; i++) {
        if (s[0]-'0'>9 || s[0]-'0'< 0) {
            if (s[0] == '{') index++;
            s.erase(0, 1);
        }
        else {
            while (s[0] - '0' > 0 && s[0] - '0' <= 9) {
                tmp += s[0];
                s.erase(0, 1);
            }
            tup[index].push_back(stoi(tmp));
            s.erase(0, 1);
            tmp = "";
        }
    }
    for (int i = 1; i <= index + 1; i++) {
        for (int j = 0; j <= index; j++) {
            if (tup[j].size() == i) {
                for (int k = 0; k < i; k++) {
                    if (dat[tup[j][k]] != 1) {
                        answer.push_back(tup[j][k]);
                        dat[tup[j][k]] = 1;
                    }
                }
                break;
            }
        }
        
    }
    int buf = 1;
    return answer;
}
int main(void) {
    cin >> s;
    solution(s);
}