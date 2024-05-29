#include<bits/stdc++.h>
using namespace std;

bool is_end = false;

using ARR = array<array<char, 2>, 2>;
const ARR EMPTY = {array<char, 2>{'.', '.'}, array<char, 2>{'.', '.'}};
const array<ARR, 2> EMPTYCUBE = {EMPTY, EMPTY};

void solve() {
  int H, N;
  cin >> H >> N;

  if(H == 0 && N == 0) {
    is_end = true;
    return;
  }

  vector<ARR> field_init;
  for(int i = 0; i < H; i++) {
    ARR c;
    string s;
    cin >> s;
    c[0][0] = s[0], c[0][1] = s[1];
    cin >> s;
    c[1][0] = s[0], c[1][1] = s[1];
    field_init.push_back(c);
  }

  vector<array<ARR, 2>> b(3, EMPTYCUBE);
  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    b[i][0][0][0] = s[0], b[i][0][0][1]  = s[1];
    cin >> s;
    b[i][0][1][0] = s[0], b[i][0][1][1]  = s[1];
    cin >> s;
    b[i][1][0][0] = s[0], b[i][1][0][1]  = s[1];
    cin >> s;
    b[i][1][1][0] = s[0], b[i][1][1][1]  = s[1];
    if(b[i][0] == EMPTY) swap(b[i][0], b[i][1]);
  }

  int ans = 0;
  for(int ax : {-1, 0, 1}) for(int ay : {-1, 0, 1}) {
    for(int bx : {-1, 0, 1}) for(int by : {-1, 0, 1}) {
      for(int cx : {-1, 0, 1}) for(int cy : {-1, 0, 1}) {

        int cnt_del = 0;
        bool valid = true;
        vector<ARR> field = field_init;

        auto is_adj = [&](int pos, array<ARR, 2> block) -> bool {
          for(int j = 0; j < 1 << 2; j++) {
            int j0 = (j >> 0) & 1;
            int j1 = (j >> 1) & 1;
            if(block[0][j0][j1] == '#') {
              if(field[pos][j0][j1] == '#') return true;
            }else if(block[1][j0][j1] == '#') {
              if(field[pos + 1][j0][j1] == '#') return true;
            }
          }
          return false;
        };

        auto stopper = [&](array<ARR, 2> block) -> int {
          field.push_back(EMPTY);
          field.push_back(EMPTY);
          for(int i = int(field.size()) - 3; i >= 0; i--) {
            if(is_adj(i, block)) {
              return i + 1;
            }
          }
          return 0;
        };

        auto place = [&](array<ARR, 2> block) -> void {
          int stp = stopper(block);
          if(stp >= int(field.size())) {
            field.push_back(block[0]);
          }else {
            if(block[0][0][0] == '#') field[stp][0][0] = block[0][0][0];
            if(block[0][0][1] == '#') field[stp][0][1] = block[0][0][1];
            if(block[0][1][0] == '#') field[stp][1][0] = block[0][1][0];
            if(block[0][1][1] == '#') field[stp][1][1] = block[0][1][1];
          }
          stp++;
          if(stp >= int(field.size())) {
            field.push_back(block[1]);
          }else {
            if(block[1][0][0] == '#') field[stp][0][0] = block[1][0][0];
            if(block[1][0][1] == '#') field[stp][0][1] = block[1][0][1];
            if(block[1][1][0] == '#') field[stp][1][0] = block[1][1][0];
            if(block[1][1][1] == '#') field[stp][1][1] = block[1][1][1];
          }
          vector<ARR> field_new;
          for(int i = 0; i < int(field.size()); i++) {
            if(field[i][0][0] == '.') { field_new.push_back(field[i]); continue; }
            if(field[i][0][1] == '.') { field_new.push_back(field[i]); continue; }
            if(field[i][1][0] == '.') { field_new.push_back(field[i]); continue; }
            if(field[i][1][1] == '.') { field_new.push_back(field[i]); continue; }
            cnt_del++;
          }
          swap(field, field_new);
        };

        auto moved = [&](array<ARR, 2> block, int dx, int dy) -> array<ARR, 2> {
          array<ARR, 2> ret = EMPTYCUBE;
          for(int j = 0; j < 1 << 3; j++) {
            int j0 = (j >> 0) & 1;
            int j1 = (j >> 1) & 1;
            int j2 = (j >> 2) & 1;
            if(block[j0][j1][j2] == '.') continue;
            if(j1 + dx < 0 || j1 + dx > 1) { valid = false; continue; }
            if(j2 + dy < 0 || j2 + dy > 1) { valid = false; continue; }
            ret[j0][j1 + dx][j2 + dy] = block[j0][j1][j2];
          };
          return ret;
        };

        place(moved(b[0], ax, ay));
        // if(ax == 0 && ay == 0 && bx == 1 && by == 1 && cx == 0 && cy == 0) {
        //   for(auto fi : field) {
        //     cout << fi[0][0] << fi[0][1] << endl;
        //     cout << fi[1][0] << fi[1][1] << endl;
        //     cout << endl;
        //   }
        // }

        place(moved(b[1], bx, by));
        place(moved(b[2], cx, cy));
        if(valid) ans = max(ans, cnt_del);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  while(!is_end) { solve(); }
}