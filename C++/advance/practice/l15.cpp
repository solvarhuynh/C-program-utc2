#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    // int a[n];
    // set<int> b, s;
    // for(int &x : a) cin >> x;
    // while(m--){
    //     int x; cin>> x;
    //     b.insert(x);
    // }
    // for(int x : a){
    //     if(!(b.count(x)))
    //         s.insert(x);
    // }
    // for(int x : s)
    //     cout << x << " ";

    set<int>a;
    while(n--){
        int x; cin >> x;
        a.insert(x);
    }
    while(m--){
        int x; cin >> x;
        if(a.find(x) != a.end()){
            a.erase(x);
        }
    }
    for(int x : a)
        cout << x << " ";
}