#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "FileName.h"
#include <locale.h>
#include <time.h>
#include <conio.h>


using namespace std;

void moveCursor(int row, int col) {
	cout << "\033[" << row << ";" << col << "H";
}

//void moveCursorHor(int col) {
//	for (int i = 0; i < col ; i++) {
//		cout << "\x1b[C";
//	}
//}

void enter(int c) {
	for (int i = 0; i < c; i++) {
		cout << "|                                |\n";
	}
}

void enteer(int count, int lenght) {
	for (int i = 0; i < count; i++) {
		cout << "|";
		for (int i = 0; i < (lenght - 2); i++) {
			cout << " ";
		}
		cout << "|\n";
	}
}

void enter(){
	cout << "\n";
}

void error() {

	cout << "\033[37;41mNah, not quite ;((\033[0m\n";
}

//Цвета
/*

\033[0m

1 → Bold
4 → Underline

30 → Black
31 → Red
32 → Green
33 → Yellow
34 → Blue
35 → Magenta
36 → Cyan
37 → White

Background Colors:

40 → Black
41 → Red
42 → Green
43 → Yellow
44 → Blue
45 → Magenta
46 → Cyan
47 → White

\033[0m

*/




void Random_Table_intr(int flag) {
	cout << "+--------------------------------------\033[1mSudoku\033[0m---------------------------------------+\n";
	if (flag) {
		cout << "| \033[33mMore than 10 would be safer, this one’s a bit unreliable\033[0m";
		moveCursor(2, 85);
		cout << "|\n";
	}
	cout << setfill(' ') << left << setw(84) << "| How many tables we talkin': " << "|\n";
	
	cout << "|";
	for (int i = 0; i < 83; i++) {
		cout << " ";
	}
	cout << "|\n";
	
	cout << "+";
	for (int i = 0; i < 83; i++) {
		cout << "-";
	}
	cout << "+";
	int a = 2;
	if (flag) {
		a++;
	}
	moveCursor(a,31);
}


//Проверка условий
int Conditions_check(int A[][9], int value, int i, int j) {
	for (int r = 0; r < j; r++) {
		if (A[i][r] == value) {
			return 0;
		 }}
	for (int r = j+1; r < 9; r++) {
		if (A[i][r] == value) {
			return 0;
		}}
	for (int d = 0; d < i; d++) {
		if (A[d][j] == value) {
			return 0;
		}}
	for (int d = i+1; d < 9; d++) {
		if (A[d][j] == value) {
			return 0;
		}}
	int k1 = i/3, k2 = j/3;
	for (int n = (k1 * 3); n < ((k1*3) + 3); n++) {
		for (int p = (k2 * 3); p < ((k2*3) + 3); p++) {
			if (n != i and p != j) {
				if (value == A[n][p]) {
					return 0;
				}
			}
		}
	}
	return 1;
}


//Условия в квадрате 3*3
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
int Conditions_check_1(int A[][9], int value, int i, int j) {
	int k1 = i / 3, k2 = j / 3;
	for (int n = (k1 * 3); n < ((k1 * 3) + 3); n++) {
		for (int p = (k2 * 3); p < ((k2 * 3) + 3); p++) {
			if (n != i and p != j) {
				if (value == A[n][p]) {
					return 0;
				}
			}
		}
	}
	return 1;
}

//Судоку
/*
0 1 2  3 4 5  6 7 8

1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9

1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9

1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9
1 2 3  4 5 6  7 8 9
*/  

//Печать таблицы
void print_table(int A[][9], int e1, int e2, int count) {
	/*cout << "| К-во ошибок перед созданием: " << setfill(' ') << left << setw(53) << e1 << "|" << "\n"
       	<< "| Полных перезагрузок: " << setfill(' ') << left << setw(61) << e2 << "|" << "\n";*/
	enteer(1, 85);
	for (int i = 0; i < 9; i++) {
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout << A[i][j] << " ";
			if ((j + 1) % 3 == 0) {
				cout << "  ";
			}
		}
		cout << "\r";
		for (int i = 0; i < 84; i++) {
			cout << "\x1b[C" << flush;;
		}
		cout << "|\n";
		if ((i + 1) % 3 == 0 * (i + 1) > 0) {
			enteer(1, 85);
		}
	}
	//enter();
	//for (int k = 1; k < 10; k++) {            /*вывод с проверкой цифр красным*/
	//	for (int i = 0; i < 9; i++) {
	//		printf("\n");
	//		for (int j = 0; j < 9; j++) {
	//			if (A[i][j] == k) {
	//				printf("\033[31m%d\033[0m ", A[i][j]);
	//			}
	//			if (A[i][j]!= k) {
	//				cout << A[i][j] << " ";
	//			}
	//			
	//		}
	//	}
	//	cout << "\n";
	//}
}

void del_table(int A[][9]) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			A[i][j] = 0;
		}
	}
}
void del_cell(int A[][9], int max_i, int max_j) {
	for (int i = (max_i*3 - 3);i < 9;i++) {
		for (int i = (max_i - 3); i < max_i; i++) {
			for (int j = (max_j - 3); j < max_j; j++) {
				A[i][j] = 0;
			}
		}
	}
}

//Вывод рандомной таблицы
void Random_Table(int c) {
	srand(time(NULL));
	
	int A[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			A[i][j] = 0;
		}}
	
	int TableCount = c;
	if (not (c)) {
		
		Random_Table_intr(0);
		cin >> TableCount;
	}
	moveCursor(3,1);
	int value, count_tbl = 1;
	int error_check;
	int error_count = 0;
	int error_big_count = 0;
	for (int c = 0; c < TableCount; c++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				value = (rand() % 9)+1;
				error_check = 0;
				while (Conditions_check(A, value, i, j) == 0) {
					value = (rand() % 9)+1;
					error_check++;
					if (error_check == 1000) {
						i = 0; j = 0; error_check = 0; 
						error_count++;
						if (error_count % 100 == 0) {
							i = 0; j = 0; error_check = 0; del_table(A);
							error_big_count++;
						}
						break;
					}
					/*print_table(A);*/             /* вывод для проверки*/
					/*system("cls");*/					
				}
				error_check = 0;
				A[i][j] = value;
		}}
		
		enteer(1, 85);
		print_table(A, error_count, error_big_count, count_tbl++);
		error_count = 0;
		error_big_count = 0;
		del_table(A);
	}
	if (TableCount == 0) {
		enteer(1, 85);
	}
	cout << "+-----------------------------------------------------------------------------------+\n";
	system("pause");
	system("cls");
}


int searching_solves(int A[][9], int* e1, int* e2, int max_i, int max_j) {
	int value;
	int error_check;
	int error_count = 0;
	int EBC = 0;
	for (int i = (max_i - 3); i < max_i; i++) {
		for (int j = (max_j -3); j < max_j; j++) {
			value = (rand() % 9) + 1;
			error_check = 0;
			while (Conditions_check(A, value, i, j) == 0) {
				value = (rand() % 9) + 1;
				error_check++;
				if (error_check == 200) {
					i = 0; j = 0; error_check = 0;
					error_count++;
					if (error_count % 30 == 0) {
						i = 0; j = 0; error_check = 0; del_cell(A, max_i, max_j);
					}
					if (error_count == 300) {
						return (EBC +1);
					}
					break;
				}
				/*print_table(A);*/             /* вывод для проверки*/
				/*system("cls");*/

			}
			error_check = 0;
			A[i][j] = value;
		}
	}
	*e1 += error_check;
	*e2 += error_count;
	return EBC;
}

void Random_Table2() {
	Random_Table_intr(1);
	srand(time(NULL));

	int A[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			A[i][j] = 0;
		}
	}

	int TableCount;
	cin >> TableCount;
	int value, count_tbl = 1;
	int error_check;
	int error_count = 0;
	int EBC = 0;
	int start_pos;
	int a, f = 1, fails = 0;

	for (int c = 0; c < TableCount; c++) {
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < 4; j++) {
				EBC += searching_solves(A, &error_check, &error_count, i * 3, j * 3);
			}
		}
		f = 1;
		for (int i = 0; i < 9 and f; i++) {
			for (int j = 0; j < 9 and f; j++) {
				if (A[i][j] == 0) {
					f = 0;
					fails++;
		}}}
		if ((f)) {

			enteer(1, 85);
			print_table(A, error_count, EBC, count_tbl++);
			error_count = 0;
			EBC = 0;

		}

		del_table(A);
	}
	/*if (fails > 1 and ((fails % 100 >= 10 and fails % 100 < 15) or fails % 10 > 4)) {								русский		
		cout << "\033[33mНе удалось создать " << fails << " таблиц этим методом, нажмите любую клавишу\033[0m \n";
	}
	if ((fails % 10 > 1 and fails % 10 < 5) and (fails % 100 < 10 or fails % 100 >14)) {
		cout << "\033[33mНе удалось создать " << fails << " таблицы этим методом, нажмите любую клавишу\033[0m \n";
	}
	if (fails % 10 == 1 and fails %100 !=11) {
		cout << "\033[33mНе удалось создать "<< fails <<" таблицу этим методом, нажмите любую клавишу\033[0m \n";
	}*/

	if (fails > 9) {
		cout << "|\033[33m Creating " << fails << " tables failed… Press any key to cope.\033[0m";

		cout << "\r";
		for (int i = 0; i < 84; i++) {
			cout << "\x1b[C" << flush;;
		}
		cout << "|\n";

	}
	if ((fails > 1) and (fails < 10)) {
			cout << "|\033[33m Creating " << fails << setfill(' ') << left << setw(75) << " tables failed… Press any key to cope.\033[0m"<< " | \n";
	}
	if (fails == 1 ) {
		cout << setfill(' ') << left << setw(93) << "| \033[33mCreating failed… Press any key to cope.\033[0m" << "|\n";
	}
	if (TableCount == 0) {
		enteer(1, 85);
	}
	cout << "+-----------------------------------------------------------------------------------+\n";
	system("pause");
	system("cls");
}


int main() {
	setlocale(LC_ALL, "Russian");

	int c = 1, x, y;

	for (;true; ) {
		system("cls");
		cout << "+------------\033[1mSudoku\033[0m--------------+\n";
		enter(1);
		cout << "| 1: Table of randomness         |\n";
		cout << "| 2: Table of randomness2 [beta] |\n";
		cout << "| 0: Get outta here              |\n";
		enter(1);
		cout << "+--------------------------------+\n";
		enter();

		cout << "Choose: ";
		while (scanf_s("%d", &c) != 1) {            
			error();
			enter();
			while ((getchar()) != '\n');
/*			x = wherex();
			y = wherey();*/
			cout << "Choose smart! ";
		}

		switch (c)
		{
		case 1: {
			system("cls");
			Random_Table(0);
			enter();
			break;
		}
		case 2: {
			system("cls");
			Random_Table2();
			enter();
			break;
		}
		case 0: {
			exit(0);
		}
		
		default:
			error();
			cout << "\033[37;41mSmash any button and retry\033[0m\n";
			system("pause");
			break;
		}
	}
}

/*
4 5 2  1 9 6  7 8 3
6 8 7  5 2 3  9 1 4
1 9 3  7 8 4  2 6 5

9 1 4  2 7 5  8 3 6
3 6 5  8 4 9  1 7 2
7 2 8  6 3 1  5 4 9

2 3 9  4 1 8  6 5 7
5 4 1  9 6 7  3 2 8
8 7 6  3 5 2  4 9 1
*/

