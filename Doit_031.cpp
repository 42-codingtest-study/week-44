#include <iostream>

using namespace std;

//이차원배열에 수를 담고, 이를 1차원으로 바꾼다음에 정렬을 실제로 한다면, 10^10 크기의 배열이기 때문에 시간초과가 날것임.
// arr[k] = x 에서 x 보다 작거나 같은 수 개수가 k 개 라는 뜻ㅇ.. 모르겠노ㅋㅋ
// x 값을 이진탐색으로 조정하면서 x 보다 작은 수를 k fkd dlfcltlzlsek.
// x 보다 작은 원소 개수는 구구단을 이용해보자.
// 각 단으로 나눠서 나머지의 합을 x 보다 작거나 같은 수의 개수로 판단할 수 있음. 
int n,k;

int main()
{
  cin>>n>>k;
  
  long long l,r, mid;

  l = 1;
  r = k;

  while (l < r)
  {
    mid = (l + r)/2;
    long long cnt = 0;
    long long tmp;

    for (long long layer = 1; layer <= n; layer++)  //구구단 갈기면서 1단부터 n단
    {
      tmp = mid / layer;
      if (tmp > n)
        tmp = n; //하지만 몫이 n보다 클땐 n으로 낮춰준다.
      cnt += tmp;//그 몫들의 합을 더한다.
    }

    if (cnt < k)
      l = mid + 1;
    else 
      r =mid;
  }
  cout<<l;

  return 0;
}