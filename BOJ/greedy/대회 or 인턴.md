import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        // N명 여학생, M명 남학생 여학생2, 남학생1 팀 결성
        // K명은 인턴십 프로그램 참여
        // 인턴십 학생은 대회에 참여 못함
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int K = Integer.parseInt(stringTokenizer.nextToken());

        int possible = N / 2;
        if (possible >= M) {
            possible = M;
        }
        int left = (N - (2 * possible)) + (M - possible);
        if (left < K) {
            if ((K - left) % 3 == 0)
                possible -= (K - left) / 3;
            else
                possible -= ((K - left) / 3) + 1;
        }
        if (possible < 0) possible = 0;
        System.out.println(possible);
    }
}
