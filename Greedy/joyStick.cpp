#include <string>
#include <vector>

/////////////////////////////////////////////////////
/*
한쪽 방향으로만 탐색할 게 아니라 그떄그때 가장 빠르게 갈 수 있는 방향으로 탐색해야함
실제 체감 난이도는 3이상 
ㄹㅇ 찐 그리디 같음 시발 애들아 테케 
*/
/////////////////////////////////////////////////////

using namespace std;
string name;
bool flag = true;
bool allA(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A')break;
        if (i == name.length() - 1)return true;
    }
    return false;
}

int solution(string name) {
    int answer = 0;
    if (abs(name[0] - 'A') <= 13) answer += abs(name[0] - 'A');
    else answer += ('Z' - name[0]) + 1;
    name[0] = 'A';
    int i = 0;
    while (flag) {
        if (allA(name)) break;
        int j = i + 1;
        i--;
        int cnt = 1;
        while (true) {
            if (i == -1)i = name.size() - 1;
            if (j == name.size())j = 0;
            if (name[j] != 'A') { i = j; break; }
            if (name[i] != 'A') { i = i; break; }
            i--; j++; cnt++;
        }
        answer += cnt;
        if (abs(name[i] - 'A') <= 13) answer += abs(name[i] - 'A');
        else answer += ('Z' - name[i]) + 1;
        name[i] = 'A';

    }
    return answer;
}
