#include <iostream>
#include <fstream>
#include "Interface.h"
int getWords();

int main()
{
    setlocale(LC_ALL, "Russian");
    Interface Table;
    char menu;
    int iCount;
    do
    {
        system("cls");
        cout << "----------| МЕНЮ |----------" << endl;
        cout << "1. Добавить поезд" << endl
             << "2. Извлечь поезд" << endl
             << "3. Сортировать поезда по алфавиту" << endl
             << "4. Вывести список поездов" << endl
             << "5. Поиск поездов по времени" << endl
             << "6. Сосчитать кол-во слов в файле" << endl
             << "0. Выход" << endl
             << "Выбор: ";
        cin >> menu;
        if (!(cin.peek() == '\n' || cin.peek() == EOF))
        {
            cin.ignore(INT_MAX, '\n');
            cout << "[Error] Введите пункт меню в пределах [0-4]" << endl;
            system("pause");
            continue;
        }
        cin.ignore(INT_MAX, '\n');
        switch (menu)
        {
        case '1':
            Table.add();
            break;
        case '2':
            Table.del();
            break;
        case '3':
            Table.sort();
            break;
        case '4':
            Table.print();
            break;
        case '5':
            Table.search();
            break;
        case '6':
            iCount = getWords();
            if (!(iCount == -1))
                cout << "Число слов : " << iCount << endl;
            break;
        case '0':
            return 0;
        default:
            cout << "[Error] Введите пункт меню в пределах [0-4]" << endl;
            break;
        }
        system("pause");
    } while (true);
    system("pause");
    return 0;
}

int getWords()
{
    try
    {
        ifstream file("Text.txt");
        int wordsCount = 0;
        int lengthWord = 0;
        string word;
        if (!file)
            throw(string) "Ошибка открытия файла";
        while (!file.eof())
        {
            getline(file, word);
            cout << word << endl;
            lengthWord = 0;
            for (int i = 0; i < word.size() + 1; i++)
            {
                if (word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z')
                    lengthWord++;
                else
                {
                    if (lengthWord < 5 && lengthWord > 0)
                        wordsCount++;
                    lengthWord = 0;
                }
            }
        }
        return wordsCount;
    }
    catch (string err)
    {
        cout << "[Error] " + err << endl;
        return -1;
    }
}
