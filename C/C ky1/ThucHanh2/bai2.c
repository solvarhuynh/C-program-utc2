#include <stdio.h>
#include <string.h>
//tao kieu du lieu Menu tu Struct
typedef struct Menu{
    int id;
    char name[50];
    float price;
}Menu;
//ham nhap mon an vao list menu
void inputMenu(Menu dishList[], int n, int m){
    for(int i = 0; i<n; i++){
        if(m == 0){
            printf("\n========= NHAP MON AN THU %d =========\n",i+1);
        }else{
            printf("\n========= NHAP MON AN MOI THU %d =========\n",i+1);
        }
        printf("Nhap id: ");
        scanf("%d",&dishList[i].id);
        getchar();
        printf("Nhap ten mon an: ");
        scanf("%[^\n]",dishList[i].name);
        printf("Nhap gia ban: ");
        scanf("%f",&dishList[i].price);
    }
}
//ham in ra 1 phan tu (1 mon an)
void outputDish(Menu dish){
    printf(" %-6d %-14s %-13.1f VND \n",dish.id,dish.name,dish.price);

}
//ham in ra danh sach mon an trong menu
void printMenu(Menu dishList[], int n){
    printf("-----+--------------+--------------------\n");
    printf(" %-6s %-15s %-13s\n","ID", "NAME", "PRICE");
    printf("-----+--------------+--------------------\n");

    for(int i = 0; i<n; i++){
        outputDish(dishList[i]);
    }
}
//ham them so mon an vao menu
void addDish(Menu dishList[], int n, Menu newList[], int m){
    for(int i = n; i< n+m ;i++){
        dishList[i] = newList[i-n];
    }
    
    printMenu(dishList, n+m);
}
//ham bo 1 mon an tai vi tri nhap tu ban phim
void lessDish(Menu dishList[], int n, int index){
    for(int i = index; i < n ;i++){
        dishList[i-1] = dishList[i];
    }
    
    printMenu(dishList, n-1);
}
//tim kiem cac mon an theo ten gan dung
void searchByName(Menu dishList[],int n, char nameSearch[]){
    Menu listSearched[100];
    //khai bao bien dem de danh dau thu tu mon an duoc tim
    int count=0;
    for(int i = 0; i<n; i++){
        if(strstr(dishList[i].name,nameSearch) == NULL){
            continue;
        }else{
            listSearched[(count++)] = dishList[i];
        }
    }
    if(count == 0)
        printf("Khong co mon an nay!\n");
    else{
        printf("\n========== SEARCH FOR DISH NAME =========\n");
        printMenu(listSearched,count);
    }
}

int main(){
    //khai bao n la so mon an, m la dieu kien in o ham nhap
    int n,m=0;
    //nhap n
    do{
        printf("Nhap so mon an: ");
        scanf("%d",&n);
    }while (n<=0);
    //khai bao danh sach mon an bang kieu du lieu menu
    Menu dishList[100];
    //nhap mon an vao danh sach
    inputMenu(dishList,n,m);
    //in danh sach mon an
    printf("\n=============== MENU LIST ===============\n");
    printMenu(dishList,n);
    //nhap so mon an moi, dong thoi thay doi dieu kien in o ham nhap
    do{
        printf("\nNhap so mon an moi: ");
        scanf("%d",&m);
    }while (m<=0);
    //khai bao danh sanh mon an moi
    Menu newList[m];
    //nhap danh sach
    inputMenu(newList,m,m);
    //in danh sach sau khi da them mon an
    printf("\n========= ADD NEW MENU LIST =========\n");
    addDish(dishList,n,newList,m);
    //khai bao vi tri can xoa mon an
    int index;
    //nhap vi tri
    do{
        printf("\nNhap vi tri can bo: ");
        scanf("%d",&index);
    }while (index > n+m || index <= 0);
    //in danh sach sau khi xoa mon an
    printf("\n======== LESS NEW MENU LIST ========\n");
    lessDish(dishList,n+m,index);

    //khai bao ten mon an
    char nameSearch[20];
    //tim kiem mon an theo ten
    do{
        printf("\nNhap ten mon an (hoac nhan x de thoat): ");
        getchar();
        scanf("%[^\n]s",nameSearch);
        if(strcmp(nameSearch,"x") == 0)
        {
            break;
        }

        searchByName(dishList,n+m-1,nameSearch);        
    }while(1);
}
