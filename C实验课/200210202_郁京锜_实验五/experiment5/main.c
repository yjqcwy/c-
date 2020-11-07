/****************************
** 文件名 :experiment5
** 创建人 :郁京锜
** 日 期:2002.10.28
** 描 述:学生成绩管理系统
** 版 本:1.0
** ------------------------
*****************************/


#include <stdio.h>
#include <stdlib.h>
#define N 30

/****************************
** 函数名:Menu
** 输入:choice
** choice---
** 功能描述:输出菜单列表、记下选择数字
** ------------------------
*****************************/
int Menu (void)
{
    int choice=0;

    printf("1. Input record \n2. Calculate total and average score of course \n3. Sort in descending order by score \n4. Sort in ascending order by score \n5. Sort in ascending order by number \n6.Search by number \n7. Statistic analysis \n8. List record \n0.Exit \nPlease enter your choice: \n");
    scanf("%d",&choice);

    /*防止输入出错*/
    while(choice<0||choice>8)
    {
        printf("Wrong,please input a number bewteen 0~8.\nPlease enter your choice:\n");
        scanf("%d",&choice);
    }
    return (choice);
}



/****************************
** 函数名:ReadRecord
** 输入:long num[],int score[]
** ---num[]学号
** ---num2[]备份学号
** ---score[]成绩
** ---score2[]备份成绩
** 输出:i
** i---学生人数
** 功能描述:储存学号成绩并备份一份
** ------------------------
*****************************/
void ReadRecord(int n,long num[],long num2[],int score[],int score2[])
{
    int i;
    for(i=0;i<n;i++)
    {

 Again: printf("Input student's ID and score:");
        scanf("%ld%d",&num[i],&score[i]);
        if (score[i]<0||score[i]>100)
            {
                printf("Wrong,score must bewteen 0~100.Please try again\n");
                goto Again;
            }

        num2[i]=num[i];
        score2[i]=score[i];
    }
}



/***************************
**函数名：Sum_Average
**输入：
**
**功能描述：计算并输出总分和平均分
** ---------------------------
*******************************/
void Sum_Average (int score[],int n)
{
    int i;
    int sum=0;
    float average;
    for(i=0;i<n;i++)
    {
        sum+=score[i];
    }
    printf("sum=%d  ",sum);
    average=sum/n;
    printf("average=%f\n",average);
}



/*****************************
**函数名：Descending_By_Score
**
**
**功能描述：成绩降序并打印
** -----------------------------
********************************/
void Descending_By_Score (int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (score[j]>score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("num = %ld   score = %d\n",num[i],score[i]);
    }
}



/*****************************
**函数名：Ascending_By_Score
**
**
**功能描述：成绩升序并打印
** -----------------------------
********************************/
void Ascending_By_Score (int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (score[j]<score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("num = %ld   score = %d\n",num[i],score[i]);
    }
}



/*****************************
**函数名：Ascending_By_Number
**
**
**功能描述：学号升序并打印
** -----------------------------
********************************/
void Ascending_By_Number (int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (num[j]<num[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("num = %ld   score = %d\n",num[i],score[i]);
    }
}




/*****************************
**函数名：Search_By_Number
**
**
**功能描述：学号查找排名及成绩
** -----------------------------
********************************/
void Search_By_Number (int score[],long num[],int n)
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (score[j]>score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }

    long a;
    int b;
    printf("Please input the number of the student you want to search:");
    scanf("%ld",&a);
    for(b=0;b<n;b++)
    {
        if(a==num[b])
        {
            printf("rank=%d  score = %d\n ",b+1,score[b]);
        }
    }
}



/*****************************
**函数名：Statistic_Analysis
**
**
**功能描述：分析数据
** -----------------------------
********************************/
void Statistic_Analysis (int score[],int n)
{
    int i,a,b,c,d,e;
    a=b=c=d=e=0;
    for (i=0;i<n;i++)
    {
        if (score[i]<=100&&score[i]>=90)
        {
            a++;
        }
        else if (score[i]<90&&score[i]>=80)
        {
            b++;
        }
        else if (score[i]<80&&score[i]>=70)
        {
            c++;
        }else if (score[i]<70&&score[i]>=60)
        {
            d++;
        }else if (score[i]<60&&score[i]>=0)
        {
            e++;
        }
    }
    printf("100-90:%d  ratio:%.2f%%\n",a,(float)100*a/n);
    printf("89-80:%d  ratio:%.2f%%\n",b,(float)100*b/n);
    printf("79-80:%d  ratio:%.2f%%\n",c,(float)100*c/n);
    printf("69-60:%d  ratio:%.2f%%\n",d,(float)100*d/n);
    printf("59-0:%d  ratio:%.2f%%\n",e,(float)100*e/n);

}



int main()
{
    int choice,score[N],score2[N],n,i;
    long num[N],num2[N];

    choice =Menu();

    while (choice!=1)
    {
        if(choice==0)
        {
            exit(0);
        }
        else if(choice<0||choice>8)
        {
            printf("Wrong,please input a number bewteen 0~8.\n");
        }
        else
        {
            printf("Please choose 1 to input student's information first.\n");
        }

        printf("Please choose again:");
        scanf("%d",&choice);
    }

    printf("How many students?(must bewteen 1~30)\n");
    scanf("%d",&n);
    printf("Total students are %d\n",n);
    ReadRecord(n,num,num2,score,score2);

    do
    {
        switch(choice)
        {
            case 1:
                printf("Progress 1 has already done.");
                break;
            case 2:
                Sum_Average(score,n);
                break;
            case 3:
                Descending_By_Score(score,num,n);
                break;
            case 4:
                Ascending_By_Score(score,num,n);
                break;
            case 5:
                Ascending_By_Number(score,num,n);
                break;
            case 6:
                Search_By_Number(score,num,n);
                break;
            case 7:
                Statistic_Analysis(score,n);
                break;
            case 8:
                for(i=0;i<n;i++)
                {
                    printf("num = %ld score = %d\n",num2[i],score2[i]);
                }
                break;
            case 0:
                exit(0);
                break;
        }
        printf("Now choose again:\n");
        scanf("%d",&choice);
        while(choice<0||choice>8)
        {
            printf("Wrong,please input a number bewteen 0~8.\nPlease enter your choice:\n");
            scanf("%d",&choice);
        }
    }
    while(choice>=0&&choice<=8);


    return 0;
}
