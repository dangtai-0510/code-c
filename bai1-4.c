#include <stdio.h>
#include <string.h>

// Hàm nhập mảng ký tự (1.1)
int nhapMang(char a[], int *n) {
    printf("Nhap so luong ky tu (toi da 12): ");
    scanf("%d", n);
    if (*n > 12 || *n <= 0) {
        printf("So luong ky tu khong hop le! Nhap lai.\n");
        return 0; 
    }

    printf("Nhap mang ky tu (A-Z): ");
    scanf(" %s", a);
    if (strlen(a) != *n) {
        printf("So ky tu nhap khong dung voi do dai da khai bao! Nhap lai.\n");
        return 0; 
    }

    for (int i = 0; i < *n; i++) {
        if (a[i] < 'A' || a[i] > 'Z') {
            printf("Ky tu khong hop le (phai tu A-Z)! Nhap lai.\n");
            return 0;
        }
    }
    return 1; 
}
// Hàm kiểm tra mảng đối xứng (1.2)
int kiemTraDoiXung(char a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            return 0; 
        }
    }
    return 1; 
}

// Hàm đếm số lần xuất hiện của dãy con (1.3)
int demDayCon(char a[], int n, char b[], int m) {
    int count = 0;
    for (int i = 0; i <= n - m; i++) {
        int match = 1;
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                match = 0;
                break;
            }
        }
        if (match) count++;
    }
    return count;
}

// Chương trình chính (1.4)
int main() {
    char a[13], b[13];
    int n, m;

    
    while (!nhapMang(a, &n)) {
       
    }
    printf("Mang vua nhap: %s\n", a);

    
    if (kiemTraDoiXung(a, n)) {
        printf("Mang doi xung.\n");
    } else {
        printf("Mang khong doi xung.\n");
    }

   
    printf("Nhap do dai day con (toi da %d): ", n);
    scanf("%d", &m);
    printf("Nhap day con (A-Z): ");
    scanf(" %s", b);
    for (int i = 0; i < m; i++) {
        if (b[i] < 'A' || b[i] > 'Z') {
            printf("Day con khong hop le!\n");
            return 0;
        }
    }

    int soLan = demDayCon(a, n, b, m);
    printf("So lan xuat hien cua day con %s trong mang: %d\n", b, soLan);

    return 0;
}