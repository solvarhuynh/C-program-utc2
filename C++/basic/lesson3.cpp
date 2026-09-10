#include <iostream>
using namespace std;
bool check(long long n){
    int sum = 0;
    while (n!=0){
        sum += n%10;
        n /= 10;
    }
    return sum%10 == 8;
}

int main(){
    long long n; cin >> n;
    if (check(n)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    //cout << (check(n) ? "YES\n" : "NO\n");
}