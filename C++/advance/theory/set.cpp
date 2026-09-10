#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
//O(logn)
// chi luu so phan tu khac nhau
//insert - size
//find - count
//erase
//order
//multiset
//unordered_set
int main(){
    // set<int>s;
    // s.insert(100);
    // s.insert(200);
    // s.insert(300);
    // s.insert(100);
    // s.insert(200);
    // cout << s.size() << endl;

    // set <int> s;
    // for (int i  = 0; i<10; i++){
    //     s.insert(i);
    // }
    // cout <<s.size() <<endl;
    // if(s.count(5)){
    //     cout << "Found\n";
    // }else{
    //     cout << "Not Found\n";
    // }
    // if(s.find(10) != s.end()){
    //     cout << "Found\n";
    // }else{
    //     cout <<"Not found\n";
    // }

    // set<int> s;
    // s.insert(5);
    // s.insert(4);
    // s.insert(6);
    // for (int x : s){
    //     cout << x << endl;
    // }
    // s.erase(5); 
    // s.erase(s.find(4)); //find trả vể iterator đc xem như là 1 con trỏ và trỏ tới vị trí của số 4, con trỏ này có kiểu là set<int>::iterator
    // cout << s.size();

    // set<int> s;
    // for (int i = 0; i <10; i++){
    //     s.insert(i);
    // }
    // for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;
    // for(auto x = s.begin(); x!=s.end(); x++){
    //     cout << *x << " ";
    // }
    // cout << endl;
            //auto kieu khac
    //     for(auto x : s){
    //         cout << x << " ";
    //     }

    // int m; cin >> m;
    // set<int> s;
    // for (int i = 0; i<m; i++){
    //     int x; cin >> x;
    //     s.insert(x);
    // }
    // cout << s.size() << endl; 

    // int m; cin >> m;
    // //cin.ignore();
    // set<string> s;
    // for(int i = 0; i<m; i++){
    //     string c; //getline(cin,c);
    //     getline(cin >> ws,c);
    //     s.insert(c);
    // }
    // for(set<string>::iterator it = s.begin(); it != s.end(); ++it){
    //     cout << *it << " ";
    // }

    // multiset<int> ms;
    // ms.insert(100);
    // ms.insert(200);
    // ms.insert(100);
    // for(int x : ms){
    //     cout <<x<< " ";
    // }
    // cout << ms.count(100) << endl;
    // // muon xoa trong multiset thi dung iterator
    //     ms.erase(100); // xoa het
    //     for(int x : ms){
    //         cout <<x<< " ";
    //     }

    // int n, k; cin >> n >> k;
    // int a[n];
    // for(int &x : a) cin >> x;
    // multiset<int>ms;
        // for(int i = 0; i<n-k+1; i++){
        //     for(int j = i; j < i + k; j++){
        //         ms.insert(a[j]);
        //     }
        //     cout << *(ms.rbegin()) << " ";
        //     ms.clear();
        // }
    // for(int i = 0; i<k; i++){
    //     ms.insert(a[i]);
    // }
    // for(int i = k; i<n; i++){
    //     cout << *(ms.rbegin()) << " ";
    //     ms.erase(ms.find(a[i-k]));
    //     ms.insert(a[i]);
    // }
    // cout << *(ms.rbegin());

    unordered_set<int> us; // in theo thu tự ngược nhập
    for(int i = 0; i < 10; i++){
        us.insert(i);
    } us.insert(3);
    for(int x : us) cout << x << endl;
    
}
    