#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int RANDOM(void)/*����ĺ���*/
{
    int r;
    srand(time(NULL));
    r = rand() % 4 + 1;
    return r;
}

int right_or_wrong(float a,float b)/*�ж���ȵĺ���*/
{
    int r;
    r=RANDOM();

    int temp=(a+0.005)*100;
    a=temp/100;
    temp=(b+0.005)*100;
    b=temp/100;/*�������������������뾫ȷ����λ*/

    if( fabs(a-b)<1E-3 )
    {
        switch(r)
        {
        case 1:
            printf("Very good!\n");
            break;
        case 2:
            printf("Excellent!\n");
            break;
        case 3:
            printf("Nice work!\n");
            break;
        case 4:
            printf("Keep up the good work!\n");
            break;
        }
        return 10;
    }
    else
    {
        switch(r)
        {
        case 1:
            printf("No.Please try next subject!\n");
            break;
        case 2:
            printf("Wrong.Be careful!\n");
            break;
        case 3:
            printf("Don't give up!\n");
            break;
        case 4:
            printf("Not correct.Keep trying.\n");
            break;

        }
        return 0;
    }
}
int Problem (void)/*��һһ����ʽ�ĺ���*/
{
    int a,b,r,score;
    float answer;
    score=0;
    srand(time(NULL));
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    r=RANDOM();
    switch(r)
        {
        case 1:
            printf("%d+%d=",a,b);
            scanf("%f",&answer);
            score+=right_or_wrong(answer,a+b);
            break;
        case 2:
            printf("%d-%d=",a,b);
            scanf("%f",&answer);
            score+=right_or_wrong(answer,a-b);
            break;
        case 3:
            printf("%d*%d=",a,b);
            scanf("%f",&answer);
            score+=right_or_wrong(answer,a*b);
            break;
        case 4:
            printf("%d/%d=",a,b);
            scanf("%f",&answer);
            score+=right_or_wrong(answer,(float)a/b);
            break;
        }
    return (score);
}
int main()
{
    int score,count;
BEGIN:
    score=0;
    count=1;
    while(count<=10)/*�ظ�ʮ�ε�����ʽ����*/
    {
        score+=Problem();
        count++;
    }

    printf("\nYour score is %d\n",score);
    if(score>=75)
    {
        printf("Congratulations!\nYour score>=75\nYou have passed the exam.\n");
    }
    else
    {
        printf("Sorry.You have failed the exam.\nYou score<75\nPlease try again.\n\n\n");
        goto BEGIN;
    }
    /*�жϷ�������������*/



    return 0;
}
