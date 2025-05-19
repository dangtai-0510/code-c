#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct thisinh{
    int sobadanh;
    int diemthisinh;
    char hovaten[50];
    char quequan[50];
};
typedef struct thisinh ts;
int main(){
    FILE *fi, *fo;
    int dem = 0;
    int n, diemchuan;
    char quequan1[100];
    fi = fopen("input.txt","r");
    if(fi == NULL){
        printf("Khong the mo file input.txt\n");
        return 1;
    }
    fscanf(fi,"%d %d %s",&n, &diemchuan, quequan1);
    ts ds[n];
    ts loc[n];
    for(int i=0;i<n;i++){
        fscanf(fi, "%d %d %s %s",&ds[i].sobadanh, &ds[i].diemthisinh, ds[i].hovaten, ds[i].quequan);
        if(strcmp(ds[i].quequan, quequan1) == 0 && ds[i].diemthisinh >= diemchuan){
            loc[dem++] = ds[i];
        }
    }
    fclose(fi);
    fo = fopen("output.txt", "w");
    if (fo == NULL) {
        printf("Khong the doc file output.txt\n");
        return 1;
    }
    fprintf(fo, "Tinh: %s\n",quequan1);
    fprintf(fo, "Tong so thi sinh trung tuyen: %d\n",dem);    
    for(int i=0;i<dem;i++){
        fprintf(fo, "%d %d %s\n",loc[i].sobadanh, loc[i].diemthisinh, loc[i].hovaten);
    }
    return 0;
}