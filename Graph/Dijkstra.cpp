
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
