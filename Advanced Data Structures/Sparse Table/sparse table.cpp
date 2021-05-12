const int MAX = 1<<18 , LG = 18 ;
ll n , q , a[MAX] , x ;
ll sp[LG][MAX] , lg[MAX] ;
map <ll,ll> ans ;

void Pre(){
    lg[0]= -1 ;
    for ( int i = 0 ; i < MAX-1 ; i++ ){
        sp[0][i] = a[i] ;
        lg[i+1] = lg[i] + !(i&(i+1)) ;
    }
}
void BuildSP(){
    Pre() ;
    for ( int j = 1 ; (1<<j) <= n ; j++ ){

        for ( int i = 0 ; i + (1<<j) <= n ; i ++ ){
            ll a = sp[j-1][i] ;
            ll b = sp[j-1][i+ (1<<(j-1)) ] ;
            sp[j][i] =  __gcd ( a,b ) ;
        }
    }

}
ll GetGcd( int L , int R ){
    ll sz = R-L+1;
    ll l = lg[sz] ;
    ll a = sp[l][L] ;
    ll b = sp[l][R-(1<<l)+1] ;
    return __gcd ( a, b ) ;
}
