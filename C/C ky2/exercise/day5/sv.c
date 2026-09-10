#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct SinhVien{
    long long MSV;
    char* hoTen;
    int NS;
    char* lop;
    float DTB;
    char* diaChi;
}SV;
typedef struct DSSV{
    SV sv;
    struct DSSV *next;
}DS;

DS* infoSV(long long msv, char* hoten, int ns, char* lop, float dtb, char* diachi){
    DS *sv = (DS*)malloc(sizeof(DS));
    sv->sv.MSV = msv;
    sv->sv.hoTen = (char*)malloc(strlen(hoten)+1);
    strcpy(sv->sv.hoTen, hoten);
    sv->sv.NS = ns;
    sv->sv.lop = (char*)malloc(strlen(lop)+1);
    strcpy(sv->sv.lop, lop);
    sv->sv.DTB = dtb;
    sv->sv.diaChi = (char*)malloc(strlen(diachi)+1);
    strcpy(sv->sv.diaChi, diachi);
    sv->next = NULL;
    return sv;
}
DS *them1SV(DS *head, DS *sv){ //ht, tl
    if(head == NULL){
        head = sv;
        return head;       
    }
    DS *tmp = head;
    while(tmp->next!=NULL)
        tmp = tmp->next;
    tmp->next = sv;
    return head;
}
void nhapSV(DS **head, int n){
    long long msv;
    int ns;
    char hoten[20], lop[10], diachi[30];
    float dtb;
    for(int i = 0; i<n; i++){
        printf("\n============= INFORMATION SV %d =============\n",i+1);
        printf("\nNhap MSV: ");
        scanf("%lld",&msv);
        printf("Nhap Nam Sinh: ");
        scanf("%d",&ns);
        printf("Nhap Diem Trung Binh: ");
        scanf("%f", &dtb);
        getchar();
        printf("Nhap Ho Ten: ");
        scanf("%[^\n]%*c",hoten);
        printf("Nhap Lop: ");
        scanf("%[^\n]%*c",lop);
        printf("Nhap Dia Chi: ");
        scanf("%[^\n]%*c",diachi);
        DS *sv = infoSV(msv,hoten,ns,lop,dtb,diachi);
        *head = them1SV(*head,sv);
    }
}
void xuatSV(DS *head){
    printf("\n================================= STUDENT LIST ====================================\n");
    printf("\n STT |     MSV     |        HoTen        |  NS  |    Lop    |        DiaChi       |\n");
    int i = 1;
    while(head != NULL){
        printf("-----------------------------------------------------------------------------------\n");
        printf("  %d  | %-11lld | %-19s | %-4d | %-9s | %-20s\n", i++, head->sv.MSV, head->sv.hoTen, head->sv.NS, head->sv.lop, head->sv.diaChi);
        head = head->next;
    }
}
void sapXep(DS **head, int n){
    if(*head == NULL || (*head)->next == NULL)
        return;
    for(int i = 0; i<n; i++){
        DS *tmp = *head;
        while(tmp->next != NULL){
            if(strcmpi(tmp->sv.hoTen, tmp->next->sv.hoTen)>0){
                SV tmpsv = tmp->sv;
                tmp->sv = tmp->next->sv;
                tmp->next->sv = tmpsv;
            }
            tmp = tmp->next;
        }
    }
}
void sapXepDTB(DS **head){
    if(!head || !(*head) || !((*head)->next))
        return;
    for(DS *p = *head; p; p = p->next){
        for(DS *q = p->next; q;q = q->next){
            if(p->sv.DTB < q->sv.DTB){
                SV tmp = p->sv;
                p->sv = q->sv;
                q->sv = tmp;
            }
        }
    }
}
void ghiFileSapXepDTB(DS *head){
    FILE *f = fopen("D:/ML/C/C K2/exercise/day5/SapxepDTB.txt","w");
    if(!f){
        printf("Loi mo file\n");
        return;
    }
    int i = 1;
    while(head){
        fprintf(f,"%d %-11lld %-19s %-4d %-9s %-20.2f %s\n",i++, head->sv.MSV, head->sv.hoTen, head->sv.NS, head->sv.lop, head->sv.DTB, head->sv.diaChi);
        head = head->next;
    }
    fclose(f);
    printf("\nDanh sach sinh vien xep theo DTB da ghi vao 'SapxepDTB.txt'\n");
}
void ghiHocLai(DS *head){
    FILE *f = fopen("D:/ML/C/C K2/exercise/day5/HocLai.txt", "w");
    if(!f){
        printf("Loi mo file\n");
        return;
    }
    int count = 0;
    while(head){
        if(head->sv.DTB < 4.0){
            fprintf(f,"%lld %s %d %s %.2f %s\n", head->sv.MSV, head->sv.hoTen, head->sv.NS, head->sv.lop, head->sv.DTB, head->sv.diaChi);
            count++;
        }
        head = head->next;
    }
    fclose(f);
    printf("\nCo %d sinh vien hoc lai da ghi vao 'HocLai.txt'\n", count);
}
int main(){
    DS *head = NULL;
    int n;
    do{
        printf("Nhap so luon sinh vien: ");
        scanf("%d",&n);
        if(n<=0)
            printf("Loi! Vui long Nhap Lai!\n");
    }while(n<=0);
    nhapSV(&head,n);
    xuatSV(head);
    sapXep(&head,n);
    printf("\nDanh sach sinh vien duoc xep theo thu tu:");
    xuatSV(head);
    sapXepDTB(&head);
    ghiFileSapXepDTB(head);
    ghiHocLai(head);
}