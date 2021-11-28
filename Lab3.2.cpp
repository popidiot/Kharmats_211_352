#include <iostream>

using namespace std;

void input(int*& arr, int* size) {
	delete[] arr;
	cout << "Input size: ";
	cin >> *size;
	arr = new int[*size * 2];
	cout << "Now input numbers for array: " < ;
	for (int i = 0; i < *size; i++) {
		cout << "Input number for " << i << " element: ";
		cin >> arr[i];
	}
	cout << "Saved successful" < ;
}

void output(int*& arr, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "Outputed successful" < ;
}

void sort1(int*& arr, int* size) {
	for (int i = 0; i < *size; i++) {
		if (arr[i] < 10) {
			cout << "Incorrect array. Try input again." << endl << "Wrong >> ";
			return;
		}
	}
	for (int i = 0; i < *size; i++) {
		int rev = 0, sum = 0, temp = arr[i];
		while (temp != 0) {
			rev = (rev * 10) + (temp % 10);
			temp /= 10;
		}
		while (rev > 0) {
			rev /= 10;
			sum += rev % 10;
			rev /= 10;
		}
		arr[*size + i] = sum;
	}
	int temp;
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size - i - 1; j++) {
			if (arr[*size + j] > arr[*size + j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				temp = arr[*size + j];
				arr[*size + j] = arr[*size + j + 1];
				arr[*size + j + 1] = temp;
			}
		}
	}
}

void sort2(int*& arr, int* size) {
	int rev;
	for (int i = 0; i < *size; i++) {
		arr[*size + i] = arr[i] % 10;
	}
	bool tumbler = false; int temp, start = 0;
	for (int i = 0; i < *size; i++) {
		for (int j = start; j < *size - i - 1; j++) {
			if (arr[*size + j] > arr[*size + j + 1] && tumbler == false) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				temp = arr[*size + j];
				arr[*size + j] = arr[*size + j + 1];
				arr[*size + j + 1] = temp;
			}
			else if (arr[*size + j] == arr[*size + j + 1]) {
				tumbler = true;
				start = j + 2;
				j += 2;
				i = 0;
			}
			if (arr[*size + j] < arr[*size + j + 1] && tumbler == true) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				temp = arr[*size + j];
				arr[*size + j] = arr[*size + j + 1];
				arr[*size + j + 1] = temp;
			}
		}
	}
	cout << "Sorted successful!" < ;
}

int main() {
	int N;
	int size = 0;
	int* arr = new int[0];
	while (true) {
		cout << endl << "Input task's number: ";
		cin >> N; cout << endl;
		switch (N) {
		case 1: {
			input(*&arr, &size);
			break;
		}
		case 2: {
			output(*&arr, &size);
			break;
		}
		case 3: {
			sort1(*&arr, &size);
			break;
		}
		case 4: {
			sort2(*&arr, &size);
			break;
		}
		case 5: {
			return 0;
		}
		}
	}
}