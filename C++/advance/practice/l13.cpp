#include <iostream>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<char, int> m;
    while(n--){
        char s; cin >> s;
        m[s] ++;
    }
    for(pair<char,int> x : m)
        cout << x.first << " " << x.second << endl;
    cout<<endl;
    for(map<char,int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it){
        cout << (*it).first << " " << it->second << endl;
    }
}