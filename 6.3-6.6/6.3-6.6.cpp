#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <list>
#include <map>

using std::cout;
using std::cin;
using std::endl;

using namespace std;

int Dived(int a) {
	while (a % 2 == 0)
		a /= 2;
	while (a % 3 == 0)
		a /= 3;
	while (a % 5 == 0)
		a /= 5;
	return a;
}

void task_queue() {
	int n;
	std::queue<int> spisok;
	cout << "Введите число n: " << endl;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (Dived(i) == 1) {
			spisok.push(i);
		}
	}
	for (int i = 0; i < spisok.size(); i++) {
		cout << spisok.front() << " ";
		spisok.pop();
	}
}

void task_set() {
	std::string st1, st2;
	std::set<std::string> s1, s2;
	int n;
	cout << "Введите количество: ";
	cin >> n;
	cout << "Вводите фамилии и ответ на тест: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> st1 >> st2;
		if (s1.find(st1) == s1.end()) {
			s1.insert(st1);
			s2.insert(st1 + ' ' + st2);
		}
	}
	cout << endl;
	for (int i = 0; i < s1.size(); i++) {
		cout << *(s2.begin()) << endl;
		s2.erase(*(s2.begin()));
	}
}

void task_list() {
	std::list<std::string> MyList;
	int n;
	std::string MyString;
	cout << "Введите число n: " << endl;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		getline(cin, MyString);
		MyList.push_back(MyString);
	}
	MyList.sort();
	for (int i = 0; i <= n; i++) {
		cout << MyList.front() << " ";
		MyList.pop_front();
	}
}

void task_map() {
	string word;
	map<string, int> slova;
	int n;
	cout << "Введите n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		slova[word]++;
	}
	map<string, int>::iterator it;
	for (it = slova.begin(); it != slova.end(); ++it) {
		double pro = double((double(it->second) / n) * 100);
		cout << it->first << ": ";
		cout << pro << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "RUS");
	int vb;
	while (true)
	{
		cout << "Что вы хотите выполнить?" << endl;
		cout << "1: queue" << endl;
		cout << "2: set" << endl;
		cout << "3: list" << endl;
		cout << "4: map" << endl;
		cout << "5: Выход." << endl;
		cin >> vb;

		switch (vb) {
		case 1:
		{
			task_queue();
			cout << endl;
			break;
		}
		case 2:
		{
			task_set();
			cout << endl;
			break;
		}
		case 3:
		{
			task_list();
			cout << endl;
			break;
		}
		case 4:
		{
			task_map();
			cout << endl;
			break;
		}
		case 5:
		{
			return 0;
		}
		default:
		{
			cout << "неизвестная команда" << endl;
			cout << endl;
			break;
		}
		}
	}
}