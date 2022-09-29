#include <iostream>
#include <string>
using namespace std;

const int MAXN = 20;

bool column_has_queen[MAXN];
bool LD_RU_Diagonal[MAXN * 2 + 1];
bool LU_RD_Diagonal[MAXN * 2 + 1];

int n = 8;
bool grid[8][8];

void update(int y, int x, bool val);

void input()
{
	for(int i = 0; i < 8; ++i)
    {
    	string s;
      cin >> s;
    	for(int j = 0; j < 8; ++j)
        {
        	if(s[j] == '*')
            {
            	grid[i][j] = true;
            }
        }
    }
}

void update(int y, int x, bool val) {
  column_has_queen[x] = val;
  LD_RU_Diagonal[y + x] = val;
  LU_RD_Diagonal[n - 1 + (y - x)] = val;
}

bool isValidQueenPosition(int y, int x) {
  if (column_has_queen[x])
    return false;
  if (LD_RU_Diagonal[y + x])
    return false;
  if (LU_RD_Diagonal[n - 1 + (y - x)])
    return false;
  if(grid[y][x])
    return false;
  return true;
}

int ans;
void dfs(int y) {
  if (y == n) {
    ++ans;
    return;
  }
  for (int x = 0; x < n; ++x) {
    if (!isValidQueenPosition(y, x))
      continue;
    update(y, x, true);
    dfs(y + 1);
    update(y, x, false);
  }
}

int main() 
{
  input();
  dfs(0);
  cout << ans << endl;
  return 0;
}

