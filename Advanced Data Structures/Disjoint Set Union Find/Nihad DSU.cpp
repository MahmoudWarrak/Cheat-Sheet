struct num{ll l,r,i,sm,mx,mn;}d[200005];
int dsu(int x){
    if(d[x].i==x) return x;
    return d[x].i=dsu(d[x].i);
}
void join(int u,int v){
    u=dsu(u);
    v=dsu(v);
    if(u==v) R ;
    d[u].l=min(d[u].l,d[v].l);
    d[u].r=max(d[u].r,d[v].r);
    d[u].mn=min(d[u].mn,d[v].mn);
    d[u].mx=max(d[u].mx,d[v].mx);
    d[u].sm+=d[v].sm;
    d[v].i=u;
}
