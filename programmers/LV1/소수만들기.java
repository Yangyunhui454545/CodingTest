import java.util.HashMap;
import java.util.Map;

class Solution {
    Map<Integer, Boolean> map = new HashMap<>();

    public int solution(int[] nums) {
        int answer = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    int sosu = nums[i] + nums[j] + nums[k];
                    if (map.get(sosu) == null) {
                        boolean c = checkSosu(sosu);
                        map.put(sosu, c);
                    }
                    if (map.get(sosu)) answer++;
                }
            }
        }

        return answer;
    }

    public boolean checkSosu(int s) {
        boolean c = true;
        for (int i = 2; i < s / 2; i++) {
            if (s % i == 0) {
                c = false;
                break;
            }
        }
        return c;
    }
}
