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
