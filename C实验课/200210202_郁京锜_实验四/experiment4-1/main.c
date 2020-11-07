#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int multiplication(int score)
{
    int r1,r2,answer;

    srand(time(NULL));
    r1 = rand() % 10 + 1;
    r2 = rand() % 10 + 1;/*随机两个1-10的值*/


    printf("%d*%d=?\n",r1,r2);

    int count=1;

    while (count<=3)
    {
        scanf("%d",&answer);

        if(answer==r1*r2)
        {
            printf("Right!\n");
            score=score+10;/*对的话 加十分*/
            break;
        }
        else/*第三次错分两种情况*/
        {   if(count!=3)
            {
                printf("Wrong!Please try again.\n");
                count++;
            }
            else
            {
                printf("Wrong!Test next subject.\n");
                count++;
            }
        }

    }
     return score;
}


int main()
{   int score=0;
    int a=1;
    while(a<=10)/*重复十次*/
    {
        score=multiplication(score);
        a++;
    }
    printf("\n\n\nscore=%d\n",score);
    printf("correct rate =%d%%\n",score);

    return 0;
}
