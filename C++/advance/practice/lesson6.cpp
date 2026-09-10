#include<iostream>
#include<set>
#include<map>

using namespace std;
int main(){
    int t; cin >> t;
    //cin.ignore();
    // while(t--){
    //     string m; cin>>m;
    //     set<char> s;
    //     for(char x : m){
    //         s.insert(x<=97 ? char(x+32) : x); //tolower
    //     }
    //     if(s.size() == 26)
    //         cout << "Yes\n";
    //     else cout << "No\n";
    // }

    while(t--){
        string m; cin>>m;
        bool cnt[26] = {0};
        for(char x : m){
            cnt[tolower(x)-'a'] = true;
        }
        int dem = 0;
        for(int i = 0; i<26; i++){
            if(cnt[i])
                dem++;
        }
        if(dem == 26)
            cout << "Yes\n";
        else cout << "No\n";
    }

    // while(t--){
    //     string m; cin>>m;
    //     map<char,bool> mp;
    //     for(char x : m){
    //         mp[tolower(x)] = true;
    //     }
    //     if(mp.size() == 26)
    //         cout << "Yes\n";
    //     else cout << "No\n";
    // }

}