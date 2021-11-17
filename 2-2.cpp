/***---------------------------------------****
****---------Курс программирование---------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : 2-2.CPP                      *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 07/10/2021                   *
* Last Revision: 23/10/2021                   *
* --------------------------------------------*
* Comment      : Вторая лабораторная работа   *
****------------------------------------------*/

#include <iostream>
#include <chrono>
using namespace std;
const int MAXIMUM = 100, MINIMUM = -100;
const int FIRST_STEP_SIZE = 30;
const int SECOND_STEP_SIZE = 500000;

//функция инициализации массива случайных чисел
void getRandomArray(int* array, //массив значений
	int size); //кол-во элементов в массиве

//функция инициализации массива по неубыванию
void getIncreasingArray(int* array, //массив значений
	int size); //кол-во значений в массиве

//функция печати массива 
void printArray(int* array, //массив значений
	int size); //кол-во значений в массиве

//последовательный поиск
void S(int* array, //массив значений
	int size, //кол-во значений в массиве
	int key); //ключ для поиска

//быстрый последовательный поиск 
void Q(int* array, //массив значений
	int size, //кол-во значений в массиве
	int key); //ключ для поиска

//последовательный поиск в упорядоченном массиве
void T(int* array, //массив значений
	int size, //кол-во значений в массиве
	int key); //ключ для поиска

//бинарный поиск
void B(int* array, //массив значений
	int size, //кол-во значений в массиве
	int key); //ключ для поиска


int main() {
	setlocale(LC_ALL, "Russian");
	int firstStepKey, secondStepKey;  //ключи для двух этапов программы
	int* firstStepArray = new int[FIRST_STEP_SIZE]; //массив для первого этапа
	int* secondStepArray = new int[SECOND_STEP_SIZE]; //массив для второго этапа
	
	
	cout << "\t\t\t\t*=======П Е Р В Ы Й   Э Т А П=======*\n\n";
	getRandomArray(firstStepArray, FIRST_STEP_SIZE); //инициализируем массив случайных чисел
	printArray(firstStepArray, FIRST_STEP_SIZE); //печатаем массив
	cout << "Введите ключ для поиска: ";
	cin >> firstStepKey; //вводим ключ для поиска
	S(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //выполняем последовательный поиск
	Q(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //выполняем быстрый последовательный поиск
	cout << "\n\n";
	getIncreasingArray(firstStepArray, FIRST_STEP_SIZE); //инициализируем массив по неубыванию
	printArray(firstStepArray, FIRST_STEP_SIZE); //печатаем массив
	cout << "Введите ключ для поиска: ";
	cin >> firstStepKey; //вводим ключ для поиска
	T(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //выполняем последовательный поиск в упорядоченном массиве
	B(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //выполняем бинарный поиск
	delete[] firstStepArray;
	cout << "\n\n\n";

	cout << "\t\t\t\t*=======В Т О Р О Й   Э Т А П=======*\n\n";
	getRandomArray(secondStepArray, SECOND_STEP_SIZE); //инициализируем массив случайных чисел
	cout << "Введите ключ для поиска: ";
	cin >> secondStepKey; //вводим ключ для поиска

	auto start = chrono::high_resolution_clock::now(); //отсчитываем время начала работы функции
	S(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //выполняем последовательный поиск
	chrono::duration<double>duration_S = chrono::high_resolution_clock::now() - start; //вычисляем время работы функции
	cout << "Функция отработала за " << duration_S.count() * 1000 << " мс\n"; //выводим время работы функции

    start = chrono::high_resolution_clock::now(); //отсчитываем время начала работы функции
	Q(secondStepArray, SECOND_STEP_SIZE, secondStepKey);  //выполняем быстрый последовательный поиск
	chrono::duration<double>duration_Q = chrono::high_resolution_clock::now() - start; //вычисляем время работы функции
	cout << "Функция отработала за " << duration_Q.count() * 1000 << " мс\n"; //выводим время работы функции
	cout << "\n\n";

	getIncreasingArray(secondStepArray, SECOND_STEP_SIZE); //инициализируем массив по неубыванию
	cout << "Введите ключ для поиска: ";
	cin >> secondStepKey; //вводим ключ для поиска

	start = chrono::high_resolution_clock::now(); //отсчитываем время начала работы функции
	T(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //выполняем последовательный поиск в упорядоченном массиве
	chrono::duration<double>duration_T = chrono::high_resolution_clock::now() - start; //вычисляем время работы функции
	cout << "Функция отработала за " << duration_T.count() * 1000 << " мс\n"; //выводим время работы функции
	
	start = chrono::high_resolution_clock::now(); //отсчитываем время начала работы функции
	B(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //выполняем бинарный поиск
	chrono::duration<double>duration_B = chrono::high_resolution_clock::now() - start; //вычисляем время работы функции
	cout << "Функция отработала за " << duration_B.count() * 1000 << " мс\n"; //выводим время работы функции
	delete[] secondStepArray;
	cout << "\n\n\n";
}//main

void getRandomArray(int* array, //массив значений
	int size) //кол-во элементов в массиве
{
	cout << "Последовательность из случайных чисел\n";
	srand(time(NULL));
	int diapason = MAXIMUM - MINIMUM; //диапазон
	for (int i = 0; i < size; i++)
	{
		array[i] = int(rand() % diapason); //вычисляем значение
	}//for
}//random


void getIncreasingArray(int* array, //массив значений
	int size) //кол-во значений в массиве
{
	cout << "Неубывающая последовательность\n";
	for (int i = 0; i < size; i++)
	{
		array[i] = i; //записываем значение
	}//for
}//increasing

void printArray(int* array, //массив значений
	int size) //кол-во значений в массиве
{
	for (int i = 0; i < size; i++) {
		cout << array[i] << " "; //выводим значение
	}//for
	cout << "\n\n";
}//printArray


void S(int* array, int size, int key) 
{
	int count = 0; //счетчик сравнений
	for (int i = 0; i < size; i++)
	{
		count += 2;            //считаем количество сравнений
		if (array[i] == key)      //если элемент найден
		{
			cout << "Количество сравнений в последовательном поиске (S) равно " << count << endl; //выводим кол-во сравнений
			cout << "Искомый элемент находится на " << i + 1 << " месте" << endl; //выводим позицию элемента
			return;
		}//if
	}//for
	cout << "Количество сравнений в последовательном поиске (S) равно " << count << endl; //выводим кол-во сравнений
	cout << "Искомый элемент не найден" << endl; //выводим сообщение об ошибке
}//S


void Q(int* array, int size, int key) {
	int count = 1; //счетчик сравнений
	int last = array[size - 1]; //запоминаем последнее значение
	array[size - 1] = key; //вместо последнего значения ставим ключ
	int i = 0; //итератор
	while (array[i] != key) //пока не нашли ключ
	{
		count++; //считаем количество сравнений
		i++; //увеличиваем итератор
	}//while
	array[size - 1] = last; //ставим последнее значение на место
	count++; //увеличиваем счетчик
	if ((i < size - 1) || (array[size - 1] == key)) //если найденный элемент не последний или равен ключу
	{
		cout << "Количество сравнений в быстром последовательном поиске (Q) равно " << count << endl; //выводим кол-во сравнений
		cout << "Искомый элемент находится на " << i + 1 << " месте" << endl; //выводим позицию элемента
	}
	else
	{
		cout << "Количество сравнений в быстром последовательном поиске (Q) равно " << count << endl; //выводим кол-во сравнений
		cout << "Искомый элемент не найден" << endl; //выводим сообщение об ошибке
	}//if
}//Q


void T(int* array, int size, int key) {
	int count = 1; //счетчик сравнений
	int i = 0; //итератор
	int temp = array[size - 1]; //запоминаем последнее значение
	array[size - 1] = INT32_MAX; //заменяем последний элемент самым большим числом
	while (key>array[i]) //пока ключ больше значения массива
	{
		count++; //увеличиваем счетчик
		i++; //увеличиваем итератор
	}//while
	array[size - 1] = temp; //вставляем последнее значение на свое место
	count++; //увеличиваем счетчик
	if (key == array[i])
	{
		cout << "Количество сравнений в последовательном поиске в упорядоченном массиве (T) равно " << count << endl; //выводим кол-во сравнений
		cout << "Искомый элемент находится на " << i + 1 << " месте" << endl; //выводим позицию элемента
	}
	else
	{
		cout << "Количество сравнений в последовательном поиске в упорядоченном массиве (T) равно " << count << endl; //выводим кол-во сравнений
		cout << "Искомый элемент не найден" << endl; //выводим сообщение об ошибке
	}//if
}//T

void B(int* array, int size, int key) {
	int count = 0; //счетчик сравнений
	int low = 0; //нижняя граница
	int high = size - 1; //верхняя граница
	int mid; //среднее значение
	while (low <= high) //пока нижняя граница не больше верхней
	{
		mid = (low + high) / 2; //вычисляем среднее значение
		count += 2; //увеличиваем счетчик
		if (key == array[mid]) //если ключ равен среднему значению
		{
			cout << "Количество сравнений в бинарном поиске (B) равно " << count << endl; //выводим кол-во сравнений
			cout << "Искомый элемент находится на " << mid + 1 << " месте" << endl; //выводим позицию элемента
			return;
		}
		if (key > array[mid]) //если ключ больше среднего значения
		{
			low = mid + 1; //считаем нижнюю границу
		}
		else
		{
			high = mid - 1; //считаем верхнюю границу
		}//if
		count++; //увеличиваем счетчик
	}//while
	cout << "Количество сравнений в бинарном поиске (B) равно " << count << endl; //выводим кол-во сравнений
	cout << "Искомый элемент не найден" << endl; //выводим сообщение об ошибке
}//B
/*--------------End of file 2-2.CPP--------------*/