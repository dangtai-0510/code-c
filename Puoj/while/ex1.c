#include <stdio.h>

int main() {
    int M1, M2;
    scanf("%d %d", &M1, &M2);

    int count = 0;
    int result[10000]; // lưu các n thỏa mãn

    for (int n = 1; n <= 10000; ++n) {
        int val = n * n - 100 * n + 1;
        if (val >= M1 && val <= M2) {
            result[count++] = n;
        }
    }

    if (count == 0) {
        printf("vo nghiem\n");
    } else {
        printf("%d\n", count);
        for (int i = 0; i < count; ++i) {
            if (i > 0) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }

    return 0;
}
