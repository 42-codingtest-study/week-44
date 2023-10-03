// 1167번 트리의 지름
// 이것두모르겠음,,,,,,,,,,

// 임의의 한 점에서 가장 먼 점을 찾고
// 그 점에서 가장 먼 점을 찾으면 그 거리가 트리의 지름이다.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static vector<bool> visited;
static vector<vector<pair<int, int> > > graph;
static vector<int> max_dist;

void BFS(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i].first;
      int dist = graph[cur][i].second;

      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
        max_dist[next] = max_dist[cur] + dist;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  graph.resize(n + 1);

  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    while (1) {
      int e, v;
      cin >> e;
      if (e == -1) break;
      cin >> v;
      graph[s].push_back(make_pair(e, v));
    }
  }
  max_dist = vector<int>(n + 1, 0);
  visited = vector<bool>(n + 1, false);
  BFS(1);  // 임의의 한 점에서 가장 먼 점 찾기
  int max_idx = 1;

  for (int i = 2; i <= n; i++) {  // 1에서 가장 먼 점 찾기
    if (max_dist[max_idx] < max_dist[i]) max_idx = i;
  }
  fill(visited.begin(), visited.end(), false);  // visited 초기화
  fill(max_dist.begin(), max_dist.end(), 0);    // max_dist 초기화
  BFS(max_idx);
  sort(max_dist.begin(), max_dist.end());
  cout << max_dist[n];
  return 0;
}
