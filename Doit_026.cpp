#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static vector<bool> visited;
static bool check;
static vector<vector<int> > graph;

void DFS(int now) {
  // 종료조건
  if (visited[now] == true) return;
  cout << now << " ";
  visited[now] = true;

  for (int i : graph[now]) {
    if (!visited[i]) DFS(i);
  }
}

void BFS(int now) {
  queue<int> q;
  q.push(now);
  visited[now] = true;

  while (!q.empty()) {
    int now_node = q.front();
    q.pop();
    cout << now_node << " ";
    for (int i : graph[now_node]) {
      if (!visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}
int main() {
  int n, m, v;
  cin >> n >> m >> v;

  check = false;
  graph.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    // cout << "here";
    graph[start].push_back(end);
    graph[end].push_back(start);
  }
  for (int i = 1; i <= n; i++) {  // 정점이 여러 개인 경우 정점 번호가 작은
                                  // 것부터 방문하기 위해 정렬
    sort(graph[i].begin(), graph[i].end());  //
  }
  visited = vector<bool>(n + 1, false);
  DFS(v);
  cout << "\n";
  visited = vector<bool>(n + 1, false);
  BFS(v);
}