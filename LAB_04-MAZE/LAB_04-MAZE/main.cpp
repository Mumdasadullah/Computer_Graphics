#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <stack>

const int rows = 35;
const int cols = 35;
const int cell_pat = 35;

struct Cell {
    bool visited;
    bool wallTop, wallRight, wallBottom, wallLeft;
};

std::vector<Cell> maze(rows* cols);
int startRow, startCol, endRow, endCol;

bool isValid(int row, int col) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

void generateMaze() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            maze[row * cols + col].visited = false;
            maze[row * cols + col].wallTop = true;
            maze[row * cols + col].wallRight = true;
            maze[row * cols + col].wallBottom = true;
            maze[row * cols + col].wallLeft = true;
        }
    }

    std::stack<std::pair<int, int>> stack;
    startRow = std::rand() % rows;
    startCol = std::rand() % cols;
    stack.push(std::make_pair(startRow, startCol));
    maze[startRow * cols + startCol].visited = true;

    while (!stack.empty()) {
        int currentRow = stack.top().first;
        int currentCol = stack.top().second;
        stack.pop();

        std::vector<int> neighbors = { 0, 1, 2, 3 };
        std::shuffle(neighbors.begin(), neighbors.end(), std::mt19937(std::random_device()()));

        for (int dir : neighbors) {
            int newRow = currentRow;
            int newCol = currentCol;
            switch (dir) {
            case 0: newRow--; break; // Up
            case 1: newCol++; break; // Right
            case 2: newRow++; break; // Down
            case 3: newCol--; break; // Left
            }

            if (isValid(newRow, newCol) && !maze[newRow * cols + newCol].visited) {
                if (dir == 0) {
                    maze[currentRow * cols + currentCol].wallTop = false;
                    maze[newRow * cols + newCol].wallBottom = false;
                }
                if (dir == 1) {
                    maze[currentRow * cols + currentCol].wallRight = false;
                    maze[newRow * cols + newCol].wallLeft = false;
                }
                if (dir == 2) {
                    maze[newRow * cols + newCol].wallTop = false;
                    maze[currentRow * cols + currentCol].wallBottom = false;
                }
                if (dir == 3) {
                    maze[newRow * cols + newCol].wallRight = false;
                    maze[currentRow * cols + currentCol].wallLeft = false;
                }

                stack.push(std::make_pair(newRow, newCol));
                maze[newRow * cols + newCol].visited = true;
            }
        }
    }

    endRow = rows - 1;
    endCol = cols - 1;
    int currentRow = 0;
    int currentCol = 0;
    while (currentRow != endRow || currentCol != endCol) {
        if (currentRow < endRow) {
            maze[currentRow * cols + currentCol].wallBottom = false;
            maze[(currentRow + 1) * cols + currentCol].wallTop = false;
            currentRow++;
        }
        else if (currentCol < endCol) {
            maze[currentRow * cols + currentCol].wallRight = false;
            maze[currentRow * cols + currentCol + 1].wallLeft = false;
            currentCol++;
        }
    }
}

void drawMaze() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            const Cell& cell = maze[row * cols + col];
            int x = col * cell_pat;
            int y = row * cell_pat;

            glColor3f(1.0f, 1.0f, 1.0f);
            if (cell.wallTop) {
                glBegin(GL_LINES);
                glVertex2i(x, y);
                glVertex2i(x + cell_pat, y);
                glEnd();
            }
            if (cell.wallRight) {
                glBegin(GL_LINES);
                glVertex2i(x + cell_pat, y);
                glVertex2i(x + cell_pat, y + cell_pat);
                glEnd();
            }
            if (cell.wallBottom) {
                glBegin(GL_LINES);
                glVertex2i(x, y + cell_pat);
                glVertex2i(x + cell_pat, y + cell_pat);
                glEnd();
            }
            if (cell.wallLeft) {
                glBegin(GL_LINES);
                glVertex2i(x, y);
                glVertex2i(x, y + cell_pat);
                glEnd();
            }
        }
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, cols * cell_pat, 0, rows * cell_pat);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    generateMaze();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Maze Lab");
    glutDisplayFunc(drawMaze);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}