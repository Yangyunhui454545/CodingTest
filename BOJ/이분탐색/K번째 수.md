이번에는 그래도 소수를 구해서 연산해보려는 노력이라도 했음!! <br> 

시간초과코드 <br> 

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    // N X N 인 배열 A
    // 배열의 수 A[i][j] = i X j
    // 일차원 배열 B에 넣으면 B의 크기는 N x N 이 된다.
    // B[k]를 구하기
    static long N;
    static long k;

    static long answer;


    static Map<Long, Long> map = new HashMap<>();
    static List<Long> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        k = Integer.parseInt(bufferedReader.readLine());
        long index = 0;
        for (long i = 1; i < N; i++, index++) {
            list.add(i);
        }
        for (long i = N; i <= N * N; i += N, index++) {
            list.add(i);
        }
        map.put(1L, 1L);
        new Main().binarySearch(index - 1);
        System.out.print(answer);

    }

    public void binarySearch(long index) {
        long s = 0;
        long e = index;

        while (s < e) {
            long m = s + (e - s) / 2;
            long checkNum = list.get((int) m);
            long count = 0;
            for (int i = 1; i <= checkNum; i++) {
                count += sosju(i);
            }
            if (count > k) {
                answer = checkNum;
                e = m;
            } else {
                s = m + 1;
            }
        }
    }

    public long sosju(long m) {
        long sosu = 1;
        if (map.get(m) != null) return map.get(m);
        for (int i = 1; i <= Math.sqrt(m); i++) {
            if (m % i == 0) sosu++;
        }
        map.put(m, sosu);
        return sosu;
    }
}
```

정답코드 <br> 

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    // N X N 인 배열 A
    // 배열의 수 A[i][j] = i X j
    // 일차원 배열 B에 넣으면 B의 크기는 N x N 이 된다.
    // B[k]를 구하기
    static long N;
    static long k;

    static long answer;


    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        k = Integer.parseInt(bufferedReader.readLine());

        new Main().binarySearch();
        System.out.print(answer);
    }

    public void binarySearch() {
        long s = 0;
        long e = k;

        while (s < e) {
            long count = 0;
            long m = s + (e - s) / 2;
            for (int i = 1; i <= N; i++) {
                count += Math.min(m / i, N);
            }
            if (count >= k) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        answer = s;
    }
}
```
