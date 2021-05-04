#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int max = 0;
    int maxIdx = 0;
    vector<int> v;
    vector<int> tmp;
    tmp = stones;
    sort(tmp.begin(), tmp.end());
    int kk = tmp[0];
    int bb = tmp[stones.size() - 1];
    if (k == 1) {
        sort(stones.begin(), stones.end());
        return stones[0];
    }
    if (k == stones.size()) {
        sort(stones.begin(), stones.end());
        return stones[stones.size() - 1];
    }
    for (int i = 0; i < stones.size();) {
        if (stones.size() - i < k)break;
        max = 0;
        for (int j = i; j < i + k; j++) {
            if (stones[j] == bb) {
                maxIdx = j;
                max = bb;
                break;
            }
            if (max < stones[j]) {
                max = stones[j];
                maxIdx = j;
            }
        }
        if (kk == max)return kk;
        v.push_back(max);
        i = maxIdx + 1;
    }

    sort(v.begin(), v.end());
    return v[0];
}