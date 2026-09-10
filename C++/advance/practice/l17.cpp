#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];

    // vector<int> v;
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    //     v.push_back(a[i]);
    // }
    // sort(v.begin(),v.end());
    // int min = *v.begin(), max = *v.rbegin();
    // for(int x : a){
    //     if(x ==  min)
    //        cout << *(find(v.begin(), v.end(), x) + 1) << " " << -1 << endl;
    //     else if(x == max)
    //         cout << -1 << " " << *(find(v.begin(), v.end(), x) - 1) << endl;
    //     else cout << *(find(v.begin(), v.end(), x) + 1) << " " << *(find(v.begin(), v.end(), x) - 1) << endl;
    // }

    set<int> s;
    
    //upper_bound(x): Tra ve gia tri nho nha > x trong set
    //lower_bound(x): Tra ve gia tri nho nhat >= x trong set

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 0; i < n; i++){

        set<int>::iterator it1 = s.upper_bound(a[i]);
        if( it1 != s.end()) cout << *it1 << " ";
        else cout << -1 << " ";

        set<int>::iterator it2 = s.lower_bound(a[i]);
        if(it2 != s.begin()){ /* vì đề bài này sẽ luôn có giá trị trả về vì hàm lower tìm chính a[i] để trả về luôn
            nhưng vì mình cần tìm só ở trước nó (lớn nhất mà nhỏ hơn x - ở trước - nhỏ nhát mà >= x) nên nếu lower trả về begin tức là min thì
            không có số trước thỏa mãn nên phải xét điều kiện != begin */
            --it2;
            cout<<*it2<<endl;
        }else cout << -1 << endl;
    }

}