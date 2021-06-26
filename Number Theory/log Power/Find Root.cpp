ll FindRoot( ll x ){
    ll lo = 0 , hi = 1e10 , mid ;
    while ( lo < hi-1 ){
        mid = lo+hi>>1 ;
        if ( mid * mid > x )
            hi = mid ;
        else
            lo = mid ;
    }
    return lo ;
}
