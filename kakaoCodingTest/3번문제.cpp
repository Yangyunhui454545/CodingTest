#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
//지금 인덱스 - k, 끝난 인덱스 , 삭제한 인덱스 저장하는 vector
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int last = n - 1, tmp=0;
    int arr[1000001] = { 0 };
    vector<int> deleted;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'D') {
            for (int j = k; j < n; j++) {
                if (arr[j] == 0) {
                    tmp++;
                }
                if (tmp == cmd[i][2]) {
                    k = j;
                    break;
                }
            }
        }
        else if (cmd[i][0] == 'U') {
            for (int j = k; j > 0; j--) {
                if (arr[j] == 0) {
                    tmp++;
                }
                if (tmp == cmd[i][2]) {
                    k = j;
                    break;
                }
            }
        }
        else if (cmd[i][0] == 'C') {
            deleted.push_back(k);
            arr[k] = 1;
            int j = 1 + 1;
            for (j = i + 1; j < n; j++) {
                if (arr[j] == 0) {
                    k = j;
                    break;
                }
            }
            if (j == n) {
                for (j = i - 1; j >= 0; j--) {
                    if (arr[j] == 0) {
                        k = j;
                        break;
                    }
                }
            }
        }
        else if (cmd[i][0] == 'Z') {
            int get = deleted.back();
            arr[get] = 0;
            deleted.pop_back();
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)answer += 'O';
        else 'X';
    }
    return answer;
}

int main(void) {
    cout<< solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" })<<endl;
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" }) << endl;

}
