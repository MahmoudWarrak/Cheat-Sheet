// Same Basic BIT notes..
// You may have to compress the values and decompress them..

const int N = 1<<18 ; // ~= 1e5 ;

struct multiSet
{
    BIT bit;
    multiSet()
    {
        bit.init();
        bit.add(0, -1);
    }
    void insert(int val)
    {
        bit.add(val, 1);
    }
    void erase(int val)
    {
        bit.add(val, -1);
    }
    int count(int val)
    {
        return bit.get(val) - bit.get(val - 1);
    }
    int size()
    {
        return bit.get(N - 1) + 1;
    }
    int at(int ind)
    {
        return bit.find(ind);
    }
};

