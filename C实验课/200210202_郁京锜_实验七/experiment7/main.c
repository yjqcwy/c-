/****************************
** 文件名 :experiment7
** 创建人 :郁京锜
** 日 期:2002.11.04
** 描 述:学生成绩管理系统
** 版 本:3.0
** ------------------------
*****************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define MAX_LEN 100
#define COURSE 6

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

    printf(     "1.Input record\n"
                "2.Calculate total and average score of every course\n"
                "3.Calculate total and average score of every student\n"
                "4.Sort in descending order by total score of every student\n"
                "5.Sort in ascending order by total score of every student\n"
                "6.Sort in ascending order number\n"
                "7.Sort in dictionary order by name\n"
                "8.Search by number\n"
                "9.Search by name\n"
                "10.Statistic analysis for every course\n"
                "11.List record\n"
                "0. Exit\n"
                "Please enter your choice:");
    scanf("%d",&choice);

    while(choice<0||choice>11)
    {
        printf("Wrong,please input a number bewteen 0~11.\nPlease enter your choice:\n");
        scanf("%d",&choice);
    }
    return (choice);
}



/****************************
** 函数名:ReadRecord
** 输入:int n,long num[],long num2[],int score[][],int score2[][],char name[][MAX_LEN],char name2[][MAX_LEN])
**
** 功能描述:储存姓名学号成绩并备份一份
** ------------------------
*****************************/
void ReadRecord(int n,int course,long num[],long num2[],int score[][COURSE],int score2[][COURSE],char name[][MAX_LEN],char name2[][MAX_LEN])
{
    int i,j;
    printf("Please enter the student's name,number and scores as Amy 200210101 90 65 83:)\n");
    for(i=0;i<n;i++)
    {
 Again:
        scanf("%s %ld",name[i],&num[i]);

        for (j=0;j<course;j++)
        {
            scanf("%d",&score[i][j]);
        }


        for (j=0;j<course;j++)
        {
            if (score[i][j]<0||score[i][j]>100)
            {
                printf("Wrong,score must bewteen 0~100.Please try again\n");
                goto Again;
            }
            score2[i][j]=score[i][j];
        }
        strcpy(name2[i],name[i]);
        num2[i]=num[i];

    }
}



/***************************
**函数名：Sum_Average_Course
**输入：
**
**功能描述：计算并输出课程总分和平均分
** ---------------------------
*******************************/
void Sum_Average_Course (int score[][COURSE],int n,int course)
{
    int i,j;
    int sum=0;
    float average;
    for(j=0;j<course;j++)
    {
        for(i=0;i<n;i++)
        {
            sum+=score[i][j];
        }
        printf("course %d  ",j+1);
        printf("sum: %d ",sum);
        average=(float)sum/n;
        printf("average: %.2f \n",average);
        sum=0;
    }
}


/***************************
**函数名：Sum_Average_Student
**输入：
**
**功能描述：计算并输出学生总分和平均分
** ---------------------------
*******************************/
void Sum_Average_Student (int score[][COURSE],int n,int course,char name[][MAX_LEN])
{
    int i,j;
    int sum=0;
    float average;

    for(i=0;i<n;i++)
    {
        for(j=0;j<course;j++)
        {
            sum+=score[i][j];
        }

        printf("name: %s",name[i]);
        printf(" sum: %d ",sum);
        average=(float)sum/course;
        printf(" average: %.2f\n",average);
        sum=0;
    }
}




/*****************************
**函数名：Descending_By_Score
**
**
**功能描述：成绩降序并打印
** -----------------------------
********************************/
void Descending_By_Score (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,temp1,a;
    long temp2;
    char temp3[MAX_LEN];
    int temp4[COURSE];
    int total_score[n];

    for(i=0;i<n;i++)
    {
        a=0;
        for(j=0;j<course;j++)
        {
            a+=score[i][j];
        }
        total_score[i]=a;
    }

    for(i=j=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (total_score[j]>total_score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            temp1=total_score[k];
            total_score[k]=total_score[i];
            total_score[i]=temp1;

            for(m=0;m<course;m++)
            {
                temp4[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp4[m];
            }

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("name: %s num: %ld score: ",name[i],num[i]);
        for(j=0;j<course;j++)
        {
            printf("%d ",score[i][j]);
        }
        printf("total_score: %d\n",total_score[i]);
    }
}



/*****************************
**函数名：Ascending_By_Score
**
**
**功能描述：成绩升序并打印
** -----------------------------
********************************/
void Ascending_By_Score (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,temp1,a;
    long temp2;
    char temp3[MAX_LEN];
    int temp4[COURSE];
    int total_score[n];

    for(i=0;i<n;i++)
    {
        a=0;
        for(j=0;j<course;j++)
        {
            a+=score[i][j];
        }
        total_score[i]=a;
    }

    for(i=j=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (total_score[j]<total_score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            temp1=total_score[k];
            total_score[k]=total_score[i];
            total_score[i]=temp1;

            for(m=0;m<course;m++)
            {
                temp4[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp4[m];
            }

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("name: %s num: %ld score: ",name[i],num[i]);
        for(j=0;j<course;j++)
        {
            printf("%d ",score[i][j]);
        }
        printf("total_score: %d\n",total_score[i]);
    }
}




/*****************************
**函数名：Ascending_By_Number
**
**
**功能描述：学号升序并打印
** -----------------------------
********************************/
void Ascending_By_Number (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,sum;
    int temp1[COURSE];
    long temp2;
    char temp3[MAX_LEN];
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
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            for(m=0;m<course;m++)
            {
                temp1[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp1[m];
            }

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("num: %ld name: %s score: ",num[i],name[i]);
        sum=0;
        for(j=0;j<course;j++)
        {
            printf("%d ",score[i][j]);
            sum+=score[i][j];
        }
        printf("total score: %d",sum);
        putchar('\n');
    }
}



/*****************************
**函数名：SortString
**
**
**功能描述：姓名升序并打印
** -----------------------------
********************************/
void SortString (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,sum;
    int temp1[COURSE];
    long temp2;
    char temp3[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (strcmp(name[j],name[k]) < 0)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            for(m=0;m<course;m++)
            {
                temp1[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp1[m];
            }

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("name: %s num: %ld score: ",name[i],num[i]);
        sum=0;
        for(j=0;j<course;j++)
        {
            printf("%d ",score[i][j]);
            sum+=score[i][j];
        }
        printf("total score: %d",sum);
        putchar('\n');
    }
}



/*****************************
**函数名：Search_By_Number
**
**
**功能描述：学号查找排名及成绩
** -----------------------------
********************************/
void Search_By_Number (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,temp1;
    long temp2;
    char temp3[MAX_LEN];
    int temp4[COURSE];
    int total_score[n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<course;j++)
        {
            total_score[i]+=score[i][j];
        }
    }

    for(i=j=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (total_score[j]>total_score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            temp1=total_score[k];
            total_score[k]=total_score[i];
            total_score[i]=temp1;

            for(m=0;m<course;m++)
            {
                temp4[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp4[m];
            }

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
            printf("name: %s num: %ld rank: %d score: ",name[b],num[b],b+1);
            for(j=0;j<course;j++)
            {
                printf("%d ",score[b][j]);
            }
        }
    }
}



/*****************************
**函数名：Search_By_Nname
**
**
**功能描述：姓名查找排名及成绩
** -----------------------------
********************************/
void Search_By_Name (int score[][COURSE],long num[],int n,int course,char name[][MAX_LEN])
{
    int i,j,k,m,temp1;
    long temp2;
    char temp3[MAX_LEN];
    int temp4[COURSE];
    int total_score[n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<course;j++)
        {
            total_score[i]+=score[i][j];
        }
    }

    for(i=j=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if (total_score[j]>total_score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            temp1=total_score[k];
            total_score[k]=total_score[i];
            total_score[i]=temp1;

            for(m=0;m<course;m++)
            {
                temp4[m]=score[k][m];
                score[k][m]=score[i][m];
                score[i][m]=temp4[m];
            }

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }

    char a[MAX_LEN];
    int b;
    printf("Please input the name of the student you want to search:");
    getchar();
    gets(a);
    for(b=0;b<n;b++)
    {
        if(strcmp(a,name[b])==0)
        {
            printf("name: %s num: %ld rank: %d score: ",name[b],num[b],b+1);
            for(j=0;j<course;j++)
            {
                printf("%d ",score[b][j]);
            }
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
void Statistic_Analysis (int score[][COURSE],int n,int course)
{
    int m;
    int i,a,b,c,d,e;
    for(m=0;m<course;m++)
    {
        a=b=c=d=e=0;
        for (i=0;i<n;i++)
        {
            if (score[i][m]<=100&&score[i][m]>=90)
            {
                a++;
            }
            else if (score[i][m]<90&&score[i][m]>=80)
            {
                b++;
            }
            else if (score[i][m]<80&&score[i][m]>=70)
            {
                c++;
            }else if (score[i][m]<70&&score[i][m]>=60)
            {
                d++;
            }else if (score[i][m]<60&&score[i][m]>=0)
            {
                e++;
            }
        }
        printf("course %d\n",m+1);
        printf("100-90: %d  ratio: %.2f%%\n",a,(float)100*a/n);
        printf("89-80: %d  ratio: %.2f%%\n",b,(float)100*b/n);
        printf("79-80: %d  ratio: %.2f%%\n",c,(float)100*c/n);
        printf("69-60: %d  ratio: %.2f%%\n",d,(float)100*d/n);
        printf("59-0: %d  ratio: %.2f%%\n",e,(float)100*e/n);
    }
}




int main()
{
    int choice,score[N][COURSE],score2[N][COURSE],n,i,course,sum,j;
    long num[N],num2[N];
    char name[N][MAX_LEN],name2[N][MAX_LEN];


    choice =Menu();

    while (choice!=1)
    {
        if(choice==0)
        {
            exit(0);
        }
        else if(choice<0||choice>11)
        {
            printf("Wrong,please input a number bewteen 0~11.\n");
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
    while(n<1||n>30)
    {
        printf("Wrong,please input a number bewteen 1~30:\n");
        scanf("%d",&n);
    }

    printf("How many courses?(must bewteen 1~6)\n");
    scanf("%d",&course);
    while(course<1||course>6)
    {
        printf("Wrong,please input a number bewteen 1~6:\n");
        scanf("%d",&course);
    }

    getchar();

    printf("Total students are %d\n",n);
    printf("Total courses are %d\n",course);

    ReadRecord(n,course,num,num2,score,score2,name,name2);

    do
    {
        switch(choice)
        {
            case 1:
                printf("Progress 1 has already done.");
                break;
            case 2:
                Sum_Average_Course(score,n,course);
                break;
            case 3:
                Sum_Average_Student(score,n,course,name);
                break;
            case 4:
                Descending_By_Score(score,num,n,course,name);
                break;
            case 5:
                Ascending_By_Score(score,num,n,course,name);
                break;
            case 6:
                Ascending_By_Number(score,num,n,course,name);
                break;
            case 7:
                SortString(score,num,n,course,name);
                break;
            case 8:
                Search_By_Number(score,num,n,course,name);
                break;
            case 9:
                Search_By_Name(score,num,n,course,name);
                break;
            case 10:
                Statistic_Analysis(score,n,course);
                break;
            case 11:
                for(i=0;i<n;i++)
                {
                    printf("name: %s num: %ld score: ",name2[i],num2[i]);
                    sum=0;
                    for(j=0;j<course;j++)
                    {
                        printf("%d ",score2[i][j]);
                        sum+=score2[i][j];
                    }
                    printf("total score: %d ",sum);
                    printf("average: %.2f\n",(float)sum/course);
                }
                break;
            case 0:
                exit(0);
                break;

        }
        printf("\nNow choose again:\n");
        scanf("%d",&choice);
        while(choice<0||choice>11)
        {
            printf("Wrong,please input a number bewteen 0~11.\nPlease enter your choice:\n");
            scanf("%d",&choice);
        }
    }
    while(choice>=0&&choice<=11);


    return 0;
}
