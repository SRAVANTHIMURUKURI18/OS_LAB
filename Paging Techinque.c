#include <stdio.h>

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    printf("\nEnter the memory size -- ");
    scanf("%d", &ms);

    printf("\nEnter the page size -- ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("\nThe number of pages available in memory are -- %d\n", nop);

    printf("\nEnter number of processes -- ");
    scanf("%d", &np);

    rempages = nop;

    for (i = 0; i < np; i++) {
        printf("\nEnter no. of pages required for p[%d]-- ", i + 1);
        scanf("%d", &s[i]);

        if (s[i] > rempages) {
            printf("\nMemory is Full");
            break;
        }

        rempages -= s[i];

        printf("\nEnter page table for p[%d] --- ", i + 1);
        for (j = 0; j < s[i]; j++) {
            scanf("%d", &fno[i][j]);
        }
    }

    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter process number (0 to %d), page number, and offset -- ", np - 1);
    scanf("%d %d %d", &x, &y, &offset);

    if (x < 0 || x >= np || y < 0 || y >= s[x] || offset < 0 || offset >= ps) {
        printf("\nInvalid Process, Page Number or Offset\n");
    } else {
        pa = fno[x][y] * ps + offset;
        printf("\nThe Physical Address is -- %d\n", pa);
    }

    return 0;
}
