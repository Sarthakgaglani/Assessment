#include<stdio.h>
int main()
{
	//Declaration of 2*2 matrix
    int m[2][2], n[2][2], c[2][2];
    int i, j, k; // loop variables
	
	//First Matrix
    printf("-------First Matrix-------\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter [%d][%d] element: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    printf("\n\n");
    
	//Second Matrix

    printf("-------Second Matrix-------\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter [%d][%d] element: ", i, j);
            scanf("%d", &n[i][j]);
        }
    }
    printf("\n\n");
    
    //Output of first matrix
    printf("-------a-------\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    //Output of second matrix
    printf("-------b-------\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d\t", n[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    //Declartion of resultant matrix
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            c[i][j] = 0;
        }
    }
    
    //Matrix multiplication logic c[i][j] += m[i][k] * n[k][j]
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
    printf("\n\n");
    
    //Output matrix
    printf("-------Result matrix-------\n");
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

