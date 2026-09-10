#include <iostream>
#include <math.h>
using namespace std;

int distance(int a[], int n){
    int kc = pow(10,9);
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(kc > abs(a[i] - a[j]))
                kc = abs(a[i] - a[j]);
        }
    }
    return kc;
}
int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin >> n;
        int a[n];
        for(int j =0; j<n; j++){
            cin >> a[j];
        }
        cout << distance(a,n) << endl;
    }
}