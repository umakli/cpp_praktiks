#include <iostream>
#include <windows.h>
#include <stdio.h>   
#include "Shape.h"   
#include "Triangle.h"     
#include "Rhomb.h"  
#include "Isostrape.h"
#include "RingSector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 2  ВАРИАНТ-17\n";
    auto author = []()
        {
            cout << "Макрецова Полина БББО-23-24" << endl;
        };
    author();

    Shape* shapes[4];
    shapes[0] = new RingSector(20, 10, 65);
    shapes[1] = new Triangle(12, 16, 20);
    shapes[2] = new Rhomb(23, 5);
    shapes[3] = new Isostrape(3,4,5,6);

    for (int i = 0; i < 4; ++i)
    {
        cout << "Фигура " << i + 1 << ": ";
        shapes[i]->display();
        cout << endl;
        cout << "Площадь: " << shapes[i]->Area() << endl;
        cout << "Периметр: " << shapes[i]->Perimetr() << endl;
        cout << endl;
    }

    char fileName[20]="log.txt";

    ofstream outfile(fileName, ios_base::out);
    if (!outfile.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return -1;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            shapes[i]->SaveToFIle(outfile);
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        delete shapes[i];
    }
    return 0;
}