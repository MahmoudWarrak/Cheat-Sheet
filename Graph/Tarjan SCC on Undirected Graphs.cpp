// BiEdges have to be consecutive!!
 
const int N = 1e4 + 5, M = 1e5 + 5;
int n;

struct ADJ {
    int n, head[N], nxt[M], to[M], ne;

    void addEdge(int f, int t) {
        nxt[ne] = head[f];
        to[ne] = t;
        head[f] = ne++;
    }

    void addBiEdge(int f, int t){
        addEdge(f,t);
        addEdge(t,f);
    }

    int addNode(){
        head[n] = -1 ;
        return n++;
    }
    void init(int n) {
        this->n = n ;
        memset(head, -1, n * sizeof head[0]);
        ne = 0 ;
    }

} adj, comps;

int vis[N], vid, stk[N], stkSz, ncp,isArt[N],isBridge[M],lw[N],dfsTime[N], curTime;

void tarjanDFS(int u, int pe) {
    vis[u] = vid;
    stk[stkSz++] = u;
    lw[u] = dfsTime[u] = curTime++ ;
    for ( int e=adj.head[u] ; ~e ; e=adj.nxt[e] ){
        if( e == pe )
          continue ;
        int v = adj.to[e] ;
        if ( vis[v] != vid){
            tarjanDFS ( v , e^1 ) ;
            lw[u] = min ( lw[u] , lw[v] ) ;
          
            if ( lw[v] >= dfsTime[u] ){
                if( ~pe || dfsTime[v] > dfsTime[u]+1 )
                    isArt[u] = vid ;
                int id = comps.addNode() ;
                comps.addEdge ( id , u ) ;
                do {
                    comps.addEdge ( id , stk[--stkSz] ) ;
                }while ( stk[stkSz] != v ) ;

            }
            if ( lw[v] > dfsTime[u] ) {
                isBridge[e] = isBridge[e^1] = vid ;
            }

        }else{
            lw[u] = min( lw[u] , dfsTime[v] ) ;
        }
    }
}

void T() {
    ++vid ;
    comps.init(0);
    ncp = 0 ;
    curTime = 0 ;
    for ( int i = 0 ; i < n ; ++i )
        if ( vis[i] != vid ){
            stkSz = 0 ;
            tarjanDFS ( i , -1 ) ;
            if(!(~adj.head[i]))
              comps.addEdge ( comps.addNode() , i ) ;
        }

}
