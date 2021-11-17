/***---------------------------------------****
****---------���� ����������������---------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : 2-2.CPP                      *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 07/10/2021                   *
* Last Revision: 23/10/2021                   *
* --------------------------------------------*
* Comment      : ������ ������������ ������   *
****------------------------------------------*/

#include <iostream>
#include <chrono>
using namespace std;
const int MAXIMUM = 100, MINIMUM = -100;
const int FIRST_STEP_SIZE = 30;
const int SECOND_STEP_SIZE = 500000;

//������� ������������� ������� ��������� �����
void getRandomArray(int* array, //������ ��������
	int size); //���-�� ��������� � �������

//������� ������������� ������� �� ����������
void getIncreasingArray(int* array, //������ ��������
	int size); //���-�� �������� � �������

//������� ������ ������� 
void printArray(int* array, //������ ��������
	int size); //���-�� �������� � �������

//���������������� �����
void S(int* array, //������ ��������
	int size, //���-�� �������� � �������
	int key); //���� ��� ������

//������� ���������������� ����� 
void Q(int* array, //������ ��������
	int size, //���-�� �������� � �������
	int key); //���� ��� ������

//���������������� ����� � ������������� �������
void T(int* array, //������ ��������
	int size, //���-�� �������� � �������
	int key); //���� ��� ������

//�������� �����
void B(int* array, //������ ��������
	int size, //���-�� �������� � �������
	int key); //���� ��� ������


int main() {
	setlocale(LC_ALL, "Russian");
	int firstStepKey, secondStepKey;  //����� ��� ���� ������ ���������
	int* firstStepArray = new int[FIRST_STEP_SIZE]; //������ ��� ������� �����
	int* secondStepArray = new int[SECOND_STEP_SIZE]; //������ ��� ������� �����
	
	
	cout << "\t\t\t\t*=======� � � � � �   � � � �=======*\n\n";
	getRandomArray(firstStepArray, FIRST_STEP_SIZE); //�������������� ������ ��������� �����
	printArray(firstStepArray, FIRST_STEP_SIZE); //�������� ������
	cout << "������� ���� ��� ������: ";
	cin >> firstStepKey; //������ ���� ��� ������
	S(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //��������� ���������������� �����
	Q(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //��������� ������� ���������������� �����
	cout << "\n\n";
	getIncreasingArray(firstStepArray, FIRST_STEP_SIZE); //�������������� ������ �� ����������
	printArray(firstStepArray, FIRST_STEP_SIZE); //�������� ������
	cout << "������� ���� ��� ������: ";
	cin >> firstStepKey; //������ ���� ��� ������
	T(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //��������� ���������������� ����� � ������������� �������
	B(firstStepArray, FIRST_STEP_SIZE, firstStepKey); //��������� �������� �����
	delete[] firstStepArray;
	cout << "\n\n\n";

	cout << "\t\t\t\t*=======� � � � � �   � � � �=======*\n\n";
	getRandomArray(secondStepArray, SECOND_STEP_SIZE); //�������������� ������ ��������� �����
	cout << "������� ���� ��� ������: ";
	cin >> secondStepKey; //������ ���� ��� ������

	auto start = chrono::high_resolution_clock::now(); //����������� ����� ������ ������ �������
	S(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //��������� ���������������� �����
	chrono::duration<double>duration_S = chrono::high_resolution_clock::now() - start; //��������� ����� ������ �������
	cout << "������� ���������� �� " << duration_S.count() * 1000 << " ��\n"; //������� ����� ������ �������

    start = chrono::high_resolution_clock::now(); //����������� ����� ������ ������ �������
	Q(secondStepArray, SECOND_STEP_SIZE, secondStepKey);  //��������� ������� ���������������� �����
	chrono::duration<double>duration_Q = chrono::high_resolution_clock::now() - start; //��������� ����� ������ �������
	cout << "������� ���������� �� " << duration_Q.count() * 1000 << " ��\n"; //������� ����� ������ �������
	cout << "\n\n";

	getIncreasingArray(secondStepArray, SECOND_STEP_SIZE); //�������������� ������ �� ����������
	cout << "������� ���� ��� ������: ";
	cin >> secondStepKey; //������ ���� ��� ������

	start = chrono::high_resolution_clock::now(); //����������� ����� ������ ������ �������
	T(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //��������� ���������������� ����� � ������������� �������
	chrono::duration<double>duration_T = chrono::high_resolution_clock::now() - start; //��������� ����� ������ �������
	cout << "������� ���������� �� " << duration_T.count() * 1000 << " ��\n"; //������� ����� ������ �������
	
	start = chrono::high_resolution_clock::now(); //����������� ����� ������ ������ �������
	B(secondStepArray, SECOND_STEP_SIZE, secondStepKey); //��������� �������� �����
	chrono::duration<double>duration_B = chrono::high_resolution_clock::now() - start; //��������� ����� ������ �������
	cout << "������� ���������� �� " << duration_B.count() * 1000 << " ��\n"; //������� ����� ������ �������
	delete[] secondStepArray;
	cout << "\n\n\n";
}//main

void getRandomArray(int* array, //������ ��������
	int size) //���-�� ��������� � �������
{
	cout << "������������������ �� ��������� �����\n";
	srand(time(NULL));
	int diapason = MAXIMUM - MINIMUM; //��������
	for (int i = 0; i < size; i++)
	{
		array[i] = int(rand() % diapason); //��������� ��������
	}//for
}//random


void getIncreasingArray(int* array, //������ ��������
	int size) //���-�� �������� � �������
{
	cout << "����������� ������������������\n";
	for (int i = 0; i < size; i++)
	{
		array[i] = i; //���������� ��������
	}//for
}//increasing

void printArray(int* array, //������ ��������
	int size) //���-�� �������� � �������
{
	for (int i = 0; i < size; i++) {
		cout << array[i] << " "; //������� ��������
	}//for
	cout << "\n\n";
}//printArray


void S(int* array, int size, int key) 
{
	int count = 0; //������� ���������
	for (int i = 0; i < size; i++)
	{
		count += 2;            //������� ���������� ���������
		if (array[i] == key)      //���� ������� ������
		{
			cout << "���������� ��������� � ���������������� ������ (S) ����� " << count << endl; //������� ���-�� ���������
			cout << "������� ������� ��������� �� " << i + 1 << " �����" << endl; //������� ������� ��������
			return;
		}//if
	}//for
	cout << "���������� ��������� � ���������������� ������ (S) ����� " << count << endl; //������� ���-�� ���������
	cout << "������� ������� �� ������" << endl; //������� ��������� �� ������
}//S


void Q(int* array, int size, int key) {
	int count = 1; //������� ���������
	int last = array[size - 1]; //���������� ��������� ��������
	array[size - 1] = key; //������ ���������� �������� ������ ����
	int i = 0; //��������
	while (array[i] != key) //���� �� ����� ����
	{
		count++; //������� ���������� ���������
		i++; //����������� ��������
	}//while
	array[size - 1] = last; //������ ��������� �������� �� �����
	count++; //����������� �������
	if ((i < size - 1) || (array[size - 1] == key)) //���� ��������� ������� �� ��������� ��� ����� �����
	{
		cout << "���������� ��������� � ������� ���������������� ������ (Q) ����� " << count << endl; //������� ���-�� ���������
		cout << "������� ������� ��������� �� " << i + 1 << " �����" << endl; //������� ������� ��������
	}
	else
	{
		cout << "���������� ��������� � ������� ���������������� ������ (Q) ����� " << count << endl; //������� ���-�� ���������
		cout << "������� ������� �� ������" << endl; //������� ��������� �� ������
	}//if
}//Q


void T(int* array, int size, int key) {
	int count = 1; //������� ���������
	int i = 0; //��������
	int temp = array[size - 1]; //���������� ��������� ��������
	array[size - 1] = INT32_MAX; //�������� ��������� ������� ����� ������� ������
	while (key>array[i]) //���� ���� ������ �������� �������
	{
		count++; //����������� �������
		i++; //����������� ��������
	}//while
	array[size - 1] = temp; //��������� ��������� �������� �� ���� �����
	count++; //����������� �������
	if (key == array[i])
	{
		cout << "���������� ��������� � ���������������� ������ � ������������� ������� (T) ����� " << count << endl; //������� ���-�� ���������
		cout << "������� ������� ��������� �� " << i + 1 << " �����" << endl; //������� ������� ��������
	}
	else
	{
		cout << "���������� ��������� � ���������������� ������ � ������������� ������� (T) ����� " << count << endl; //������� ���-�� ���������
		cout << "������� ������� �� ������" << endl; //������� ��������� �� ������
	}//if
}//T

void B(int* array, int size, int key) {
	int count = 0; //������� ���������
	int low = 0; //������ �������
	int high = size - 1; //������� �������
	int mid; //������� ��������
	while (low <= high) //���� ������ ������� �� ������ �������
	{
		mid = (low + high) / 2; //��������� ������� ��������
		count += 2; //����������� �������
		if (key == array[mid]) //���� ���� ����� �������� ��������
		{
			cout << "���������� ��������� � �������� ������ (B) ����� " << count << endl; //������� ���-�� ���������
			cout << "������� ������� ��������� �� " << mid + 1 << " �����" << endl; //������� ������� ��������
			return;
		}
		if (key > array[mid]) //���� ���� ������ �������� ��������
		{
			low = mid + 1; //������� ������ �������
		}
		else
		{
			high = mid - 1; //������� ������� �������
		}//if
		count++; //����������� �������
	}//while
	cout << "���������� ��������� � �������� ������ (B) ����� " << count << endl; //������� ���-�� ���������
	cout << "������� ������� �� ������" << endl; //������� ��������� �� ������
}//B
/*--------------End of file 2-2.CPP--------------*/