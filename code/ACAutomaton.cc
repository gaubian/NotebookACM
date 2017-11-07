// How many Pi are in T ?
// COMPLEXITY: linear
// USAGE: call init, insert to create dictionnary (strings are copied), and query
const int MAXN = 500010;
const int Alphabet = 26;
struct Trie {
  int next[MAXN][Alphabet],fail[MAXN],end[MAXN];
  int root, L;
  int newnode() {
    for (int i=0; i<Alphabet; i++) next[L][i] = -1;
    end[L++] = 0;
    return L-1;
  }
  void init() {
    L=0;
    root = newnode();
  }
  void insert(const char buf[]) {
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (next[now][buf[i] - 'a'] == -1)
        next[now][buf[i] - 'a'] = newnode();
        now = next[now][buf[i] - 'a'];
    }
    end[now]++;
  }
  void build() {
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < Alphabet; i++)
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
  while(!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int i = 0; i < Alphabet; i++)
      if (next[now][i] == -1)
        next[now][i] = next[fail[now]][i];
      else {
        fail[next[now][i]] = next[fail[now]][i];
        Q.push(next[now][i]);
      }
    }
  }
  int query(const char buf[]) {
    int len = strlen(buf);
    int now = root;
    int res = 0;
    for (int i = 0; i < len; i++) {
      now = next[now][buf[i] - 'a'];
      int temp = now;
      while (temp != root) {
        res += end[temp];
        end[temp] = 0;
        temp = fail[temp];
      }
    }
    return res;
  }
};
