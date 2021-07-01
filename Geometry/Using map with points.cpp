template<typename T> struct les {};
 
template<typename T>
struct les<complex<T> >
{
    bool operator()(complex<T> const& a,complex<T> const& b)
    {
        return make_pair(a.real(),a.imag()) < make_pair(b.real(),b.imag());
    }
};
map < point , ll , les<point > > mp ;
