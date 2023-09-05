import java.util.*;


class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int zeroCnt = 0;
        int correctCnt = 0;

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < 6; i++) {
            if (lottos[i] == 0) {
                zeroCnt++;
            } else map.put(lottos[i], 1);
        }

        for (int i = 0; i < 6; i++) {
            Integer tmp = map.get(win_nums[i]);
            if (tmp != null) correctCnt++;
        }

        // 예상 가능한 경우의 수
        int expect = 6 - zeroCnt - correctCnt;
        
        answer[1] = correctCnt;
        answer[0] = correctCnt + zeroCnt;

        for(int i=0; i<answer.length; i++) {
            if(answer[i]==6) answer[i] = 1;
            else if(answer[i]==5) answer[i]=2;
            else if(answer[i]==4)answer[i]=3;
            else if(answer[i]==3)answer[i]=4;
            else if(answer[i]==2)answer[i]=5;
            else answer[i]=6;
        }
        
        return answer;
    }
}
