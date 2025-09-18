#include<stdio.h>
int main()
{
    int m[2][2], n[2][2], c[2][2];
    int i, j, k;

    printf("First Matrix:\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter [%d][%d] element: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Second Matrix:\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter [%d][%d] element: ", i, j);
            scanf("%d", &n[i][j]);
        }
    }
    printf("a = \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("b = \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", n[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            c[i][j] = 0;
        }
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<2; k++)
            {
                c[i][j] += m[i][k] * n[k][j];
            }
        }
    }
    printf("c = \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

