#include <stdio.h>
#define MAX 1000
int longestZeroSumSubarray(int arr[], int n) {
    int prefix_sum[MAX] = {0};
    int index[MAX];       
    int size = 0;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            max_len = i + 1;
        }
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefix_sum[j] == sum) {
                int length = i - index[j];
                if (length > max_len)
                    max_len = length;
                found = 1;
                break;
            }
        }
        if (!found) {
            prefix_sum[size] = sum;
            index[size] = i;
            size++;
        }
    }
    return max_len;
}
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", longestZeroSumSubarray(arr, n));
    return 0;
}
