typedef long long ll;

const int N = 1e5 + 5;

typedef pair<int, int> stData;

struct monoStack
{
    stack<pair<stData, stData> > st;
    monoStack()
    {
        st.emplace(make_pair(INT_MIN, INT_MIN), make_pair(INT_MIN, INT_MIN));
    }
    void push(stData x)
    {
        st.emplace(x, ::max(x, st.top().S));
    }
    void pop()
    {
        st.pop();
    }
    stData top()
    {
        return st.top().F;
    }
    stData max()
    {
        return st.top().S;
    }
    int size()
    {
        return st.size() - 1;
    }
    bool empty()
    {
        return st.size() == 1;
    }
};

struct monoQueue
{
    monoStack add, rem;
    void push(stData x)
    {
        add.push(x);
    }
    void pop()
    {
        if(rem.empty()) move();
        rem.pop();
    }
    stData top()
    {
        if(rem.empty()) move();
        return rem.top();
    }
    stData max()
    {
        return ::max(add.max(), rem.max());
    }
    int size()
    {
        return add.size() + rem.size();
    }
    bool empty()
    {
        return !size();
    }
    void move()
    {
        while(add.size())
        {
            rem.push(add.top());
            add.pop();
        }
    }
};

struct myStack
{
    stack<pair<int, int> > st;
    int push(pair<int, int> x)
    {
        while(st.size() and st.top().F >= x.F) st.pop();
        int ret = st.size() ? st.top().S : -1;
        st.push(x);
        return ret;
    }
};
