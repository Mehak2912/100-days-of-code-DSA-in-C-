#include <stdio.h>
#include <string.h>
#define EMPTY -1
int table[100];
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}
void insert(int key, int m) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
    printf("Hash Table Overflow\n");
}
void search(int key, int m) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[idx] == EMPTY) {
            break;
        }
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);
    init(m);
    char op[10];
    int key;
    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }
    return 0;
}
