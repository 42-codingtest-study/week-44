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

bool visited[2001],
    answer;  // 방문한 정점을 표시하기 위한 배열과 정답 표시 변수
vector<int> friends[2001];  // 각 정점의 인접 리스트

// DFS 함수 정의
void dfs(pair<int, int> curr) {
  if (curr.second == 5) {  // 5개의 정점을 방문했다면
    answer = true;         // 정답을 찾았다고 표시하고
    return;                // 종료한다.
  }
  for (int next : friends[curr.first])  // 인접 정점들을 순회
    if (!visited[next])                 // 방문하지 않은 정점이라면
      visited[next] = true, dfs(make_pair(next, curr.second + 1)),
      visited[next] = false;  // 방문하고 재귀적으로 DFS 진행 후, 다시 방문하지
                              // 않은 상태로 돌린다.
}

int main() {
  fast;
  int N, M, a, b;
  cin >> N >> M;  // 정점과 간선의 개수를 입력받는다.
  while (M--)
    cin >> a >> b, friends[a].push_back(b),
        friends[b].push_back(a);  // 양방향 간선으로 인접 리스트를 구성한다.
  for (int i = 0; i < N; i++) {               // 모든 정점에 대해
    memset(visited, false, sizeof(visited));  // 방문 배열을 초기화하고
    visited[i] = true, dfs(make_pair(i, 1));  // DFS를 시작한다.
    if (answer) break;  // 정답을 찾았다면 더 이상 검사하지 않고 종료한다.
  }
  cout << (answer ? "1" : "0");  // 정답을 출력한다.
}
