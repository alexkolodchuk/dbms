#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* ������ ���������� */

typedef struct TColumnData {
    ;
} ColumnData;

/* ����� ���������� */

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
        lang? cout << "Welcome to MephDBMS.\n"                 : cout << "����� ���������� � �������.\n";
        lang? cout << "To create new spreadsheet, press N.\n"  : cout << "����� ������� ����� ����, ������� N.\n";
        lang? cout << "To open an already existing, press O.\n": cout << "����� ������� ������������, ������� O.\n";
        lang? cout << "To open preferences, press P.\n"        : cout << "����� ������� ���������, ������� P.\n";
        lang? cout << "To close MephDBMS, press Q.\n"          : cout << "����� ������� �������, ������� Q.\n";

        i = getchar();
        system("cls");
        if (i=='n' || i=='N' || i=='�' || i=='�') {
            // �������� ���� � ������ � ���
        } else if (i=='o' || i=='O' || i=='�' || i=='�') {
            // �������� ���� � ������ � ���
        }
        else if (i=='p' || i=='P' || i=='�' || i=='�') {
            // ��������� ��������

            // ���������:
            // [1] ����: �������
            // [2] ���������� ������
            // [3] ����� ������
            // [4] ����� � ������� ����
        }
        else if (i=='q' || i=='Q' || i=='�' || i=='�') return 0;
    }

    return 0;
}
