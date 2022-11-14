#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 21

int** board;
int DIR[4][2] = { {0,-2},{0,+2},{-2,0},{+2,0} };
int visited[SIZE][SIZE] = { 0 };

void RecursiveBackTraing(int y, int x);
void Init();
void GenerateByBinaryTree();
int inRange(int y, int x);
void shuffleArray(int* array, int size);

void Init() {
	board = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		board [i] = (int*)malloc(sizeof(int) * SIZE);
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = 0;
		}
	}
	GenerateByBinaryTree();
}

void GenerateByBinaryTree()
{
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			if (x % 2 == 0 || y % 2 == 0) {
				board[y][x] = 0;
			}
			else {
				board[y][x] = 1;
			}
		}
	}
	RecursiveBackTraing(1, 1);
	printf("정상 실행\n");
	board[SIZE - 2][SIZE - 2] = 1;
}


void shuffleArray(int* array, int size) {
	int i, r, temp;

	for (i = 0; i < (size - 1); ++i)
	{
		int ra = rand() % 4;
		r = i + (ra % (size - i));
		temp = array[i];
		array[i] = array[r];
		array[r] = temp;
	}
}

int inRange(int y, int x)
{
	return (y > 0 && y < SIZE - 1) && (x > 0 && x < SIZE - 1);
}

void RecursiveBackTraing(int y, int x) {
	int r, nx, ny;
	int directions[4] = { 0,1,2,3 };

	visited[y][x] = 1;

	shuffleArray(directions, 4);
	for (r = 0; r < 4; r++) {
		nx = x + DIR[directions[r]][0];
		ny = y + DIR[directions[r]][1];
		if (inRange(ny, nx) && (board[ny][nx] == 1) && visited[ny][nx] == 0) {
			RecursiveBackTraing(ny, nx);
			if (ny != y) {
				board[(ny + y) / 2][nx] = 1;
			}
			else {
				board[ny][(nx + x) / 2] = 1;
			}
		}
	}
}

void Show_Maze() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {		//벽일때
				printf("■");
			}
			else {						//이동가능공간일 때
				printf("  ");
			}
		}
		printf("\n");
	}
}
int main() {
	srand((unsigned int)time(NULL));
	Init();
	Show_Maze();
}