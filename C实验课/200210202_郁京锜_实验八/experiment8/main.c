/****************************
** 文件名 :experiment8
** 创建人 :郁京锜
** 日 期:2002.11.06
** 描 述:学生成绩管理系统
** 版 本:4.0
** ------------------------
*****************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define MAX_LEN 10
#define COURSE 6


typedef struct astudent
{
    char name[MAX_LEN];
    long num;
    int score[COURSE];
    int sum;
    float average;
}STUDENT;

/****************************
** 函数名:Swap
** 功能描述:交换结构体
** ------------------------
*****************************/
void Swap(STUDENT *a,STUDENT *b)
{
    STUDENT temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

/****************************
** 函数名:Menu
** 输入:choice
** choice---
** 功能描述:输出菜单+-列表、记下选择数字
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
**
** 功能描述:储存姓名学号成绩,计算总分和平均分,复制一份
** ------------------------
*****************************/
void ReadRecord(int n,int course,STUDENT stu[],STUDENT stu2[])
{
    int i,j;
    printf("Please enter the student's name,number and scores as Amy 200210101 90 65 83:)\n");
    for(i=0;i<n;i++)
    {
 Again:
        scanf("%s %ld",stu[i].name,&stu[i].num);
        strcpy(stu2[i].name,stu[i].name);

        for (j=0;j<course;j++)
        {
            scanf("%d",&stu[i].score[j]);
            stu2[i].score[j]=stu[i].score[j];
        }

        for (j=0;j<course;j++)
        {
            if (stu[i].score[j]<0||stu[i].score[j]>100)
            {
                printf("Wrong,score must bewteen 0~100.Please try again\n");
                goto Again;
            }
        }

    }

    for(i=0;i<n;i++)
    {
        stu[i].sum=0;
        for(j=0;j<course;j++)
        {
            stu[i].sum+=stu[i].score[j];
        }
        stu[i].average=(float)stu[i].sum/course;
        stu2[i].sum=stu[i].sum;
        stu2[i].average=stu[i].average;
    }
}



/***************************
**函数名：Sum_Average_Course
**输入：
**
**功能描述：计算并输出课程总分和平均分
** ---------------------------
*******************************/
void Sum_Average_Course (int n,int course,STUDENT stu[])
{
    int i,j,sum;
    float average;
    for(j=0;j<course;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=stu[i].score[j];
        }
        printf("course %d  ",j+1);
        printf("sum: %d ",sum);
        average=(float)sum/n;
        printf("average: %.2f \n",average);

    }
}


/***************************
**函数名：Sum_Average_Student
**输入：
**
**功能描述：输出学生总分和平均分
** ---------------------------
*******************************/
void Sum_Average_Student (int n,int course,STUDENT stu[])
{
    for (int i=0;i<n;i++)
    {
        printf("name: %s sum: %d average: %.2f\n",stu[i].name,stu[i].sum,stu[i].average);
    }
}




/*****************************
**函数名：Descending_By_Score
**
**
**功能描述：成绩降序并打印
** -----------------------------
********************************/
void Descending_By_Score (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (stu[j].sum>stu[k].sum)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }


    for (int i=0;i<n;i++)
    {
        printf("name: %s num: %ld score:",stu[i].name,stu[i].num);
        for(j=0;j<course;j++)
        {
            printf("%d ",stu[i].score[j]);
        }
        printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
    }
}



/*****************************
**函数名：Ascending_By_Score
**
**
**功能描述：成绩升序并打印
** -----------------------------
********************************/
void Ascending_By_Score (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (stu[j].sum<stu[k].sum)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }


    for (int i=0;i<n;i++)
    {
        printf("name: %s num: %ld score:",stu[i].name,stu[i].num);
        for(j=0;j<course;j++)
        {
            printf("%d ",stu[i].score[j]);
        }
        printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
    }
}




/*****************************
**函数名：Ascending_By_Number
**
**
**功能描述：学号升序并打印
** -----------------------------
********************************/
void Ascending_By_Number (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (stu[j].num<stu[k].num)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }


    for (int i=0;i<n;i++)
    {
        printf("name: %s num: %ld score:",stu[i].name,stu[i].num);
        for(j=0;j<course;j++)
        {
            printf("%d ",stu[i].score[j]);
        }
        printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
    }
}



/*****************************
**函数名：SortString
**
**
**功能描述：姓名升序并打印
** -----------------------------
********************************/
void SortString (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (strcmp(stu[j].name,stu[k].name)<0)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }


    for (int i=0;i<n;i++)
    {
        printf("name: %s num: %ld score:",stu[i].name,stu[i].num);
        for(j=0;j<course;j++)
        {
            printf("%d ",stu[i].score[j]);
        }
        printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
    }
}



/*****************************
**函数名：Search_By_Number
**
**
**功能描述：学号查找排名及成绩
** -----------------------------
********************************/
void Search_By_Number (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (stu[j].sum>stu[k].sum)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }

    long temp;
    printf("Please input the number of the student you want to search:");
    scanf("%ld",&temp);
    for(i=0;i<n;i++)
    {
        if(temp==stu[i].num)
        {
            printf("name: %s num: %ld rank: %d score:",stu[i].name,stu[i].num,i+1);
            for(j=0;j<course;j++)
            {
                printf("%d ",stu[i].score[j]);
            }
            printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
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
void Search_By_Name (int n,int course,STUDENT stu[])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if (stu[j].sum>stu[k].sum)
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                Swap(&stu[k],&stu[i]);
            }
        }
    }

    char temp[MAX_LEN];
    printf("Please input the name of the student you want to search:");
    getchar();
    gets(temp);
    for(i=0;i<n;i++)
    {
        if(strcmp(temp,stu[i].name)==0)
        {
            printf("name: %s num: %ld rank: %d score:",stu[i].name,stu[i].num,i+1);
            for(j=0;j<course;j++)
            {
                printf("%d ",stu[i].score[j]);
            }
            printf("sum: %d average: %.2f\n",stu[i].sum,stu[i].average);
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
void Statistic_Analysis (int n,int course,STUDENT stu[])
{
    int m;
    int i,a,b,c,d,e;
    for(m=0;m<course;m++)
    {
        a=b=c=d=e=0;
        for (i=0;i<n;i++)
        {
            if (stu[i].score[m]<=100&&stu[i].score[m]>=90)
            {
                a++;
            }
            else if (stu[i].score[m]<90&&stu[i].score[m]>=80)
            {
                b++;
            }
            else if (stu[i].score[m]<80&&stu[i].score[m]>=70)
            {
                c++;
            }else if (stu[i].score[m]<70&&stu[i].score[m]>=60)
            {
                d++;
            }else if (stu[i].score[m]<60&&stu[i].score[m]>=0)
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


/*****************************
**函数名：Printscore
**
**
**功能描述：打印数据
** -----------------------------
********************************/
void Printscore(int n,int course,STUDENT stu2[])
{
    for(int i=0;i<n;i++)
    {
            printf("name: %s num: %ld rank: %d score:",stu2[i].name,stu2[i].num,i+1);
            for(int j=0;j<course;j++)
            {
                printf("%d ",stu2[i].score[j]);
            }
            printf("sum: %d average: %.2f\n",stu2[i].sum,stu2[i].average);
    }
}


int main()
{
    int choice,n,course;
    STUDENT stu[N];
    STUDENT stu2[N];

    choice = Menu();

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

    ReadRecord(n,course,stu,stu2);

    do
    {
        switch(choice)
        {
            case 1:
                printf("Progress 1 has already done.");
                break;
            case 2:
                Sum_Average_Course(n,course,stu);
                break;
            case 3:
                Sum_Average_Student(n,course,stu);
                break;
            case 4:
                Descending_By_Score(n,course,stu);
                break;
            case 5:
                Ascending_By_Score(n,course,stu);
                break;
            case 6:
                Ascending_By_Number(n,course,stu);
                break;
            case 7:
                SortString(n,course,stu);
                break;
            case 8:
                Search_By_Number(n,course,stu);
                break;
            case 9:
                Search_By_Name(n,course,stu);
                break;
            case 10:
                Statistic_Analysis(n,course,stu);
                break;
            case 11:
                Printscore(n,course,stu2);
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
