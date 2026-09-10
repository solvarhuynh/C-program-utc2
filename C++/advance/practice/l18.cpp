#include <iostream>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> m;
    while(n--){
        int x; cin >> x;
        m[x] ++;
    }
    int res = 0;
    for(auto x : m){
        if(x.second >= 2)
            res += (x.second * (x.second - 1))/2;
    }
    cout << res;
}