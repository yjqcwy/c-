#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159

int main()
{
    double r;
    printf("������Բ�뾶r=");
    scanf("%lf",&r);
    printf("\nԲ�ı����Ϊ%lf",4*pi*r*r);
    printf("\nԲ�����Ϊ%lf",4*pi*r*r*r/3);
    return 0;
}
