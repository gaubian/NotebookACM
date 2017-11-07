// INTERSECTION DE DEMI-PLAN
// demi-plan : à gauche de la ligne
struct Line {
  PT P;    // point
  PT v;   // vecteur directeur
  double ang;
  Line() {}
  Line(PT P, PT v):P(P),v(v){ ang = atan2(v.y, v.x); }
  bool operator < (const Line& L) const {
    return ang < L.ang;
  }
};
bool OnLeft(const Line& L, const PT& p) {
  return cross(L.v, p-L.P) > 0;
}
PT GetLineIntersection(const Line& a, const Line& b) {
  return ComputeLineIntersection(a.P, a.P+a.v, b.P, b.P+b.v);
}
// INPUT : set of half-plane
// OUPUT : polygon (if exists)
// COMPLEXITY n log n ?
vector<PT> HalfplaneIntersection(vector<Line> L) {
  int n = L.size();
  sort(L.begin(), L.end());
  int first, last;
  vector<PT> p(n);
  vector<Line> q(n);
  vector<PT> ans;
  q[first=last=0] = L[0];
  for(int i = 1; i < n; i++) {
    while(first < last && !OnLeft(L[i], p[last-1])) last--;
    while(first < last && !OnLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if(fabs(cross(q[last].v, q[last-1].v)) < EPS) {
      last--;
      if(OnLeft(q[last], L[i].P)) q[last] = L[i];
    }
    if(first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]);
  }
  while(first < last && !OnLeft(q[first], p[last-1])) last--;
  if(last - first <= 1) return ans;
  p[last] = GetLineIntersection(q[last], q[first]);
  for(int i = first; i <= last; i++) ans.push_back(p[i]);
  return ans;
}
