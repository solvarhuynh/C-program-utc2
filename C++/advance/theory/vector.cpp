//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//vector<kieudulieu> ten_vector
//push_bakc() - them phan tu
//size() - kich thuoc cua vector (so phan tu)
int main(){
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // cout << v.size() << endl;
    // v.push_back(40);
    // cout << "phan tu dau tien: " << v[0] << endl;
    // cout <<"Phan tu cuoi cung: " << v[v.size()-1] << v.back()<< endl;

    // for(int i = 0; i<v.size(); i++){
    //     cout << v[i] << " ";
    // }

    // for(int x : v){
    //     cout << x << " ";
    // }vector<int>::iterator i = v.v

    // for(vector<int>::iterator i = v.begin(); i != v.end(); i++){ //iterator là giả con tro ~ con tro
    //     cout << *i << endl;
    // }
    
    // for(auto i = v.begin(); i != v.end(); i++){
    //     cout << *i << endl;
    // }
    //cout << *(v.begin() + 2);

    // int n; cin>>n;
            //1. cach nhập vào vector động có sãn n phần tử
    // vector<int> v1(n); //khai bao vector da co san n phan tu int | neu viet v[n]: 1 vector gom n vector
    // for(int i = 0; i<n; i++){
    //     cin >>v1[i];
    // }
            //2. cách nhập vector động, không cần phải cấp phát lại như C
    // vector<int> v2;
    // for(int i  = 0; i<n; i++){
    //     int x; cin >> x;
    //     v2.push_back(x);
    // }
    // // //khai nao vector có n phần tử mà mỗi phần tử có giá trị như nhau và bằng ..
    // vector<int> v(n,6);
    // for(int i = 0; i<n; i++){
    //     cout <<v[i]<<endl;
    // }
    // vector<string> v;
    // v.push_back("Lap trinh");
    // v.push_back("DSA");
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << endl;
    // }


    vector<string> v;
    string s = "Su Pham Ky Thuat TP.HCM HCMUTE";
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        cout << tmp << endl;
        v.push_back(tmp);
    }
    for(string x : v){
        cout << x << " ";
    }
}
