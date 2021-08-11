const int MAX = 1e5+10 ;
const int MOD = 1e9+7 ;
ll fact[MAX], inv[MAX] ;

ll FastPower( ll x , ll n )
{
    ll ret = 1 ;
    while(n)
    {
        if( n&1 )
            ret = ret*x %MOD ;
        x = (x*x)%MOD ;
        n >>= 1 ;
    }
    return ret ;
}

ll ModInverse( ll x ){
    return FastPower ( x , MOD-2) ;
}

void Fac( )
{
    fact[0] = 1, inv[0] = 1 ;
    for( int i = 1 ; i < MAX ; i ++ ){
        fact[i] = ( fact[i-1] * i ) % MOD ;
        inv[i] = ModInverse ( fact[i] ) ;
    }
}
