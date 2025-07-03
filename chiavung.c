#include <stdio.h>

int main() {
    int x0, y0;
    int R0, R1, R2;
    int m;

    // Tọa độ điểm O
    scanf("%d %d", &x0, &y0);
    // 3 bán kính
    scanf("%d %d %d", &R0, &R1, &R2);
    // Số điểm
    scanf("%d", &m);

    int f0x[m], f0y[m], n0 = 0;
    int f1x[m], f1y[m], n1 = 0;
    int f2x[m], f2y[m], n2 = 0;

    int R0s = R0 * R0;
    int R1s = R1 * R1;
    int R2s = R2 * R2;

    for (int i = 0; i < m; ++i) {
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        int dx = xi - x0;
        int dy = yi - y0;
        int r2 = dx * dx + dy * dy;

        if (r2 < R0s) {
            f0x[n0] = xi;
            f0y[n0] = yi;
            n0++;
        } else if (r2 < R1s) {
            f1x[n1] = xi;
            f1y[n1] = yi;
            n1++;
        } else if (r2 <= R2s) {
            f2x[n2] = xi;
            f2y[n2] = yi;
            n2++;
        }
    }

    printf("F0 %d\n", n0);
    for (int i = 0; i < n0; ++i)
        printf("%d %d\n", f0x[i], f0y[i]);

    printf("F1 %d\n", n1);
    for (int i = 0; i < n1; ++i)
        printf("%d %d\n", f1x[i], f1y[i]);

    printf("F2 %d\n", n2);
    for (int i = 0; i < n2; ++i)
        printf("%d %d\n", f2x[i], f2y[i]);

    return 0;
}
