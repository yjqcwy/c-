#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r;
    const double pi=3.14159;
    printf("������Բ�뾶r=");
    scanf("%lf",&r);
    printf("\nԲ�ı����Ϊ%lf",4*pi*r*r);
    printf("\nԲ�����Ϊ%lf",4*pi*r*r*r/3);
    return 0;
}
