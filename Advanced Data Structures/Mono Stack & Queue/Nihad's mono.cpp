struct monotonicStack{
    stack<pair<ll,ll> > stk;
    void push(ll x){ stk.emplace(x,max(x,getMax())); }
    void pop(){ stk.pop(); }
    ll top(){ return stk.top().first; }
    bool empty(){ return stk.empty(); }
    ll size(){ return stk.size(); }
    ll getMax(){
        if(stk.empty()) return -1e15;
        return stk.top().second;
    }
};
struct monotonicQueue{
    monotonicStack psh,pp;
    void push(ll x) { psh.push(x); }
    void pop(){
        move();
        pp.pop();
    }
    ll top(){
        move();
        return pp.top();
    }
    void clear(){
        while(psh.size()) psh.pop();
        while(pp.size())  pp.pop();
    }
    ll size(){ return psh.size()+pp.size(); }
    bool empty(){ return psh.empty()&&pp.empty(); }
    ll getMax(){ return max(psh.getMax(),pp.getMax()); }
    void move(){
        if(pp.empty())
            while(psh.size()){
                pp.push(psh.top());
                psh.pop();
            }
    }
}q;
