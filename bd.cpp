#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Initialiation start */

typedef struct TColumnData {
    ;
} ColumnData;

/* Initialization end */

int main()
{
    setlocale(LC_ALL, "Russian");

	// Language initialization
    string input; bool lang;
    while (true) {
        cout << "Language? [0] RUS, [1] ENG: ";
        cin >> input;
        if (system("cls")==32512) system("clear");
        if (input=="0") { lang=0; break; }
        if (input=="1") { lang=1; break; }
    }

	// Mainloop
    string i;
    while (true) {
		
		// Main menu
        lang? cout << "Welcome to MephDBMS.\n"                 : cout << "Добро пожаловать в МифСУБД.\n";
        lang? cout << "To create new spreadsheet, press N.\n"  : cout << "Чтобы создать новую базу, нажмите N.\n";
        lang? cout << "To open an already existing, press O.\n": cout << "Чтобы открыть существующую, нажмите O.\n";
        lang? cout << "To open preferences, press P.\n"        : cout << "Чтобы открыть окно настроек, нажмите P.\n";
        lang? cout << "To close MephDBMS, press Q.\n"          : cout << "Чтобы выйти из МифСУБД, нажмите Q.\n";

		// Symbol reading
        cin >> i;
        if (system("cls")==32512) system("clear");
        
        if (i=="n" || i=="N" || i=="т" || i=="Т") {
            /* DB initialization and working with it */
            
        } else if (i=="o" || i=="O" || i=="щ" || i=="Щ") {
            /* DB opening and work with it */
        }
        else if (i=="p" || i=="P" || i=="з" || i=="З") {
            /* Settings menu */

			while (true) {
				lang? cout << "Settings:\n"             : cout << "Настройки:\n";
				lang? cout << "[1] Language: English\n" : cout << "[1] Язык: Русский\n";
				lang? cout << "[2] Keybindings...\n"    : cout << "[2] Управление клавишами...\n";
				lang? cout << "[3] Reset all binds\n"   : cout << "[3] Сброc управления\n";
				lang? cout << "[4] Quit to main menu\n" : cout << "[4] Выход в главное меню\n";
				cin >> i;
				if (system("cls")==32512) system("clear");
				
				if (i=="1") {
					lang? cout << "Change program language to Russian?\n[y/n] " : cout << "Изменить язык программы на Английский?\n[y/n] ";
					cin >> i;
					if (i=="y" || i=="Y" || i=="н" || i=="Н") {lang = !lang; continue;}
				} else if (i=="2") {
					// In progress..
				} else if (i=="3") {
					// In progress..
				} else if (i=="4")
					break;
			}
        }
        else if (i=="q" || i=="Q" || i=="й" || i=="Й") return 0;
    }

    return 0;
}
