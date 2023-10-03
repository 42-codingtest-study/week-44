import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 최대 10만개의 숫자가 주어지고 이 숫자는 순서가 바뀌지 않는다.
 *
 * m 개의 블루레이로 숫자들을 담을 수 있는 최적의 크기를 구하는 문제이다.
 *
 * 최적의 숫자를 이분탐색으로 구할 수 있다. 일반적으로 정렬하지만 순서가 바뀌지 않는다는 점에서 이분탐색을 사용할 수 있다.
 *
 * left 를 배열을 가장 작은 단위로 묶을 수 있는 수 (N 묶음할 수 있는 배열의 최대 값)
 * right 를 배열을 한 번에 묶을 수 있는 수 (배열의 총합)
 */
public class Doit_030 {

    private static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];

        int sum = 0;
        int max = 0;
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
            sum += arr[idx];
            max = Math.max(max, arr[idx]);
        }

        int left = max;
        int right = sum;
        int mid;
        int count;
        int tmpSum;
        while (left <= right) {
            mid = (left + right) / 2; // size
            count = 0;
            tmpSum = 0;
            for (int idx = 0; idx < N; idx++) {
                if (tmpSum + arr[idx] > mid) {
                    count++;
                    tmpSum = 0;
                }
                tmpSum += arr[idx];
            }
            if (tmpSum != 0)
                count++;
            if (M >= count) { // 담야아 하는 횟수 > 실제로 담은 횟수 -> 더 작은 그릇으로 여러번 담아야 하므로 sizeDown
                right = mid - 1;
            } else if (M < count) {
                left = mid + 1;
            }
        }
        System.out.println(left);
    }

}