#include <stdio.h>
#include <stdlib.h>
void queen(int,int,int,int[10][10]);
int check(int,int,int,int[10][10]);
int lp=1;
int main()
{
    int n,nm[10][10]={0};
    printf("Enter board\n");
    scanf("%d",&n);
    queen(n,0,0,nm);
    return 0;
}
void queen(int n,int ro,int co,int mat[10][10])
{
    int i,j;
     if(co==n)
    {
        return ;
    }


    if(check(n,ro,co,mat))
    {


        mat[ro][co]=1;
  /*      for(j=0;j<=ro;j++)
        {
        for(i=0;i<n;i++)
        {
          printf("%d ",mat[j][i]);
        }
        printf("\n");
        }*/

                if(n-1==ro)
    {
        printf("%d\n",lp++);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf(" %d ",mat[i][j]);
            printf("\n");
        }
        printf("\n");
    }
//printf("\n");

        queen(n,ro+1,0,mat);
        mat[ro][co]=0;
    }

    queen(n,ro,co+1,mat);
}
int check(int n,int row,int column,int a[10][10])
{
    int i,j;
if((row==0 && column==0 )|| (row==0 && column!=0 ))
{
    return 1;

}
else
{

    for(i=0;i<row;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            break;
        }
        if(j==column)
            return 0;
        else if(i-j==row-column)
            return 0;
        else if(i+j==row+column)
            return 0;

    }
    return 1;
}

}
