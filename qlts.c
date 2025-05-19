#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct thisinh{
    int sobaodanh;
    int diemthisinh;
    char hovaten[50];
    char quequan[50];
};
typedef struct thisinh ts;
int main(){
    FILE *fi, *fo;
    int dem = 0;
    int n;
    int diemchuan;
    fi = fopen("input.txt", "r");
    if(fi == NULL){
        printf("Khong the mo file input.txt");
        return 1;
    }
    fscanf(fi, "%d %d",&n, &diemchuan);
    ts ds[n];
    ts loc[n];
    for(int i=0;i<n;i++){
        fscanf(fi, "%d %d %s %s",&ds[i].sobaodanh, &ds[i].diemthisinh, ds[i].hovaten, ds[i].quequan);
        if(ds[i].diemthisinh >= diemchuan){
            loc[dem++] = ds[i];
        }
    }
    fclose(fi);
    fo = fopen("output.txt", "w");
    if (fo == NULL) {
        printf("Khong the doc file output.txt\n");
        return 1;
    } 
    fprintf(fo, "Tong so thi sinh trung tuyen: %d\n",dem);
    for(int i=0;i<dem;i++){
        
        fprintf(fo, "%d %d %s %s\n", loc[i].sobaodanh, loc[i].diemthisinh, loc[i].hovaten, loc[i].quequan);
        
    }   
    fclose(fo);
    return 0;

}