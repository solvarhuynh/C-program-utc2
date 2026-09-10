//dem so luong phan tu khac nhau trong mang so nguyen
#include <iostream>
#include <set>
#include <map>

using namespace std;
int main(){
    // int t; cin >> t;
    // for(int i = 0; i<t; i++){ //while(t--)
    //     int n; cin >> n;
    //     set<int> s;
    //     for(int j = 0; j<n; j++){
    //         int x; cin >> x;
    //         s.insert(x);
    //     }
    //     cout << s.size() << endl;
    // }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int,int> m;
        for(int j = 0; j<n; j++){
            int x; cin >> x;
            m[x] ++;
        }
        cout << m.size() << endl;
    }
    
    //nếu dùng mảng tỉnh thì sort rồi so sánh 2 phần tử liền kề nếu khác nhau tăng biến đếm, giống nhau ko tăng

}