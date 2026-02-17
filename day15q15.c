#include <stdio.h>
int main()
{
    int m, n, i, j, sum = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int mat[m][n];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int limit = (m < n) ? m : n;
    for (i = 0; i < limit; i++)
    {
        sum += mat[i][i];
    }
    printf("Sum of the primary diagonal elements is %d\n", sum);
    return 0;
}
