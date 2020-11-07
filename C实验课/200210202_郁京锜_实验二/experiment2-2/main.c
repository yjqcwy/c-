#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double a,b,c,S,p;
    printf("请输入三个正数a,b,c作为三角形的边长,每次输入完请按回车\n");
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a+b > c && a+c > b && b+c > a)/*判断是否满足三角形*/
    {
        printf("能组成三角形\n且为");

        if((a==b)||(b==c)||(c==a))
        {
            if((a==b)&&(b==c))
            {
                printf("等边");
            }
            else
            {
                printf("等腰");
            }
        }

        if ((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
        {
            printf("直角");
        }
        if((a!=b)&&(b!=c)&&(c!=a)&&(a*a+b*b!=c*c)&&(a*a+c*c!=b*b)&&(b*b+c*c!=a*a))
        {
            printf("一般");
        }
        printf("三角形\n");

        p=(a+b+c)/2;
        S=sqrt(p*(p-a)*(p-b)*(p-c));/*计算并输出面积*/
        printf("且该三角形的面积为%f",S);
    }
    else
    {
        printf("不能组成三角形\n");
    }
    return 0;
}
