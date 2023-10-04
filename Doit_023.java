import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 방향없는 그래프가 주어진다.
 * -> List 에 add 할 때 양 방향으로 저장한다.
 *
 * 연결 요소의 개수를 구한다.
 * -> DFS 를 통해 탐색하면서 한 번의 순회가 끝날 때 한 개의 연결 요소를 카운팅한다.
 */
public class Doit_023 {

    static List<Integer>[] graph;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int node = Integer.parseInt(st.nextToken());
        int edge = Integer.parseInt(st.nextToken());

        graph = new ArrayList[node + 1];
        visited = new boolean[node + 1];

        for (int idx = 1; idx <= node; idx++) {
            graph[idx] = new ArrayList<>();
        }

        for (int idx = 1; idx <= edge; idx++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            // 방향 없는 그래프 저장
            graph[s].add(e);
            graph[e].add(s);
        }

        int count = 0;
        for (int idx = 1; idx <= node; idx++) {
            // dfs가 한 번 호출될 때마다 연결 요소 개수를 더해줘야 한다.
            if (!visited[idx]) {
                dfs(idx);
                count++;
            }
        }
        System.out.println(count);
    }

    static void dfs(int start) {
        // 종료 조건: 이전에 방문한 적이 있는가?
        if (visited[start]) {
            return ;
        }
        visited[start] = true;
        for (int end : graph[start]) {
            if (!visited[end]) {
                dfs(end);
            }
        }
    }

}
