//dem phan tu thuoc mang 1 ma khong thuoc mang 2
#include <iostream>
#include <set>
#include <map>

using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n];
        set<int> s;
        for(int &x : a) cin >> x;
        for(int i = 0; i<m; i++){
            int x; cin >> x;
            s.insert(x);
        }
        int dem = 0;
        for(int x : a){
            if(s.find(x) == s.end()){
                dem ++;
            }
        }
        if(dem)
            cout << dem << endl;
        else
            cout << "NOT FOUND\n";
    }
}