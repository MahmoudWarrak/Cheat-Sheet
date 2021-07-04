point FindYthCoordinate ( point &a , point &b , ld x ){
    point ret ;
//    y = mx - mx0 + y0
    pair<ld,ld> tmp ;
    tmp = slope(a,b) ;
    ld m = tmp.F/tmp.S ;
    ld y = m*x - m*a.X + a.Y ;
    return ret = {x,y} ;
}
