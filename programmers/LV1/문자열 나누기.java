import java.util.*;

class Solution {

    public static int solution(String s) {
        int answer = 0;
        int countZero = 1;
        int countDiff = 0;
        char c = s.charAt(0);


        for (int i = 1; i < s.length(); i++) {
            if (c == s.charAt(i)) {
                countZero++;
            } else {
                countDiff++;
            }
            if (countZero == countDiff) {
                countZero = 0;
                answer++;
                if (i == s.length() - 1)
                    break;
               
                c = s.charAt(i + 1);
                i++;
                countZero = 1;
                countDiff = 0;
            }

        }
        if (countZero > 0) answer++;
        return answer;
    }
}
