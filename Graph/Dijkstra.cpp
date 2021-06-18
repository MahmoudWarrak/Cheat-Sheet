typedef pair<ll, ll>        pll;

const int N = 1e5 + 5, M = 1e6 + 5;
ll cost[M] , dis[N];
struct ADJ {
    int head[N], nxt[M], to[M], ne ;

    void addEdge(int f, int t, int cst ) {
        nxt[ne] = head[f];
        to[ne] = t;
        cost[ne] = cst ;
        head[f] = ne++;
    }

    void addBiEdge(int f , int t ,int cst){
        addEdge(f, t ,cst) ;
        addEdge(t, f ,cst);
    }

    void init(int n) {
        memset(head, -1, n * sizeof head[0]);
        memset ( dis , 0x3f3f3f3f , n*(sizeof dis[0]) ) ;
        ne = 0;
    }

}adj;

ll Dij ( int src ){
    priority_queue<pll> pq;
    dis[src] = 0 ;
    pq.push({0,src}) ;
    while ( !pq.empty() ){
        int u = pq.top().S , dst = -pq.top().F ;
        pq.pop() ;

        if ( u == to )
            break ;
        if ( dst != dis[u] )
            continue ;

        for ( int e = adj.head[u] ; ~e ; e = adj.nxt[e] ){
            int v = adj.to[e] ;
            ll c = cost[e] ;
            if ( dst + c < dis[v] ){
                dis[v] = dst+c ;
                pq.push({-dis[v] , v }) ;
            }
        }
    }
    return ( dis[to] < 0x3f3f3f3f ? dis[to] : -1 ) ;
}
