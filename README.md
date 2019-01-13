
# Keyence参戦記
## A問題(Beginning)
解法をいつくか思いついてしまい、頭がこんがらがってしまった。こういった時の取捨選択の速度を鍛えていかないといけないと感じた。結局、頭を使う方の解法を選んでしまった。シンプルな解法を洗濯できなかったのが悔しかった。
### 解法１(採用)
1以上の数字の和は、一意に定まるということを利用した。この場合、入力が一つでも0だとNGなのでそこの条件文を書かなければいけないのがネックである。また、入力を配列で受け取った場合、ネックである条件文を短く書くことができるが、「わざわざ、for文書く...?」みたいに思ってしまったのでやらなかった。
```cpp
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
```
### 解法2(こっちのがスッキリしている)
バケットで管理して、値が出現してるかどうか調べる
```cpp
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
```

## B問題(KEYENCE String)
条件に合致するパターンが３つに分けることが出来るのには気づいた。substrの使用に不慣れだったので、途中で何度かプリントデバックを挟んだため、ロスってしまった。しかし、実戦でsubstrを利用できたので、これに関しては進歩だと言える。
文字列に関する実装問題が弱い気がするので、練習しておく必要があると感じた。
書いたコードについては、思考をまとめきれず、非効率的なコードを書いてしまった感が否めない。
### 解法
まず、"keyence"を前半と後半に分けることを考える。前半部分をhead, 後半部分をtailとする。
```
例
head = "key"
tail = "ence"
```
次に入力文字列の頭と尻尾を作成する。頭:sHeadは、入力文字列の先頭からhead.size()だけ取り出したものである。
尻尾：sTailは、入力文字列の末尾からtail.size()だけ取り出したものである。
`head == sHead && tail == sTail`が`true`であれば、keyence文字列であり、`YES`を出力する。



### 提出コード
```cpp
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
```
### 競技終了後にリファクタリングしたもの
`substr(hoge, 7)`のように末尾を超えた位置を指定して強制的に末尾まで指定していたが、ぴったり末尾を指すように改善した。
次に、競技中に書いたコードでは場合1,2と場合3を分離して書いていたが、すべてまとめて書いたことにより、かなり短く書けた。
```cpp
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
```

## C問題(Exam and Wizard)
とても素直な問題だと感じた。実装中に`A-B`とするところを`B-A`としてしまったのは、ちょっと悔しかった。実行して結果を見たときに一瞬で気づいたので成績に影響はなかったが、落ち着いて実装できるようになると良いと感じた。
### 解法
まず、`B > A`の項は、必ず書き換える必要がある。該当する”足りない項”に加える必要がある値の総和を`Require`の意味で`re`とする。
点数を引っ張ってくる先は、`A > B`を満たす項の中で、`A - B`が大きい順に選べば良い。

実装の方針として、`c = a - b`として、配列`c`をソートすれば良い。
```cpp
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
```

## D問題(Double Landscape)
### 競技中
残った時間で考えたが、処理する内容が多すぎて困った。意外と束縛条件が多いので、そこを突く方向性だと思ったが、まとまらなかった。DPぽい？と思った。
### 解説読んだ後
全然、DPじゃなかった。
しっかり考察を重ねる系の問題だった。かなり悔しいやつ。
過去の負債か、こういった場合の数をテーマにした問題に弱いので、勉強する必要がありそう。

## 総括
- A問題は、取捨選択ができずにロスってしまった。
- B問題は、仕方ない気がした。やはり、文字列の扱い弱いなと感じた。
- C問題は、意外とすんなり解けたと感じたが、解くのに20分以上かかっててびびった。こういう素直な問題の、素直な実装を正確に、早く実装できるようになるのが大事だと感じた。
- D問題をやった感想としては、「場合の数、弱いな」という感じ。しかし、これの前に塞ぐべき穴があるので、後回し。

振り返った感じ、難しい問題に着手するよりも、標準的な問題を継続的に解き続けるのが大事だと感じた。
標準的な問題を大量に解いて、解法の取捨選択、シンプルなコーディングを身に付けるのが、ワンランク上の問題に挑戦するのに必要だと感じる。

最後に、実際に使用する段になって、リソースを喰われると応用ができないので、典型的なテクニックや便利関数（深さ優先探索、幅優先探索、累積和、しゃくとり法、substr）を定期的に書いてみる必要があると感じた。

**お疲れ様でした！**
