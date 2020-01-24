
const int NMAX=1e5+1;
int visite[NMAX];
vector<int> listeAdj[NMAX];
int id=1;
int p[NMAX];
vector<int> adjCentroides[NMAX];
int t[NMAX];
int res=-1;

void centroide(int u,int& n) {
    t[u]=1;
    visite[u]=id;
    int maxBranche=0;
    for(auto v:listeAdj[u])
        if(visite[v]!=id&&visite[v]!=-1)
        {
            centroide(v,n);
            t[u]+=t[v];
            maxBranche=max(maxBranche,t[v]);
        }
    if(n-t[u]<=n/2&&maxBranche<=n/2)
        res=u;
}

void decomposition(int depart,int parent,int n) {
    centroide(depart,n); id++;
    int fils=res;
    visite[fils]=-1;
    p[fils]=parent;
    if(p!=-1)
    	adjCentroides[parent].push_back(fils);
    for(auto v:listeAdj[fils])
        if(visite[v]!=-1) {
            if(t[v]<=n/2)
                decomposition(v,fils,t[v]);
            else
                decomposition(v,fils,n-t[fils]);
        }
}
