#include <iostream>
using namespace std;


int sumit(int num)
{
   int sum = 0;
   for (; num ; --num)
       sum += num;
   return sum;
}

int main()
{
    int n = 10;
    cout << n << endl;
    cout << sumit(n) << endl;
    cout << n << endl;
 return 0;
}
