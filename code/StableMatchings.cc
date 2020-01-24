// Stable matching for N boys and N girls. Boys are numbered as 0 to 
// N-1. Girls are numbereed as N to 2N-1. Returns the list of preferences
// of **girls**

bool prefersM1(vector<vector<int>> prefer, int w, int m, int m1, int N){
    for (int i = 0; i < N; i++) { 
        if (prefer[w][i] == m1) 
            return true; 
        if (prefer[w][i] == m) 
           return false; 
    } 
} 
  
vector<int> stableMarriage(vector<vector<int>> &prefer) {
    int N = prefer.size() / 2;	
    vector<int> wPartner(N,-1); 
    bool mFree[N]; 
    memset(mFree, false, sizeof(mFree)); 
    int freeCount = N; 
  
    while (freeCount > 0) { 
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == false) 
                break; 
        for (int i = 0; i < N && mFree[m] == false; i++) { 
            int w = prefer[m][i]; 
            if (wPartner[w-N] == -1) { 
                wPartner[w-N] = m; 
                mFree[m] = true; 
                freeCount--; 
            } 
            else { 
                int m1 = wPartner[w-N]; 
                if (prefersM1(prefer, w, m, m1, N) == false) { 
                    wPartner[w-N] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } 
        } 
    } 
    return wPartner;
} 
  
int main() { 
    vector<vector<int>> prefer = { {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    }; 
    auto wPartner = stableMarriage(prefer); // 2, 1, 3, 0
} 
