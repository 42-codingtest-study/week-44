#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

// 노드와 그 노드까지의 거리 정보를 담을 그래프
vector<pair<int, int> > graph[100001];
// N: 노드의 개수, maxV: 가장 먼 거리의 노드, maxDist: 최대 거리
int N, v, node, dist, maxV = 0, maxDist = 0;
bool visited[100001];  // 노드 방문 여부 체크

// DFS로 트리의 지름 탐색
void dfs(int curr, int d) {
  if (d > maxDist) maxDist = d, maxV = curr;  // 현재까지의 최대 거리 갱신
  visited[curr] = true;
  for (pair<int, int> next : graph[curr])
    // 아직 방문하지 않은 노드에 대해 DFS 수행
    if (!visited[next.first]) dfs(next.first, d + next.second);
}

int main() {
  fast;

  cin >> N;  // 노드의 개수 입력받기
  for (int i = 0; i < N; i++) {
    cin >> v;  // 노드 번호 입력받기
    while (1) {
      cin >> node;            // 연결된 노드 번호 입력받기
      if (node == -1) break;  // -1이면 연결 정보 입력 종료
      cin >> dist;            // 노드 사이의 거리 입력받기
      graph[v].push_back(make_pair(node, dist));  // 그래프에 연결 정보 추가
    }
  }
  dfs(1, 0);  // 첫 번째 DFS: 임의의 노드에서 가장 먼 노드 찾기
  memset(visited, false, sizeof(visited));  // 방문 정보 초기화
  dfs(maxV, 0);  // 두 번째 DFS: 가장 먼 노드에서의 최대 거리 찾기 (트리의 지름)
  cout << maxDist;  // 트리의 지름 출력
}
