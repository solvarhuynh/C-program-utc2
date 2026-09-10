//sop co so lan xuat hien nhieu nhat trong mang
#include <iostream>
#include <map>

using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin>> n;
        map<int,int> m;
        for(int i = 0; i<n; i++){
            int x; cin>>x;
            m[x] ++;
        }
        int max_fre = 0, value = 0;
        for(auto x : m){
            if(x.second > max_fre){
                max_fre = x.second;
                value = x.first;
            }
        }
        cout << value << " " << max_fre << endl;
    }
}