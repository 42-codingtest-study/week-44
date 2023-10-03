// 2178 미로 탐색하기
// 이런문제검색없이못풀겠다,,,,,,
#include <iostream>
#include <queue>

using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int n, m;
static bool visited[101][101];  // 100x100 크기의 배열로 visited 정의
static int graph[101][101];     // 100x100 크기의 배열로 graph 정의

void BFS(int i, int j) {
  queue<pair<int, int> > q;
  q.push(make_pair(i, j));

  while (!q.empty()) {
    int now_i = q.front().first;
    int now_j = q.front().second;
    q.pop();
    visited[now_i][now_j] = true;

    for (int k = 0; k < 4; k++) {
      int x = now_i + dx[k];
      int y = now_j + dy[k];

      if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] &&
          graph[x][y] !=
              0)  // 범위를 벗어나지 않고, 방문하지 않았으며, 0이 아닌 경우
      {
        visited[x][y] = true;
        graph[x][y] = graph[now_i][now_j] + 1;
        q.push(make_pair(x, y));
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      graph[i][j] = s[j] - '0';
    }
  }

  //   visited 배열 초기화
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }

  BFS(0, 0);
  cout << graph[n - 1][m - 1] << "\n";
}
