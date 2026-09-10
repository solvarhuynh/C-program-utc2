#include <stdio.h>
int main(){
    int n;
    printf("Nhap so nguyen nho hon 9999 can phat am: ");
    scanf("%d",&n);
    int nghin = n/1000;
    int tram = n/100%10;
    int chuc = n%100/10;
    int don_vi = n%10;
    if(n>=0){
        switch (nghin){
            case 1: printf("Mot nghin ");
            break;
            case 2: printf("Hai nghin ");
            break;
            case 3: printf("Ba nghin ");
            break;
            case 4: printf("Bon nghin ");
            break;
            case 5: printf("Nam nhin ");
            break;
            case 6: printf("Sau nghin ");
            break;
            case 7: printf("Bay nghin ");
            break;
            case 8: printf("Tam nghin ");
            break;
            case 9: printf("Chin nghin ");
        }
        
        switch (tram){
            case 0: if(n>1000 && n%1000!=0){
                printf("khong tram ");
                break;
            }else if (n%1000==0){
                printf("");
                break;
            }break;
            case 1: printf("mot tram ");
            break;
            case 2: printf("hai tram ");
            break;
            case 3: printf("ba tram ");
            break;
            case 4: printf("bon tram ");
            break;
            case 5: printf("nam tram ");
            break;
            case 6: printf("sau tram ");
            break;
            case 7: printf("bay tram ");
            break;
            case 8: printf("tam tram ");
            break;
            case 9: printf("chin tram ");
            break;
        }

        switch (chuc){
            case 0: if(n>100 && n%10!=0){
                printf("linh ");
                break;
            }else if(n%10==0){
                break;
            }break;
            case 1: printf("muoi ");
            break;
            case 2: printf("hai muoi ");
            break;
            case 3: printf("ba muoi ");
            break;
            case 4: printf("bon muoi ");
            break;
            case 5: printf("nam muoi ");
            break;
            case 6: printf("sau muoi ");
            break;
            case 7: printf("bay muoi ");
            break;
            case 8: printf("tam muoi ");
            break;
            case 9: printf("chin muoi ");
            break;
        }
        
        switch (don_vi){
            case 0: if(n==0){
                printf("khong");
                break;
            }else{
                break;
            }
            case 1: if(chuc>11){
                printf("mots");
                break;
            }else{
                printf("mot");
                break;
            }
            case 2: printf("hai");
            break;
            case 3: printf("ba");
            break;
            case 4: printf("bon");
            break;
            case 5: if(chuc > 5){
                printf("lam");
                break;
            }else{
                printf("nam");
                break;
            }
            case 6: printf("sau");
            break;
            case 7: printf("bay");
            break;
            case 8: printf("tam");
            break;
            case 9: printf("chin");
            break;
        }
    }else{
        printf("Vui long nhap so lon hon hoac bang 0");
    }

    return 0;
}