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

bool visited[1001];       // 방문한 노드를 표시하기 위한 배열
vector<int> graph[1001];  // 인접 리스트를 사용한 그래프 표현

// DFS 함수 정의
void dfs(int curr) {
  visited[curr] = true;         // 현재 노드를 방문한 것으로 표시
  for (int next : graph[curr])  // 인접 노드들을 순회
    if (!visited[next]) dfs(next);  // 방문하지 않았다면, 재귀적으로 DFS 호출
}

int main() {
  fast;
  int N, M, x, y,
      answer = 0;  // N: 노드 개수, M: 간선 개수, answer: 연결 요소의 개수
  cin >> N >> M;  // N과 M을 입력받음
  for (int i = 0; i < M; i++) {
    cin >> x >> y;  // 간선 정보를 입력받음
    graph[x].push_back(
        y);  // 양방향 그래프이므로 x와 y 양쪽 모두에 간선 정보를 추가
    graph[y].push_back(x);
  }
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {  // 모든 노드를 순회하며, 방문하지 않은 노드가 있다면
      answer++;  // 연결 요소의 개수를 하나 증가시키고
      dfs(i);    // 해당 노드에서 DFS 시작
    }
  }
  cout << answer;  // 연결 요소의 개수 출력
}
