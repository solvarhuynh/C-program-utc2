//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

//moi phan tu trong map la 1 pair: key - value
// insert
// count - find
//erase (XOA Ca CAP)
int main(){
    // map<int,int> mp;
    // mp[100] = 200;
    // mp[200] = 300;
    // mp.insert({300,400});
    // mp.insert({400,500});
    // cout << mp.size() << endl;

    // mp[100] = 300; //size se khong thay doi, KEY giong nhu trong set -> 0 doi, chi thay doi value

//3 cach in ra - theo thu tu key tang dan
    // for(pair<int,int> x : mp)
    //     cout << x.first << " " << x.second <<  endl;

    // for(auto it : mp)
    //     cout << it.first << " " << it.second <<  endl;

    // for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
    //     cout <<(*it).first <<" "<< (*it).second << endl;

//tim kiem
    // if(mp.count(200) && mp[200] == 300) //mp.find() != mp.end() => trả về iterator
    //     cout <<"Found"<< endl;
    // else
    //     cout <<"Not Found"<<endl;

//xoa
    // mp.erase(100);

//bai toan dem phan tu
    // map<int,int>mp;
    // int n; cin >> n;
        // for(int i = 0; i<n; i++){
        //     int x; cin >> x;
        //     mp[x] ++;
        // }
        // for(auto it : mp)
        //     cout << it.first << " " << it.second <<  endl;
    // int a[n];
    // for(int i = 0; i<n; i++){
    //     cin >> a[i];
    //     mp[a[i]] ++;
    // }
    // for(int i = 0; i<n; i++)
    //     if(mp[a[i]] != 0){
    //         cout << a[i] << " " << mp[a[i]] <<  endl;
    //         mp[a[i]] = 0;
    //     }

//string    
    // map<string,int> mp;
    // int n; cin >> n;
    // for(int i = 0; i<n; i++){
    //     string s; cin>>s;
    //     mp[s] ++;
    // }
    // int max_fre = 0;
    // string res;
    // for(auto x : mp){
    //     if (max_fre < x.second){
    //         max_fre = x.second;
    //         res = x.first;
    //     }
    // }
    // cout << res << " " << max_fre << endl;

//multimap ==> tuong tu set, co the luu cung gia tri (key)
    // multimap<int,int> mp;
    // mp.insert({1,100});
    // mp.insert({2,200});
    // mp.insert({1,200});
    // for(auto x : mp){
    //     cout << x.first << " " << x.second << endl;
    // }
    // cout << mp.count(1) << endl;

//unorder_map
    unordered_map<int,int> up;
    
}