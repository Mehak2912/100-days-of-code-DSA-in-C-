#include <stdio.h>
int main() {
    int arr[100], n, k, comparisons = 0, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = 1;
            printf("Element %d found at position %d\n", k, i + 1);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", k);
    }
    printf("Number of comparisons made: %d\n", comparisons);
    return 0;
}
