//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// pair<datatype1, datatype2> v;

int main(){
    pair<int,int> v1; //0 0
    cout << v1.first << v1.second << endl;
    pair<int,int> v2 = {10,20}; //make_pair(10,20);
    cout << v2.first << v2.second << endl;

    //neu muon 3 cap tro len => tuple
    pair<pair<int,int>,int> v3;
    tuple<int, int, int> t1{1,2,3};
    cout << get<0>(t1) << get<2>(t1) << endl;
    tuple<string,string,int> t = make_tuple("HCMUTE","HTN",18);
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t)<<endl;
}