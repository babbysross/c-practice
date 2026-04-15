/* Conway's game of life in C */
#include <stdio.h>
#include <unistd.h>

#define GRID_COLS 206
#define GRID_ROWS 9
#define ALIVE '*'
#define DEAD ' '

typedef struct grid {
    int x[GRID_COLS];
    int y[GRID_ROWS];
} grid;

/*  Translate cell location (x, y) to the linear array index.
    Wrapping implemented to prevent array overflow. */
int celloffset(int x, int y) {
    if (x < 0) {
        x = (-x) % GRID_COLS;
        x = GRID_COLS - x;
    }
    if (y < 0) {
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if (x >= GRID_COLS) x = x % GRID_COLS;
    if (y >= GRID_ROWS) y = y % GRID_ROWS;

    return ((y * GRID_COLS) + x);
}

// Set cell (x,y) in a given grid to the specified state
void setcell(char* grid, int x, int y, int state) {
    grid[celloffset(x, y)] = state;
    return;
}

char getcell(char* grid, int x, int y) {
    return grid[celloffset(x, y)];
}

/* Show the grid on screen, clear with ANSI escape seq */
void printgrid(char* grid) {
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            printf("%c", getcell(grid, x, y));
        }
        printf("\n");
    }
}

/* set all grid cells to specified state */
void setgrid(char* grid, char state) {
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            setcell(grid, x, y, state);
        }
    }
}

int main(void) {
    grid* lim;
    char grid[(sizeof(lim->x) / sizeof(*lim->x)) * (sizeof(lim->y) / sizeof(*lim->y))];
    for (int i = 0; i < (GRID_COLS * GRID_ROWS); i++) {
        printf("\e[2J\e[H\n");
        setgrid(grid,ALIVE);
        grid[i] = '>';
        printgrid(grid);
        usleep(100000);
    }
    return 0;
}