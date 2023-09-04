import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        Map<Character, Integer> score = new HashMap<>();
        score.put('R', 0);
        score.put('T', 0);
        score.put('C', 0);
        score.put('F', 0);
        score.put('J', 0);
        score.put('M', 0);
        score.put('A', 0);
        score.put('N', 0);

        int point;
        for (int i = 0; i < survey.length; i++) {
            if (choices[i] < 4) {
                point = score.get(survey[i].charAt(0));
                score.put(survey[i].charAt(0), point + 4 - choices[i]);
            } else if (choices[i] > 4) {
                point = score.get(survey[i].charAt(1));
                score.put(survey[i].charAt(1), point + choices[i] - 4);
            }
        }

        if (score.get('R') >= score.get('T')) {
            answer += "R";
        } else answer += "T";

        if (score.get('C') >= score.get('F')) {
            answer += "C";
        } else answer += "F";

        if (score.get('J') >= score.get('M')) {
            answer += "J";
        } else answer += "M";

        if (score.get('A') >= score.get('N')) {
            answer += "A";
        } else answer += "N";

        return answer;
    }
}
