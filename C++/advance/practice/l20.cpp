#include <iostream>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> m;
    while(n--){
        int x,y; cin >> x >> y;
        map<int,int>::iterator it = m.find(x);
        if(it != m.end() && (*it).second == y){
            cout << "YES";
            break;
        }
        m[x] = y;  
    }
}