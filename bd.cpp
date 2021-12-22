/* DBMS Project © Alex Kolodchuk, 2021
 *
 * Please do ensure that your compiler supports C++'11 or GNU++'11 standarts
 *
 * A repository of this project: https://github.com/alexkolodchuk/dbms
 * A detailed (Russian) explanation: https://imgur.com/a/7YevnZI
 */
#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Initialiation start */

class ColumnData
{
	private:
		int len;
		char* name;

	public:
		ColumnData(int x, string s)
		{
			len = x;
			name = (char*)malloc(len*sizeof(char));
			for (int i=0; i<len; i++)
				name[i] = s[i];
		}

		int Len()
		{
			return len;
		}

		string Name()
		{
			string s = "";
			for (int i=0; i<len; i++)
				s += name[i];
			return s;
		}

		void Clear()
		{
		    free(name);
		}
};

class Table
{
	private:
		int rows = 0, columns = 0;
		char*** t;
		ColumnData* data;

	public:
		Table(int r, int c, ColumnData* d)
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

				for (int cell=0; cell<columns; cell++) {
					char* k = (char*)malloc(d[cell].Len()*sizeof(char));
					t[row][cell] = k;
				}
			}

			data = (ColumnData*)malloc(columns*sizeof(ColumnData));

			for (int i=0; i<columns; i++)
				data[i] = d[i];
		}

		int GetColumns()
		{
			return columns;
		}

		int GetRows()
		{
			return rows;
		}

		ColumnData GetColData(int c)
		{
			return data[c];
		}

		string GetData(int x, int y)
		{
            string s = "";
            for (int i=0; i<data[x].Len(); i++)
                s += t[y][x][i];
            return s;
		}


		void SetColData(int n, ColumnData d)
		{
		    // In progress...
		}

		void AddRow(int y)
		{
            // In progress...
		}

		// Column-setter
		void AddColumn(int id, ColumnData c)
		{
			// So, the table is being cached, then cleared and reinitialized
			// As well as the ColumnData array

			/* Start of initializing cache arrays */
			char*** cache = (char***)malloc(rows*sizeof(char**));
			for (int row=0; row<rows; row++) {
				char** k = (char**)malloc(columns*sizeof(char*));
				cache[row] = k;

				for (int cell=0; cell<columns; cell++) {
					char* k = (char*)malloc(data[cell].Len()*sizeof(char));
					cache[row][cell] = k;

					for (int i=0; i<data[cell].Len(); i++)
						cache[row][cell][i] = t[row][cell][i];
				}
			}

			ColumnData* dataCache = (ColumnData*)malloc(columns*sizeof(ColumnData));
			for (int i=0; i<columns; i++)
				dataCache[i] = data[i];
			/* End of initializing cache arrays */

			// Clearing away all of the memory contained in the main table after the id-column and it itself.
			for (int row=0; row<rows; row++) {
				for (int cell=0; cell<columns; cell++) {
					free(t[row][cell]);
				}
				free(t[row]);
			}
			free(data);

			columns++;

			// Rewriting data to ColumnData array, then clearing away cache array
			data = (ColumnData*)malloc(columns*sizeof(ColumnData));
			for (int i=0; i<columns; i++) {
				if (i<id) data[i] = dataCache[i];
				else if (i==id) data[i] = c;
				else data[i] = dataCache[i+1];
			}
			free(dataCache);

			// Rewriting data to main table array, then clearing away cache array
			for (int row=0; row<rows; row++) {
				char** k = (char**)malloc(columns*sizeof(char*));
				t[row] = k;
				for (int cell=0; cell<columns; cell++) {
					char* k = (char*)malloc(data[cell].Len()*sizeof(char));
					t[row][cell] = k;
					if (cell<id) {
						for (int i=0; i<cell; i++)
							t[row][cell][i] = cache[row][cell][i];

					} else if (cell==id) {
						for (int i=0; i<cell; i++)
							t[row][cell][i] = '1';

					} else if (cell>id) {
						for (int i=0; i<cell; i++)
							t[row][cell][i] = cache[row][cell-1][i];
					}
				}
			}

			for (int row=0; row<rows; row++) {
				for (int cell=0; cell<columns-1; cell++)
					free(cache[row][cell]);
				free(cache[row]);
			}
			free(cache);
		}

        void SetData(int x, int y, char* d)
        {
            for (int i=0; i<data[x].Len(); i++)
                t[y][x][i] = d[i];
            free(d);
        }

        void SortBy(int x, bool mode)
        {
            // In progress...
        }

        void Clear()
        {
            for (int row=0; row<rows; row++) {
				for (int cell=0; cell<columns; cell++) {
					free(t[row][cell]);
				}
				free(t[row]);
			}
			free(t);
			free(data);
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
            ColumnData* cols = (ColumnData*)malloc(0);
            for (int i=0; i<sizeC; i++) {
            	string name; int len;
				lang? cout << "\nEnter the name of the column №" << i << ": " : cout << "Введите название столбца №" << i+1 << ": ";
				cin >> name;
				getline(cin, name);
				lang? cout << "\nEnter the length of the column №" << i << ": " : cout << "Введите длину столбца №" << i+1 << ": ";
				cin >> len;

                realloc(cols, (i+1)*sizeof(ColumnData));
                ColumnData k(len, name);
				cols[i] = k;
			}
			lang? cout << "Enter initial quantity of rows: " : cout << "Введите начальное кол-во строк: ";
            cin >> sizeR;

            Table t(sizeR, sizeC, cols);

            // In progress...

            //ColumnData f(1, "a");
            //t.AddColumn(1, f);


        } else if (i=="o" || i=="O" || i=="щ" || i=="Щ") {
            /* DB opening and work with it */
            // In progress...
        }
        else if (i=="p" || i=="P" || i=="з" || i=="З") {
            /* Settings menu */

			while (true) {
				lang? cout << "Preferences:\n"          : cout << "Настройки:\n";
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
