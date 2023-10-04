#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

#define MAX 100000001
// 한 자리 수의 경우, 소수로 가능한 뒷 자리 수들
int nextValues[4] = {1, 3, 7, 9};

// 주어진 숫자가 소수인지 확인하는 함수
bool isPrime(int num) {
  for (int i = 2; i * i <= num; i++)
    if (num % i == 0) return false;  // i로 나누어 떨어지면 소수가 아님
  return true;                       // 소수임
}

// DFS를 사용하여 주어진 깊이까지 소수를 생성하고 출력하는 함수
void dfs(pair<int, int> curr, int depth) {
  if (curr.second == depth) {    // 현재 깊이가 목표 깊이와 같다면
    cout << curr.first << "\n";  // 현재 값 출력
    return;
  }
  for (int next : nextValues) {  // 가능한 뒷 자리 수들에 대하여
    int nextValue = curr.first * 10 + next;  // 다음 값을 계산하고
    // 그 값이 소수라면 DFS 계속 진행
    if (isPrime(nextValue)) dfs(make_pair(nextValue, curr.second + 1), depth);
  }
}

int main() {
  fast;
  int N, starts[4] = {2, 3, 5, 7};
  cin >> N;
  // 각 시작 숫자에서 DFS 시작
  for (int next : starts) dfs(make_pair(next, 1), N);
}
