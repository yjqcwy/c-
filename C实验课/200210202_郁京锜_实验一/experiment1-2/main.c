#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number 200210202\nSubject 1 Programe 1-2\n");
    printf("please input one letter\n");
    char ch;/*����������ַ�����*/
    ch=getchar();
    ch=ch-32;/*���ַ�ת���ɴ�д*/
    putchar('\n');

    int a=1;/*a��������*/
    int b=1;/*b��������*/

    while(b<=8)
    {
        while(a<=16)
        {
            if((a+b)%2==0)/*������������Ϊż��*/
            {
            printf("%c",ch);/*������ַ�*/
            }
            else/*��Ϊ����*/
            {
            printf(" ");/*������ո�*/
            }
            a++;/*ÿһ��������һ*/
        }
        putchar('\n');
        a=1;/*һ�н���ʱ��������һ*/
        b++;/*ÿһ��������һ*/
    }
  return 0;
}
