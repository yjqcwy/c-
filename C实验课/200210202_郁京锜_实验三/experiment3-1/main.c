#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m=100;
    int i=2;
    int n;/*����ȡ������m*/
    int count=0;/*ͳ����������*/
    int a[100];/*���һ�ٸ���*/
    int x,y;/*�����к���*/

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
                count++;/*���һ��ѭ�������һ*/
            }
        }
        i=2;
        m++;
    }
    count--;/*��һ*/


/*��������*/
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
/*��ת����*/
    int t,o,p,q;/*����ԭ����ʮλ������λ������λ��*/
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
