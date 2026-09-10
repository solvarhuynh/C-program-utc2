// khi khai báo int a[] thì trình phiên dịch hiểu là *a , nó sẽ tương tự khi a[i] = *(a+i)
// vd int a[] thì máy hiểu là *a (là con trỏ với a = &a[0] là địa chỉ 1234) và a[2] = *(a+2) tức con trỏ trỏ tới địa chỉ 1236
/* 1 ô nhớ tương đương 1 byte và có 1 địa chỉ riêng, và tùy theo kiểu dữ liệu của mảng thì khoảng cách giữ 2 phần tử là 1 với
kiểu char hay 2 với kiểu int hay 4 với kiểu float */
#include <stdio.h>

void enter(int *a){
    
    for(int i = 0; i<a; i++){

    }
}

//getchar(), scanf("%[^\n]%*c",...) and while ((c = getchar() != "\n" && c != EOF)

// Tình huống	                        Cần truyền gì?	     Lý do
// xóa node đầu	                        Node **head	         Vì thay đổi địa chỉ đầu danh sách
// xóa node cuối	                    Node *head	         Chỉ sửa .next, không đổi head
// sửa nội dung node	                Node *head	         Chỉ sửa .data, không đổi địa chỉ
// thêm phần tử mảng động (realloc)	    int **a	             realloc có thể đổi địa chỉ mảng
// nếu mảng đã cấp phát trước	        int *a	             Không đổi địa chỉ, chỉ sửa nội dung