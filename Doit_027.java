import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 최소 값을 탐색하는 전형적인 BFS 문제
 *
 * 2차원 배열을 탐색하므로 dx, dy 값이 필요하다.
 */
public class Doit_027 {

    private static int[][] arr;
    private static boolean[][] visited;
    private static int[] dy = {1, 0, -1, 0};
    private static int[] dx = {0, 1, 0, -1};
    private static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        visited = new boolean[N][M];
        arr = new int[N][M];

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            String row = st.nextToken();
            for (int x = 0; x < M; x++) {
                arr[y][x] = Integer.parseInt(row.substring(x, x + 1));
            }
        }

        BFS(0, 0);
        System.out.println(arr[N-1][M-1]);

    }
    private static void BFS(int py, int px) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {py, px});
        visited[py][px] = true;

        while (!queue.isEmpty()) {
            int[] now = queue.poll();
//            visited[now[0]][now[1]] = true;
            for (int k = 0; k < 4; k++) {
                int nextY = now[0] + dy[k];
                int nextX = now[1] + dx[k];
                if (0 <= nextY && 0 <= nextX && nextY < N && nextX < M) {
                    if (!visited[nextY][nextX] && arr[nextY][nextX] != 0) {
                        queue.offer(new int[] {nextY, nextX});
                        visited[nextY][nextX] = true;
                        arr[nextY][nextX] = arr[now[0]][now[1]] + 1;
                    }
                }
            }
        }

    }
}