#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double a,b,c,S,p;
    printf("��������������a,b,c��Ϊ�����εı߳�,ÿ���������밴�س�\n");
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a+b > c && a+c > b && b+c > a)/*�ж��Ƿ�����������*/
    {
        printf("�����������\n��Ϊ");

        if((a==b)||(b==c)||(c==a))
        {
            if((a==b)&&(b==c))
            {
                printf("�ȱ�");
            }
            else
            {
                printf("����");
            }
        }

        if ((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
        {
            printf("ֱ��");
        }
        if((a!=b)&&(b!=c)&&(c!=a)&&(a*a+b*b!=c*c)&&(a*a+c*c!=b*b)&&(b*b+c*c!=a*a))
        {
            printf("һ��");
        }
        printf("������\n");

        p=(a+b+c)/2;
        S=sqrt(p*(p-a)*(p-b)*(p-c));/*���㲢������*/
        printf("�Ҹ������ε����Ϊ%f",S);
    }
    else
    {
        printf("�������������\n");
    }
    return 0;
}
