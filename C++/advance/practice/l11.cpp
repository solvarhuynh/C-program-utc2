#include <iostream>
#include <set>
using namespace std;
int main(){
    int n; cin >> n;
    set<int> s;
    while(n--){
        int x; cin  >> x;
        s.insert(x);
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(s.count(x)) cout << "YES\n" ;
        else cout << "NO\n";
    }
}