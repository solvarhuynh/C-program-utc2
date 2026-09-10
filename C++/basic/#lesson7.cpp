#include <iostream>

using namespace std;

// int max_array(int a[], int n){
//     int answer = a[0];
//     for(int i = 1; i<n; i++){
//         if(answer < a[i])
//             answer = a[i];
//     }return answer;
// }
// int marker(int a[],int n){
//     int max = max_array(a,n);
//     if(max <= 0) return 1;
//     for(int i = 1; i<=max; i++){
//         for(int j = 0; j<n; j++){
//             if(i == a[j])
//                 break;
//             if(j == n-1)
//                 return i;
//         }
//     }
//     return max + 1;
// }
int marker(int a[], int n){
    bool persent[n+1] = {false};
    for(int i = 0; i<n; i++){
        if(a[i] > 0 && a[i]<=n)
            persent[a[i]] = true;
    }
    for(int i = 1; i<=n; i++){
        if(!persent[i])
            return i;
    }
    return n+1;
}
/* 
mảng persent đúng phải có n+1 phần tử vì  tình từ 0 - n, dùng chỉ xét từ 1 đến n nhưng mảng nào cũng có chỉ số 0 nên phải
là n+1. sở dỉ không cần n+2 vì nếu không đủ số để lấp đầy từ 1 - n thì chắc chắn sẽ là 1 trong n số đó, còn nếu lấp đầy
từ 1 - n thì chắc chắn số cần tìm là n+1 thì cần gì phải lo cho n +2
*/
int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin >> n;
        int a[n];
        for(int j =0; j<n; j++){
            cin >> a[j];
        }
        cout << marker(a,n) << endl;
    }
}

