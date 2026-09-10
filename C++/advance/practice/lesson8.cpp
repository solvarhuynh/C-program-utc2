#include<iostream>
#include<map>
#include<set>
#include<sstream>
using namespace std;
int main(){
    int t; cin >> t;
    cin.ignore();
    //cung duoc nhung chua dung
    // while(t--){
    //     string m; getline(cin,m);
    //     multiset<string> ms;
    //     stringstream ss(m);
    //     string word;
    //     int max_fre = 0;
    //     string lecter;
    //     while(ss >> word){
    //         ms.insert(word);
    //         if(ms.count(word) > max_fre){
    //             max_fre = ms.count(word);
    //             lecter = word;
    //         }
    //     }
    //     cout << lecter << endl;
    // }

    while(t--){
        string m; getline(cin,m);
        map<string,int> mp;
        stringstream ss(m);
        string word;
        while(ss >> word){
            mp[word]++;
        }
        int max_fre = 0;
        string lecter;
        for(auto x : mp){
            if(x.second > max_fre){
                max_fre = x.second;
                lecter = x.first;
            }
        }
        cout << lecter << endl;
    }
}