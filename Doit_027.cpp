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

// N, M은 미로의 크기, visited는 해당 위치를 방문한 횟수 저장, dx와 dy는 네
// 방향을 나타냄
int N, M, visited[101][101], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string map[101];  // 미로의 정보 저장

// DFS로 미로 탐색
void dfs(int x, int y) {
  // (N, M)에 도달하면 함수 종료
  if (x == N - 1 && y == M - 1) return;
  for (int i = 0; i < 4; ++i) {
    // 현재 위치에서 네 방향으로의 새로운 위치 계산
    int nx = x + dx[i], ny = y + dy[i];
    // 새로운 위치가 미로 내부이며, 방문하지 않았거나 더 짧은 경로가 있는 경우
    if ((nx >= 0 && nx < N && ny >= 0 && ny < M) &&
        ((visited[nx][ny] == 0 && map[nx][ny] == '1') ||
         (map[nx][ny] == '1' && visited[nx][ny] > visited[x][y] + 1)))
      // 방문 횟수 갱신 후, DFS 계속 진행
      visited[nx][ny] = visited[x][y] + 1, dfs(nx, ny);
  }
}

int main() {
  fast;
  cin >> N >> M;                              // 미로의 크기 입력받기
  for (int i = 0; i < N; ++i) cin >> map[i];  // 미로 정보 입력받기
  visited[0][0] = 1, dfs(0, 0);  // 시작점 방문 횟수 초기화, DFS 시작
  cout << visited[N - 1][M - 1];  // (N, M)까지의 최소 이동 횟수 출력
}
