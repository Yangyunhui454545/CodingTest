#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int solution(string s) {
    int answer = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if ((int)(s[i]) > 57) {
            if (s[i] == 'z') {
                ans += '0';
                i += 3;
                continue;
            }
            else if (s[i] == 'o') {
                ans += '1';
                i += 2;
                continue;
            }
            else if (s[i] == 't') {
                if (s[i + 1] == 'w') {
                    ans += '2';
                    i += 2;
                    continue;
                }
                else {
                    ans += '3';
                    i += 4;
                    continue;
                }
            }
            else if (s[i] == 'f') {
                if (s[i + 1] == 'o') {
                    ans += '4';
                    i += 3;
                    continue;
                }
                else {
                    ans += '5';
                    i += 3;
                    continue;
                }
            }
            else if (s[i] == 's') {
                if (s[i + 1] == 'i') {
                    ans += '6';
                    i += 2;
                    continue;
                }
                else {
                    ans += '7';
                    i += 4;
                    continue;
                }
            }
            else if (s[i] == 'e') {
                ans += '8';
                i += 4;
                continue;
            }
            else if (s[i] == 'n') {
                ans += '9';
                i += 3;
                continue;
            }
        }
        else ans += s[i];
    }
    answer = stoi(ans);
    return answer;
}
int main(void) {
    cout << solution("one4seveneight") << endl;
    cout << solution("23four5six7") << endl;
    cout << solution("2three45sixseven") << endl;
    cout << solution("123") << endl;
}