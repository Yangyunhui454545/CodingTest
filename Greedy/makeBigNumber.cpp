#include<iostream>
#include <vector>
#include<algorithm>
#include<string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;
string number;
int k;

/////////////////////////////////////////////////////
/*
시간 초과로 개고생함 시발
substr 대신 erase로 고치고 시간초과 극복
그리고 이차원이 아닌 일차원 for문으로 어떻게든 뜯어고침,,,
*/
/////////////////////////////////////////////////////
string solution(string number, int k) {
    string tmp = number;        
    int minIdx = 0;
    int s = number.length();
    int cnt = 0;
    for (int j = minIdx - 1; j < s - 1; j++) {
        if (j == -1)continue;
        if (cnt == k)break;
        if (number[j]  < number[j + 1]) {
            minIdx = j; 
            tmp = number;
            number.erase(minIdx, 1);
            j-=2;
            s = number.size();
            cnt++;
        }
    }
    if (cnt!=k) {
        return number.erase(number.size()-(k-cnt), k-cnt);
    }

    string answer = "";
    answer = number;
    return answer;
}
int main(void) {
    cin >> number;
    cin >> k;
    const char* c = number.c_str();
    cout << solution(c, k);
}
