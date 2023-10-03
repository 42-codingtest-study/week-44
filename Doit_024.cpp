#include <iostream>
#include <math.h>

using namespace std;

//ㅈ대는 아이디어로 dfs 로 푸는거였는데 기억이 안남
// 자리수마다 소수를 다 찾는다 -> 8자리일때 O(NloglogN) 라서 빠르다..
// 1, 4, 6, 8, 9 제외
// dfs 함수 호출 인자로 (숫자, 몇자리수) , 종료조건을 자릿수가 n 이 되면 소수임을 만족한 자릿수 찾은거니까 출력하자!

int n;
/* //에라토스테네스 하면 메모리초과가 난다. 그냥 수 하나하나 소수인지 판단하자.
bool eratos[100000001] = { false,};
void eratosFunc()
{
  eratos[1] = true;
  for (int i = 2; i <= 10000; i++)
  {
    if (eratos[i]) continue;
    for (int j = i + i; j <= 100000000; j+=i)
      eratos[j] = true;
  }
}
*/

bool checkPrime(int num)
{
  for (int i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0) return false;
  }
  return true;
}

void dfs(int num, int digits)
{
  if (digits == n)
  {
    if (checkPrime(num) == true) cout<<num <<"\n";
    return;
  }

  for (int i = 0; i <= 9; i++)
  {
    if (i % 2 == 0) continue; // 짝수면 소수 못됨.
    if (checkPrime(num*10 + i) == true)
    {
      dfs(num*10 + i, digits+1);
    }
  }
}

int main()
{
  
  cin>>n;
  
  dfs(2,1);
  dfs(3,1);
  dfs(5,1);
  dfs(7,1);

  return 0;
}