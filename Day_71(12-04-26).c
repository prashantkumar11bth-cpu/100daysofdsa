#include <stdio.h>
#include <string.h>

int main() {
    int m, q;
    scanf("%d", &m);

    int table[m];
    for(int i = 0; i < m; i++)
        table[i] = -1;

    scanf("%d", &q);

    while(q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            int i = 0;
            while(i < m) {
                int index = (key % m + i*i) % m;

                if(table[index] == -1) {
                    table[index] = key;
                    break;
                }
                i++;
            }
        }

        else if(strcmp(op, "SEARCH") == 0) {
            int i = 0;
            int found = 0;

            while(i < m) {
                int index = (key % m + i*i) % m;

                if(table[index] == key) {
                    found = 1;
                    break;
                }

                if(table[index] == -1)
                    break;

                i++;
            }

            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}