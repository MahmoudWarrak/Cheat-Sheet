// Remember to check if you need long long. 
// Remember to make N equals power of twos.
// You may need another functions, build 'em all.

const int N = 1<<18 ; // ~= 1e5 ;
struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
    int find(int t)
    {
        int st = 0;
        for(int sz = N >> 1 ; sz ; sz >>= 1)
        {
            if(tree[st + sz - 1] < t)
            {
                t -= tree[(st += sz) - 1];
            }
        }
        return st;
    }
};

