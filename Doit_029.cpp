#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int arr[100002];

//수를 찾는 문제로, 정렬해 놓고 단순 탐색으로 값을 찾거나, 이진탐색을 이용하자.
// 입력하는 게 많은 경우에 시간초과 신경써서 stdio 로 풀기

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  sort(arr, arr+n);

  int m, tmp;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &tmp);

    int start = 0; int end = n-1;
    int mid;
    bool flag = false;
    while(start <= end)
    {
      mid = (start+end)/2;
      if (tmp < arr[mid])
        end = mid-1;
      else if (tmp > arr[mid])
        start = mid + 1;
      else
      {
        flag = true;
        break;
      }
    }
    if (flag == true)
      printf("1\n");
    else printf("0\n");;
  }
  return 0;
}