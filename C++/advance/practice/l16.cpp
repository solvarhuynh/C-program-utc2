#include <iostream>
// #include <bits/stdc++.h>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> m;
    while(n--){
        int x; cin >> x;
        m[x] ++;
    }
    int value1, max_fre = 0;
    for(auto x : m){
        if(max_fre < x.second){
            max_fre = x.second;
            value1 = x.first;
        }
    }cout << value1 << " " << max_fre <<endl;
    int value2, min_fre = 1001;
    for(pair<int,int> x : m){
        if(min_fre >= x.second){
            min_fre = x.second;
            value2 = x.first;
        }
    }cout << "\n" << value2 << " " << min_fre; cout <<"\n"<< endl;
    for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
        cout<< (*it).first << " " << (*it).second << endl;
    }cout << endl;
    for(map<int,int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++){
        cout<< (*it).first << " " << (*it).second << endl;
    }
}