#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number 200210202\nSubject 1 Programe 1-2\n");
    printf("please input one letter\n");
    char ch;/*定义输入的字符变量*/
    ch=getchar();
    ch=ch-32;/*将字符转化成大写*/
    putchar('\n');

    int a=1;/*a代表列数*/
    int b=1;/*b代表行数*/

    while(b<=8)
    {
        while(a<=16)
        {
            if((a+b)%2==0)/*若行数加列数为偶数*/
            {
            printf("%c",ch);/*则输出字符*/
            }
            else/*若为奇数*/
            {
            printf(" ");/*则输出空格*/
            }
            a++;/*每一次列数加一*/
        }
        putchar('\n');
        a=1;/*一行结束时将列数归一*/
        b++;/*每一次行数加一*/
    }
  return 0;
}
