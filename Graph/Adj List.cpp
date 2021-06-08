// check if there are costs on edges..
// check if you need to reset something else in init function..
// N equals maximum number of nodes..
// M equals maximum number of edges..

const int N = 1e5 + 5, M = 1e6 + 5;
//int cost[M] , dis[N];
struct ADJ {
    int n ,head[N], nxt[M], to[M], ne ;
    
    void addEdge(int f, int t /*,int cst */) {
        nxt[ne] = head[f];
        to[ne] = t;
//        cost[ne] = cst ;
        head[f] = ne++;
    }
    
    void addBiEdge(int f , int t ,/*int cst*/){
        addEdge(f, t /*, cst*/) ;
        addEdge(t, f /*, cst*/);
    }
    
    int addNode(){
        head[n]=-1;
        return n++;
    }
    
    void init(int n) {
//        this->n=n;
        memset(head, -1, n * sizeof head[0]);
//        memset(dis , 0x3f3f3f3f , n*(sizeof dis[0]) );
        ne = 0;
    }

};
