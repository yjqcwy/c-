/****************************
** �ļ��� :experiment6
** ������ :�����
** �� ��:2002.10.30
** �� ��:ѧ���ɼ�����ϵͳ
** �� ��:2.0
** ------------------------
*****************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define MAX_LEN 100


/****************************
** ������:Menu
** ����:choice
** choice---
** ��������:����˵��б�����ѡ������
** ------------------------
*****************************/
int Menu (void)
{
    int choice=0;

    printf("1. Input record \n2. Calculate total and average score of course \n3. Sort in descending order by score \n4. Sort in ascending order by score \n5. Sort in ascending order by number \n6.Sort in dictionary order by name \n7.Search by number \n8.Search by name \n9. Statistic analysis \n10. List record \n11.Exit \nPlease enter your choice: \n");
    scanf("%d",&choice);

    /*��ֹ�������*/
    while(choice<1||choice>11)
    {
        printf("Wrong,please input a number bewteen 1~11.\nPlease enter your choice:\n");
        scanf("%d",&choice);
    }
    return (choice);
}



/****************************
** ������:ReadRecord
** ����:int n,long num[],long num2[],int score[],int score2[],char name[][MAX_LEN],char name2[][MAX_LEN])
**
** ��������:��������ѧ�ųɼ�������һ��
** ------------------------
*****************************/
void ReadRecord(int n,long num[],long num2[],int score[],int score2[],char name[][MAX_LEN],char name2[][MAX_LEN])
{
    int i;
    for(i=0;i<n;i++)
    {

 Again: printf("Input student's name:");
        gets(name[i]);
        printf("Input student's ID and score:");
        scanf("%ld%d",&num[i],&score[i]);
        getchar();
        if (score[i]<0||score[i]>100)
            {
                printf("Wrong,score must bewteen 0~100.Please try again\n");
                goto Again;
            }
        strcpy(name2[i],name[i]);
        num2[i]=num[i];
        score2[i]=score[i];
    }
}



/***************************
**��������Sum_Average
**���룺
**
**�������������㲢����ֺܷ�ƽ����
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
    printf("sum=%d ",sum);
    average=sum/n;
    printf("average=%f",average);
}



/*****************************
**��������Descending_By_Score
**
**
**�����������ɼ����򲢴�ӡ
** -----------------------------
********************************/
void Descending_By_Score (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
    long temp2;
    char temp3[MAX_LEN];
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
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

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
        printf("name ");
        puts(name[i]);
        printf("num = %ld score = %d\n",num[i],score[i]);
    }
}



/*****************************
**��������Ascending_By_Score
**
**
**�����������ɼ����򲢴�ӡ
** -----------------------------
********************************/
void Ascending_By_Score (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
    long temp2;
    char temp3[MAX_LEN];
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
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

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
        printf("name ");
        puts(name[i]);
        printf("num = %ld score = %d\n",num[i],score[i]);
    }
}



/*****************************
**��������Ascending_By_Number
**
**
**����������ѧ�����򲢴�ӡ
** -----------------------------
********************************/
void Ascending_By_Number (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
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
        printf("name ");
        puts(name[i]);
        printf("num = %ld score = %d\n",num[i],score[i]);
    }
}



/*****************************
**��������SortString
**
**
**�����������������򲢴�ӡ
** -----------------------------
********************************/
void SortString (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
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
        printf("name ");
        puts(name[i]);
        printf("num = %ld score = %d\n",num[i],score[i]);
    }
}



/*****************************
**��������Search_By_Number
**
**
**����������ѧ�Ų����������ɼ�
** -----------------------------
********************************/
void Search_By_Number (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
    long temp2;
    char temp3[MAX_LEN];
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
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

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
            printf("name ");
            puts(name[b]);
            printf("rank=%d score = %d\n ",b+1,score[b]);
        }
    }
}



/*****************************
**��������Search_By_Nname
**
**
**�������������������������ɼ�
** -----------------------------
********************************/
void Search_By_Name (int score[],long num[],int n,char name[][MAX_LEN])
{
    int i,j,k,temp1;
    long temp2;
    char temp3[MAX_LEN];
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
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);

            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

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
            printf("name ");
            puts(name[b]);
            printf("rank=%d score = %d\n ",b+1,score[b]);
        }
    }
}



/*****************************
**��������Statistic_Analysis
**
**
**������������������
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
    char name[N][MAX_LEN],name2[N][MAX_LEN];


    choice =Menu();

    while (choice!=1)
    {
        if(choice==11)
        {
            exit(11);
        }
        else if(choice<1||choice>11)
        {
            printf("Wrong,please input a number bewteen 1~11.\n");
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
    getchar();
    ReadRecord(n,num,num2,score,score2,name,name2);

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
                Descending_By_Score(score,num,n,name);
                break;
            case 4:
                Ascending_By_Score(score,num,n,name);
                break;
            case 5:
                Ascending_By_Number(score,num,n,name);
                break;
            case 6:
                SortString(score,num,n,name);
                break;
            case 7:
                Search_By_Number(score,num,n,name);
                break;
            case 8:
                Search_By_Name(score,num,n,name);
                break;
            case 9:
                Statistic_Analysis(score,n);
                break;
            case 10:
                for(i=0;i<n;i++)
                {
                    printf("name ");
                    puts(name[i]);
                    printf("num = %ld score = %d\n",num2[i],score2[i]);
                }
                break;
            case 11:
                exit(0);
                break;
        }
        printf("\nNow choose again:\n");
        scanf("%d",&choice);
        while(choice<1||choice>11)
        {
            printf("Wrong,please input a number bewteen 1~11.\nPlease enter your choice:\n");
            scanf("%d",&choice);
        }
    }
    while(choice>=1&&choice<=11);


    return 0;
}
