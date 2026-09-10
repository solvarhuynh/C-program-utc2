//ký tự có số lần sh nhiều nhn e
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int t; cin >> t;
    cin.ignore();
    // while(t--){
    //     string s;
    //     getline(cin,s);
    //     map<char,int> m;
    //     for(char x : s)
    //         m[x] ++;
    //     int max_fre = 0;
    //     char character;
    //     for(auto x : m){
    //         if(x.second >= max_fre){
    //             max_fre = x.second;
    //             character = x.first;
    //         }
    //     }
    //     cout << character << " " << max_fre << endl;
    // }

    while(t--){
        string s;
        getline(cin,s);
        int dem[256] = {0};
        for(char x : s)
           dem[x]++;
        int max_fre = 0;
        char character;
        for(int x = 0; x < 256; x++){
            if(dem[x] > max_fre){
                max_fre = dem[x];
                character = (char)(x);
            }
        }
        cout << character << endl;
    }
}