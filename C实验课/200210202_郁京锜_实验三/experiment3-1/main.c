#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m=100;
    int i=2;
    int n;/*用于取整根号m*/
    int count=0;/*统计素数个数*/
    int a[100];/*最多一百个数*/
    int x,y;/*代表行和列*/

    x=0;
    y=1;

    while(m<=200)
    {
        n=sqrt(m);
        while(i<=n)
        {
            if(m%i==0) break;
            i++;
            if(i==n+1)
            {
                a[count]=m;
                count++;/*最后一次循环多加了一*/
            }
        }
        i=2;
        m++;
    }
    count--;/*减一*/


/*正常数字*/
    while(x<=9)
    {
        while(y<=10)
        {
            if((x*10+y-1)<=count)
            {
                printf("%d ",a[x*10+y-1]);
            }

            y++;
        }
        y=1;
        printf("\n");
        x++;
    }
/*反转数字*/
    int t,o,p,q;/*代表原数、十位数、个位数、百位数*/
    x=0;
    y=1;
        while(x<=9)
    {
        while(y<=10)
        {
            if((x*10+y-1)<=count)
            {
                t=a[x*10+y-1];
                q=t/100;
                t=t-100*q;
                p=t/10;
                o=t%10;
                printf("%d ",o*100+p*10+q*1);
            }

            y++;
        }
        y=1;
        printf("\n");
        x++;
    }



    return 0;
}
