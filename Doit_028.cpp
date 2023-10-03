#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// 트리의 가장 긴 지름을 찾는 문제로, 한점에서 가장 먼 거리의 점을 찾고, 그 점에서 가장 먼 거리를 찾으면 된다.
// 이를 위해 dfs 를 사용했다. -> 최단은 bfs 가 맞는데, 최장거리는 dfs 이용하기하네
int v;
vector<pair<int, int>> trees[100002];
int visited[100002];
int max_dist = -1;
int maxvalue = -1;

void dfs(int i, int dist)
{
  if (visited[i] == 1)
    return;
  if (max_dist < dist)
  {
    max_dist = dist;
    maxvalue = i;
  }

  visited[i] = 1;
  for (int j = 0; j < (int)trees[i].size(); j++)
    dfs(trees[i][j].first, trees[i][j].second + dist);
}

int main()
{
  cin >> v;

  for (int i = 0; i < v; i++)
  {
    int num, n1, n2;
    cin >> num;
    cin >> n1;
    while (n1 != -1) // 입력받는게 제일 어려움. split 구현 해놓은거 하나 외우자
    {
      cin >> n2;
      trees[num].push_back(make_pair(n1, n2));
      trees[n1].push_back(make_pair(num, n2));
      cin >> n1;
    }
  }

  dfs(1, 0);
  memset(visited, 0, sizeof(int) * 100001);
  dfs(maxvalue, 0);
  cout << max_dist << "\n";
  return 0;
}