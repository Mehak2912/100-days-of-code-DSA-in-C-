#include <stdio.h>
int integerSqrt(int n) {
    int left = 0, right = n, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= n / mid) {
            ans = mid;        // possible answer
            left = mid + 1;   // search right for larger value
        } else {
            right = mid - 1;  // search left
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", integerSqrt(n));
    return 0;
}
