// stable marriage O(n2)
int L, R;
int L_pref[MAX_L][MAX_R], R_rank[MAX_R][MAX_L];
int L2R[MAX_L], R2L[MAX_R];
int p[MAX_L]; // id of the best R in L_pref the l can get
void stable_marriage () {
  fill_n(R2L, R, -1);
  fill_n(p, L, 0);
  for (int i = 0; i < L; i++)
    for (int l = i; l >= 0;) {
      int r = L_pref[l][p[l]++];
      if (R2L[r] < 0 || R_rank[r][l] < R_rank[r][R2L[r]]) {
        int old_l = R2L[r];
        R2L[L2R[l] = r] = l;
        l = old_l;
      }
    }
}

// hospital resident (mariage stable polygame) O(n2)
/*
RO : needed for Resident -Oriented version
HO : needed for Hospital -Oriented version
*/
// Input data
int R, H; // Number of Residents/Hospitals
int C[MAX_H]; // Capacity of hospitals
vector <int > R_pref[MAX_R], H_pref[MAX_H]; // Preferences : adjency lists
/*RO*/int H_rank[MAX_H][MAX_R]; // Rank : rank of r in H_pref[h]
/*HO*/int R_rank[MAX_R][MAX_H]; // Rank : rank of h in R_pref[r]
// Internal data
int RankWorst[MAX_H]; // Rank of the worst r taken by h
/*RO*/int BestH[MAX_R]; // Indice of the best h in R_pref the r can get
/*HO*/int BestR[MAX_H]; // Indice of the best r in H_pref the h can get
int Size[MAX_H]; // Number of residents taken by h
// Output data
int M[MAX_R];
void stable_hospitals_RO () {
  for (int h = 0; h < H; h++)
    RankWorst[h] = H_pref[h].size() - 1;
  fill_n(BestH, R, 0);
  fill_n(Size, H, 0);
  fill_n(M, R, INF);
  for (int i = 0; i < R; i++)
    for (int r = i; r >= 0;) {
      if (BestH[r] == int(R_pref[r].size()))
        break;
      const int h = R_pref[r][BestH[r]++];
      if (Size[h]++ < C[h]) {
        M[r] = h;
        break;
      }
      int WorstR = H_pref[h][RankWorst[h]];
      while (WorstR == INF || M[WorstR] != h) // Compute the worst
        WorstR = H_pref[h][--RankWorst[h]];
      if (H_rank[h][r] < RankWorst[h]) { // Ranked better that worst
        M[r] = h;
        M[r = WorstR] = INF; // We have eliminated it, he need to put it somewhere
      }
    }
}
void stable_hospitals_HO () {
  fill_n(BestR, H, 0);
  fill_n(Size, H, 0);
  fill_n(M, R, INF);
  VI SH;
  for (int h = 0; h < H; h++)
    SH.push_back(h);
  while (!SH.empty()) {
    int h = SH.back();
    if (Size[h] == C[h] || BestR[h] == int(H_pref[h].size())) { // Full or no r
// available
      SH.pop_back();
      break;
    }
    const int r = H_pref[h][BestR[h]++];
// r is unassigned or prefer h to current hospital
    if (M[r] == INF || R_rank[r][h] < R_rank[r][M[r]]) {
      Size[h]++;
      if (Size[h] == C[h]) // Will be full
        SH.pop_back();
      if (M[r] != INF) { // Delete from M[r]
        Size[M[r]]--;
        SH.push_back(M[r]);
      }
      M[r] = h;
    }
  }
}

// stable roomate (mariage stable homosexuel) O(n2)
const int MAX_N = 1000;
int N; // Entree : Nombre de colocataires
int M[MAX_N][MAX_N]; // Entree : Liste de preferences de chaque colocataire
int rank[MAX_N][MAX_N];
int pos[MAX_N][3]; // Positions of left -most , second , right -most
int found[MAX_N];
int Match[MAX_N]; // Sortie : Matching recherche
bool Matching () {
// Phase 1
  for (int i = 0; i < N; i++) {
    M[i][N - 1] = i; // Sentinel
    for (int j = 0; j < N; j++)
      rank[i][M[i][j]] = j;
    pos[i][0] = 0;
    pos[i][2] = N - 1;
  }
  for (int p = 0; p < N; p++) {
    int next, current, prop = p;
    do {
      next = M[prop][pos[prop][0]];// next to propose to
      current = M[next][pos[next][2]];// next has proposition from
      // next is better with current:
      while (rank[next][prop] > rank[next][current]) {
        pos[prop][0]++;   // Let ’s try the next one
        next = M[prop][pos[prop][0]];
        current = M[next][pos[next][2]];
      }
      pos[next][2] = rank[next][prop];// Update data
      prop = current;// This one just loose its proposal
    }
    while (current != next);// next was associated with current , ie himself
  }
  for (int i = 0; i < N; i++)
    pos[i][1] = pos[i][0] + 1;
  // Phase 2
  vector <int> path;
  fill_n(found, N, -1);
  for (int i = 0; i < N; i++) {
    path.push_back(i);
    while (!path.empty()) {
      int p = path.back(), size;
      if (pos[p][0] == pos[p][2]) {
        const int q = M[p][pos[p][0]];
        Match[Match[q] = p] = q;
        path.pop_back();
        continue;
      }
      found[p] = -1; // Force exploration (might be != -1 from before)
      while (found[p] == -1) { // Find cycle
        found[p] = path.size(); // Register it
        int nd = M[p][pos[p][1]]; // Second
        while (pos[nd][2] < rank[nd][p])
          nd = M[p][++pos[p][1]];
        path.push_back(p = M[nd][pos[nd][2]]);
      }
      for (int i = size = found[p]; i < (int) path.size(); i++) {
        found[p = path[i]] = -1;
        pos[p][0] = pos[p][1]++; // p refuses it’s first proposal
        const int q = M[p][pos[p][0]];
        pos[q][2] = rank[q][p]; // Propagate association
        if (pos[q][0] > pos[q][2]) // No solution
          return false;
      }
      path.resize(size - 1); // 1 5 4 [2 3 4] ==> found[p] = 3 ==> 1 5
    }
  }
  return true;
}
