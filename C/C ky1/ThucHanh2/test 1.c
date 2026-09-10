#include <stdio.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[30];
    float GPA;
} Student;

// Hàm nhập thông tin một sinh viên
void inputStudent(Student *st) {
    printf("Nhập mã sinh viên : ");
    scanf("%d", &st->id);
    printf("Nhập họ tên sinh viên : ");
    getchar(); // loại bỏ ký tự thừa
    scanf("%[^\n]", st->name); // nhận chuỗi có khoảng trắng
    printf("Nhập GPA : ");
    scanf("%f", &st->GPA);
}

// Hàm nhập danh sách sinh viên
void inputListStudent(int n, Student listSt[]) {
    for (int i = 0; i < n; i++) {
        printf("\n==== NHẬP SINH VIÊN THỨ %d ====\n", i + 1);
        inputStudent(&listSt[i]);
    }
}

// Hàm in thông tin một sinh viên
void printStudent(Student st) {
    printf("\n%d \t %s \t\t %.2f \n", st.id, st.name, st.GPA);
}

// Hàm in danh sách sinh viên
void printListStudent(int n, Student listSt[]) {
    printf("Mã \t Họ tên \t\t GPA \n");
    for (int i = 0; i < n; i++) {
        printStudent(listSt[i]);
    }
}

// Tìm sinh viên có GPA cao nhất
Student findMaxOfGPA(int n, Student listSt[]) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (listSt[i].GPA > listSt[index].GPA) {
            index = i;
        }
    }
    return listSt[index];
}

// Tìm kiếm sinh viên theo tên
Student* searchByName(char nameSearch[], int n, Student listSt[]) {
    for (int i = 0; i < n; i++) {
        if (strstr(listSt[i].name, nameSearch) != NULL) {
            return &listSt[i]; // trả về con trỏ tới sinh viên
        }
    }
    return NULL; // không tìm thấy
}

int main() {
    // khai báo số lượng sinh viên, 0 < N <= 50
    int n;

    // nhập n
    do {
        printf("Nhập số lượng sinh viên (0 < N <= 50), N = ");
        scanf("%d", &n);
    } while (n <= 0 || n > 50);

    // khai báo danh sách có N sinh viên;
    Student listSt[n];

    // nhập danh sách sinh viên
    inputListStudent(n, listSt);

    // in danh sách sinh viên
    printf("\n====== DANH SÁCH SINH VIÊN ======\n");
    printListStudent(n, listSt);

    // tìm sinh viên có điểm GPA cao nhất
    printf("\n====== SINH VIÊN CÓ ĐIỂM GPA CAO NHẤT ======\n");
    printStudent(findMaxOfGPA(n, listSt));

    // tìm kiếm sinh viên theo tên
    printf("\n====== TÌM KIẾM SINH VIÊN THEO TÊN ======\n");

    char nameSearch[30];
    do {
        printf("Nhập tên sinh viên cần tìm (hoặc nhấn -x để thoát): ");
        getchar(); // loại bỏ ký tự thừa
        scanf("%[^\n]", nameSearch);

        // Kiểm tra nếu nhập -x thì thoát
        if (strcmp(nameSearch, "-x") == 0) {
            break;
        }

        // Tìm kiếm sinh viên
        Student *found = searchByName(nameSearch, n, listSt);
        if (found != NULL) {
            printStudent(*found);
        } else {
            printf("\nKhông tìm thấy sinh viên với tên \"%s\"!\n", nameSearch);
        }
    } while (1);

    return 0;
}
