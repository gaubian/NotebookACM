// Compte les inversions dans un tableau à l'aide du tri fusion
// renvoie le nombre total, et rempli rep pour le nombre d'inversion comprenant
// chaque élement (à droite) -> permet de compter le nombre de triplet inversion
// COMPLEXITY: n log n
// pair.first: valeur de la case
// pair.second: indice dans le tableau initialement (rep est rempli en fonction)
PII tmp[100001]; // tableau temporaire
int rep[100001]; // réponse (doit être initialisé à 0)
void fusion(PII *s1, PII *e1, PII *s2, PII *e2) {
  PII *start = s1, *end = e2;
  PII *p = tmp;
  while(s1 < e1 && s2 < e2) {
    if((inv && s2->first < s1->first) || (!inv && s2->first > s1->first)) {
      rep[s2->second] += e1-s1;
      *p = *s2; p++; s2++;
    }
    else
      *p = *s1; p++; s1++;
  }
  while(s1 < e1) *p = *s1; p++; s1++;
  while(s2 < e2) *p = *s2; p++; s2++;
  for(int i = 0; i < end-start; i++) // TODO memcpy ?
    start[i] = tmp[i];
}
// s: début du tableau (inclu), e: fin (exclu)
int count_inv(PII *s, PII *e) {
  if(s == e)
    return;
  if(s + 1 == e)
    return;
  size_t seg = (e-s)/2;
  int rep = count_inv(s, s+seg) + count_inv(s+seg, e);
  rep += fusion(s, s+seg, s+seg, e);
  return rep;
}
