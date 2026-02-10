#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    scanf("%s", s);
    int low = 0;
    int high = strlen(s) - 1;
    while (high > low) {
        if (s[low++] != s[high--]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
