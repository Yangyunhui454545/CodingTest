import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] answer = new int[targets.length];

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < keymap.length; i++) {
            for (int j = 0; j < keymap[i].length(); j++) {
                char c = keymap[i].charAt(j);

                if (map.get(c) == null) {
                    map.put(c, j + 1);
                } else {
                    int check = map.get(c);
                    if (check > j + 1) {
                        map.put(c, j + 1);
                    }
                }

            }
        }

        for (int i = 0; i < targets.length; i++) {
            int ans = 0;
            for (int j = 0; j < targets[i].length(); j++) {
                Integer tmp = map.get(targets[i].charAt(j));
                if (tmp == null) {
                    ans = -1;
                    break;
                } else ans += tmp;
            }
            answer[i] = ans;
        }

        return answer;
    }
}
