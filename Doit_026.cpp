#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

bool visited[1001];
vector<int> graph[1001];  // 각 정점의 인접 리스트
queue<int> q;             // BFS를 위한 큐

// DFS 함수
void dfs(int curr) {
  cout << curr << " ";          // 현재 정점 출력
  visited[curr] = true;         // 현재 정점 방문 처리
  for (int next : graph[curr])  // 인접 정점들을 순회
    if (!visited[next]) dfs(next);  // 방문하지 않은 정점에 대해 DFS 수행
}

// BFS 함수
void bfs(int start) {
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";          // 현재 정점 출력
    for (int next : graph[curr])  // 인접 정점들을 순회
      // 방문하지 않은 정점을 큐에 추가하고 방문 처리
      if (!visited[next]) q.push(next), visited[next] = true;
  }
}

int main() {
  fast;
  int N, M, V, x, y;
  cin >> N >> M >> V;  // 정점 수, 간선 수, 시작 정점 입력
  // 양방향 간선으로 인접 리스트를 구성
  while (M--) cin >> x >> y, graph[x].push_back(y), graph[y].push_back(x);
  // 인접 리스트를 오름차순으로 정렬
  for (int i = 0; i <= N; i++) sort(graph[i].begin(), graph[i].end());
  dfs(V);        // DFS 수행
  cout << "\n";  // DFS 결과와 BFS 결과를 구분하기 위한 줄바꿈
  memset(visited, false, sizeof(visited));  // 방문 정보 초기화
  q.push(V), visited[V] = true;  // 시작 정점을 큐에 넣고 방문 처리한 뒤
  bfs(V);                        // BFS 수행
}
