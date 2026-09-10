#include <iostream>
using namespace std;

// void s(int a[], int n){
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j < n; j ++){
//             if (a[j] == i){
//                 int tmp = a[i];
//                 a[i] = i;
//                 a[j] = tmp;
//                 break;
//             }  
//         }
//     }
//     for(int i = 0; i<n;i++){
//         if(a[i] != i)
//             a[i] = -1;
//     }
// }

void s(int a[], int n){
    bool m[n] = {false};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[j] == i){
                m[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(m[i]){
            a[i] = i;
        }else
            a[i] = -1;
    }
}
int main(){
    int t; cin >> t;
    int n;
    for( int i = 0; i<t; i++){
        cin >> n;
        int a[n];
        for(int j = 0; j<n; j++){
            cin >> a[j];
        }
        s(a,n);
        for(int j = 0; j<n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}