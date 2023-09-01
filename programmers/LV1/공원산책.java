class Solution {
    // E 동쪽 , N 북쪽, S 남쪽, W 서족
    // S에서 시작
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];
        int y = 0;
        int x = 0;
        
        int w = park[0].length();
        int h = park.length;
        
        int[][] parking = new int[w][h];
        
        for(int i=0; i<h; i++) {
            String s = park[i];
            for(int j=0; j<w; j++) {
                char c = s.charAt(j);
                if(c == 'S'){ //시작점 확인
                    y = i;
                    x = j;
                } else if(c == 'X') {
                    parking[i][j] = -1; //장애물 위치 체크
                }
            }
        }
        for(int i=0; i<routes.length; i++) {
            char direct = routes[i].charAt(0);
            int move = Integer.parseInt(String.valueOf(routes[i].charAt(2)));
            
            int yy = y;
            int xx = x;
            
            for(int j=1; j<=move; j++) {
                if(yy==-1 &&xx==-1) break;
                switch (direct) {
                    case 'E' : 
                        xx++;
                        break;
                    case 'S' : 
                        yy++;
                        break;
                    case 'W' :
                        xx--;
                        break;
                    case 'N' : 
                        yy--;
                        break;
                    default:
                        break;
                }
                if(xx < 0 || xx > w-1 || yy < 0 || yy > h-1 || parking[yy][xx] == -1) {
                            xx=-1;
                            yy=-1;
                        }
            }
            if(yy!=-1 &&xx!=-1) {
                y = yy;
                x = xx;
            }
        }
        answer[0] = y;
        answer[1] = x;
        return answer;
    }
}
