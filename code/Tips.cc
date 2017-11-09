// change stack size, in bytes
#pragma comment(linker, "/STACK:33777216") // no spaces !

// regex
regex reg(R"[a-z]+");
string str("couCOU");
bool match = regex_match(str, reg);

// builtins
__gcd(x, y);
// for __builtin_*, add suffix l for long, ll for long long
__builtin_ffs(int);// 1 + least significant 1-bit
// __builtin_ffs(1010b) = 2
// __builtin_ffs(0) = -1
__builtin_clz(unsigned int) // number of leading 0-bits
// __builtin_clz(0..010100b) = 27
// __builtin_clz(0) is undefined
__builtin_ctz(unsigned int) // number of trailing 0-bits
// __builtin_ctz(0..010100b) = 2
// __builtin_ctz(0) is undefined
__builtin_popcount(int) // number of 1-bits
// __builtin_popcount(0110b) = 2
__builtin_parity(unsigned int) // number of 1-bits modulo 2

// desynchronise standard i/o
ios::sync_with_stdio(false);

// bits
// enumeratee subsets of mask
subset = mask;
do {
  // ...
  subset = (subset - 1) & mask;
} while(subset != mask);

// is x a power of 2 ?
!(x & (x-1))

// isolate least significant bit set to 1
x & (-x)

// enumerate permutation
sort(tabl, tabl+n);
do {
	//...
} while(next_permutation(tabl, tabl+n);

// liste doublement chainées :
list<type> l;
// push_front, push_back, pop_front, pop_back, insert, erase
// l.sort()
// fusion de deux listes triées : l.merge(l2)
// suppression des doubles consécutifs : l.unique();
// suppression des elements consecutifs satisfant un prédicat l.unique(pred) : pref(a, b) = true si b doit etre supprimé
// suppression de tous les elements égaux à v : l.remove(v)
// l.remove_if(pred)

// // Sprague-Grundy
// Pour une position : perdu => nimber = 0
// sinon, nimber minimal pas dans les
// positions suivantes
// Perdu <=> nimber = 0
// Sprague-Grundy
// : nimber(G + G') = nimber(G) xor nimber(G')
// // Burnside
// nb_orbites = sum_{g in G}(nb_points_fixes_de_g) / card(G)
