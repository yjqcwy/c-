#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    unsigned long long int sum=0;
    unsigned long long int a=1;
    int i=1;
    do
    {
      sum=sum+a;
      a=a*2;
      i++;
    }
    while(i<=64);
    printf("用前项计算后项得sum=%llu\n",sum);


    i=1;
    a=1;
    sum=0;
    while(i<=64)
    {
        a=pow(2,i-1);
        sum=sum+a;
        i++;
    }
    printf("用直接计算累加通项得sum=%llu",sum);
    return 0;
}
