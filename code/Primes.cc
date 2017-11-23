using L = __uint128_t;

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
    for(int r = 0 ; r < s ; ++r)
	if (ipow (a , d << r , n ) == n -1) return true ;
    return false ;
}

bool is_prime (L n) {
    return ( n == 2 || n % 2 != 0) && (n != 46856248255981) &&
    (strong_probable_prime (n,2)) && (strong_probable_prime (n,3)) &&
    (strong_probable_prime (n,7)) && (strong_probable_prime (n,61)) &&
    (strong_probable_prime (n,24251));
}
