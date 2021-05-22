const int MAX = 1<<20 , LG = 20 ;

ll sum[MAX] ;
int l[MAX] , r[MAX] ,ans , n ;
ll sp[LG][MAX] , lg[MAX] ;
set <int> st ;
map<int,int> compress ,decompress ;
ll cnt ;

void Pre(){
    lg[0]= -1 ;
    for ( int i = 0 ; i < MAX-1 ; i++ ){
        sp[0][i] = sum[i] ;
        lg[i+1] = lg[i] + !(i&(i+1)) ;
    }
}
void BuildSP(){
    Pre() ;
    for ( int j = 1 ; (1<<j) <= cnt ; j++ ){

        for ( int i = 0 ; i + (1<<j) <= cnt ; i ++ ){
            ll a = sp[j-1][i] ;
            ll b = sp[j-1][i+ (1<<(j-1)) ] ;
            sp[j][i] =  min ( a,b ) ;
        }
    }

}

ll getmin ( int L , int R ){
    ll sz = R-L+1;
    ll l = lg[sz] ;
    ll a = sp[l][L] ;
    ll b = sp[l][R-(1<<l)+1] ;
    return min ( a, b ) ;
}
