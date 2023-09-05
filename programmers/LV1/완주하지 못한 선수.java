// 해시는 그만 풀어야 겟다

import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> p = new HashMap<>();
        
        for(String s : participant) {
            Integer i = p.get(s);
            if(i != null) p.put(s, i + 1);
            else p.put(s, 1);
        }
        for(String s : completion) {
            p.put(s, p.get(s) - 1);
        }
        for(String s : participant) {
            if(p.get(s) != 0) {
                answer = s;
                break;
            }
        }
        return answer;
    }
}
