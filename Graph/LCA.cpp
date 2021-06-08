// zero indexed..

const int N = 1e5 + 5, M = 1e5 + 5;
ll up[MAX][20] , depth[MAX] , dist[MAX][20] , cost[MAX] ;

struct ADJ {
    int head[N], nxt[M], to[M], ne ;

    void addEdge(int f, int t ,int cst ) {
        nxt[ne] = head[f];
        to[ne] = t;
        cost[ne] = cst ;
        head[f] = ne++;
    }

    void addBiEdge(int f , int t , int cst){
        addEdge(f, t , cst) ;
        addEdge(t, f , cst) ;
    }

    void init(int n) {
        memset(head, -1, n*(sizeof head[0]) );
        ne = 0;
    }

} adj;

void dfs(int u,int p ){
    for ( int e = adj.head[u] ; ~e ; e = adj.nxt[e] ){
        int v = adj.to[e] ;
        int c = cost[e] ;
        if( v == p )
            continue ;
        depth[v] = depth[u]+1 ;
        up[v][0] = u ;
        dist[v][0] = c ;
        dfs(v ,u );
    }
}
int lca(int x,int y){
    if( depth[x] < depth [y] )
        swap( x, y ) ;
    ll dif = depth[x] - depth[y] ;
    for ( int i = 18; ~i ; i-- ){
        if ( dif & (1<<i) )
            x = up[x][i] ;
    }
    if( x == y )
        return x ;

    for ( int i = 18 ; ~i ;i-- )
        if ( up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    return up[x][0];
}

int jump ( int x , int k ){
    for ( int i = 18 ; ~i ;i-- )
        if( k & (1<<i ))
            x = up[x][i] ;
    return x;
}

void build(){
    dfs(0,0);
    for ( int i = 1 ; i <= 18 ; i++ )
        for ( int j = 0 ; j < n ; j++ ){
            up[j][i] = up[ up[j][i-1] ][i-1] ;
            dist[j][i] = dist[j][i-1] + dist[ up[j][i-1] ][i-1] ;
        }
}

ll FindDist( ll x , ll y ){// return the cost edges between any two vertices..
    ll ans = 0 , mid = lca ( x,y )  ;
    ll dif1 = depth[x]-depth[mid] , dif2 = depth[y] - depth[mid];

    for ( int i = 18 ; ~i ; i -- ){
        if ( dif1 & (1<<i) ){
            ans += dist[x][i] ;
            x = up[x][i] ;
        }
        if ( dif2 & (1<<i) ){
            ans += dist[y][i] ;
            y = up[y][i] ;
        }
    }
    return ans ;
}

ll FindK( ll x , ll y , ll k ){// return the k-th vertex between x and y..
    ll mid = lca ( x , y ) ;
    if ( k <= depth[x] - depth[mid] +1 ){
        --k ;
        return jump( x , k ) ;
    }else{
        k -= depth[x] - depth[mid]+1 ;
        k = ( depth[y] - depth[mid]-k ) ;
        return jump(y,k) ;
    }
}
