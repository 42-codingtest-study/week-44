import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 아이디어 1)
 * B[K] = 𝑥 라는 의미는 𝑥 보다 작거나 같은 원소의 개수가 최소 K개
 *
 * 우리가 구해야하는 값은 B[K] 이다.
 * K 는 B[K] 보다 작거나 같은 숫자의 개수이다.
 * K 를 알고 있으므로 이를 이용해 x 를 구할 것이다.
 * B[K] = 𝑥에서 우리가 조정해가면서 탐색해야 하는 것은 𝑥이다.
 *
 * 즉, 𝑥를 통해 𝑥 보다 작은 원소의 개수(=K)를 찾고,
 * 해당 값이 문제에서 주어지는 K값과 일치하는지를 이분탐색으로 구현을 하면 된다.
 *
 */
public class Doit_031 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        int left = 1;
        int right = K;

        while (left < right) {
            int mid = (left + right) / 2;
            long count = 0;

            for (int idx = 1; idx <= N; idx++) {
                count += min(mid / idx, N);
            }
            if (count >= K) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(left);
    }
}