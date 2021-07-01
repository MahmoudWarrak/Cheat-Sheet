
ll FloorDiv(ll a , ll b) {
	if (a > 0) 
        return a / b;
	else if ( !(a % b) ) 
        return a / b ;
	else 
        return a / b - 1 ;
}
 
ll CeilDiv(ll a , ll b) {
    return (a + b - 1) / b;
}
