#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200210202\n  Subject 1 Program 1-1\n");
    char a;
    int b;
    short int c;
    float d;
    double e;
    /*定义五个变量a~e*/

    printf("input char:a=");
    scanf("%c",&a);
    printf("char a=%c,size of char is %d\n",a,sizeof(char));

    printf("input int:b=");
    scanf("%d",&b);
    printf("int b=%d,size of int is %d\n",b,sizeof(int));

    printf("input short int:c=");
    scanf("%hd",&c);
    printf("short int c=%hd,size of short int is %d\n",c,sizeof(short int));

    printf("input float:d=");
    scanf("%f",&d);
    printf("float d=%f,size of float is %d\n",d,sizeof(float));

    printf("input double:e=");
    scanf("%lf",&e);
    printf("double e=%lf,size of double is %d\n",e,sizeof(double));
    /*逐一输入输出*/
    return 0;
}
