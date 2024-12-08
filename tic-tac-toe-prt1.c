#include <stdio.h>
#include <locale.h>
void show_field(char arr_field[]) {
	printf("   1   2   3\n");
	printf(" -------------\n");
	printf("1| %c | %c | %c |\n", arr_field[0], arr_field[1], arr_field[2]);
	printf(" -------------\n");
	printf("2| %c | %c | %c |\n", arr_field[3], arr_field[4], arr_field[5]);
	printf(" -------------\n");
	printf("3| %c | %c | %c |\n", arr_field[6], arr_field[7], arr_field[8]);
	printf(" -------------\n");

}
int choose_turn(int first_turn) {
	printf("Выбери каким ты хочешь ходить(1 - первый; 2 - второй): ");
	scanf_s("%d", &first_turn);
}

char process_gaming(char arr_field[], int player_turn, char figure_player, char figure_computer) {
	int position; // что выбирает игрок
	int what_swap; // переменная которая запоминает позицию в массиве на которую поменяли 
	if (player_turn == 1) { // ход игрока
		while (player_turn == 1) { //Выбирает пока не выбирет свободную позицию
			printf("Выбери позицию(Первое число - это строка. Вторео число - столбец): ");
			scanf_s("%d", &position);
			switch (position) {
			case 11:
				if (arr_field[0] == ' ') {
					arr_field[0] = figure_player;
					player_turn = 0;
					what_swap = 0;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 12:
				if (arr_field[1] == ' ') {
					arr_field[1] = figure_player;
					player_turn = 0;
					what_swap = 1;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 13:
				if (arr_field[2] == ' ') {
					arr_field[2] = figure_player;
					player_turn = 0;
					what_swap = 2;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 21:
				if (arr_field[3] == ' ') {
					arr_field[3] = figure_player;
					player_turn = 0;
					what_swap = 3;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 22:
				if (arr_field[4] == ' ') {
					arr_field[4] = figure_player;
					player_turn = 0;
					what_swap = 4;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 23:
				if (arr_field[5] == ' ') {
					arr_field[5] = figure_player;
					player_turn = 0;
					what_swap = 5;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 31:
				if (arr_field[6] == ' ') {
					arr_field[6] = figure_player;
					player_turn = 0;
					what_swap = 6;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 32:
				if (arr_field[7] == ' ') {
					arr_field[7] = figure_player;
					player_turn = 0;
					what_swap = 7;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			case 33:
				if (arr_field[8] == ' ') {
					arr_field[8] = figure_player;
					player_turn = 0;
					what_swap = 8;
				}
				else {
					printf("ОШИБКА!!! ПОЛЕ УЖЕ ЗАНЯТО, ВЫБЕРИ ДРУГОЕ\n");
				}
				break;
			default:
				printf("Error\n");
			}
		}
	}
	else {     // Ход Робота
		if (arr_field[4] == ' ') { // занимаем центр по возможности
			arr_field[4] = figure_computer;
		}
		arr_field[8 - what_swap] = figure_computer;
	}
}

void check_win() {
	


}

int main() {
	setlocale(LC_ALL, "rus");
	char figure_player;
	char figure_computer;
	int player_turn;
	int first_turn = 0;
	char arr_field[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };

	choose_turn(first_turn);

	if (first_turn == 1) {
		figure_player = 'X';
		figure_computer = 'O';
	}
	else { 
		figure_player = 'O'; 
		figure_computer = 'X';
	}



}