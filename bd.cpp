#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Начало инициализации */

typedef struct TColumnData {
    ;
} ColumnData;

/* Конец инициализации */

int main()
{
    setlocale(LC_ALL, "Russian");

    string input; bool lang;
    while (true) {
        cout << "Language? [0] RUS, [1] ENG: ";
        cin >> input;
        system("cls");
        if (input=="0") { lang=0; break; }
        if (input=="1") { lang=1; break; }
    }

    char i;
    while (true) {
        lang? cout << "Welcome to MephDBMS.\n"                 : cout << "Добро пожаловать в МифСУБД.\n";
        lang? cout << "To create new spreadsheet, press N.\n"  : cout << "Чтобы создать новую базу, нажмите N.\n";
        lang? cout << "To open an already existing, press O.\n": cout << "Чтобы открыть существующую, нажмите O.\n";
        lang? cout << "To open preferences, press P.\n"        : cout << "Чтобы открыть окно настроек, нажмите P.\n";
        lang? cout << "To close MephDBMS, press Q.\n"          : cout << "Чтобы выйти из МифСУБД, нажмите Q.\n";

        i = getchar();
        system("cls");
        if (i=='n' || i=='N' || i=='т' || i=='Т') {
            // Инициализация БД и работа с ней
        } else if (i=='o' || i=='O' || i=='щ' || i=='Щ') {
            // Открытие БД и работа с ней
        }
        else if (i=='p' || i=='P' || i=='з' || i=='з') {
            // Окно настроек

            // Настройки:
            // [1] Язык: Русский
            // [2] Управление клавиш
            // [3] Сброс управления
            // [4] Выйти в главное меню
        }
        else if (i=='q' || i=='Q' || i=='й' || i=='Й') return 0;
    }

    return 0;
}
