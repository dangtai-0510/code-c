#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int maSo;
    char hoTen[51];
    int tuoi;
    char cauLacBo[51];
    int soNamSinhHoat;
} SinhVien;

void swap(SinhVien *a, SinhVien *b) {
    SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    
    int n;
    char tenCLB[51];
    fscanf(in, "%d", &n);
    fscanf(in, "%s", tenCLB);
    
    SinhVien ds[1000];
    int i, j;
    for (i = 0; i < n; i++) {
        fscanf(in, "%d %s %d %s %d", 
               &ds[i].maSo, ds[i].hoTen, &ds[i].tuoi, ds[i].cauLacBo, &ds[i].soNamSinhHoat);
    }

    SinhVien loc[1000];
    int dem = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].cauLacBo, tenCLB) == 0) {
            loc[dem++] = ds[i];
        }
    }

    for (i = 0; i < dem - 1; i++) {
        for (j = i + 1; j < dem; j++) {
            if (loc[i].soNamSinhHoat < loc[j].soNamSinhHoat ||
                (loc[i].soNamSinhHoat == loc[j].soNamSinhHoat && loc[i].maSo > loc[j].maSo)) {
                swap(&loc[i], &loc[j]);
            }
        }
    }

    fprintf(out, "Cau lac bo: %s\n", tenCLB);
    fprintf(out, "So sinh vien: %d\n", dem);
    for (i = 0; i < dem; i++) {
        fprintf(out, "%d %s %d %d\n", 
                loc[i].maSo, loc[i].hoTen, loc[i].tuoi, loc[i].soNamSinhHoat);
    }

    fclose(in);
    fclose(out);
    return 0;
}
