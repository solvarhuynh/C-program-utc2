#include <iostream>
#include <set>
using namespace std;
int main(){
    int n; cin >> n;
    multiset<int> ms;
    while(n--){
        int x; cin >> x;
        ms.insert(x);
    }
    int q; cin >> q;
    while(q--){
        int tt; cin >> tt;
        int x; cin >> x;
        if(tt == 1)
            ms.insert(x);
        else if(tt == 2){
            if(ms.find(x) != ms.end())
                ms.erase(ms.find(x));
        }else if(tt == 3){
            if(ms.count(x)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    for(int x : ms){
        cout << x << " ";
    }
}
