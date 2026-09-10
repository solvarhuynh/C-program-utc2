#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int t; cin>>t;
    cin.ignore();
    // while(t--){
    //     string m; getline(cin,m);
    //     map<string,int> mp;
    //     stringstream ss(m);
    //     string word;
    //     while(ss >> word){
    //         mp[word] ++;
    //         if(mp[word] == 2){
    //             cout << word << endl;
    //             break;
    //         }      
    //     }
    // }

    // while(t--){
    //     string m; getline(cin,m);
    //     multiset<string> ms;
    //     stringstream ss(m);
    //     string word;
    //     while(ss >> word){
    //         ms.insert(word);
    //         if(ms.count(word) == 2){
    //             cout << word << endl;
    //             break;
    //         }      
    //     }
    // }

    while(t--){
        string m; getline(cin,m);
        set<string> s;
        stringstream ss(m);
        string word;
        vector<string> v;
        while(ss >> word){
            v.push_back(word);     
        }
        for(string x : v){
            if(s.find(x) != s.end()){
                cout << x << endl; 
                break;
            } s.insert(x);
        }
    }
}