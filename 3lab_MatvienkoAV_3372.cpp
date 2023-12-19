#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

void createNewMatrix(int* firstElement, int N)
{
	int* end = firstElement + N * N;
	for (int* i = firstElement; i < end; i++)
	{
		*i = rand() % N * N + 1;
	}
}

void fillZeroMatrix(int* firstElement, int N)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		*i = 0;
	}
}

void spiralFill(int* firstElement, int N)
{
	int* arr = new int[N * N];
	int* end = firstElement + N * N;
	fillZeroMatrix(firstElement, N);
	for (int index = 0; index < N * N; index++)
	{
		for (int i = 0; i < N / 2; i++)
		{
			int* pUpLeft = firstElement + i * (N + 1);
			int* pUpRight = firstElement + i * (N - 1) + (N - 1);
			int* pDownRight = firstElement + (N * N - 1) - i * (N + 1);
			int* pDownLeft = firstElement + (N * N - N) - i * (N - 1);
			for (int* j = pUpLeft; j < pUpRight; j++)
			{
				*j = rand() % (N * N) + 1;
				arr[index] = *j;
				system("cls");
				for (int* i = firstElement; i < end; i++)
				{
					cout << setw(4) << *i;
					if ((i - firstElement + 1) % N == 0)
					{
						cout << "\n";
					}
				}
				index++;
				Sleep(100);
			}
			for (int* j = pUpRight; j < pDownRight; j += N)
			{
				*j = rand() % (N * N) + 1;
				arr[index] = *j;
				system("cls");
				for (int* i = firstElement; i < end; i++)
				{
					cout << setw(4) << *i;
					if ((i - firstElement + 1) % N == 0)
					{
						cout << "\n";
					}
				}
				index++;
				Sleep(100);
			}
			for (int* j = pDownRight; j > pDownLeft; j--)
			{
				*j = rand() % (N * N) + 1;
				arr[index] = *j;
				system("cls");
				for (int* i = firstElement; i < end; i++)
				{
					cout << setw(4) << *i;
					if ((i - firstElement + 1) % N == 0)
					{
						cout << "\n";
					}
				}
				index++;
				Sleep(100);
			}
			for (int* j = pDownLeft; j > pUpLeft; j -= N)
			{
				*j = rand() % (N * N) + 1;
				arr[index] = *j;
				system("cls");
				for (int* i = firstElement; i < end; i++)
				{
					cout << setw(4) << *i;
					if ((i - firstElement + 1) % N == 0)
					{
						cout << "\n";
					}
				}
				index++;
				Sleep(100);
			}
		}
	}
	cout << endl;
}

void snakeFill(int* firstElement, int N)
{
	int* end = firstElement + N * N;
	fillZeroMatrix(firstElement, N);
	for (int i = 0; i < N / 2; i++)
	{
		int* pUp = firstElement + i * 2;
		int* pDown = firstElement + N * N - N + i * 2;
		int* pRightUp = firstElement + N * N - N + 1 + i * 2;
		int* pRightDown = firstElement + 1 + i * 2;
		for (int* j = pUp; j <= pDown; j += N)
		{
			*j = rand() % (N * N) + 1;
			system("cls");
			for (int* i = firstElement; i < end; i++)
			{
				cout << setw(4) << *i;
				if ((i - firstElement + 1) % N == 0)
				{
					cout << "\n";
				}
			}
			Sleep(100);
		}
		for (int* j = pRightUp; j >= pRightDown; j -= N)
		{
			*j = rand() % (N * N) + 1;
			system("cls");
			for (int* i = firstElement; i < end; i++)
			{
				cout << setw(4) << *i;
				if ((i - firstElement + 1) % N == 0)
				{
					cout << "\n";
				}
			}
			Sleep(100);
		}
	}
}

void splitMatrix(int* firstElement, int N)
{
	int* end = firstElement + N * N - 1;
	int* start = firstElement + N / 2 - 1;
	int* mid = firstElement + (N * N / 2) - 1;
	cout << "\n\n";
	for (int* i = firstElement; i <= end; i++)
	{
		cout << setw(4) << *i;
		if (((i - firstElement + 1) % (N / 2) == 0) && ((i - firstElement + 1) % N != 0))
		{
			cout << "  ";
		}
		if (((i - firstElement + 1) % ((N * N) / 2) == 0) && ((i - firstElement + 1) % (N * N) != 0))
		{
			cout << '\n' << " ";
		}
		if ((i - firstElement + 1) % N == 0)
		{
			cout << '\n';
		}
	}
}

void swapBlocksA(int* firstElement, int N)
{
	for (int i = 0; i < (N * N / 4); i++)
	{
		int* ptr1 = firstElement + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);

		int temp = *ptr2;
		*ptr2 = *ptr1;
		int temp1 = *ptr4;
		*ptr4 = temp;
		temp = *ptr3;
		*ptr3 = temp1;
		*ptr1 = temp;
	}
	splitMatrix(firstElement, N);
}

void swapBlocksB(int* firstElement, int N)
{
	for (int i = 0; i < (N * N / 4); i++)
	{
		int* ptr1 = firstElement + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr4);
		swap(*ptr2, *ptr3);
	}
	splitMatrix(firstElement, N);
}

void swapBlocksC(int* firstElement, int N)
{
	for (int i = 0; i < (N * N / 4); i++)
	{
		int* ptr1 = firstElement + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr3);
		swap(*ptr2, *ptr4);
	}
	splitMatrix(firstElement, N);
}

void swapBlocksD(int* firstElement, int N)
{
	for (int i = 0; i < (N * N / 4); i++)
	{
		int* ptr1 = firstElement + (i / (N / 2)) * N + (i % (N / 2));
		int* ptr2 = ptr1 + (N / 2);
		int* ptr4 = ptr2 + (N / 2) * N;
		int* ptr3 = ptr4 - (N / 2);
		swap(*ptr1, *ptr2);
		swap(*ptr3, *ptr4);
	}
	splitMatrix(firstElement, N);
}

void bubbleSort(int* firstElement, int N)
{
	int* end = firstElement + (N * N);
	for (int* i = firstElement; i < end; i++)
	{
		for (int* j = firstElement; j < end - 1; j++)
		{
			if (*j > *(j + 1))
			{
				swap(*j, *(j + 1));
			}
		}
	}
}

void showMatrix(int* firstElement, int N)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		cout << setw(4) << *i;
		if ((i - firstElement + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void plusNumber(int* firstElement, int N, int number)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		*i += number;
	}
}

void minusNumber(int* firstElement, int N, int number)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		*i -= number;
	}
}

void multiplyNumber(int* firstElement, int N, int number)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		*i *= number;
	}
}

void divideNumber(int* firstElement, int N, int number)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		*i /= number;
	}
}

void showIDZMatrix(int* firstElement, int N)
{
	int* end = firstElement + N * N - 1;
	for (int* i = firstElement; i <= end; i++) {
		cout << setw(4) << *i;
		if ((i - firstElement + 1) % N == 0) {
			cout << '\n';
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int size6 = 6, size8 = 8, size10 = 10;
	int arr6[size6][size6], arr8[size8][size8], arr10[size10][size10];
	int* pArr6 = &arr6[0][0], * pArr8 = &arr8[0][0], * pArr10 = &arr10[0][0];

	while (true)
	{
		cin.clear();
		cin.sync();
		cout << "1)    Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках. Пользователь должен видеть процесс заполнения квадратичной матрицы (*Для манипуляции с элементами используйте только арифметику указателей):" << endl;
		cout << "2)    Получить новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами (*Для манипуляции с элементами используйте только арифметику указателей):" << endl;
		cout << "3)    Используя арифметику указателей, отсортировать элементы любой сортировкой из списка ниже (если во 2 ПР вы реализовывали одну из представленных сортировок, рекомендуется переиспользовать написанный код и модернизировать его для работы с указатями). " << endl;
		cout << "4)    Уменьшить, увеличить, умножить или поделить все элементы матрицы на введенное пользователем число (*Для манипуляции с элементами используйте только арифметику указателей)." << endl;

		int taskNumb;
		cin >> taskNumb;

		switch (taskNumb)
		{
		case 1:
		{
			cout << "Выберите способ заполнения матрицы: " << endl;
			cout << "1) Спиралью\n" << "2) Змейкой" << endl;
			int choise;
			cin >> choise;
			if (choise == 1)
			{
				cout << "Введите порядок матрицы (6, 8, 10)" << endl;
				int matrixOrder;
				cin >> matrixOrder;

				switch (matrixOrder)
				{
				case 6:
				{
					spiralFill(pArr6, size6);
					break;
				}
				case 8:
				{
					spiralFill(pArr8, size8);
					break;
				}
				case 10:
				{
					spiralFill(pArr10, size10);
					break;
				}
				default:
				{
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				}
			}
			if (choise == 2)
			{
				cout << "Введите порядок матрицы (6, 8, 10)" << endl;
				int matrixOrder;
				cin >> matrixOrder;

				switch (matrixOrder)
				{
				case 6:
				{
					snakeFill(pArr6, size6);
					break;
				}
				case 8:
				{
					snakeFill(pArr8, size8);
					break;
				}
				case 10:
				{
					snakeFill(pArr10, size10);
					break;
				}
				default:
				{
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				}
			}
		}
		break;
		case 2:
		{
			cout << "Изначальное расположение блоков: \n"
				<< "\t --- --- \n"
				<< "\t| 1 | 2 |\n"
				<< "\t --- --- \n"
				<< "\t| 4 | 3 |\n"
				<< "\t --- --- \n\n";
			cout << "Выберите способ переставления блоков:\n";
			cout << "1) \n"
				<< "\t --- --- \n"
				<< "\t| 4 | 1 |\n"
				<< "\t --- --- \n"
				<< "\t| 3 | 2 |\n"
				<< "\t --- --- \n";
			cout << "2) \n"
				<< "\t --- --- \n"
				<< "\t| 3 | 4 |\n"
				<< "\t --- --- \n"
				<< "\t| 2 | 1 |\n"
				<< "\t --- --- \n";
			cout << "3) \n"
				<< "\t --- --- \n"
				<< "\t| 4 | 3 |\n"
				<< "\t --- --- \n"
				<< "\t| 1 | 2 |\n"
				<< "\t --- --- \n";
			cout << "4) \n"
				<< "\t --- --- \n"
				<< "\t| 2 | 1 |\n"
				<< "\t --- --- \n"
				<< "\t| 3 | 4 |\n"
				<< "\t --- --- \n";
			int choise;
			cin >> choise;
			if (choise == 1)
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr6, size6);
					splitMatrix(pArr6, size6);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksA(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr8, size8);
					splitMatrix(pArr8, size8);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksA(pArr8, size8);
					break;
				}
				case  10:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr10, size10);
					splitMatrix(pArr10, size10);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksA(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
			}
			if (choise == 2)
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr6, size6);
					splitMatrix(pArr6, size6);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksB(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr8, size8);
					splitMatrix(pArr8, size8);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksB(pArr8, size8);
					break;
				}
				case  10:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr10, size10);
					splitMatrix(pArr10, size10);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksB(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
			}
			if (choise == 3)
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr6, size6);
					splitMatrix(pArr6, size6);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksC(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr8, size8);
					splitMatrix(pArr8, size8);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksC(pArr8, size8);
					break;
				}
				case  10:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr10, size10);
					splitMatrix(pArr10, size10);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksC(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
			}
			if (choise == 4)
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr6, size6);
					splitMatrix(pArr6, size6);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksD(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr8, size8);
					splitMatrix(pArr8, size8);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksD(pArr8, size8);
					break;
				}
				case  10:
				{
					cout << "Исходная матрица:";
					createNewMatrix(pArr10, size10);
					splitMatrix(pArr10, size10);
					cout << "\nМатрица с переставленными блоками:";
					swapBlocksD(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
			}
			break;
		}
		case 3:
		{
			cout << "Введите порядок матрицы (6, 8, 10)\n";
			int matrixOrder;
			cin >> matrixOrder;
			switch (matrixOrder)
			{
			case 6:
			{
				createNewMatrix(pArr6, size6);
				cout << "Исходная матрица:\n";
				showMatrix(pArr6, size6);
				bubbleSort(pArr6, size6);
				cout << "Отсортированная матрица:\n";
				showMatrix(pArr6, size6);
				break;
			}
			case 8:
			{
				createNewMatrix(pArr8, size8);
				cout << "Исходная матрица:\n";
				showMatrix(pArr8, size8);
				bubbleSort(pArr8, size8);
				cout << "Отсортированная матрица:\n";
				showMatrix(pArr8, size8);
				break;
			}
			case 10:
			{
				createNewMatrix(pArr10, size10);
				cout << "Исходная матрица:\n";
				showMatrix(pArr10, size10);
				bubbleSort(pArr10, size10);
				cout << "Отсортированная матрица:\n";
				showMatrix(pArr10, size10);
				break;
			}
			default:
				cout << "Доступны размерности 6, 8, 10.\n\n";
				break;
			}
			break;
		}
		case 4:
		{
			cout << "Введите число\n";
			int number;
			cin >> number;

			cout << "Выберите действие:\n" << "1) +\n" << "2) -\n" << "3) *\n" << "4) /\n";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr6, size6);
					showMatrix(pArr6, size6);
					plusNumber(pArr6, size6, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr8, size8);
					showMatrix(pArr8, size8);
					plusNumber(pArr8, size8, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr8, size8);
					break;
				}
				case 10:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr10, size10);
					showMatrix(pArr10, size10);
					plusNumber(pArr10, size10, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				break;
			}
			case 2:
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr6, size6);
					showMatrix(pArr6, size6);
					minusNumber(pArr6, size6, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr8, size8);
					showMatrix(pArr8, size8);
					minusNumber(pArr8, size8, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr8, size8);
					break;
				}
				case 10:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr10, size10);
					showMatrix(pArr10, size10);
					minusNumber(pArr10, size10, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				break;
			}
			case 3:
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr6, size6);
					showMatrix(pArr6, size6);
					multiplyNumber(pArr6, size6, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr8, size8);
					showMatrix(pArr8, size8);
					multiplyNumber(pArr8, size8, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr8, size8);
					break;
				}
				case 10:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr10, size10);
					showMatrix(pArr10, size10);
					multiplyNumber(pArr10, size10, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				break;
			}
			case 4:
			{
				cout << "Введите порядок матрицы (6, 8, 10)\n";
				int matrixOrder;
				cin >> matrixOrder;
				switch (matrixOrder)
				{
				case 6:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr6, size6);
					showMatrix(pArr6, size6);
					divideNumber(pArr6, size6, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr6, size6);
					break;
				}
				case 8:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr8, size8);
					showMatrix(pArr8, size8);
					divideNumber(pArr8, size8, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr8, size8);
					break;
				}
				case 10:
				{
					cout << "Исходная матрица:\n";
					createNewMatrix(pArr10, size10);
					showMatrix(pArr10, size10);
					divideNumber(pArr10, size10, choice);
					cout << "После манипуляции:\n";
					showMatrix(pArr10, size10);
					break;
				}
				default:
					cout << "Доступны размерности 6, 8, 10.\n\n";
					break;
				}
				break;
			}
			}
			break;
		}
		default:
			cout << "Доступно 4 задания.\n";
			_getch();
		}
	}
	return 0;
}