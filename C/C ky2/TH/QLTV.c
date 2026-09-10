#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//cau truc ve ngay thang nam
typedef struct date{
    int ngay, thang, nam;
}date;
//cau truc ve thong tin doc gia
typedef struct docGia{
    char *hoVaTen; //ho va ten
    char *MSSV;   //ma so sinh vien
    date ngaySinh; //ngay sinh
    char *gioiTinh;   //gioi tinh
    date ngayTaoThe; // ngay tao the
    date ngayHetHanThe; //ngay het han the
    struct docGia *next; //con tro tro den NODE chua doc gia khac
}docGia;
//cau truc ve thong tin mot cuon sach
typedef struct sach{
    char *ISBN; //ma so sach
    char *tenSach; //ten sach
    char *tacGia; //tac gia
    date ngayXuatBan; //ngay san xuat
    char *theLoai; //the loai sach
    int giaSach; //gia sach
    int soLuong; //so luong con lai
}sach;
//cau truc ve thong tin phieu muon sach
typedef struct phieuMuonSach{
    char *MSSV; //ma so sinh vien
    date ngayMuonSach; //ngay muon sach
    date ngayTraDK; //ngay tra sach du kien
    int soSach; //so luong sach duoc muon
    char **ISBNm; //danh sach ma so sach duoc muon
}phieuMuonSach;
//cau truc ve thong tin phieu tra sach
typedef struct phieuTraSach{
    char *MSSV; //ma so sinh vien
    date ngayTraTT; //ngay tra sach thuc te
    int soST; //so sach tra
    char **ISBNt; //danh sach ma so sach tra
}phieuTraSach;
//ham nhap thong tin 1 doc gia
docGia *taoDG(char *hoVaTen, char *MSSV, date ngaySinh, char *gioiTinh, date ngayTaoThe){
    docGia *DG = (docGia*)calloc(1,sizeof(docGia));
    DG->hoVaTen = (char*)malloc(strlen(hoVaTen)+1);
    strcpy(DG->hoVaTen,hoVaTen);
    DG->MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(DG->MSSV,MSSV);
    DG->ngaySinh.ngay = ngaySinh.ngay; DG->ngaySinh.thang = ngaySinh.thang; DG->ngaySinh.nam = ngaySinh.nam;
    DG->gioiTinh = (char*)malloc(strlen(gioiTinh)+1);
    strcpy(DG->gioiTinh,gioiTinh);
    DG->ngayTaoThe.ngay = ngayTaoThe.ngay; DG->ngayTaoThe.thang = ngayTaoThe.thang; DG->ngayTaoThe.nam = ngayTaoThe.nam;
    DG->ngayHetHanThe = ngayTaoThe; DG->ngayHetHanThe.nam += 4;
    DG->next = NULL;
    return DG;
}
//ham them 1 doc gia vao danh sach
void themDocGia(docGia **headDG, docGia *DG){
    if(*headDG == NULL){
        *headDG = DG;
    }else{
        docGia *tmp = *headDG;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = DG;
    }
}
//ham nhap so doc gia
int soDG(int dk){
    int n;
    lap:
    dk ? printf("\nNhap so doc gia: ") : printf("Nhap so doc gia moi: ");
    scanf("%d", &n); getchar();
    if(n<=0){
        printf("Loi! Vui long nhap lai!\n");
        goto lap;
    }return n;
}
//ham kiem tra nhap ngay thang nam 
int kiemTraNgay(date date){
    return (date.ngay < 1 || date.ngay > 31) || (date.thang < 1 || date.thang > 12) || (date.nam < 1000);
}
//ham nhap ngay
void nhapNgay(date *ngay, char *ten){
    do{
        printf("Nhap ngay %s (dd/mm/yy): ", ten);
        if(scanf("%d/%d/%d", &ngay->ngay, &ngay->thang, &ngay->nam) != 3){
            printf("Loi nhap ngay! Hay nhap lai!\n");
            while(getchar() != '\n');
            continue;
        }getchar();
        if(kiemTraNgay(*ngay))
            printf("Ngay khong hop le! Hay nhap lai!\n");
    }while(kiemTraNgay(*ngay));
}
//ham nhap thong tin tung doc gia vao danh sach
void nhapDSDG(docGia **headDG, int *n, int dk){
    *n = soDG(dk);
    char hoVaTen[30], MSSV[15], gioiTinh[5];
    date ngaySinh;
    date ngayTaoThe;
    dk ? printf("\n<<   NHAP THONG TIN DOC GIA   >>\n") : printf("\n<<  NHAP THONG TIN DOC GIA MOI   >>\n");
    for(int i=0; i<*n; i++){
        printf("\n<<    Thong Tin Doc Gia %d    >>\n",i+1);
        printf("Nhap ho va ten: ");
        scanf("%[^\n]%*c", hoVaTen);
        printf("Nhap ma so sinh vien: ");
        scanf("%s", MSSV);
        nhapNgay(&ngaySinh, "sinh");
        printf("Nhap gioi tinh: ");
        scanf("%s", gioiTinh);
        nhapNgay(&ngayTaoThe, "tao the");
        docGia *DG = taoDG(hoVaTen, MSSV, ngaySinh, gioiTinh, ngayTaoThe);
        themDocGia(headDG, DG);
    }
}
//ham ghi vao file quan ly doc gia de luu tru thong tin doc gia
void ghiFileDG(docGia *headDG){
    FILE *f = fopen("quanLyDocGia.txt","w");
    if(f == NULL){
        printf("Loi thong tin doc gia chua duoc luu! Vui long thu lai.\n");
        return;
    }
    while(headDG != NULL){
        fprintf(f, "| %-20s | %-12s | %02d/%02d/%-4d | %-9s | %02d/%02d/%-5d | %02d/%02d/%-5d |\n",headDG->hoVaTen, headDG->MSSV, headDG->ngaySinh.ngay, headDG->ngaySinh.thang, headDG->ngaySinh.nam, headDG->gioiTinh, headDG->ngayTaoThe.ngay, headDG->ngayTaoThe.thang, headDG->ngayTaoThe.nam, headDG->ngayHetHanThe.ngay, headDG->ngayHetHanThe.thang, headDG->ngayHetHanThe.nam);
        headDG = headDG->next;
    }fclose(f);
}
//ham nhap thong tin 1 sach
sach themSach(char *ISBN, char *tenSach, char *tacGia, date ngayXuatBan, char *theLoai, int giaSach, int soLuong){
    sach themS;
    themS.ISBN = (char*)malloc(strlen(ISBN)+1);
    strcpy(themS.ISBN, ISBN);
    themS.tenSach = (char*)malloc(strlen(tenSach)+1);
    strcpy(themS.tenSach, tenSach);
    themS.tacGia = (char*)malloc(strlen(tacGia)+1);
    strcpy(themS.tacGia, tacGia);
    themS.ngayXuatBan.ngay = ngayXuatBan.ngay; themS.ngayXuatBan.thang = ngayXuatBan.thang; themS.ngayXuatBan.nam = ngayXuatBan.nam;
    themS.theLoai = (char*)malloc(strlen(theLoai)+1);
    strcpy(themS.theLoai, theLoai);
    themS.giaSach = giaSach;
    themS.soLuong = soLuong;
    return themS;
}
//ham nhap so luong sach, so luong phieu muon sach / phieu tra sach
int nhap(char *ten){
    int m;
    do{
        printf("\nNhap so luong %s: ",ten);
        scanf("%d",&m); getchar();
        if(m<=0){
            printf("Loi!!. Vui long nhap lai!\n");
        }
            
    }while(m<=0);
    return m;
}
//ham nhap thong tin sach
void nhapTTSach(sach **dsSach, int *m){
    printf("\n>>    NHAP THONG TIN SACH    <<\n");
    *m = nhap("sach");
    //cap phat bo nho cho mang dsSach
    *dsSach = (sach*)calloc(*m,sizeof(sach));
    //khai bao cac bien tam 
    char ISBN[10], tenSach[40], tacGia[30], theLoai[15];
    date ngayXuatBan;
    int giaSach, soLuong;
    //nhap du lieu vao cac bien tam
    for(int i = 0; i<*m; i++){
        printf("\nNhap ma sach thu %d: ", i+1);
        scanf("%s", ISBN); getchar();
        printf("Nhap ten sach: ");
        scanf("%[^\n]%*c", tenSach);
        printf("Nhap tac gia: ");
        scanf("%[^\n]%*c", tacGia);
        do{
        printf("Nhap ngay xuat ban: ");
        scanf("%d/%d/%d", &ngayXuatBan.ngay, &ngayXuatBan.thang, &ngayXuatBan.nam); getchar();
        if(ngayXuatBan.ngay < 1 || ngayXuatBan.ngay > 31 || ngayXuatBan.thang < 1 || ngayXuatBan.thang > 12 || ngayXuatBan.nam < 1000)
            printf("Loi! Vui long nhap lai!\n");
        }while(kiemTraNgay(ngayXuatBan));
        printf("Nhap the loai cua sach: ");
        scanf("%[^\n]%*c", theLoai);
        printf("Nhap gia sach: ");
        scanf("%d",&giaSach);
        printf("Nhap so luong sach: ");
        scanf("%d",&soLuong);
        while(getchar() != '\n');
        (*dsSach)[i] = themSach(ISBN, tenSach, tacGia, ngayXuatBan, theLoai, giaSach, soLuong); //phan tu thu i cua dsSach la con tro mang sach 1 chieu
    }//a kiểu s**, *a = a[0] = b kiểu s*, *(a)[0] = *b kiểu sach
}
//ham ghi vao file quan ly sach
void ghiFileSach(sach *dsSach, int m){
    FILE *f = fopen("quanLySach.txt", "w");
    if(f == NULL){
        printf("Loi thong tin sach chua duoc luu! Vui long thu lai!\n");
        return;
    }
    for(int i = 0; i<m; i++){
        fprintf(f,"| %-8s | %-30s | %-20s | %02d/%02d/%-5d | %-10s | %-8d VND | %d |\n",(dsSach+i)->ISBN, (*(dsSach+i)).tenSach, (dsSach+i)->tacGia, dsSach[i].ngayXuatBan.ngay, dsSach[i].ngayXuatBan.thang, dsSach[i].ngayXuatBan.nam, dsSach[i].theLoai, dsSach[i].giaSach, dsSach[i].soLuong);
    }fclose(f);
}
//ham xuat thong tin 1 doc gia
void xuatDG(docGia *dG){
    printf("+ Ho va ten: %s\n", dG->hoVaTen);
    printf("+ MSSV: %s\n", dG->MSSV);
    printf("+ Ngay sinh: %02d/%02d/%d\n", dG->ngaySinh.ngay, dG->ngaySinh.thang, dG->ngaySinh.nam);
    printf("+ Gioi tinh: %s\n", dG->gioiTinh);
    printf("+ Ngay tao the: %02d/%02d/%d\n", dG->ngayTaoThe.ngay, dG->ngayTaoThe.thang, dG->ngayTaoThe.nam);
    printf("+ Ngay het han the: %02d/%02d/%d\n", dG->ngayHetHanThe.ngay, dG->ngayHetHanThe.thang, dG->ngayHetHanThe.nam);\
}
//(*)ham xuat danh sach doc gia 
void xuatDSDG(docGia *headDG){
    int i = 1;
    while(headDG != NULL){
        printf("\n<<   Thong Tin Doc Gia %d   >>\n", i++);
        xuatDG(headDG);
        headDG = headDG->next;
    }
}
//(*)ham them doc gia
void themDG(docGia **headDG, int *n){
    int a;
    nhapDSDG(headDG,&a,0);
    n += a;
    ghiFileDG(*headDG);
}
//ham xoa doc gia dau dslk
void xoaDau(docGia **headDG){
    docGia *delDG = *headDG; 
    *headDG = (*headDG)->next;
    free(delDG);
    ghiFileDG(*headDG);
}
//ham xoa doc gia giua/cuoi dslk
void xoaGiua_Cuoi(docGia **headDG, docGia *delDG){
    docGia *tmp1 = *headDG;
    while(tmp1->next != delDG)
        tmp1 = tmp1->next;
    tmp1->next = delDG->next;
    free(delDG);
    ghiFileDG(*headDG);
}
//(*)ham xoa the doc gia
void xoaDG(docGia **headDG, char *MSSV, int *n){
    docGia *tmp1 = *headDG;
    if(strcmp(tmp1->MSSV, MSSV) == 0){
        xoaDau(headDG);
        printf("\nDa xoa THANH CONG the doc gia.\n");
        *n--;
        return;
    }
    while(tmp1 != NULL){
        if(strcmp(tmp1->MSSV, MSSV) == 0){
            xoaGiua_Cuoi(headDG, tmp1);
            printf("\nDa xoa THANH CONG the doc gia.\n");
            *n--;
            return;
        }
        tmp1 = tmp1->next;
    }
    if(tmp1 == NULL)
        printf("\nMSSV khong duoc tim thay!\n");
}
//ham in ra menu chon thong tin can sua
void menuSua(){
    printf("\n======= SUA THONG TIN =======\n");
    printf("1. Sua ho va ten doc gia\n");
    printf("2. Sua ma so sinh vien doc gia\n");
    printf("3. Sua ngay sinh doc gia\n");
    printf("4. Sua gioi tinh doc gia\n");
    printf("5. Sua ngay tao the doc gia\n");
    printf("6. Thoat!\n");
    printf("==============================\n");
    printf("Chon muc can sua thong tin: ");
}
//ham chon thong tin de sua
void chonTTSua(docGia *headDG){
    int choice;
    char hoVaTen[30], MSSVm[15], gioiTinh[5];
    date ngaySinh;
    date ngayTaoThe;
    do{
        menuSua();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon. Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1:
                printf("Nhap ho ten moi: ");
                scanf("%[^\n]%*c", hoVaTen);
                strcpy(headDG->hoVaTen, hoVaTen);
                printf("=> Sua doi ho ten HOAN THANH!\n");
                break;
            case 2:
                printf("Nhap ma so sinh vien moi: ");
                scanf("%s", MSSVm); getchar();
                strcpy(headDG->MSSV,MSSVm);
                printf("=> Sua doi MSSV HOAN THANH!\n");
                break;
            case 3:
                nhapNgay(&ngaySinh, "sinh");
                headDG->ngaySinh.ngay = ngaySinh.ngay; headDG->ngaySinh.thang = ngaySinh.thang; headDG->ngaySinh.nam = ngaySinh.nam;    
                printf("=> Sua doi ngay sinh HOAN THANH!\n");
                break;
            case 4: 
                printf("Nhap gioi tinh moi: ");
                scanf("%s", gioiTinh); getchar();
                strcpy(headDG->gioiTinh, gioiTinh);
                printf("=> Sua doi gioi tinh HOAN THANH!\n");
                break;
            case 5:
                nhapNgay(&ngayTaoThe,"tao the");
                headDG->ngayTaoThe.ngay = ngayTaoThe.ngay; headDG->ngayTaoThe.thang = ngayTaoThe.thang; headDG->ngayTaoThe.nam = ngayTaoThe.nam;
                printf("=> Sua doi ngay tao the HOAN THANH!\n");
                break;
            default: choice = 6;
        }     
    }while(choice != 6);
}
//(*)ham chinh sua thong tin doc gia
void chinhSuaDG(docGia *headDG){
    docGia *tmp = headDG;
    char MSSV[15];
    printf("\nNhap MSSV can chinh sua: ");
    scanf("%s", MSSV);
    while(1){
        if(strcmp(headDG->MSSV,MSSV) == 0)
            break;
        headDG = headDG->next;
        if(headDG == NULL){
            printf("MSSV khong ton tai!\n");
            return;
        }
    }
    chonTTSua(headDG);
    ghiFileDG(tmp);
}
//ham xuat ma va ten doc gia
void tenDG(docGia *headDG, char *MSSV){
    while(headDG != NULL){
        if(strcmp(headDG->MSSV, MSSV) == 0){
            printf("\nTen doc gia: %s\n",headDG->hoVaTen);
            printf("MSSV: %s\n", MSSV);
            break;
        }
    }
}
//ham in menu cac chuc nang quan ly doc gia
void menuDG(){
    printf("\n======= QUAN LY DOC GIA ======\n");
    printf("1. Xem danh sach doc gia\n");
    printf("2. Them doc gia\n");
    printf("3. Xoa doc gia\n");
    printf("4. Chinh sua thong tin doc gia\n");
    printf("5. Thoat!\n");
    printf("===============================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly doc gia
void chonCNDG(docGia **headDG, int *n){
    int choice;
    int a;
    char MSSV[15];
    do{
        menuDG();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>    DANH SACH DOC GIA    <<\n");
                xuatDSDG(*headDG);
                break;
            case 2:
                printf("\n>>     THEM DOC GIA     <<\n");
                themDG(headDG,n);
                break;
            case 3:
                printf("\n>>     XOA DOC GIA     <<\n");
                printf("\nNhap MSSV can xoa the: ");
                scanf("%s", MSSV);getchar();
                xoaDG(headDG,MSSV,n);
                break;
            case 4:
                printf("\n>>  CHINH SAU THONG TIN DOC GIA  <<\n");
                chinhSuaDG(*headDG);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}
//ham xuat thong tin 1 sach
void xuatSach(sach sach, int kieu){
    printf("+ Ma so sach: %s\n", sach.ISBN);
    printf("+ Ten sach: %s\n", sach.tenSach);
    printf("+ Tac gia: %s\n", sach.tacGia);
    printf("+ Ngay xuat ban: %02d/%02d/%d\n", sach.ngayXuatBan.ngay,sach.ngayXuatBan.thang, sach.ngayXuatBan.nam);
    printf("+ The loai: %s\n", sach.theLoai);
    printf("+ Gia sach: %d VND\n", sach.giaSach);
    kieu ? printf("+ So luong con lai: %d\n", sach.soLuong) : printf("+ So luong da muon: 1\n");
}
//(*)ham xuat danh sach cac sach trong thu vien
void xuatDSSach(sach *dsSach, int m){
    for(int i = 0; i<m; i++){
        printf("\n<<   Thong Tin Sach Thu %d   >>\n", i+1);
        xuatSach(dsSach[i],1);
    }
}
//ham so sanh 2chuoi
int soSanhChuoi(char *bienCanSS, char *bienDuocSS){
    if(strcmpi(bienCanSS, bienDuocSS) == 0)
        return 1;
    return 0;
}
//ham xuat ma va ten sach
void tenSach(sach *dsSach, int m, char *ISBN){
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(dsSach[i].ISBN, ISBN)){
            printf("Ma sach: %s\n", ISBN);
            printf("Ten sach: %s\n", dsSach[i].tenSach);
            break;
        }
    }
}
//(*)ham tim kiem sach theo ma sach
void timKiemISBN(sach *dsSach, int m){
    char ISBN[15];
    printf("Nhap ISBN cua sach can tim: ");
    scanf("%s", ISBN); getchar();
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(ISBN, dsSach[i].ISBN)){
            printf("\n<<    Thong Tin Sach Can Tim    >>\n");
            xuatSach(dsSach[i],1);
            return;
        }
    }
    printf("\nKhong tim thay ISBN trong thu vien!\n");
}
//(*)ham tim kiem sach theo ten sach
void timKiemTS(sach *dsSach, int m){
    char tenSach[40];
    printf("Nhap ten sach can tim: ");
    scanf("%[^\n]%*c", tenSach);
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(tenSach, dsSach[i].tenSach)){
            printf("\n<<    Thong Tin Sach Can Tim    >>\n");
            xuatSach(dsSach[i],1);
            return;
        }
    }
    printf("\nKhong tim thay ten sach trong thu vien!\n");
}
//(*)ham them sach moi vao thu vien
void themSM(sach **dsSach, int *m){
    int a, dem = 0;
    do{
        printf("\nNhap so luong sach can them: ");
        if(scanf("%d",&a) != 1){
            printf("Loi! Hay thu lai!\n");
            while(getchar() != '\n');
        }else break;       
    }while(1);
    *dsSach = (sach*)realloc(*dsSach,(*m + a) * sizeof(sach));
    char ISBN[10], tenSach[40], tacGia[30], theLoai[15];
    date ngayXuatBan;
    int giaSach, soLuong;
    for(int i = *m; i<*m+a; i++){
        printf("\n<<    Thong Tin Sach Moi %d    >>\n", ++dem);
        printf("Nhap ma sach moi: ");
        scanf("%s", ISBN); getchar();
        printf("Nhap ten sach: ");
        scanf("%[^\n]%*c", tenSach);
        printf("Nhap tac gia: ");
        scanf("%[^\n]%*c", tacGia);
        nhapNgay(&ngayXuatBan,"xuat ban");
        printf("Nhap the loai cua sach: ");
        scanf("%[^\n]%*c", theLoai);
        printf("Nhap gia sach: ");
        scanf("%d",&giaSach);
        printf("Nhap so luong sach: ");
        scanf("%d",&soLuong);
        while(getchar() != '\n');
        (*dsSach)[i] = themSach(ISBN, tenSach, tacGia, ngayXuatBan, theLoai, giaSach, soLuong);
    }
    *m += a;
    ghiFileSach(*dsSach, *m);
}
//ham in menu cac chuc nang quan ly sach
void menuSach(){
    printf("\n============= QUAN LY SACH =============\n");
    printf("1. Xem danh sach cac sach trong thu vien\n");
    printf("2. Tim kiem sach theo ISBN\n");
    printf("3. Tim kiem sach theo ten sach\n");
    printf("4. Them sach moi\n");
    printf("5. Thoat!\n");
    printf("========================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly sach
void chonCNSach(sach **dsSach, int *m){
    int choice;
    do{
        menuSach();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>   DANH SACH SACH TRONG THU VIEN   <<\n");
                xuatDSSach(*dsSach,*m);
                break;
            case 2:
                printf("\n>>    TIM KIEM SACH THEO ISBN    <<\n");
                timKiemISBN(*dsSach, *m);
                break;
            case 3:
                printf("\n>>   TIM KIEM SACH THEO TEN SACH   <<\n");
                timKiemTS(*dsSach, *m);
                break;
            case 4:
                printf("\n>>     THEM SACH MOI     <<\n");
                themSM(dsSach, m);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}
//ham so sanh ngay kiem tra lon hay nho hon ngay duoc kiem tra
int soSanhNgay(date ngayKT, date ngayHH){
    if(ngayKT.nam > ngayHH.nam) return 1;
    if(ngayKT.nam == ngayHH.nam && ngayKT.thang > ngayHH.thang) return 1;
    if(ngayKT.nam == ngayHH.nam && ngayKT.thang == ngayHH.thang && ngayKT.ngay > ngayHH.ngay) return 1;
    return 0;
}
//ham kiem tra the doc gia con han hay het han
int kiemTraThe(docGia *headDG, char *MSSV, date ngayKT){
    while(headDG!=NULL){
        if(soSanhChuoi(headDG->MSSV, MSSV)){
            if(soSanhNgay(ngayKT, headDG->ngayHetHanThe))
                return 1;
            else return 0;
        }
        headDG = headDG->next;
    }
    return 0;
}
//ham cap nhap so luong sach con lai
int capNhatSLS(sach *dsSach, char *ISBN, int m, int kieu){
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(ISBN, dsSach[i].ISBN)){
            !kieu ? dsSach[i].soLuong -- :  dsSach[i].soLuong ++;
            if(dsSach[i].soLuong == -1){
                printf("\nThu vien da het sach nay!\n");
                dsSach[i].soLuong ++;
            }
            ghiFileSach(dsSach, m);
            return 0;
        }
    }return 1;
}
//ham kiểm tra nam nhuan
int namNhuan(int nam){
    return ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0));
}
//ham ngay trong thang
int ngayTrongThang(int thang, int nam){
    int ngay[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(thang == 2 && namNhuan(nam))
        return 29;
    return ngay[thang];
}
//ham tinh ngay tra du kien (so ngay muon toi da la 91 ngay)
date ngayTraDuKien(docGia *headDG, char *MSSV, date ngayMuonSach){
    date ngayTraDK = ngayMuonSach;
    ngayTraDK.ngay = 91 - (ngayTrongThang(ngayMuonSach.thang, ngayMuonSach.nam) - ngayMuonSach.ngay);
    if(++ngayTraDK.thang > 12){
        ngayTraDK.thang = 1;
        ngayTraDK.nam++;
    }
    while(ngayTraDK.ngay > ngayTrongThang(ngayTraDK.thang, ngayTraDK.nam)){
        ngayTraDK.ngay -= ngayTrongThang(ngayTraDK.thang++, ngayTraDK.nam);
        if(ngayTraDK.thang > 12){
            ngayTraDK.thang = 1;
            ngayTraDK.nam++;
        }
    }
    return kiemTraThe(headDG, MSSV, ngayTraDK) ? headDG->ngayHetHanThe : ngayTraDK;
}
//ham nhap danh sach "ma sach" cua nhung sach duoc muon
char **nhapISBN(int soSach, char ISBN[][15]){
    char **ISBNm = (char**)calloc(soSach,sizeof(char*)); 
    for(int i = 0; i<soSach; i++){
        ISBNm[i] = (char*)malloc(strlen(ISBN[i])+1); 
        strcpy(ISBNm[i], ISBN[i]); 
    }return ISBNm;
}
//ham nhap thong tin 1 phieu muon sach
phieuMuonSach themPMS(docGia *headDG, char *MSSV, date ngayMuonSach, int soSach, char ISBN[][15]){
    phieuMuonSach pM;
    pM.MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(pM.MSSV,MSSV);
    pM.ngayMuonSach.ngay = ngayMuonSach.ngay; pM.ngayMuonSach.thang = ngayMuonSach.thang; pM.ngayMuonSach.nam = ngayMuonSach.nam;
    pM.ngayTraDK = ngayTraDuKien(headDG, MSSV, ngayMuonSach);
    pM.soSach = soSach;
    pM.ISBNm = nhapISBN(soSach, ISBN);
    return pM;
}
//ham kiem tra MSSV theo danh sach MSSV o doc gia
int kiemTraMSSVdg(docGia *headDG, char *MSSV){
    while(headDG != NULL){
        if(soSanhChuoi(MSSV, headDG->MSSV))
            return 0;
        headDG = headDG->next;
    }
    return 1;
}
//(*)ham ghi vao file quan ly phieu muon sach
void ghiFilePM(phieuMuonSach *pMS, int q){
    FILE *f = fopen("quanLyPhieuMuon.txt", "w");
    if(f == NULL){
        printf("Loi! thong tin phieu muon sach chua duoc luu!\n");
        return; 
    }
    for(int i = 0; i<q; i++){
        fprintf(f,"| %-15s | %02d/%02d/%-5d | %02d/%02d/%-5d | %d |", pMS[i].MSSV, pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam, pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam, pMS[i].soSach);
        for(int j =0; j<pMS[i].soSach; j++)
            fprintf(f," %-15s |", pMS[i].ISBNm[j]);
        fprintf(f,"\n");
    }
    fclose(f);
}
//(*)ham nhap phieu muon sach
void nhapPMS(phieuMuonSach **pMS, int *q, docGia **headDG, int *n, sach *dsSach, int m){
    int a, dem = 0;
    a = nhap("phieu muon sach");
    *pMS = (phieuMuonSach*)realloc(*pMS, (a + *q) * sizeof(phieuMuonSach));
    char MSSV[15], ISBNm[10][15];
    date ngayMuonSach;
    int soSach;
    for(int i = *q; i< *q+a; i++){
        printf("\n<<    Phieu Muon Sach %d    >>\n", ++dem);
        do{
            int xet=0;
            printf("Nhap ma so sinh vien muon sach: ");
            scanf("%s", MSSV);getchar();
            if(kiemTraMSSVdg(*headDG, MSSV))
                printf("\nMSSV khong duoc tim thay trong the doc gia\n");
            else break;
        }while(1);
        nhapNgay(&ngayMuonSach,"muon sach");
        if(kiemTraThe(*headDG,MSSV,ngayMuonSach)){
            printf("\nThe doc gia da het han!\nTao the moi hoac tra lai tat ca sach da muon truoc do.\n");
            xoaDG(headDG,MSSV,n);
            return;
        }
        do{
            printf("Nhap so sach da muon: ");
            scanf("%d",&soSach);
            if(soSach < 1 || soSach > 10)
                printf("So sach gioi han 1 lan muon la 1 -> 10 cuon.\nVui long nhap lai!\n");
        }while(soSach < 1 || soSach > 10);
        while(getchar() != '\n');
        for(int j = 0; j < soSach; j++){
            do{
                printf("Nhap ma sach da muon %d: ", j+1);
                scanf("%s", ISBNm[j]); getchar();
                if(capNhatSLS(dsSach, ISBNm[j], m, 0))
                    printf("\nISBN khong duoc tim thay. Hay nhap lai!n");
                else break;
            }while(1);
        }
        (*pMS)[i] = themPMS(*headDG, MSSV, ngayMuonSach, soSach, ISBNm);
    }// *a = a[0] = b kieu *sach => *(a)[0] = a[0][0] = b[0] kieu sach
    *q += a;
    ghiFilePM(*pMS, *q);
    ghiFileDG(*headDG);
    ghiFileSach(dsSach, m);
}
//ham kiem tra MSSV o phieu muon sach
int kiemTraMSSVpm(char *MSSV, phieuMuonSach *pMS, int q){
    for(int i = 0; i<q; i++){
        if(strcmp(MSSV,pMS[i].MSSV) == 0)
            return 0;
    }
    return 1;
}
//(*)ham xuat danh sach cac sach duoc muon boi 1 doc gia theo MSSV
void xuatSachMuon(phieuMuonSach *pMS, int q, sach *dsSach, int m, docGia *headDG){
    char MSSV[15];
    int dem = 0;
    do{
        printf("\nNhap MSSV: ");
        scanf("%s", MSSV); getchar();
        if(kiemTraMSSVpm(MSSV, pMS, q))
            printf("\nMSSV khong duoc tim thay trong danh sach phieu muon.\n");
    }while(kiemTraMSSVpm(MSSV, pMS, q));
    tenDG(headDG, MSSV);
    for(int i = 0; i<q; i++){
        if(soSanhChuoi(MSSV, pMS[i].MSSV)){
            printf("Ngay muon sach: %02d/%02d/%d\n",pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam);
            printf("Ngay tra sach du kien: %02d/%02d/%d\n",pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
            for(int j = 0; j < pMS[i].soSach; j++){
                printf("\n<<    Thong Tin Sach %d    >>\n",dem++);
                for(int k = 0; k<m; k++){
                    if(soSanhChuoi(pMS[i].ISBNm[j], dsSach[k].ISBN))
                        xuatSach(dsSach[k],0);
                }
            }
        }
    }
    if(!dem)
        printf("\nMSSV: %s khong duoc tim thay trong danh sach phieu muon.\n");
}
//ham xoa phieu mmuon sach
void xoaPMS(phieuMuonSach **pMS, int *q, int a){
    free((*pMS)[a].MSSV);
    for(int i = a; i< *q-1; i++){
        (*pMS)[i] = (*pMS)[i+1];
    }
    free((*pMS)[*q-1].MSSV);
    *q--;
}
//ham cap nhat lai phieu muon sach
int capNhapPMS(phieuMuonSach **pMS, int *q, char *MSSV, char *ISBNt){
    for(int i =0; i<*q; i++){
        if(strcmp((*pMS)[i].MSSV, MSSV) == 0){
            for(int j = 0; j < (*pMS)[i].soSach; j++){
                if(strcmpi((*pMS)[i].ISBNm[j], ISBNt) == 0){
                    free((*pMS)[i].ISBNm[j]);
                    for(int k = j; k < (*pMS)[i].soSach-1; k++)
                        (*pMS)[i].ISBNm[k] = (*pMS)[i].ISBNm[k+1];
                    free((*pMS)[i].ISBNm[(*pMS)[i].soSach-1]);
                    if(--(*pMS)[i].soSach == 0)
                        xoaPMS(pMS,q,i);
                    return 0;
                }
            }
        }
    }
    return 1;
}
//ham tinh ngay tien phat tra sach muon
int ngayTre(date ngayTraTT, date ngayTraDK){
    int soNgay = 0;
    if(ngayTraTT.thang>ngayTraDK.thang){
        soNgay = ngayTrongThang(ngayTraDK.thang++,ngayTraDK.nam) - ngayTraDK.ngay + ngayTraTT.ngay;
        for(int i = ngayTraDK.thang; i < ngayTraTT.thang; i++)
            soNgay += ngayTrongThang(ngayTraDK.thang++,ngayTraDK.nam);
    }else if(ngayTraTT.thang<ngayTraDK.thang){
        soNgay = ngayTrongThang(ngayTraTT.thang++,ngayTraTT.nam) - ngayTraTT.ngay + ngayTraDK.ngay;
        for(int i = ngayTraTT.thang; i < ngayTraTT.thang; i++)
            soNgay += ngayTrongThang(ngayTraTT.thang++,ngayTraTT.nam);
        soNgay = -soNgay;
    }else{
        soNgay = ngayTraTT.ngay - ngayTraDK.ngay;
    }
    for(int i = ngayTraDK.nam; i < ngayTraTT.nam; i++)
        soNgay += namNhuan(i) ? 366 : 365; 
    return soNgay;
}
//ham kiem tra va xu phat tra sach tre
void kiemTraXuPhat(date ngayTraTT, char *MSSV, phieuMuonSach *pMS, int q, char ISBNt[][15], int soST, sach *dsSach, int m, docGia *headDG){
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhChuoi(pMS[i].MSSV,MSSV)){
            for(int j = 0; j<soST; j++){
                for(int k =0; k<pMS[i].soSach; k++){
                    if(soSanhChuoi(ISBNt[j], pMS[i].ISBNm[k])){
                        if(soSanhNgay(ngayTraTT,pMS[i].ngayTraDK)){
                            !dem++ ? printf("\n=== Danh sach Sach tra tre han ===\n\n") : printf("\n");
                            tenDG(headDG, MSSV);
                            tenSach(dsSach, m, ISBNt[j]);
                            printf("Ngay muon: %02d/%02d/%d - Ngay tra du kien: %02d/%02d/%d\n", pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam, pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
                            printf("Ngay tra thuc te: %02d/%02d/%d\n", ngayTraTT.ngay, ngayTraTT.thang, ngayTraTT.nam);
                            int soNgayTre = ngayTre(ngayTraTT,pMS[i].ngayTraDK);
                            printf("So ngay tre: %d\n",soNgayTre);
                            printf("So tien xu phat: %d * 5000 = %d VND\n", soNgayTre,soNgayTre*5000);
                        }
                    }
                }
            }
        }
    }
    if(!dem)
        printf("\nDoc gia da tra sach dung han\n");
}
//ham ghi file quan ly phieu tra sach
void ghiFilePT(phieuTraSach *pTS, int p){
    FILE *f = fopen("quanLyPhieuTra.txt", "w");
    if(f == NULL){
        printf("Loi! thong tin phieu tra sach chua duoc luu!\n");
        return;
    }
    for(int i = 0; i<p; i++){
        fprintf(f,"| %-15s | %02d/%02d/%-5d | %d |", pTS[i].MSSV, pTS[i].ngayTraTT.ngay, pTS[i].ngayTraTT.thang, pTS[i].ngayTraTT.nam, pTS[i].soST);
        for(int j = 0; j<pTS[i].soST; j++)
            fprintf(f," %-15s |", pTS[i].ISBNt[j]);
        fprintf(f,"\n");
    }
    fclose(f);
}
//ham nhap thong tin 1 phieu tra sach
phieuTraSach themPTS(char *MSSV, date ngayTraTT, int soSach, char ISBNt[][15]){
    phieuTraSach pT;
    pT.MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(pT.MSSV,MSSV);
    pT.ngayTraTT.ngay = ngayTraTT.ngay; pT.ngayTraTT.thang = ngayTraTT.thang; pT.ngayTraTT.nam = ngayTraTT.nam;
    pT.soST = soSach;
    pT.ISBNt = nhapISBN(soSach, ISBNt);
    return pT;
}                
//(*)ham nhap phieu tra sach
void nhapPTS(phieuTraSach **pTS, int *p, sach *dsSach, int m, phieuMuonSach **pMS, int *q, docGia *headDG){
    int a, dem = 0;
    a = nhap("phieu tra sach");
    *pTS = (phieuTraSach*)realloc(*pTS, (a + *p) * sizeof(phieuTraSach));
    char MSSV[15], ISBNt[20][15];
    date ngayTraTT;
    int soST;
    for(int i = *p; i<*p+a; i++){
        printf("\n=== Phieu Tra Sach %d ===\n", ++dem);
        do{
            printf("Nhap ma so sinh vien tra sach: ");
            scanf("%s", MSSV);getchar();
            if(kiemTraMSSVpm(MSSV,*pMS,*q)){
                printf("\nMSSV khong duoc tim thay trong phieu muon sach\n");
                continue;
            }
            break;
        }while(1);
        nhapNgay(&ngayTraTT, "tra sach");
        printf("Nhap so sach duoc tra: ");
        scanf("%d",&soST);
        while(getchar() != '\n');
        for(int j = 0; j < soST; j++){
            printf("Nhap ma sach da tra %d: ", j+1);
            scanf("%s", ISBNt[j]); getchar();
            if(capNhapPMS(pMS,q,MSSV,ISBNt[j])){
                printf("\nKhong tim thay thong tin sach trong phieu muon cua: %s\n", MSSV);
                return;
            } 
            if(capNhatSLS(dsSach, ISBNt[j], m, 1))
                printf("\nKhong tim thay sach nay o thu vien\n");
        }
        kiemTraXuPhat(ngayTraTT,MSSV,*pMS,*q,ISBNt, soST, dsSach,m,headDG);
        (*pTS)[i] = themPTS(MSSV,ngayTraTT,soST,ISBNt);
    }
    *p += a;
    ghiFilePT(*pTS, *p);
    ghiFilePM(*pMS, *q);
    ghiFileSach(dsSach, m);
}
//ham in menu cac chuc nang quan ly phieu muon sach & phieu tra sach
void menuPMTS(){
    printf("\n====== QUAN LY PHIEU MUON SACH & TRA SACH ======\n");
    printf("1. Tao phieu muon sach\n");
    printf("2. Tao phieu tra sach\n");
    printf("3. Xem danh sach cac sach dang duoc\n   muon boi 1 doc gia theo MSSV\n");
    printf("4. Thoat!\n");
    printf("================================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly phieu muon sach & phieu tra sach
void chonCNMTS(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach *dsSach, int m){
    int choice;
    do{
        menuPMTS();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>     TAO PHIEU MUON SACH     <<\n");
                nhapPMS(pMS,q,headDG,n,dsSach,m);
                break;
            case 2:
                printf("\n>>     TAO PHIEU TRA SACH     <<\n");
                nhapPTS(pTS,p,dsSach,m,pMS,q,*headDG);
                break;
            case 3:
                printf("\n>>   DANH SACH CAC SACH DUOC MUON CUA 1 DOC GIA   <<\n");
                xuatSachMuon(*pMS,*q,dsSach,m,*headDG);
                break;
            case 4:
                choice = 4;
                break;
            default:  choice = 4;
        }
    }while(choice != 4);
}
//(*)ham thong ke so luong sach trong thu vien
int soLuongSachTV(sach *dsSach, int m){
    int soSach = 0;
    for(int i = 0; i<m; i++)
        soSach += dsSach[i].soLuong;
    return soSach;
}
//ham dem 1 sach dang duoc muon bao nhieu cuon
int demSachM(phieuMuonSach *pMS, int q, char *ISBN, int danhDau[]){
    int dem = 0, k = 0;
    for(int i = 0; i<q; i++){
        for(int j = 0; j < pMS[i].soSach; j++){
            if(strcmp(ISBN, pMS[i].ISBNm[j]) == 0){
                dem ++;
                danhDau[k] = 1;
            }
            k++;
        }
    }
    return dem;
}
//(*)ham thong ke so sach dang duoc muon
void dsSM(sach *dsSach, int m, phieuMuonSach *pMS, int q){
    int danhDau[100] = {0};
    int k = 0, dem = 1;
    for(int i = 0; i<q; i++){
        for(int j = 0; j < pMS[i].soSach; j++){
            if(danhDau[k++] == 1)
                continue;
            printf("\n<<    Thong Tin Sach Duoc Muon %d    >>\n", dem++);
            tenSach(dsSach, m, pMS[i].ISBNm[j]);
            printf("So luong: %d\n", demSachM(pMS,q,pMS[i].ISBNm[j], danhDau));
        }
    }
}
//ham thong ke so luong doc gia tre han tra sach
int soDGTH(phieuMuonSach *pMS, int q, date ngay_hien_tai){
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhNgay(ngay_hien_tai, pMS[i].ngayTraDK))
            dem++;
    }
    return dem;
}
//(*)ham xuat thong tin doc gia tre han tra sach
void dgTreHan(phieuMuonSach *pMS, int q, docGia *headDG){
    date ngay_hien_tai;
    nhapNgay(&ngay_hien_tai,"hien tai");
    if(soDGTH(pMS,q,ngay_hien_tai))
        printf("\nSo doc gia qua han tra sach: %d\n", soDGTH(pMS,q,ngay_hien_tai));
    else{
        printf("\nKhong co doc gia qua han tra sach!\n");
        return;
    }
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhNgay(ngay_hien_tai, pMS[i].ngayTraDK)){
            printf("\nDoc gia tre han tra sach %d\n\n",++dem);
            tenDG(headDG,pMS[i].MSSV);
            printf("Ngay muon: %02d/%02d/%d\n", pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam);
            printf("Ngay tra du kien: %02d/%02d/%d\n", pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
            printf("So luong: %d\n", pMS[i].soSach);
            printf("Cac ma sach duoc muon: ");
            for(int j = 0; j<pMS[i].soSach; j++){
                printf("%-6s |%c",pMS[i].ISBNm[j], (j+1)%3==0 ? '\n' : ' ');
            }
        }
    }
}
//ham in menu cac chuc nang thong ke
void menuTK(){
    printf("\n====== THONG KE (DG, SACH, PMS, PTS) ======\n");
    printf("1. Thong ke so luong sach trong thu vien\n");
    printf("2. Thong ke so sach dang duoc muon\n");
    printf("3. Thong ke so luong doc gia qua han tra sach\n");
    printf("4. Thoat!\n");
    printf("===========================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang thong ke 
void chonCNTK(phieuMuonSach *pMS, int q,docGia *headDG, sach *dsSach, int m){
    int choice;
    do{
        menuTK();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>   THONG KE SO LUONG SACH TRONG THU VIEN   <<\n");
                printf("So luong sach dang co trong thu vien la: %d\n", soLuongSachTV(dsSach,m));
                break;
            case 2:
                printf("\n>>   THONG KE SO LUONG SACH DANG MUON   <<\n");
                dsSM(dsSach,m,pMS,q);
                break;
            case 3:
                printf("\n>>   THONG KE SO DOC GIA QUA HAN TRA SACH   <<\n\n");
                dgTreHan(pMS,q,headDG);
                break;
            case 4:
                choice = 4;
                break;
            default:  choice = 4;
        }
    }while(choice != 4);
}
//ham menu chuong trinh quan ly thu vien
void menuQL(){
    printf("\n========= QUAN LY THU VIEN ========\n");
    printf("1. Quan ly doc gia\n");
    printf("2. Quan ly sach\n");
    printf("3. Lap phieu muon sach & tra sach\n");\
    printf("4. Cac thong ke\n");
    printf("5. Thoat!\n");
    printf("===================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuong trinh quan ly thu vien
void chon_muc_quan_ly(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach **dsSach, int *m){
    int choice;
    do{
        menuQL();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>    QUAN LY THE DOC GIA    <<\n");
                chonCNDG(headDG, n);
                break;
            case 2:
                printf("\n>>        QUAN LY SACH       <<\n");
                chonCNSach(dsSach,m);
                break;
            case 3:
                printf("\n>>   QUAN LY PHIEU MUON TRA SACH   <<\n");
                chonCNMTS(pMS,q,pTS,p,headDG,n,*dsSach,*m);
                break;
            case 4: 
                printf("\n>>         THONG KE         <<\n");
                chonCNTK(*pMS,*q,*headDG,*dsSach,*m);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}
int main(){
    docGia *headDG = NULL; //danh sach doc gia
    int n; //n la so luong doc gia
    nhapDSDG(&headDG, &n, 1); //nhap danh sach doc gia
    ghiFileDG(headDG); //ghi vao file quan ly doc gia de luu tru
    
    int m; //m la so luong sach trong thu vien
    sach *dsSach; //danh sach cac sach
    nhapTTSach(&dsSach, &m); //nhap thong tin cac sach
    ghiFileSach(dsSach, m); //ghi vao file quan ly sach de luu tru
    
    phieuMuonSach *pMS = NULL; //danh sach phieu muon sach
    int q = 0; //so luong phie muon sach
    
    phieuTraSach *pTS = NULL; //danh sach phieu tra sach
    int p = 0; //so luong phieu tra sach
     
    chon_muc_quan_ly(&pMS,&q,&pTS,&p,&headDG,&n,&dsSach,&m); //thuc hien cac chuc nang quan ly thu vien
    //giai phong bo nho doc gia
    while(headDG){
        docGia *tmp = headDG;
        headDG = headDG->next;
        free(tmp->hoVaTen);
        free(tmp->MSSV);
        free(tmp->gioiTinh);
        free(tmp);
    }
    //giai phong danh sach cac sach
    for(int i = 0; i<m;i++){
        free(dsSach[i].ISBN);
        free(dsSach[i].tenSach);
        free(dsSach[i].tacGia);
        free(dsSach[i].theLoai);
    }free(dsSach);
    //giai phong danh sach phieu muon sach
    for(int i = 0; i<q;i++){
        free(pMS[i].MSSV);
        for(int j = 0;j<pMS[i].soSach;j++)
            free(pMS[i].ISBNm[j]);
        free(pMS[i].ISBNm);
    }free(pMS);
    //giai phong danh sach phieu tra sach
    for(int i =0 ;i<p; i++){
        free(pTS[i].MSSV);
        for(int j = 0; j<pTS[i].soST; j++)
            free(pTS[i].ISBNt[j]);
        free(pTS[i].ISBNt);
    }free(pTS);

    return 0;
}