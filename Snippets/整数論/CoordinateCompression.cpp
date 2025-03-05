//座圧した状態から実際の面積を求めるときは、各軸ごとに求めて掛け算する。座圧したi番目を見てるなら、[i+1]-[i]が答え。[i]=3,[i+1]=4なら=1で、つまり[[i],[i+1])の区間に存在するマスを求めているといえる
template<typename T = ll>
struct CC {//座圧用 CC<ll>y,x;(二次元座標の圧縮は軸事に別々に持つので注意)
    bool initialized;//sortとeraseをしたか？というbool(add以外の関数とかの呼び出しがされたら見る)
    vector<T> xs;
    CC() : initialized(false) {}//定義されたらfalseにしておく
    void add(T x) { xs.push_back(x); }//座圧用の配列に追加する(initしてからaddをしてもそれは座圧されてないので注意) 空白が欲しいならnfor(k,-1,2)みたいにしてcc.add(i+k)とやればいい
    void init() {//座圧用配列とかの初期化を行う
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        initialized = true;
    }
    ll operator()(T x) {//()が座圧化。座圧するという関数だと思えばいい
        if (!initialized) init();
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;//upperして-1している、uniqueしてeraseだからlowerでもいいと思う。ここをupperにしてるおかげでABC374-FはACできている、revみたいなmapだと未定義のやつを見ると壊れるけどupperだから許される。毎回O(logN)くらいかけていいのか？と思ったけど俺のmpも同じだった。10^18とかの数字があると配列にもてないからこればかりはどうしようもない
    }
    T operator[](ll i) {//[]が元に戻す。配列に対する添え字というかインデックスだと思えばいい。つまり番号を渡して実際の値を回収するみたいな。
        if (!initialized) init();
        return xs[i];
    }
    ll size() {//座圧後の配列サイズを返す
        if (!initialized) init();
        return xs.size();
    }
};

void solve() {
    //とりあえず全てx以下として考えてみる
    //x以下のみにする方法は...しらん
    //少なくとも長さ1は保証される

    //開始時点でのLISはいけそうじゃない...?
    //セグ木版のLISも視野に入れた方がいいかもしれない
    //そこをけつとするLISにおいて、minの値とか格納できそうだし
    //セグ木のLISは座圧して扱う、答えが1以上なのが怪しすぎる、伝票のやつみたいにlowerで殴って良さそうだな
    //まず、セグ木のLISで求められるのは
    //seg[i][j]=i番目まで見た時に、実際の数字jがケツになるLISの最大の長さ
    
    //で、クエリを先読みして、[0,i)のiを昇順のやつで管理すればセグ木でLISするのに従って答えを求められそう
    
    ll n, q;
    cin >> n >> q;
    vl a(n);
    cin >> a;

    CC c;

    rep(i, n)c.add(a[i]);


    vv<P> query(n+1);//(x,番号)
    rep(qi, q) {
        ll r, x;
        cin >> r >> x;
        c.add(x);
        query[r].eb(x, qi);
    }
    vl ans(q);

    rep(i, n)a[i] = c(a[i]);
    ll sz = c.size();

    segtree<ll, op, e>seg(sz + 1);
    
    rrep(i, n) {
        //とりあえずセグ木更新
        ll wide = seg.prod(0, a[i-1]);// [0,a[i])の範囲から値を貰う、平面走査してるので、各自分より小さい値の後ろに今見てるa[i]の値を追加することができる、なのでそれで作れる最大の長さは、max+1
        seg.set(a[i-1], wide + 1);//セグ木に更新する、座圧した値を配列の引数？キー？[i]?みたいにしてるので、t.set(i,wide+1)ではないので注意
        
        for (auto [x, qi] : query[i]) {
            x = c(x);
            ans[qi] = seg.prod(0, x + 1);
        }
    }
    vc_cout(ans);

    return;
}

int main() {
    solve();
}