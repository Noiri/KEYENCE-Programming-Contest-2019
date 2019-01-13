#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    //keyence?
    string t = "keyence";
    bool flag = false;
    for(int i=0; i<s.size()-6; i++){
        string sub = s.substr(i, 7);
        if(t == sub){
            string head = s.substr(0, i);
            string tail = s.substr(i+7, s.size()-7);
            if(head == "" && tail != "") flag = true;
            else if(head != "" && tail == "") flag = true;
            else if(head == "" && head == "") flag = true;
        }
    }
    if(flag){
        cout << "YES" << endl;
        return 0;
    }

    for(int i=1; i<7; i++){
        string head = t.substr(0, i);
        string tail = t.substr(i, 7);
        string H = s.substr(0, i);
        string T = s.substr(s.size()-tail.size(), tail.size());
        if(head == H && tail == T){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}