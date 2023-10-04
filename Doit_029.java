import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 최대 10만개의 숫자가 주어지고 원하는 숫자가 주어진 숫자에 있는지 확인하는 문제다.
 *
 * 최대 1억 연산내로 진행해야한다.
 *
 * 찾아야하는 숫자는 최대 10만개이다.
 *
 * 그냥 일반적으로 찾는다면 n^2 시간복잡도를 고려해야하고 이는 시간 초과를 발생시킨다.
 * 따라서 이분탐색을 통해 원하는 숫자를 찾는다.
 *
 * 이분탐색은 log n 시간 복잡도를 가진다. 최대 10만번 진행하므로 nlogn 의 시간복잡도로 진행이 가능하다.
 */
public class Doit_029 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr;

        arr = new int[N];
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int idx = 0; idx < M; idx++) {
            int target = Integer.parseInt(st.nextToken());
            boolean flag = false;
            int start = 0;
            int end = arr.length - 1;

            while (start <= end) {
                int midIndex = (start + end) / 2;
                int midValue = arr[midIndex];

                if (target < midValue) {
                    end = midIndex - 1;
                } else if (target > midValue){
                    start = midIndex + 1;

                } else if (target == midValue) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

}