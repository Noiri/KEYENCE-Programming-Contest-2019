#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<int> c(n);
    ll re = 0;
    for(int i=0; i<n; i++){
        c[i] = a[i] - b[i];
        if(c[i] < 0){
            re += abs(c[i]);
            ans++;
        } 
    }
    sort(c.rbegin(), c.rend());
    for(int i=0; i<n; i++){
        if(c[i] > 0 && re > 0){
            re -= c[i];
            ans++;
        }
        else{
            break;
        }
    }
    if(re > 0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}