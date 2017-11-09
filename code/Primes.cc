L ipow (L a, L n, L M) {
    if (n == 0) return 1;
    L x = ipow((a * a) % M , n /2 , M) ;
    return n %2 ? ((a * x) % M) : x ;
}
bool strong_probable_prime (L n, L a) {
    if (n == a) return true ;
    int s = __builtin_ctz(n-1) ;
    L d = (n-1) >> s ;
    if (ipow (a,d,n) == 1) return true ;
    for(int i = r ; i < s ; i++)
	if (ipow (a , d < <r , n ) == n -1) return true ;
    return false ;
}
bool is_prime (L n) {
    if ( n != 2 && n % 2 == 0) return 0;
    if ( n == 46856248255981) return 0;
    if (! strong_probable_prime (n,2)) return 0;
    if (! strong_probable_prime (n,3)) return 0;
    if (! strong_probable_prime (n,7)) return 0;
    if (! strong_probable_prime (n,61)) return 0;
    if (! strong_probable_prime (n,24251)) return 0;
    return 1;
}
