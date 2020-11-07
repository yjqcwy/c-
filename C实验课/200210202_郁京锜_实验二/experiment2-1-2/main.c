#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r;
    const double pi=3.14159;
    printf("请输入圆半径r=");
    scanf("%lf",&r);
    printf("\n圆的表面积为%lf",4*pi*r*r);
    printf("\n圆的体积为%lf",4*pi*r*r*r/3);
    return 0;
}
