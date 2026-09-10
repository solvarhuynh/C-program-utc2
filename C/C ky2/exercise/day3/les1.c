#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct thongtin {
    int MSSV;
    char* Hoten;
    float Diemtk;
    char* Lop;
} info;

typedef struct sv {
    info SV;
    struct sv* pNext;
} SinhVien;

SinhVien* taoSV(int MSSV, char *Hoten, float DiemTK, char *Lop) {
    SinhVien *sv = (SinhVien*)malloc(sizeof(SinhVien));
    sv->SV.MSSV = MSSV;
    sv->SV.Hoten = (char*)malloc(strlen(Hoten) + 1);
    strcpy(sv->SV.Hoten, Hoten);
    sv->SV.Diemtk = DiemTK;
    sv->SV.Lop = (char*)malloc(strlen(Lop) + 1);
    strcpy(sv->SV.Lop, Lop);
    sv->pNext = NULL;
    return sv;
}

void themSV(SinhVien *head, SinhVien *sv) {
    if (head == NULL) {
        head = sv;
    } else {
        SinhVien *temp = head;
        while (temp->pNext != NULL) {
            temp = temp->pNext;
        }
        temp->pNext = sv;
    }
}

void nhapDS(SinhVien **head, int n) {
    int MSSV;
    char Hoten[50], Lop[10];
    float DiemTK;
    for (int i = 0; i < n; i++) {
        printf("Nhap MSSV: "); scanf("%d", &MSSV);
        printf("Nhap Ho ten: "); getchar(); fgets(Hoten, 50, stdin); Hoten[strcspn(Hoten, "\n")] = 0;
        printf("Nhap Diem tong ket: "); scanf("%f", &DiemTK);
        printf("Nhap Lop: "); scanf("%s", Lop);
        SinhVien *sv = taoSV(MSSV, Hoten, DiemTK, Lop);
        themSV(*head, sv);
    }
}

void xuatDS(SinhVien *head) {
    printf("\nDanh sach sinh vien:\n");
    while (head != NULL) {
        printf("MSSV: %d, Ho ten: %s, Diem TK: %.2f, Lop: %s\n", head->SV.MSSV, head->SV.Hoten, head->SV.Diemtk, head->SV.Lop);
        head = head->pNext;
    }
}

void sapxepDS(SinhVien *head) {
    if (head == NULL || head->pNext == NULL) return;
    SinhVien *i, *j;
    info temp;
    
    for (i = head; i != NULL; i = i->pNext) {
        for (j = i->pNext; j != NULL; j = j->pNext) {
            if (i->SV.MSSV > j->SV.MSSV) {
                temp = i->SV;
                i->SV = j->SV;
                j->SV = temp;
            }
        }
    }
}

SinhVien* timkiemSV(SinhVien *head, int MSSV) {
    while (head != NULL) {
        if (head->SV.MSSV == MSSV) {
            return head;
        }
        head = head->pNext;
    }
    return NULL;
}

int main() {
    SinhVien *head = NULL;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    
    nhapDS(&head, n);
    xuatDS(head);
    
    sapxepDS(head);
    printf("\nDanh sach sau khi sap xep theo MSSV:\n");
    xuatDS(head);
    
    int MSSV_Tim;
    printf("\nNhap MSSV can tim: ");
    scanf("%d", &MSSV_Tim);
    SinhVien *tim = timkiemSV(head, MSSV_Tim);
    if (tim) {
        printf("Tim thay: MSSV: %d, Ho ten: %s, Diem TK: %.2f, Lop: %s\n", tim->SV.MSSV, tim->SV.Hoten, tim->SV.Diemtk, tim->SV.Lop);
    } else {
        printf("Khong tim thay sinh vien co MSSV %d\n", MSSV_Tim);
    }
    return 0;
}
