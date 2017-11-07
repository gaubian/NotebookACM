// INPUT : a boolean matrix
// OUPUT : the maximum true rectangle (bottom right corner, width, height)
// COMPLEXITY : linear
#define MAXX 1000
// last x, width, height
tuple<int, int, int> maxUnderHistogram(int sizes[], int N) {
  stack<pair<int, int> > s; // height, start
  int mx, mw = 0, mh = 0;
  for(int i = 0; i < N; i++) {
    int start = i;
    while(true) {
      if(s.empty() || sizes[i] > s.top().first) {
        s.emplace(sizes[i], start);
        break;
      }
      else if(!s.empty() && sizes[i] < s.top().first) {
        int w = i - s.top().second;
        if(w*s.top().first > mw*mh) {
          mx = i-1; mw = w; mh = s.top().first;
        }
        start = s.top().second;
        s.pop();
      }
      else
        break;
    }
  }
  while(!s.empty()) {
    int h, st;
    tie(h, st) = s.top();
    s.pop();
    int w = N-st;
    if(w*h > mw*mh) {
      mx = N-1; mw = w; mh = h;
    }
  }
  return make_tuple(mx, mw, mh);
}
// last x, last y, width, height
tuple<int, int, int, int> biggestRectangle(bool table[][MAXX], int sizeY, int sizeX) {
  int mx, my, mw = 0, mh = 0;
  int mx2, mh2, mw2;
  int s[MAXX];
  memset(s, 0, sizeof(s));
  for(int y = 0; y < sizeY; y++) {
    for(int x = 0; x < sizeX; x++) {
      s[x] = table[y][x] ? s[x]+1 : 0;
    }
    tie(mx2, mw2, mh2) = maxUnderHistogram(s, sizeX);
    if(mw2*mh2 > mw*mh) {
      mx = mx2; my = y; mw = mw2; mh = mh2;
    }
  }
  return make_tuple(mx, my, mw, mh);
}
