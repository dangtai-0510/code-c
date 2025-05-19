#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char bxs[100];
    int thu;
    do{
        scanf("%s",bxs);
        thu = 1;
        if(strlen(bxs) != 11){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(!isdigit(bxs[0]) || !isdigit(bxs[1]) || (bxs[0] == '0' && bxs[1] == '0')){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(!isupper(bxs[2]) || !isupper(bxs[3])){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(bxs[4] != '-'){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(!isdigit(bxs[5]) || !isdigit(bxs[6]) || !isdigit(bxs[7])){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(bxs[8] != '.'){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }
        if(!isdigit(bxs[9]) || !isdigit(bxs[10])){
            thu = 0;
            printf("Bien so khong hop le. Vui long nhap lai.\n");
            continue;
        }

        if(thu){
            printf("Bien so hop le: %s\n",bxs);
            break;
        }
    }while(!thu);
    return 0;
}
