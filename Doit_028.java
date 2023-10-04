import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * 트리의 최장 지름 아이디어를 아는지 확인하는 문제
 *
 * 그래프 상에서 가장 서로 멀리 떨어진 노드 두개를 구하는 방법
 * 1. 임의의 한 그래프에서 가장 먼 노드를 구한다.
 * 2. 구한 노드에서 가장 먼 노드를 구하면 구해진 두 노드는 서로 가장 멀리 있는 최장 지름이 된다.
 *
 * DFS 를 통해 Depth 탐색을 구하면서 가장 긴 depth를 가진 노드를 찾아가며 탐색한다.
 */
public class Doit_028 {

    public static class Node {
        int end;
        int distance;

        public Node(int end, int distance) {
            this.end = end;
            this.distance = distance;
        }
    }

    private static ArrayList<Node>[] arr;
    private static boolean[] visited;
    private static int nodeNumber;
    private static int nodeMaxDistance;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        arr = new ArrayList[N + 1];
        for (int idx = 1; idx < N + 1; idx++) {
            arr[idx] = new ArrayList<>();
        }

        for (int idx = 1; idx < N + 1; idx++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            while (true) {
                int end = Integer.parseInt(st.nextToken());
                if (end == -1)
                    break;
                int distance =Integer.parseInt(st.nextToken());

                arr[start].add(new Node(end, distance));
            }
        }

        visited = new boolean[N + 1];
        DFS(1, 0);

        visited = new boolean[N + 1];
        DFS(nodeNumber, 0);
        System.out.println(nodeMaxDistance);
    }

    private static void DFS(int start, int length) {
        if (length > nodeMaxDistance) {
            nodeMaxDistance = length;
            nodeNumber = start;
        }
        visited[start] = true;

        for (Node node : arr[start]) {
            if (!visited[node.end]) {
                DFS(node.end, length + node.distance);
                visited[node.end] = true;
            }
        }
    }
}