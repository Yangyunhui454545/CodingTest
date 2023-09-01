import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String, Set<String>> repo = new HashMap<>();
        Map<String, Integer> idIndex = new HashMap<>();
        int index = 0;
        for (String s : id_list) {
            repo.put(s, new HashSet<>());
            idIndex.put(s, index++);
        }

        for (int i = 0; i < report.length; i++) {
            String[] s = report[i].split(" ");
            repo.get(s[1]).add(report[i]);
        }

        for (int i = 0; i < id_list.length; i++) {
            Set<String> stringSet = repo.get(id_list[i]);
            if (stringSet.size() >= k) {
                Iterator<String> iterator = stringSet.iterator();
                while (iterator.hasNext()) {
                    String s = iterator.next();
                    String[] arrayString = s.split(" ");
                    answer[idIndex.get(arrayString[0])]++;
                }
            }
        }
        return answer;
    }
}
