#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// формує матрицю a випадковими числами з діапазону [Low; High]
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// виводить матрицю a у вигляді таблиці
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// міняє місцями рядки row1 та row2
void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

// впорядковує рядки матриці за ключами  ↑ ↑ ↓ (стовпчики 1, 2, 3)
// методом обміну ("бульбашки")
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] > a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] == a[i1 + 1][1] &&
                    a[i1][2] < a[i1 + 1][2]))
                Change(a, i1, i1 + 1, colCount);
}

// критерій: всі, крім додатних, хоча б один індекс яких - непарний
bool IsMatch(const int x, const int i, const int j)
{
    return !(x > 0 && (i % 2 != 0 || j % 2 != 0));
}

// обчислює суму S та кількість k елементів, які задовольняють критерію,
// і замінює ці елементи нулями
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (IsMatch(a[i][j], i, j))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -41;          // нижня межа діапазону значень
    int High = 23;          // верхня межа діапазону значень
    int rowCount = 7;       // кількість рядків матриці T
    int colCount = 9;       // кількість стовпчиків матриці T

    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High);
    Print(T, rowCount, colCount);

    Sort(T, rowCount, colCount);
    Print(T, rowCount, colCount);

    int S = 0;              // сума елементів, що задовольняють критерію
    int k = 0;              // кількість таких елементів
    Calc(T, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(T, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] T[i];
    delete[] T;

    return 0;
}
