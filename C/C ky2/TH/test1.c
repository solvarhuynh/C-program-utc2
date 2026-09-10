#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    FILE *f;
    f = fopen("D:/ML/C/C K2/TH/test1.txt", "r");
    if(f == NULL){
        printf("Cannot open file !\n");
    }
    else{
        int n;
        fscanf(f, "%d", &n);
        //xử lý kí tự enter
        fgetc(f);
        char s[1000];
        fgets(s, 1000, f);
        //Xoa enter
        s[strlen(s) - 1] = '\0';
        printf("Data : %d\n%s", n, s);
        fclose(f);
    }
    return 0;
}