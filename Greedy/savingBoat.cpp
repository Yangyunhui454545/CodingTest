#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int limit, tmp;
vector<int> people;
int visit[50001], maxi, maxIdx;

/*
내가 짠 풀이 이중 포문으로 돼있어서 시간초과 문제를 해결할 수가 없었음,,,,
시발

int solution(vector<int> people, int limit) {
    int answer = 0;
    int l = 0;
   for(int i=0; i<people.size(); i++){
`       if(visit[i] ==1) continue;
        l = limit - people[i];
        visit[i] = 1;
        for(int j = 0; j < people.size(); j++){
            if(visit[j]==1)continue;
            if(l>=visit[j]){
                if(maxi < people[j]){
                    maxi = people[j];
                    maxIdx = j;
                }
            }
        }
        visit[maxIdx] = 1;
        answer++;
   }
    return answer;
}

*/
//sort 한다음에 앞뒤로 빼주면서 검사하는게 제일 빨랐음,,, 다른 사람 풀이 참고,,,,
int solution(vector<int> people, int limit) {
    int answer = 0;
    int l = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1;
    while (left <= right) {
        if (people[right] + people[left] <= limit) {    
            left++;
        }
        answer++;
        right--;
        if (left == right) {
            answer++;
        }
    }
    return answer;
}

int main(void) {


    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        people.push_back(tmp);
    }
    cin >> limit;

    cout << solution(people, limit);
}