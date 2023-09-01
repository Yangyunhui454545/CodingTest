import java.util.HashMap;
import java.util.Map;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        
        Map<String, Integer> name = new HashMap<>();
        for(int i=0; i< players.length; i++) {
            name.put(players[i], i);
        }
        for(String s : callings) {
            int rank = name.get(s);
            String tmp = players[rank-1];
            players[rank-1] = s;
            players[rank] = tmp;
            
            name.put(tmp, rank);
            name.put(s, rank-1);
        }
        answer = players;
        return answer;
    }
}
