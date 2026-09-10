#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
    int m,n; cin >> m >> n;
    set<int> hop, giao, a;
    while(m--){
        int x; cin >> x;
        a.insert(x);
        hop.insert(x);
    }
    while(n--){
        int x; cin >> x;
        if(a.count(x)) giao.insert(x);
        hop.insert(x);
    }
    for(int x : giao){
        cout << x << " ";
    }cout << endl;
    for(int x : hop){
        cout << x << " ";
    }
}