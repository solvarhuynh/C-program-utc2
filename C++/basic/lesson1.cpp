#include <iostream>
using namespace std;
void dprint(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
    cout << a+b+c << "\n";
    cout << "Ket thuc" << endl;
    //printf("%d %d %d\n",a,b,c); print("%d\n",a+b+c); print("Ket thuc\n")
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    dprint(a,b,c);
}