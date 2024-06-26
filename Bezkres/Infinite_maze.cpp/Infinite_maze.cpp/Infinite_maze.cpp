﻿#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <iostream>

const int MAZE_SIZE = 10;

enum CellType {
    EMPTY, //puste
    WALL, //#
    PLAYER, //X
    EXIT //O
};

struct Cell {
    CellType type;
};

Cell maze[MAZE_SIZE][MAZE_SIZE];
int playerX, playerY;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void generateMaze(int x, int y) {

    /*Sprawdza, czy nowe współrzędne nx i ny są w granicach labiryntu
    i czy komórka na tych współrzędnych jest ścianą (WALL)
    przeszkoda # generowana w taki sposób, aby w grze była możliwość dla X (usera) aby dojść do O */
    maze[y][x].type = EMPTY;
    int dirs[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int r = rand() % 4;
        int temp = dirs[r];
        dirs[r] = dirs[i];
        dirs[i] = temp;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x, ny = y;
        switch (dirs[i]) {
        case 0:
            ny -= 2;
            break;
        case 1:
            nx += 2;
            break;
        case 2:
            ny += 2;
            break;
        case 3:
            nx -= 2;
            break;
        }

        if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE && maze[ny][nx].type == WALL) {
            maze[ny][nx].type = EMPTY;
            maze[(y + ny) / 2][(x + nx) / 2].type = EMPTY;
            generateMaze(nx, ny);
        }
    }
}

void drawMaze() {
    for (int i = 0; i < MAZE_SIZE; ++i) {
        for (int j = 0; j < MAZE_SIZE; ++j) {
            switch (maze[i][j].type) {
            case EMPTY:
                setColor(15); // White
                std::cout << " ";
                break;
            case WALL:
                setColor(8); // Gray
                std::cout << "#";
                break;
            case PLAYER:
                setColor(10); // Green
                std::cout << "O";
                break;
            case EXIT:
                setColor(12); // Red
                std::cout << "X";
                break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

bool isValidMove(int x, int y) {
    return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[y][x].type != WALL;
}

void movePlayer(char direction) { //poruszanie się
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
    case 'w':
        newY--;
        break;
    case 's':
        newY++;
        break;
    case 'a':
        newX--;
        break;
    case 'd':
        newX++;
        break;
    default:
        std::cout << "Invalid direction! Use 'w', 'a', 's', 'd'." << std::endl;
        return;
    }

    if (isValidMove(newX, newY)) {
        maze[playerY][playerX].type = EMPTY;
        playerX = newX;
        playerY = newY;
        maze[playerY][playerX].type = PLAYER;
    }
    else {
        std::cout << "Cannot move there!" << std::endl;
    }
}

int main() {
    std::cout << "INFINITE MAZE..." << std::endl;
    srand(time(NULL));

    while (true) {
        for (int i = 0; i < MAZE_SIZE; ++i) {
            for (int j = 0; j < MAZE_SIZE; ++j) {
                maze[i][j].type = WALL;
            }
        }

        generateMaze(1, 1);
        playerX = 1;
        playerY = 1;
        maze[playerY][playerX].type = PLAYER;
        maze[MAZE_SIZE - 2][MAZE_SIZE - 2].type = EXIT;

        while (true) {
            system("cls");
            std::cout << "INFINITE MAZE..." << std::endl;
            drawMaze();

            char move = _getch();

            movePlayer(move);

            if (maze[MAZE_SIZE - 2][MAZE_SIZE - 2].type == PLAYER) {
                std::cout << "Congratulations! You found the exit!" << std::endl;
                //but actually you are never going to escape this infinite maze. It generates over and over again
                break;
            }
        }

    }

    return 0;
}