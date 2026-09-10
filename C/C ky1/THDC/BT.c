#include <stdio.h>
#include <string.h>

typedef struct Account{
    char username[30];
    char password[30];
} Account;

//mang luu tai khoan
Account accounts[100];
//bien so luong tai khoan da dang ky 
int accountCount = 0; 

//kiem tra ten tai khoan
int checkAccount(char username[30]) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}
//ham dang ky tai khoan
void registerAccount(){                                            
    char username[30], password[30];
    do{
	    printf("Nhap ten tai khoan: ");
	    scanf("%s", username);

	    if (checkAccount(username)){
	        printf("Ten tai khoan da ton tai. Vui long thu lai.\n");
	        continue;
	    }

	    printf("Nhap mat khau: ");
	    scanf("%s", password);
	
	    if (strlen(password) < 6){
	        printf("Mat khau phai co it nhat %d ky tu. Vui long thu lai.\n", 6);
	        continue;
	    }
	}
	while(checkAccount(username)||strlen(password) < 6);

    strcpy(accounts[accountCount].username, username);
    strcpy(accounts[accountCount++].password, password);

    printf("Dang ky thanh cong.\n");
}
// ham dang nhap tai khoan
void login() {
    char username[30], password[30];
    int isLoggedIn = 0;

    printf("Nhap ten tai khoan (username): ");
    scanf("%s", username);
    printf("Nhap mat khau (password): ");
    scanf("%s", password);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            isLoggedIn = 1;
            break;
        }
    }

    if (isLoggedIn)
        printf("Dang nhap thanh cong.\n");
    else
        printf("Thong tin dang nhap khong chinh xac. Vui long thu lai.\n");
}

int main() {
    int choice;
    do{
        printf("\n======= Quan Ly Tai Khoan =======\n");
        printf("1. Dang ky\n");
        printf("2. Dang nhap\n");
        printf("3. Thoat\n");
		printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Thoat chuong trinh.\n");
    			break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }while(choice!=3);
} 


