#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//dfs 를 진행하되, 타고 들어간 깊이가 5 이상인 경우가 있는지 파악하자.
//종료조건 -> 이미 방문한 노드인가?
//dfs 인자 -> 자기번호, 깊이
int n,m;
int isvisited[2002];
vector<int> arr[2002];
bool checkflag = false;

void dfs(int n, int depth)
{
  if (isvisited[n] == 1)  //dfs 시작하자마자 방문 여부 체크 하는거보다 밑에 for에서 하는게 낫죠?ㅋㅋ
    return;
  
  if (depth == 5)
  {
    checkflag = true;
    return;
  }

  isvisited[n] = 1;
  for (int idx = 0; idx < arr[n].size(); idx++)
  {
    int cur = arr[n][idx];
    dfs(cur, depth+1);
  }
  isvisited[n] = 0;   //헷갈리는 부분. 어떤 경우에는 visited 배열을 dfs 이후에 원래대로 돌려놓고 어떨땐 안함. 명확한 기준이 있노?
}
int main()
{
  cin>>n>>m;
  int a,b;
  for (int i = 0; i < m; i++)
  {
    cin>>a>>b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
  {
    dfs(i, 1); //i번 친구부터 시작하는 친구관계, 깊이는 1부터
    if (checkflag == true)
    {
      cout<<1<<"\n";
      return 0;
    }
  }
  cout<<0<<"\n";
  return 0;
}