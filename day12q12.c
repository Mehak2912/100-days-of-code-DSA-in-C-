#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    if (m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    int matrix[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int isSymmetric = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }
    if (isSymmetric)
    {
        printf("Symmetric Matrix");
    }
    else
    {
        printf("Not a Symmetric Matrix");
    }
    return 0;
}
