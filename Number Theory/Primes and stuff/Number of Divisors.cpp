const int MAX = 1e5+10 ;
ll divisnum[MAX] ;

void NumOfDivisors( int n ){
    divisnum[1] = 1 ;
    for ( int i = 2 ; i < n ; i++ ){
        divisnum[i] = 1 ;
        int x = i ;
        for ( int j = 2 ; j*j <= x ; j++ ){
            if( x%j )
                continue ;
            int c = 0 ;
            while( x%j==0 )
                x /= j , c++ ;
            divisnum[i] *= (c+1) ;
        }
        if( x!=1 )
            divisnum[i] *= 2 ;
    }
}
