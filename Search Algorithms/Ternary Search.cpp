
	ll lo = 0 , hi = n-1 , mid ; 
	ll ans = min( f(lo),f(hi) ) ;
 
        while ( hi-lo > 1 ){
        mid = (lo+hi)/2 ;
        ll ans1 = f(mid) , ans2 = f(mid+1) ;
        if( ans1 > ans2 )
            lo = mid ,ans = min ( ans , ans2 );
        else
            hi = mid ,ans = min ( ans , ans1 );
        }
