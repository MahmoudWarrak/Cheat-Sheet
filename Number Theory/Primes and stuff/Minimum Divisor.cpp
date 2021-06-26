const int MAX = 2e6 + 10;
vector <int> prime;
int IsComposite[MAX];
int LeastDivisor [MAX] ;

void LinearSieve (int n) {
	memset ( IsComposite , 0 , sizeof IsComposite ) ;
	for ( int i = 2 ; i < n ; ++i ) {
		if ( !IsComposite[i] )
            prime.push_back (i) ;
		for ( int j = 0 ; j < prime.size () && i * prime[j] < n ; ++j ) {
			IsComposite [i * prime[j]] = i ;
			if ( !( i % prime[j] ) )
                break ;
		}
	}
	LeastDivisor[0] = LeastDivisor[1] = 1 ;
	for ( int i = 2 ; i < n ; i++ ){
        if ( !IsComposite[i] )
            LeastDivisor[i] = i ;
        else
            LeastDivisor[i] = i/IsComposite[i] ;
	}

}
