#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 21

int** board;
int DIR[4][2] = { {0,-2},{0,+2},{-2,0},{+2,0} };
int visited[SIZE][SIZE] = { 0 };

void Init();
void GenerateByBinaryTree();
void RecursiveBackTraing(int y, int x);
int inRange(int y, int x);
void shuffleArray(int* array, int size);
void Show_Maze();
void BinaryTree();
void Init_Visited();

void BFS_of_DFS_Function(int y, int x) {
	Init_Visited();

	/*
	
		Add Your COde

	*/
}

int main() {
	srand((unsigned int)time(NULL));
	Init();
	Show_Maze();
	BFS_of_DFS_Function(1, 1);
}

void Init() {
	board = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		board [i] = (int*)malloc(sizeof(int) * SIZE);
	}
	Init_Visited();
	GenerateByBinaryTree();
}

void Init_Visited() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = 0;
		}
	}
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
	//미로 생성 알고리즘 1번
	RecursiveBackTraing(1, 1);

	//미로 생성 알고리즘 2번
	//BinaryTree();
	printf("정상 실행\n");
	//결승점 설정
	board[SIZE - 2][SIZE - 1] = 2;
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

//바이너리 트리 미로 생성 알고리즘
void BinaryTree() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE-1; j++) {
			if (i % 2 == 0 || j % 2 == 0)
				continue;
			int r = rand() % 2;
			if (i == SIZE - 2) {
				board[i][j + 1] = 1;
				continue;
			}
			else if (j == SIZE - 2) {
				board[i + 1][j] = 1;
				continue;
			}
			else if (r == 0) {
				board[i][j+1] = 1;
			}
			else {
				board[i+1][j] = 1;
			}
		}
	}
}
