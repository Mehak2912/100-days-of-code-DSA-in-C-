#include <stdio.h>
int isPossible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages)
            return 0;
        if (currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];
            if (students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }
    return 1;
}
int allocateBooks(int pages[], int n, int m) {
    if (m > n)
        return -1;

    int max = pages[0], sum = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (pages[i] > max)
            max = pages[i];
        sum += pages[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1;  // try smaller value
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return result;
}

int main() {
    int n = 4, m = 2;
    int pages[] = {12, 34, 67, 90};

    int ans = allocateBooks(pages, n, m);
    printf("%d\n", ans);  // Output: 113

    return 0;
}
