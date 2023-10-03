#include <iostream>
#include <vector>

using namespace std;

// 1. dfs, bfs 중에 뭐 써야할지 고민해요
// 2. 양방향 그래프인지 확인해요
// 3. 구현 할 때 종료조건 뭐로 해야할지 고민하셈

// 1 ~ 1000번 인덱스를 사용하기 때문에 1000크기로 만들면 안돼요.
vector<int> uvs[1002];
bool isvisited[1002] = {
    false,
};
int cnt = 0;

void dfs(int idx)
{
  if (isvisited[idx] == true)
    return;
  // 종료조건 : 이미 방문했던 노드면 더 보지 않고 바로 돌아옵니당
  isvisited[idx] = true;
  // 위 종료조건에 안걸린건, 방문 안했던 노드이기 때문에 여기서 방문표시 해줄게요.
  for (int i = 0; i < uvs[idx].size(); i++)
  {
    int cur = uvs[idx][i]; // 방문 여부 상관없이 일단 재귀
    if (isvisited[cur] == false)
      dfs(cur);
  }
}

int main()
{
  int n, m, u, v;

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    uvs[u].push_back(v);
    uvs[v].push_back(u); // 방향이 없는 그래프
  }

  for (int i = 1; i <= n; i++)
  {
    if (isvisited[i] == false)
    {
      // dfs 호출, 탐색을 시작하는 번호가 i 번부터...
      cnt++;
      dfs(i);
    }
  }
  cout << cnt << "\n";
  return 0;
}