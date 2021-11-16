    int m1 = p[i].Y-p[j].Y ;
    int m2 = p[i].X - p[j].X ;
    int g  = __gcd(m1, m2);
    m1 /= g ;
    m2 /= g ;
    if(m1<0){
        m1 *= -1 ;
        m2 *= -1 ;
    }
    int b = m2*p[i].Y - m1*p[i].X ;
    st.insert({b,{m1,m2}}) ;


    ll dx = x2 - x1 ;
    ll dy = y2 - y11 ;
    ll gcd = __gcd ( dx , dy ) ;
    dx /= gcd ;
    dy /= gcd ;
    if ( dx < 0 ){
        dx =- dx ;
        dy =- dy ;
    }
    if ( dx ){
        ll nx = (x1%dx+dx)%dx ;
        ll ny = y11+(nx-x1)/dx*dy ;
        if ( !st.count({dx,dy,nx,ny}) ){
            ans += mp[{-dy,dx}] ;
            ans += mp[{dy,-dx}] ;
            mp[{dx,dy}] ++ ;

            st.insert({dx,dy,nx,ny}) ;
        }
    }
    else{
        if ( !amodi.count(x1) ){
            ans += mp[{-dy,dx}] ;
            ans += mp[{dy,-dx}] ;
            mp[{dx,dy}]++ ;
            amodi.insert(x1) ;
        }
    }
