#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    m["nam"] = 1;
    if(m.find("nam") == m.end()){
        cout<<m.size()<<endl;
    }else{
        cout<<m["nam"]<<endl;
    }
}
