#include <iostream>
using namespace std;
bool so6(int n){
    while (n!=0){
        if (n%10 == 6){
            return true;
        }
        n /= 10;
    }
    return false;
}
bool tong_chan(int n){
    int sum = 0;
    while (n!=0){
        sum += n%10;
        n/=10;
    }
    return sum % 2 == 0;
}
bool chan_le(int n){
    int chan = 0, le = 0;
    while (n!=0){
        if (n%2 == 0)
            chan++;
        else
            le ++;
        n /= 10;
    }
    return le > chan;
}

int main(){
    int a,b; cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (so6(i) && tong_chan(i) && chan_le(i))
            cout << i << " ";
    }
}