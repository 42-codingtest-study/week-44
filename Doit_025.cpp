#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int> > vec;
static vector<bool> visited;
static bool check;

void DFS(int num, int depth) {
  if (depth == 5 || check) {
    check = true;  // check 변수를 true로 설정
    return;
  }
  visited[num] = true;
  for (int i : vec[num]) {
    if (!visited[i]) DFS(i, depth + 1);
  }
  visited[num] = false;
}

int main() {
  int n, m;
  cin >> n >> m;
  check = false;
  vec.resize(n + 1);  // vec 크기 조절, 노드 번호 범위를 고려하여 n + 1로 설정
  visited = vector<bool>(n + 1, false);

  for (int i = 0; i < m; i++) {
    int start, end;

    cin >> start >> end;
    vec[start].push_back(end);
    vec[end].push_back(start);
  }

  for (int i = 1; i <= n; i++) {  // 모든 노드에서 DFS를 시작
    DFS(i, 1);
    if (check) break;
  }

  if (check) {
    cout << "1"
         << "\n";
  } else {
    cout << "0"
         << "\n";
  }

  return 0;
}
