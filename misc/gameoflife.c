/* Conway's game of life in C */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define ALIVE '*'
#define DEAD ' '
#define RATE_S 0.1

unsigned short wid = 0;
unsigned short hig = 0;
typedef struct grid_t {
    int cols[4096];
    int rows[4096];
} grid_t;

typedef struct pos_t {
    int xpos;
    int ypos;
} pos_t;

int getWinSize(void) {
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
    {
        if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;
    }
    else
    {
        hig = ws.ws_row - 1;
        wid = ws.ws_col;
        return EXIT_SUCCESS;
    }
}

/*  Translate cell location (x, y) to the linear array index.
    Wrapping implemented to prevent array overflow. */
int celloffset(int x, int y) {
    if (x < 0) {
        x = (-x) % wid;
        x = wid - x;
    }
    if (y < 0) {
        y = (-y) % hig;
        y = hig - y;
    }
    if (x >= wid) x = x % wid;
    if (y >= hig) y = y % hig;

    return ((y * wid) + x);
}

// return the x,y position from a given grid array index
pos_t cellpos(char* grid, int i) {
    int x, y;
    if (wid == 0 || hig == 0) exit(-1);
    if (i < wid) {
        return (pos_t){i, 0};
    } else {
        x = i % wid;
        y = ((i - x) / hig);
        return (pos_t){x - 1, y - 1};
    } 
}

// Set cell (x,y) in a given grid to the specified state
void setcell(char* grid, int x, int y, int state) {
    grid[celloffset(x, y)] = state;
    return;
}

// return grid contents at given x, y position
char getcell(char* grid, int x, int y) {
    return grid[celloffset(x, y)];
}

/* Show the grid on screen, clear with ANSI escape seq */
void printgrid(char* grid) {
    for (int y = 0; y < hig; y++) {
        for (int x = 0; x < wid; x++) {
            printf("%c", getcell(grid, x, y));
        }
        //printf("\n");
    }
}

void refresh(char* grid) {
    printf("\e[2J\e[H\n");
    printgrid(grid);
}

// for given x,y position, return alive neighbours
int getneighbours(char* grid, int x, int y) {
    int neighbours = 0;
    for (int i = (y - 1); i <= (y + 1); i++) {
        for (int j = (x - 1); j <= (x + 1); j++) {
            if (i == y && j == x) 
                continue;
            if (getcell(grid, j, i) == ALIVE)
                neighbours++;
        }
    }
    return neighbours;
}

/* set all grid cells to specified state */
void setgrid(char* grid, char state) {
    for (int y = 0; y < hig; y++) {
        for (int x = 0; x < wid; x++) {
            setcell(grid, x, y, state);
        }
    }
}

// game of life logic, for loop resetting each time condition met?
void gameoflife(char* grid, int x, int y) {
    int n = getneighbours(grid, x, y);
    if (getcell(grid, x, y) == ALIVE) {
        if (n < 2 || n >3) {
            setcell(grid, x, y, DEAD);
            refresh(grid);
        } 
    } else if (getcell(grid, x, y) == DEAD) {
        if (n == 3) setcell(grid, x, y, ALIVE);
        refresh(grid);
    }
    return;
}


int main(void) {
    grid_t* lim;
    getWinSize();
    char grid[wid * hig];

    printf("\e[?25l");
    printf("\e[2J\e[H\n");
    setgrid(grid, DEAD);
    
    grid[celloffset(29,0)] = ALIVE;
    grid[celloffset(27,1)] = ALIVE;
    grid[celloffset(29,1)] = ALIVE;
    grid[celloffset(17,2)] = ALIVE;
    grid[celloffset(18,2)] = ALIVE;
    grid[celloffset(25,2)] = ALIVE;
    grid[celloffset(26,2)] = ALIVE;
    grid[celloffset(39,2)] = ALIVE;
    grid[celloffset(40,2)] = ALIVE;
    grid[celloffset(16,3)] = ALIVE;
    grid[celloffset(20,3)] = ALIVE;
    grid[celloffset(25,3)] = ALIVE;
    grid[celloffset(26,3)] = ALIVE;
    grid[celloffset(39,3)] = ALIVE;
    grid[celloffset(40,3)] = ALIVE;
    grid[celloffset(5,4)] = ALIVE;
    grid[celloffset(6,4)] = ALIVE;
    grid[celloffset(15,4)] = ALIVE;
    grid[celloffset(21,4)] = ALIVE;
    grid[celloffset(25,4)] = ALIVE;
    grid[celloffset(26,4)] = ALIVE;
    grid[celloffset(5,5)] = ALIVE;
    grid[celloffset(6,5)] = ALIVE;
    grid[celloffset(15,5)] = ALIVE;
    grid[celloffset(19,5)] = ALIVE;
    grid[celloffset(21,5)] = ALIVE;
    grid[celloffset(22,5)] = ALIVE;
    grid[celloffset(27,5)] = ALIVE;   
    grid[celloffset(29,5)] = ALIVE;  
    grid[celloffset(15,6)] = ALIVE;  
    grid[celloffset(21,6)] = ALIVE;  
    grid[celloffset(29,6)] = ALIVE;  
    grid[celloffset(16,7)] = ALIVE;  
    grid[celloffset(20,7)] = ALIVE;  
    grid[celloffset(17,8)] = ALIVE;  
    grid[celloffset(18,8)] = ALIVE; 
    printgrid(grid);
    usleep(1000000 * RATE_S);
    while (1) {
        for (int i = 0; i < sizeof(grid); i++) {
            pos_t pos = cellpos(grid, i);
            gameoflife(grid, pos.xpos, pos.ypos);
        } 
        printf("\e[2J\e[H\n");
        printgrid(grid);
        usleep(1000000 * RATE_S);
    }
    return 0;
}