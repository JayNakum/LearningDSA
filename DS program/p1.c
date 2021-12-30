#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10][10],b[10][10],mul[10][10],i,j,k,r,c;
    printf("Enter row:");
    scanf("%d",&r);

    printf("Enter column:");
    scanf("%d",&c);

    printf("Enter 1st matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter 2nd matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    printf("Enter mul matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mul[i][j]=0;
            for(k=0;k<c;k++)
            {
                mul[i][j]=a[i][j]*b[i][j];
            }
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d \t",mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}
