#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// //우선 2차원 배열 위에서 상하좌우로 움직이니까 dir_x, y 만들어놓고,
// //보통은 최소 값을 구하라고 하면 dfs 보단 bfs 이긴하다.


// --- 이렇게 푸는게 안좋은 방식입니까 --- //
// int table[102][102][2];
// int dir_x[4] = {-1, 0, 1, 0};
// int dir_y[4] = {0, 1, 0, -1};
// int n,m;
// queue< pair<pair<int,int>, int> > q;


// int main()
// {
//   cin>>n>>m;
//   string tmp;
//   for (int i = 0; i < n; i++)
//   {
//     cin>>tmp;
//     for (int j = 0; j < m; j++)
//     {
//       table[i][j][0] = tmp[j] - '0';
//       table[i][j][1] = 0;
//     }
//   }

//   q.push(make_pair(make_pair(0,0), 1));

//   while(!q.empty())
//   {
//     pair<pair<int,int>, int > cur = q.front();
//     q.pop();
    
//     table[cur.first.first][cur.first.second][1] = 1;
//     if (cur.first.first ==  n-1 && cur.first.second == m-1)
//     {
//       cout<<cur.second<<"\n";
//       return 0;
//     }

//     for (int i = 0; i < 4; i++)
//     {
//       int x_dir = dir_x[i]; int y_dir = dir_y[i];
//       if (table[cur.first.first + x_dir][cur.first.second + y_dir][1] == 0 && table[cur.first.first + x_dir][cur.first.second + y_dir][0] == 1)
//       {
//         q.push(make_pair(make_pair(cur.first.first + x_dir,cur.first.second + y_dir ), cur.second + 1));
//       }
//     }

//   }
//   return 0;
// }


int table[102][102];
int visited[102][102];
queue<pair<int,int> >q;
int dirx[4] = {0, -1, 0 , 1};
int diry[4] = {1, 0, -1, 0};

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i = 0; i< n; i++)
  {
    string tmp;
    cin>>tmp;
      for(int j = 0; j < m ; j++)
        table[i][j] = tmp[j] - '0';
  }
  q.push(make_pair(0,0));
  visited[0][0] = 1;
  while(!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    for(int i = 0; i <4; i++)
    {
      int newX = cur.first + dirx[i];
      int newY = cur.second + diry[i];
      if (table[newX][newY] == 0 || visited[newX][newY] >= 1) continue;
      if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
      visited[newX][newY] = visited[cur.first][cur.second] + 1;
      q.push(make_pair(newX, newY));
    }
  }
  cout<<visited[n-1][m-1];
  return 0;
}
