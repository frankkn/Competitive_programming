#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename FuncT>
pair<T, T> binarySearch(T L, T R, FuncT check) {
  if(check(R) == true)  return {R, R+1};
  if(check(L) == false)  return {L-1, L};
  while (L + 1 < R) {
    T Mid = L + (R - L) / 2;
    if (check(Mid)) L = Mid;
    else R = Mid;
  }
  return {L, R};
}

pair<int, int> binary_search(int L, int R, function<bool(int)> check)
{
    if(check(R) == true)    return  {R, R+1};
    if(check(L) == false)    return  {L-1, L};
    while(L+1 < R)
    {
        int M = (L+R)/2;
        if(check(M))    L = M;   
        else    R = M;
    }
    return {L, R};
}

int main()
{
  int arr[] = {2,3,3,4,5,6,8,9,10};
  auto check = [&](int idx) { return arr[idx] < 7; };
  return 0;
}
