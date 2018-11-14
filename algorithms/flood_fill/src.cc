#include "tracer/matrix.h"

#define N 5
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

bool vis[N][N] = {{0}};
int maze[N][N] = {
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0},
  {1, 1, 1, 1, 1},
  {0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0}
};

tracer::MatrixTracer<int, N, N> tr(maze, 0.2, "Flood Fill Algorithm");

void flood_fill(int x, int y) {
  if(x < 0 || x >= N || y < 0 || y >= N) return;
  tr.notify(x, y);

  if(vis[x][y] || !maze[x][y]) return;
  vis[x][y] = true;
  tr.select(x, y);

  for(int i = 0; i < 4; i++) {
    int nx = x+dr[i], ny = y+dc[i];
    flood_fill(nx, ny);
  }
}

int main () {
  flood_fill(1, 1);

  return 0;
}