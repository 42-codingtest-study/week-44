import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * DFS 와 BFS 를 잘 이해하고 있는지 물어보는 문제이다.
 * DFS 이후에 DFS 를 사용할 때 적절하게 공통 변수들을 초기화 해주어야 문제가 안된다.
 */
public class Doit_026 {

    private static boolean[] visited;
    private static ArrayList<Integer>[] arr;
    private static StringBuilder result = new StringBuilder();
    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        arr = new ArrayList[N + 1];
        for (int idx = 1; idx < N + 1; idx++) {
            arr[idx] = new ArrayList<>();
        }

        for (int idx = 0; idx < M; idx++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            arr[start].add(end);
            arr[end].add(start);
        }

        for (int idx = 1; idx < N + 1; idx++) {
            Collections.sort(arr[idx]);
        }

        visited = new boolean[N + 1];
        DFS(S);
        System.out.println(result);
        result.setLength(0);
        visited = new boolean[N + 1];
        BFS(S);
        System.out.println(result);
    }

    private static void DFS(int node) {
        result.append(node).append(" ");
        visited[node] = true;

        for (int nextNode : arr[node]) {
            if (!visited[nextNode]) {
                DFS(nextNode);
            }
        }
    }

    private static void BFS(int node) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(node);
        visited[node] = true;
        while (!queue.isEmpty()) {
            int nowNode = queue.poll();
            result.append(nowNode).append(" ");
            for (int nextNode : arr[nowNode]) {
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    queue.offer(nextNode);
                }
            }
        }
    }
}