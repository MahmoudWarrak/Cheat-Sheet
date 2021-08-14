struct Data{
    //some data structure..
    //void add(int val) {}
    //void getAns() {}
};

int n , u , v , Val[N] , pa[N] , St[N] , Fi[N] , DfsOrd[N] , curtime , sz[N] ;
ll Ans[N] ;
void FlattenDfs( int u ){
    DfsOrd[ St[u] = curtime++ ] = u ;
    sz[u] = 1 ;
    for ( int e = Adj.head[u] ; ~e ; e = Adj.nxt[e] ){
        int v = Adj.to[e] ;
 
        if ( v == pa[u] )
            continue ;
        pa[v] = u ;
        FlattenDfs(v) ;
        sz[u] += sz[v] ;
    }
    Fi[u] = curtime-1 ;
}
void Extend( Data &temp , int u ){
    for ( int i = St[u] ; i <= Fi[u] ; i++ ){
        //put the children in the subtree of their parent.
        int v = DfsOrd[i] ;// get the order..
        temp.add(Val[v]) ;
    }
}
 
Data SmallToLarge( int u ){
    Data Tmp ;
    int large = -1 ;
    for ( int e = Adj.head[u] ; ~e ; e = Adj.nxt[e] ){
        int v = Adj.to[e] ;
        if ( pa[u] == v )
            continue ;
        if ( sz[v]*2 >= sz[u] ){
            large = v ;
            Tmp = SmallToLarge(large) ;
            continue ;
        }
        SmallToLarge(v) ;
    }
 
    Tmp.add(Val[u]) ;// put the value of node u in the subtree
    for ( int e = Adj.head[u] ; ~e ; e = Adj.nxt[e] ){
        int v = Adj.to[e] ;
        if ( pa[u] == v || large == v )
            continue ;
        Extend(Tmp , v) ;
    }
    Ans[u] = Tmp.getans() ;
    return Tmp ;
}
