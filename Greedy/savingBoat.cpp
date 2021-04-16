#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int limit, tmp;
vector<int> people;
int visit[50001], maxi, maxIdx;

/*
���� § Ǯ�� ���� �������� ���־ �ð��ʰ� ������ �ذ��� ���� ������,,,,
�ù�

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
//sort �Ѵ����� �յڷ� ���ָ鼭 �˻��ϴ°� ���� ������,,, �ٸ� ��� Ǯ�� ����,,,,
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