#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*1. Игровое поле
2. массив из 9 элементов состоящих из пустышек
3. выбор игрока каким он собирается ходить (1/2)
4. если игрок первый, то он выбирает позицию и она заменяется X в массиве
если хочет вторым ходить то ход сначала делает робот, а потом уже игрок(O)
5. проверяем после 5-го хода на победу и после этого робот начинает дефаться если игрок ходит первым, если игрок второй, то наоборот атакует 
6. После 8 хода проверяем на невозможность победы(либо раньше так как смыс играть при любых ходах ведущих к ничье)

Почему лучше двумерный массив? С ним бл%ть работать проще чем с одномерным 
Подробности: 
1. main - статика и сама программа 
2. показ игрового поля
3. выбор каким хочет ходить(возвращает каким ходит игрок (0 или 1)) 
4.1 первый ход. 
	Игрок выбирает позицию и на его место ставится крестик, потом ИИ смотрит на какой позиции стоит X и после этого в рандомное положение ставит О. далее игрок опять выбирает позицию. Если позиция четная, то мы пытаемся занять центр, если центр уже занят, то ставим на противоположную четную позицию. 
Например(! ! !        
	 ! X 0
	 ! ! !) 
(X ! !
! X 0
! ! O)

тоже самое с нечетными позициями

ЕСЛИ позиция которая нас интересует занята, то мы рандомим позицию*/
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
	int what_swap =0; // переменная которая запоминает позицию в массиве на которую поменяли 
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

int check_win(char arr_field[], char figure_player) { // we are checking win, but now problem is realise the win for bot and player
	if (arr_field[0] == arr_field[1] == arr_field[2]) {
		if (arr_field[0] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[0] == arr_field[3] == arr_field[6]) {
		if (arr_field[0] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[0] == arr_field[4] == arr_field[8]) {
		if (arr_field[0] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[3] == arr_field[4] == arr_field[5]) {
		if (arr_field[3] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[6] == arr_field[7] == arr_field[8]) {
		if (arr_field[6] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[2] == arr_field[4] == arr_field[6]) {
		if (arr_field[6] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[2] == arr_field[5] == arr_field[8]) {
		if (arr_field[6] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[5] == arr_field[7] == arr_field[8]) {
		if (arr_field[5] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	if (arr_field[1] == arr_field[4] == arr_field[7]) {
		if (arr_field[1] == figure_player) {
			printf("Ты победил!");
		}
		else { printf("Ты проиграл(("); }
		return 0;
	}
	return 1;
}

int check_draw(char arr_field[]) {
	for (int i = 0; i < 9; i++) {
		if (arr_field[i] == ' ') {
			return 0; // возвращаем 0 если нашли пустой элемент
		}	
	}
	return 1;
}


int main() {
	setlocale(LC_ALL, "rus");
	char figure_player= 'X';
	char figure_computer = 'O';
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
	int condition_win = check_win(arr_field, figure_player); //присваиваем переменной значение функции(1 - продолжается игра; 0 - игра закончилась)	
	int condition_draw = check_draw(arr_field);
	while (condition_win && condition_draw) {
		process_gaming(arr_field, first_turn, figure_player, figure_computer);
	}
}
