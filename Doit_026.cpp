#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m, v;
vector<int> arr[1002];
int isvisited[1002];
vector<int> result_dfs;
vector<int> result_bfs;

// 이거는 왜 틀리는지 알려줄사람?
// void dfs(int cur, int depth)
// {
//   if (isvisited[cur] == 1)
//     return;
//   if (depth == n)
//     return;
  
//   isvisited[cur] = 1;
//   cout<<cur<< " ";
//   for (int idx = 0; idx < arr[cur].size(); idx++)
//   {
//     int next = arr[cur][idx];
//     dfs(next, depth+1);
//   }
// }

void dfs(int cur)
{
  
  isvisited[cur] = 1;
  result_dfs.push_back(cur);
  
  for (int idx = 0; idx < arr[cur].size(); idx++)
  {
    if (isvisited[arr[cur][idx]] == 0)
    {
      dfs(arr[cur][idx]);
    }
  }
}

void bfs(int cur)
{
  std::queue<int> q;
  q.push(cur);
  isvisited[cur] = 1;
  
  while (!q.empty())
  {
    int next = q.front();
    q.pop();
    cout << next << " ";
    for (int i = 0; i < arr[next].size(); i++)
    {
      if (isvisited[arr[next][i]] == 0)
      {
        isvisited[arr[next][i]] = 1;
        q.push(arr[next][i]);
      }
    }
  }
}
int main()
{
  int a,b;
  cin>>n>>m>>v;
  
  for (int i = 0; i < m; i++)
  {
    cin>>a>>b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++)
    sort(arr[i].begin(), arr[i].end());
  dfs(v);
  for (int i = 0; i < result_dfs.size(); i++)
    cout<<result_dfs[i] << " ";
  cout<<"\n";

  memset(isvisited, 0, sizeof(int)*1002);
  
  bfs(v);
  
}