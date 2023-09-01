import java.util.Map;
import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) 
{       int[] answer = new int[photo.length];

        Map<String, Integer> missing = new HashMap<>();
        for(int i=0; i<name.length; i++) {
            missing.put(name[i], yearning[i]);
        }
        for(int i=0; i<photo.length; i++) {
            Integer point = 0;
            for(int j=0; j<photo[i].length; j++) {
                Integer p = missing.get(photo[i][j]);
                if(p!=null) point +=p;
            }
            answer[i] = point;
        }
         return answer;
    }
}
