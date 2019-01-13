#include <bits/stdc++.h>
using namespace std;

int n[10];

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a==0 || b==0 || c==0 || d == 0) cout << "NO" << endl;
    else if(a+b+c+d == 21) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
    
}