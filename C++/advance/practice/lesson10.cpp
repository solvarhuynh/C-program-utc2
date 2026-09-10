#include <iostream>
#include <map>
using namespace std;
int main(){
    int t; cin >> t;
    map<string, int> mp;
    while(t--){
        string m; cin >> m;
        if(mp.find(m) == mp.end()){
            cout << m << endl;
        }else{
            cout << m << mp[m] << endl;
        }
        mp[m] ++;
    }
}