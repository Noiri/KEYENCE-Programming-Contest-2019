#include <bits/stdc++.h>
using namespace std;

bool n[10];

int main(){
    for(int i=0; i<4; i++){
        int a;
        cin >> a;
        n[a] = true;
    }
    if(n[1]&&n[7]&&n[9]&&n[4]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}