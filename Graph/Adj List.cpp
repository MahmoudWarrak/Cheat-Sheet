// check if there is cost for the edges..
// check if you need to reset something else in init function..
// N equals maximum number of nodes..
// M equals maximum number of edges..

const int N = 1e5 + 5, M = 1e6 + 5;

struct ADJ {
    int head[N], nxt[M], to[M], ne;// cost[M] 
    
    void addEdge(int f, int t/*int cst */) {
        nxt[ne] = head[f];
        to[ne] = t;
//      cost[ne] = cst ;
        head[f] = ne++;
    }
    
    void addBiEdge(int f , int t ,/*int cst*/){
        addEdge(f, t ,/* cst*/) ;
        addEdge(t, f ,/* cst*/);
    }
    
    void init(int n) {
        memset(head, -1, n * sizeof head[0]);
        ne = 0;
    }

};
