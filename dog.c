#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() {

		char arr[10][22];
		int i;
		char key;
		char dx, dy;
		int x = 5, y = 10;
		int ax = 8, ay = 5;
		int score = 0;

		srand(time(NULL));

do {

	sprintf(arr[0], "####################");
	for (i = 1; i < 9; i++)
		sprintf(arr[i], "#                  #");
	sprintf(arr[9], "####################");

	arr[x][y] = '@';
	arr[ax][ay] = '*';

	system("cls");

	printf("Ur score: %d\n", score);
	printf("Player: (%d, %d) | Apple: (%d, %d)\n", x, y, ax, ay);

	for (i = 0; i < 10; i++)
		printf("%s\n", arr[i]);

	key = _getch();
	
	dx = x;
	dy = y;

	if (key == 'w') x--;
	if (key == 's') x++;
	if (key == 'a') y--;
	if (key == 'd') y++;

	if (arr[x][y] == '#') {
		x = dx;
		y = dy;
	}

	if ((x == ax) && (y == ay)) {
		score++;
		if (score > 10) {
			printf("You are collect enough apples.");
			break;
		}
		do {
			ax = rand() % 8 + 1;
			ay = rand() % 18 + 1;
		} 
		while (ax == x && ay == y);
	}
}	

	while (key != 'e');

	return 0;

}
