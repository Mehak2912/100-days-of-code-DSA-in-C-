#include <stdio.h>
#include <string.h>
#define MAX 1000
#define NAME_LEN 50
int main() {
    int n;
    scanf("%d", &n);
    char names[MAX][NAME_LEN];   
    int count[MAX] = {0};        
    int size = 0;                
    for (int i = 0; i < n; i++) {
        char vote[NAME_LEN];
        scanf("%s", vote);
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(names[j], vote) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[size], vote);
            count[size] = 1;
            size++;
        }
    }
    int maxVotes = 0;
    char winner[NAME_LEN];
    for (int i = 0; i < size; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }
    printf("%s %d\n", winner, maxVotes);
    return 0;
}
