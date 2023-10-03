#include <iostream>

using namespace std;

static int n;
bool isPrime(int n) {
  for (int i = 2; i * i <= n;
       i++)  // 2부터 n의 제곱근까지 나누어 떨어지는지 검사
    if (n % i == 0) return false;  // 나누어 떨어지면 소수가 아님
  return true;
}
void DFS(int num, int count) {
  if (count == n) {
    if (isPrime(num)) {
      cout << num << "\n";
    }
    return;
  }
  for (int i = 1; i < 10; i++) {
    if (i % 2 == 0) continue;  // 짝수는 소수가 아니므로
    if (isPrime(num * 10 + i))
      DFS(num * 10 + i, count + 1);  // 소수이면 재귀 호출
  }
}

int main() {
  //   int n;
  cin >> n;

  DFS(2, 1);
  DFS(3, 1);
  DFS(5, 1);
  DFS(7, 1);
}