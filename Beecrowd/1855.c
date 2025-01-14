// Mapa do Meistre 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void move(char current_dir, int *px, int *py) {
  switch (current_dir) {
  case '>':
    (*px)++;
    break;
  case '<':
    (*px)--;
    break;
  case 'v':
    (*py)++;
    break;
  case '^':
    (*py)--;
    break;
  default:
    break;
  }
}

int main () {
  int x, y, px, py, t;
  bool valid;
  char mapa[100][100], current_dir;
  scanf("%d", &x);
  scanf("%d", &y);

  for (int i = 0; i < y;  i++) {
    for (int j = 0; j < x; j++) {
      scanf(" %c", &mapa[i][j]);
    }
  }

  current_dir = mapa[0][0];
  px = 0, py = 0, t = 0;
  valid = false;
  while (px >= 0 && px < x && py >= 0 && py < y && t < x*y && !valid) {
    switch (mapa[py][px]) {
      case '>': 
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case '<': 
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case 'v': 
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case '^': 
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case '.': 
        move(current_dir, &px, &py);
        t++;
        break;
      case '*':
        valid = true;
        break;
      default:
        break;
    }
  }

  if (valid) printf("*\n");
  else printf("!\n");
}