#include<iostream>
#include<map>
#include<set>
#include<sstream>
using namespace std;
int main(){
    int t; cin >> t;
    cin.ignore();
    // while(t--){
    //     string m; getline(cin,m);
    //     set<string> s;
    //     stringstream ss(m);
    //     string word;
    //     while(ss >> word){
    //         s.insert(word);
    //     }
    //     cout << s.size() << endl;
    // }

    while(t--){
        string m; getline(cin,m);
        map<string,bool> mp;
        stringstream ss(m);
        string word;
        while(ss >> word){
            mp[word] = true;
        }
        cout << mp.size() << endl;
    }
}