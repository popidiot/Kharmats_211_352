#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void task1(int* m, int n)
{


	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j < i; j++)
		{
			if (m[j] > m[j + 1])
			{
				int foo = m[j];
				m[j] = m[j + 1];
				m[j + 1] = foo;
			}
		}
	cout << "после сортировки" << endl;
	for (int i = 0; i < n; i++)
		cout << m[i] << ' ';
}

void task2(char* m, int n)
{
	int p[26] = { 0 };
	int j;
	for (int i = 0; i < n; i++)
	{
		j = int(m[i] - 'a');
		p[j]++;
	}
	int i = 0;
	for (j = 0; j < 26;)
	{
		if (p[j] > 0)
		{
			m[i] = char(int('a') + j);
			i++;
			p[j]--;
		}
		else j++;
	}
	for (int i = 0; i < n; i++)
		cout << m[i] << ' ';

}

void task3()
{








}

int main()
{
	setlocale(LC_ALL, "russian");

	std::cout << "Введите n ( размер массива )  ";
	int n = 0;
	int m[1000] = { 0 };
	char text[1000];
	cin >> n;
	//m = new int[n];
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 100;
		m[i] = x;
		cout << m[i] << ' ';
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 26;
		text[i] = x + 'a';
		cout << text[i] << ' ';
	}
\
	int choice = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить, напишите номер задания? \n"
			<< " задание 1 " << " задание 2 " << " задание 3 " << " выход ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{

			task1(m, n);
			break;
		}
		case 2:
		{

			task2(text, n);
			break;
		}
		case 3:
		{

			task3();
			break;

		}
		default:
		{
			return 0;
		}
		}
	}

}