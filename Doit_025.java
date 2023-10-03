import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * dfs 탐색을 하면서 depth 가 5인 경우가 있으면 1을 출력하면 된다.
 */
public class Doit_025 {

    static List<Integer>[] graph;
    static boolean[] visited;
    static int node;
    static int edge;
    static boolean flag;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        node = Integer.parseInt(st.nextToken());
        edge = Integer.parseInt(st.nextToken());

        graph = new ArrayList[node];
        visited = new boolean[node];

        for (int idx = 0; idx < node; idx++) {
            graph[idx] = new ArrayList<>();
        }

        for (int idx = 1; idx <= edge; idx++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            graph[start].add(end);
            graph[end].add(start);
        }


        for (int idx = 0; idx < node; idx++) {
            dfs(idx, 1);
            if (flag)
                break;
        }
        if (flag) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    static void dfs(int start, int depth) {
        if (depth == 5 || flag) {
            flag = true;
            return;
        }
        if (visited[start]) {
            return;
        }
        visited[start] = true;
        for (int next : graph[start]) {
            if (!visited[next]) {
                dfs(next, depth + 1);
            }
        }
        visited[start] = false;
    }

}
