#include <iostream>
#include <set>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    set<int> s;
    for(int &x : a) cin >> x;

    //cach truy van giong mang danh dau
    int f[n];
    for(int i = n - 1; i >= 0; i--){
        s.insert(a[i]);
        f[i] = s.size();
    }

    int q; cin >> q;

    while(q--){
        int i; cin >> i;
        cout << f[i] << endl;
    }
    // while(q--){
    //     int i; cin >> i;
    //     for(int j = i; j < n; j++)
    //         s.insert(a[j]);
    //     cout << s.size() << endl;
    //     s.clear();
    // }

    

}