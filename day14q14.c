#include <stdio.h>
int main()
{
    int n, i, j, flag = 1;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j && mat[i][j] != 1)
            {
                flag = 0;
                break;
            }
            else if (i != j && mat[i][j] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    if (flag == 1)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");
    return 0;
}
