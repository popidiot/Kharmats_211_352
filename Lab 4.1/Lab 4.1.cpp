#include <iostream>

using namespace std;

void input(char*& text) { // Ввод с автоматическим определением размера массива
    int i; char temp[255], buffer = 0; // Использую доп массив char temp, чтобы выполнить ввод не зная заранее кол-во символов, которое введет пользователь
    cout << " and end it with '.'" << endl;
    for (i = 0; i < 255; i++) {
        cin >> buffer;
        if (buffer != '.') temp[i] = buffer;
        else break;
    }
    text = new char[i + 1]; text[i] = '\0';
    for (int j = 0; j < i; j++) {
        text[j] = temp[j];
    }
    return;
}

bool palindrom(char*& text) { //Задание 1. Проверка на палиндром
    for (int i = 0, j = strlen(text) - 1; i < j; i++, j--) {
        if (text[i] == ' ') i++; // Пропуск пробелов
        if (text[j] == ' ') j++;
        if (text[i] < 97) text[i] += 32; // Изменение регистра на нижний, если тот является верхним
        if (text[j] < 97) text[j] += 32;
        if (text[i] != text[j]) return false; // Если видим несовпадение, то возвращаем false (не палиндром)
    }
    return true; // Если несовпадений не было, то возвращаем true (палиндром)
}

int find_substring1(const char* str_for_search_in, const char* substring, const int start_position) {// Используется f_s2. Выполняет поиск первого слева совпадения с подстрокой и возвращает ее номер.
    bool tumbler;
    for (int i = start_position; i < strlen(str_for_search_in) - strlen(substring) + 1; i++) {
        tumbler = false;
        for (int j = 0; j < strlen(substring); j++) { // Проверка на совпадения символов в строке и подстроке
            if (str_for_search_in[i + j] == substring[j]) tumbler = true;
            else {
                tumbler = false; // Если увидели несовпадение, то переключатель становится false
                break; // И прерывается внутренний цикл, начиная новый внешний
            }
        }
        if (tumbler == true) return i + 1; // Вывод номера совпадения если переключатель всю программу оставался true
    }
    return 0; // Вывод 0 в случае, когда поиск завершился, но совпадений найдено не было
}

void find_substring2(const char* str_for_search_in, const char* substring) { // Задание 2. Использует f_s1 для вывода номера каждого найденного номера совпадения подстроки
    int start_position = 0, temp, k = 0;
    while (true) {
        temp = find_substring1(str_for_search_in, substring, start_position);
        if (temp == 0) break; // Если ничего не было найдено, то завершаем цикл и функцию.
        else { // Если поиск был успешным, то...
            cout << '[' << ++k << "] = " << temp << endl; // Вывод номера совпадения
            start_position = temp + 1;
        }
    }
    return;
}

void encrypt(char*& text, int key) { //Шифр Цезаря
    for (int i = 0; i < strlen(text); i++) {
        if ('a' <= text[i] && text[i] <= 'z') { // Работа с нижним регистром
            if (text[i] + key > 'z') // Если при выплнении шифра Цезаря происходит выход за конец алфавита
                text[i] = 'z' - text[i] + 'a' + key - 1; // То переносим в начало и применяем ключ
            else text[i] += key; // Иначе, просто применяем ключ
        }
        else if ('A' <= text[i] && text[i] <= 'Z') { // Работа с верхним регистром
            if (text[i] + key > 'Z') // Аналогично нижнему
                text[i] = 'Z' - text[i] + 'A' + key - 1;
            else text[i] += key;
        }
        else if (text[i] == ' '); // Пропуск пробела
    }
    return; // Ничего не возвращает. Вывод результата шифра производится путем обращения к text
}

void names(char*& text) { // 4 задание. Вывод только названий.
    bool tumbler = false;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '"') { // Если встречем кавычки
            if (tumbler == false) cout << "| ";
            else cout << " |";
            tumbler = !tumbler; // То меняем значение переключателя на противоположный
            i++; // Пропуск кавычек
        }
        if (tumbler == true) cout << text[i]; // Если переключатель true, то выводим
    }
    cout << endl;
    return;
}

int main() {
    int N;
    while (true) {
        cout << "\nTasks:\n1. Palindrom check. \n2. Substring in string. \n3. Caesar cipher. \n4. Names at quotation marks. \n\nInput task number: ";
        cin >> N; cout << endl;
        char* text = new char[255]; // Создание главного чара, с которым будет производиться дальнейшая работа
        switch (N) { // Меню
        case 1: { // Проверка на палиндром
            cout << "Input string to check it for palindrom";
            input(*&text);
            if (palindrom(*&text) == true)
                cout << "\nIt's palindrom!" << endl;
            else cout << "\nSorry, but it's not palindrom!" << endl;
            delete[] text;
            break;
        };
        case 2: { // Поиск подстроки в строке
            cout << "Input string for search in";
            input(*&text);
            char* str_for_search_in = text;
            cout << "\nInput substring";
            input(*&text); cout << endl;
            char* substring = text;
            find_substring2(str_for_search_in, substring);
            delete[] text;
            break;
        };
        case 3: { // Шифр Цезаря
            int key;
            cout << "Input string to encrypt";
            input(*&text);
            cout << "\nInput key (key > 0): ";
            while (true) {
                cin >> key;
                if (key <= 0) cout << "Input another key" << endl;
                else break;
            }
            encrypt(*&text, key);
            char* str_for_encrypt = new char[strlen(text) + 1];
            str_for_encrypt = text + '\0';
            cout << str_for_encrypt << endl; //Вывод для теста. По ТЗ не требуется.
            delete[] text;
            break;
        };
        case 4: { // Вычленение названий (слова в кавычках) из текста
            cout << "Input text";
            input(*&text); cout << endl;
            names(*&text);
            delete[] text;
            break;
        };
        case 5: { // Завершение программы
            delete[] text;
            return 0;
        };
        default: { // Пресекание попытки ввода несуществующего задания
            cout << "Wrong task, try again" << endl;
        };
        }
    }
}