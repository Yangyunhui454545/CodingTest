#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31] = { 0 };

    for (int i = 0; i < lost.size(); i++) {
        student[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (student[i] >= 0)answer++;
        if (student[i] == -1) {
            if (student[i - 1] > 0) {
                student[i - 1]--;
                answer++;
            }
            else if (student[i + 1] > 0) {
                student[i + 1]--;
                answer++;
            }
        }
    }
    return answer;
}