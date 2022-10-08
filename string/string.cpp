#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h.>

using namespace std;

void menu();
void exercise1(char* array);
void exercise2(char* array);
void exercise3(char* array);
void exercise4(char* array);
void exercise5(char* array);
void exercise6(char* array);
void exercise7(char* array);
void exercise8(char* array);
void exercise9(char* array);
void exercise10(char* array);

void returnMenu()
{

    char exitMenu;

    do
    {
        cout << " Вернуться в меню - нажмите [1]: ";
        cin >> exitMenu;

        if (exitMenu == '1')
        {
            system("cls");
            menu();
            break;
        }
        else
        {
            cout << endl << " Введены неверные значения. Повторите попытку." << endl;
            continue;
        }

    } while (true);
}
void menu()
{
    char number;
    char* array = new char[256] {"Hello. Worl.d 1 ! <K"};

    cout << endl;
    cout << " Тема: \"Строки\"" << endl;
    cout << " _______________ " << endl << endl;
    cout << " Задание 1  - нажмите [1] " << endl
         << " Задание 2  - нажмите [2] " << endl
         << " Задание 3  - нажмите [3] " << endl
         << " Задание 4  - нажмите [4] " << endl
         << " Задание 5  - нажмите [5] " << endl
         << " Задание 6  - нажмите [6] " << endl
         << " Задание 7  - нажмите [7] " << endl
         << " Задание 8  - нажмите [8] " << endl
         << " Задание 9  - нажмите [9] " << endl
         << " Задание 10 - нажмите [0] " << endl;

    do
    {
        cout << endl << " Введите номер задания: ";
        cin >> number;

        if (number == '1')
        {
            system("cls");
            exercise1(array);
            break;
        }
        if (number == '2')
        {
            system("cls");
            exercise2(array);
            break;
        }
        if (number == '3')
        {
            system("cls");
            exercise3(array);
            break;
        }
        if (number == '4')
        {
            system("cls");
            exercise4(array);
            break;
        }
        if (number == '5')
        {
            system("cls");
            exercise5(array);
            break;
        }
        if (number == '6')
        {
            system("cls");
            exercise6(array);
            break;
        }
        if (number == '7')
        {
            system("cls");
            exercise7(array);
            break;
        }
        if (number == '8')
        {
            system("cls");
            exercise8(array);
            break;
        }
        if (number == '9')
        {
            system("cls");
            exercise9(array);
            break;
        }
        if (number == '0')
        {
            system("cls");
            exercise10(array);
            break;
        }
        else
        {
            cout << " Введены неверные значения. Повторите попытку." << endl;
            continue;
        }

    } while (number);

}
void exercise1(char* array)
{

    cout << endl << " Задание 1." << endl;
    cout << " Написать функцию, которая удаляет из строки символ с заданным номером." << endl << endl;

    int n;
    char* str = new char[strlen(array) - 1];

    cout << " Дан массив цифр: " << array << endl << endl;
    cout << " Введите номер позиуции, из которого хотите удалить символ: ";
    cin >> n;

    strncpy_s(str, strlen(array), array, n - 1);
    strcat_s(str, strlen(array), array + n);
    delete[]array;

    cout << endl << " Из массива удален символ на [" << n << "] позиции: " << str << endl << endl;

    returnMenu();

}
void exercise2(char* array)
{

    cout << endl << " Задание 2." << endl;
    cout << " Написать функцию, которая удаляет из строки все вхождения в нее заданного символа." << endl << endl;

    char* str = new char[256] {""};
    char* temp;
    char e;
    bool v = false;

    cout << " Строка символов: " << array << endl << endl;
    cout << " Введите символ, который хотите удалить: ";
    cin >> e;

    while (temp = strchr(array, e))
    {
        strncat_s(str, 256, array, strlen(array) - strlen(temp));
        array = ++temp;
        v = true;

    }
    strcat_s(str, 256, array);

    if (v == true)
    {
        
        cout << " Символ " << e << " удален из строки. Результат выполнения: " << str << endl << endl;
    }
    else
    {
        cout << " Такого символа нет." << endl;
    }

    returnMenu();

}
void exercise3(char* array)
{

    cout << endl << " Задание 3." << endl;
    cout << " Написать функцию, которая вставляет в строку в указанную позицию заданный символ." << endl << endl;
    cout << " Дан массив символов: " << array << endl;

    char* str = new char[strlen(array) + 1];
    int index;
    char symbol;

    cout << endl << " Укажите позицию в массиве, в который требуется вставить символ: ";
    cin >> index;

    cout << " Укажите символ, который хотите вставить: ";
    cin >> symbol;

    if (index > *(array))
    {
        cout << " Номер позиции превышает размер массива " << endl << endl;
    }
    else
    {
       
        strncpy_s(str, index + 2, array, index );
        *(str + index - 1) = symbol;
        strcat_s(str, strlen(str) + 2, str + index );

        cout << endl << " Позиции " << index << " присвоен символ [" << symbol << "]: " << str << endl << endl;
        
    }

    returnMenu();

}
void exercise4(char* array)
{

    cout << endl << " Задание 4." << endl;
    cout << " Написать программу, которая заменяет все символы точки \".\" " << endl;
    cout << " в строке, введенной пользователем, на символы восклицательного знака \"!\"." << endl << endl;
    cout << " Дан массив: " << array << endl;

    char* temp;

    while (temp = strchr(array, '.'))
    {
        *temp = '!';
        strcpy_s(array + (strlen(array) - strlen(temp)), strlen(array), temp);
    }

    cout << endl << " Все символы [.] заменены на [!] " << array << endl << endl;
 
    returnMenu();

}
void exercise5(char* array)
{

    cout << endl << " Задание 5." << endl;
    cout << " Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке." << endl << endl;
    cout << " Дан массив символов: " << array << endl;

    char s;
    char* temp;
    int count = 0;

    cout << " Введите символ, который нужно найти и посчитать его колличество: ";
    cin >> s;

    while (temp = strchr(array, s))
    {
        count++;
        array = ++temp;
    }

    if (count > 0)
    {
        cout << endl << " Символ [" << s << "] встречается в записи " << count << " раз(а)" << endl << endl;
    }
    else
    {
        cout << endl << " Такого символа в записи нет. " << endl << endl;
    }

    returnMenu();
}
void exercise6(char* array)
{
    cout << endl << " Задание 6." << endl;
    cout << " Пользователь вводит строку." << endl;
    cout << " Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке." << endl << endl;
    cout << " Дан массив символов: " << array << endl;

    int letter = 0, number = 0, symbol = 0;
    int temp = 0;
    string space = "";

    for (int i = 0; i < strlen(array); i++)
    {


        if (isalpha(*(array + i)))
        {
            letter++;
        }
        if (isdigit(*(array + i)))
        {
            number++;
        }
        if (*(array + i) == ' ')
        {
            space = " включая пробел(ы)";
        }

        symbol++;
    }

    temp = letter + number;
    symbol -= temp;

    cout << " Букв: " << letter << endl << " Цифр: " << number << endl << " Символов: " << symbol << space << " " << endl << endl;

    returnMenu();

}
void exercise7(char* array)
{

    cout << endl << " Задание 7." << endl;
    cout << " Дана строка символов. Заменить в ней все пробелы на табуляции." << endl << endl;
    cout << " Дан массив символов до применения табуляции: " << array << endl;

    char* temp;

    while (temp = strchr(array, ' '))
    {
        *temp = '\t';
        strcpy_s(array + (strlen(array) - strlen(temp)), strlen(array), temp);
    }

    cout << " После применения табуляции: " << array << endl << endl;

    returnMenu();
}
void exercise8(char* array)
{
    cout << endl << " Задание 8." << endl;
    cout << " Дана строка символов: " << array << endl;
    cout << " Определить количество букв, цифр и остальных символов, присутствующих в строке." << endl << endl;

    int letter = 0, number = 0, symbol = 0;
    int temp = 0;
    string space = "";

    for (int i = 0; i < strlen(array); i++) {

        if (isalpha(*(array + i)))
        {
            letter++;
        }
        if (*(array + i) == ' ')
        {
            space = " включая пробел(ы)";
        }
        if (isdigit(*(array + i)))
        {
            number++;
        }

        symbol++;
    }

    temp = letter + number;
    symbol -= temp;

    cout << " Букв: " << letter << endl << " Цифр: " << number << endl << " Символов: " << symbol << space << " " << endl << endl;

    returnMenu();

}
void exercise9(char* array)
{

    cout << endl << " Задание 9." << endl;
    cout << " Дана строка символов: " << array << endl;
    cout << " Подсчитать количество слов во введенном предложении." << endl << endl;

    char* temp;
    int count = 1;

    while (temp = strchr(array, ' '))
    {
        count++;
        array = ++temp;
    }

    cout << " Количество слов в предложении составляет: " << count << endl;

    returnMenu();
}
void exercise10(char* array)
{

    cout << endl << " Задание 10." << endl;
    cout << " Дана строка символов: " << array << endl;
    cout << " Узнать, является ли строка палиндромом." << endl << endl;

    char* str = new char[256];

    for (int i = 0, j = 0; i < strlen(array) + 1; i++)
    {
        if (array[i] != ' ')
        {
            str[j] = array[i];
            j++;
        }
    }

    if (_stricmp(str, _strrev(str)) == 0)
    {
        cout << " Строка не является палиндромом." << endl << endl;
    }
    else
    {
        cout << " Строка является палиндромом." << endl << endl;
    }

    returnMenu();
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    menu();

}


