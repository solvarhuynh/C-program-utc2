//struct lop hc, so sv, tên lớp, n sinh viên
//struct sv, mssv, ten sinh viên, gpa
//nhap, xuat
#include <stdio.h>
#include <string.h>

//so luong sinh vien toi da 1 lop
#define MAX_STUDENTS 100
//so luong lop toi da
#define MAX_CLASS 20
typedef struct student{
    int mssv;
    char name[30];
    float gpa;
}st;
typedef struct class{
    int n;
    char name[30];
    st list[MAX_STUDENTS];
}class;

//nhap thong tin 1 sinh vien
void inputStudent(st *student){
    printf("Nhap MSSV: ");
    scanf("%d",&student->mssv);
    getchar();
    printf("Nhap ten sinh vien: ");
    scanf("%[^\n]",student->name);
    printf("Nhap diem GPA: ");
    scanf("%f",&student->gpa);
}
//nhap thong tin 1 lop hoc
void inputClass(class *class){
    //nhap so luong sinh vien
    do{
        printf("Nhap so luong sinh vien: ");
        scanf("%d",&class->n);
        if(class->n <= 0 || class->n > 100)
            printf("Khong hop le!. So luong sinh vien <= 100 va > 0\n");
    }while(class->n <= 0 || class->n > 100);
    //nhap thong tin tung sinh vien
    for(int i = 0; i < class->n; i++){
        printf("\n========== THONG TIN SINH VIEN %d ==========\n",i+1);
        inputStudent(&class->list[i]);
    }
}
//nhap thong tin nhieu lop
void inputClassList(class classList[], int n){
    for(int i = 0; i<n; i++){
        //nhap ten lop hoc
        getchar();
        printf("Nhap ten lop hoc thu %d: ",i+1);
        scanf("%[^\n]", classList[i].name);
        inputClass(&classList[i]);
    }
}
//xuat thong tin 1 sinh vien
void outputST(st student){
    printf("MSSV: %d\n", student.mssv);
    printf("Ho Va Ten: %s\n", student.name);
    printf("Diem GPA: %.1f\n", student.gpa);
}
//xuat thong tin lop hoc
void printClass(class classList[], int n){
    for(int i = 0; i<n; i++){
        printf("\n========== THONG TIN LOP %s ==========\n", classList[i].name);
        printf("So luong sinh vien: %d\n",classList[i].n);
        for(int j  = 0; j < classList[i].n; j++){
            printf("\nSinh vien thu %d:\n",j+1);
            outputST(classList[i].list[j]);
        }
    }

}
//tim sinh vien co diem gpa cao nhat
void findMaxOfGPA(class classList[], int n){
    float maxOfGPA = classList[0].list[0].gpa;
    int k, v;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<classList[i].n; j++){
            if(classList[i].list[j].gpa > maxOfGPA){
                maxOfGPA = classList[i].list[j].gpa;
                k = i;
                v = j
            }
        }
    }
    outputST(classList[k].list[v]);
}
int main(){
    //khai bao so luong lop hoc
    int n;
    //nhap so luong lop hoc
    do{
        printf("Nhap so luong lop hoc: ");
        scanf("%d",&n);
        if(n <= 0 || n > 100)
            printf("Khong hop le!. So luong lop hoc <= 20 va > 0\n");
    }while(n <= 0 || n > 20);

    st student;
    class classList[n];
    inputClassList(classList, n);
    printClass(classList, n);
}