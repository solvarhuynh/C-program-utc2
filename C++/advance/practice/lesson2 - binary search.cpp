//tim kiem phan tu trong mang
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    // int t; cin >> t;
    // while(t--){
    //     int n; cin >> n;
    //     set<int> s;
    //     for(int i  = 0; i<n; i++){
    //         int x; cin>>x;
    //         s.insert(x);
    //     }
    //     int q; cin>>q;
    //     while(q--){
    //         int m; cin >> m;
    //         if(s.count(m)){
    //             cout << "YES" << endl;
    //         }else{
    //             cout << "NO" << endl;
    //         }
    //     }
    // }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int,bool> m;
        for(int i  = 0; i<n; i++){
            int x; cin>>x;
            m.insert({x,true});
        }
        int q; cin>>q;
        while(q--){
            int mi; cin >> mi;
            if(m.count(mi)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    } //binary_search()
}