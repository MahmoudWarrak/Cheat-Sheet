
{
    ld lo = MinVal , hi = MaxVal , mid ;
	ld ans = max( f(lo),f(hi) ) ;
 
        while ( hi-lo >= EPS ){
       		mid = (lo+hi)/2 ;
       		ld ans1 = f(mid) , ans2 = f(mid+EPS) ;
       	 	if( ans2 >= ans1 )
        		lo = mid ,ans = max ( ans , ans2 );
        	else
            		hi = mid ,ans = max ( ans , ans1 );
        }
        return ans ;
}
