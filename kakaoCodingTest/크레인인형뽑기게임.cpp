#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<math.h>
using namespace std;
vector<vector<int>> board;
vector<int> move1;
//0 0 0 0 0
//0 0 1 0 3
//0 2 5 0 1
//0 2 4 4 2
//3 5 1 3 1
//1 5 3 5 1 2 1 4
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    vector<int> temp;
    int tmp = 0;
    for (int i = 0; i < moves.size(); i++) {
        if (board[size - 1][moves[i] - 1] == 0) {
            tmp = -1;
            continue;
        }
        for (int j = 0; j < size; j++) {
            if (board[j][moves[i] - 1] != 0) {
                tmp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (temp.size()>0 && temp.back() == tmp) {
            temp.pop_back();
            answer += 1;
        }
        else{
            temp.push_back(tmp);
        }
    }
    return answer;
}
int main(void) {
    int t = 0;
    for (int i = 0; i < 5; i++) {
        board.push_back({});
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0;j < 5; j++) {
            cin >> t;
            board[i].push_back(t);
        }
    }
    for (int i = 0; i < 8; i++) {
        cin >> t;
        move1.push_back(t);
    }
    solution(board, move1);
}