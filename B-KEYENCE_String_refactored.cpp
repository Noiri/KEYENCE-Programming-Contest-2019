#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string key = "keyence";
    for(int i=0; i<=7; i++){
        //"keyence"を分離する
        string head = key.substr(0, i);
        string tail = key.substr(i, key.size()-i);
        //入力文字列をバースする
        string sHead = s.substr(0, i);
        string sTail = s.substr(s.size()-tail.size(), tail.size());
        if(sHead == head && sTail == tail){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}