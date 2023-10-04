import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 0부터 최대 99999999 까지의 소수판별을 거쳐야 한다.
 * 당연히 2억 연산을 훨씬 뛰어 넘는다.
 *
 * 주어진 배열을 탐색하는 것만이 탐색이 아니다.
 * 자릿 수가 정해졌으므로 자릿 수를 하나씩 추가해가며 정답을 만들어야 한다.
 * dfs 를 통해 소수 인지 판별하면서 자릿 수 만큼 depth 를 내리면 된다.
 */
public class Doit_024 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        /**
         * 1의 자리 숫자는 어짜피 소수를 안다.
         * 나머지는 실행할 필요가 없다.
         */
        dfs(2, 1);
        dfs(3, 1);
        dfs(5, 1);
        dfs(7, 1);
    }

    /**
     * 두번째 자리 수부터 소수를 만들어간다.
     */
    static void dfs(int num, int length) {
        if (length == n) {
            if (isPrime(num)) {
                System.out.println(num);
            }
            return ;
        }
        /**
         * 5 또는 짝수는 어짜피 소수가 아니다. continue
         */
        for (int idx = 1; idx <= 9; idx++) {
            if (idx == 5) {
                continue;
            }
            if (idx % 2 == 0) {
                continue;
            }
            int nextNum = num * 10 + idx;
            if (isPrime(nextNum)) {
                dfs(nextNum, length + 1);
            }
        }
    }

    static boolean isPrime(int num) {
        for (int idx = 2; idx <= num / 2; idx++) {
            if (num % idx == 0) {
                return  false;
            }
        }
        return true;
    }

}
