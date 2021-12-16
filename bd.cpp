#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Initialiation start */

typedef struct TColumnData {
    string name;
    int len;
} ColumnData;

class Table
{
	private:
		int rows = 0, columns = 0;
		char*** t;
		TColumnData data[];

	public:
		Table(int r, int c, TColumnData d[])
		{
			// Initialization of the three-dimentional array of symbols.
			// "t" is an array of rows, every row is an array of cells, every cell is an array of symbols.
			// Length of each cell is contained within TColumnData[] type.
			// In every column needs to be specified it's length and name.
			rows = r;
			columns = c;
			t = (char***)malloc(rows*sizeof(char**));
			
			for (int row=0; row<rows; row++) {
				char** k = (char**)malloc(columns*sizeof(char*));
				t[row] = k;
				
				for (int cell; cell<columns; cell++) {
					char* k = (char*)malloc(d[cell].len*sizeof(char));
					t[row][cell] = k;
				}
			}
		}
		
		void SetColumns(int c)
		{
			// In progress...
		}
		
		int GetColumns()
		{
			return columns;
		}
		
		void SetRows(int r)
		{
			// In progress...
		}
		
		int GetRows()
		{
			return rows;
		}
		
		void SetColData(int n, ColumnData d)
		{
			data[n] = d;
			// In progress...
		}
		
		ColumnData GetColData(int c)
		{
			return data[c];
		}
};

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
            
            int sizeC, sizeR;
            lang? cout << "Enter initial quantity of columns: " : cout << "Введите начальное кол-во столбцов: ";
            cin >> sizeC;
            ColumnData cols[sizeC];
            for (int i=0; i<sizeC; i++) {
				lang? cout << "\nEnter the name of the column №" << i << ": " : cout << "Введите название столбца №" << i+1 << ": ";
				cin >> cols[i].name;
				getline(cin, cols[i].name);
				lang? cout << "\nEnter the length of the column №" << i << ": " : cout << "Введите длину столбца №" << i+1 << ": ";
				cin >> cols[i].len;
			}
			lang? cout << "Enter initial quantity of rows: " : cout << "Введите начальное кол-во строк: ";
            cin >> sizeR;
            
            Table t(sizeR, sizeC, cols);
            
            
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
