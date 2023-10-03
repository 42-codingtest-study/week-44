#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > vec;
vector<bool> visited;

void DFS(int node) {
  if (visited[node]) return;
  visited[node] = true;
  for (int i : vec[node]) {
    if (visited[i] == false) DFS(i);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vec.resize(n + 1);
  visited = vector<bool>(n + 1, false);

  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    vec[start].push_back(end);
    vec[end].push_back(start);
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count++;
      DFS(i);
    }
  }
  cout << count << "\n";
}
