#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };//¹Ù·Î ¿·
int direct2[4][2] = { 2, 0, 0, 2, -2, 0, 0, -2 }; //¿·¿·
//¸ÂÀ¸¸é 1, Æ²¸®¸é 0 return
bool flag = true;
bool check(int index, int y, int x, vector<string> place) {
    for (int i = 0; i < 4; i++) {
        int ny = y + direct[i][0];
        int nx = x + direct[i][1];
        int dy = y + direct2[i][0];
        int dx = x + direct2[i][1];
        if (ny > 4 || ny < 0 || nx>4 || nx < 0)continue;
        if (place[ny][nx] == 'P') {
            return false;
        }
        if (dy > 4 || dy < 0 || dx>4 || dx < 0)continue;
        if (place[ny][nx] != 'X' && place[dy][dx] == 'P') {
            return false;
        }
    }

    if (y - 1 >= 0 && x - 1 >= 0) { //¿ÞÀ§
        if (place[y - 1][x - 1] == 'P')
            if (place[y - 1][x] != 'X' || place[y][x - 1] != 'X')return false;
    }
    if (y - 1 >= 0 && x + 1 <= 4) { //¿Þ¿À
        if (place[y - 1][x + 1] == 'P')
            if (place[y - 1][x] != 'X' || place[y][x + 1] != 'X')return false;
    }
    if (y + 1 <= 4 && x - 1 >= 0) {//¿Þ¾Æ·¡
        if (place[y + 1][x - 1] == 'P')
            if (place[y][x - 1] != 'X' || place[y + 1][x] != 'X')return false;
    }
    if (y + 1 <= 4 && x + 1 <= 4) {//¿Þ¿À¸¥
        if (place[y + 1][x + 1] == 'P')
            if (place[y + 1][x] != 'X' || place[y][x + 1] != 'X')return false;
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int size = -1;
    while (size++ < 4) {
        flag = true;
        for (int i = 0; i < 5; i++) {
            if (!flag)break;
            for (int j = 0; j < 5; j++) {
                if (places[size][i][j] == 'P') {
                    flag = check(size, i, j, places[size]);
                    if (!flag) break;
                }
            }
        }
        if (flag)answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
int main(void) {
    solution({
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        });
}