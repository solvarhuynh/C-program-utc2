#include <iostream>
using namespace std;
int gt(int n){
    int factorical = 1;
    for(int i = 2; i<=n; i++){
        factorical *= i;
    }
    return factorical;
}

int main(){
    int n; cin >> n;
    cout << gt(n)<< endl;
}