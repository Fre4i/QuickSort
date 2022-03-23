#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void quicksort(int* mas, int first, int last, long long int &C, long long int &M)
{
    int mid;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        C++;
        while (mas[f] < mid) { f++; C++; }
        while (mas[l] > mid) { l--; C++; }
        if (f <= l) //перестановка элементов
        {
            swap(mas[f], mas[l]);
            M++;

            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l, C, M);
    if (f < last) quicksort(mas, f, last, C, M);
}

//Вывод массива
void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");

    int n = 6;

    int* arr = new int[n];
    arr[0] = 12;
    arr[1] = 11;
    arr[2] = 13;
    arr[3] = 5;
    arr[4] = 6;
    arr[5] = 7;

    cout << "Массив до сортировки:\n";
    printArray(arr, n);


    auto start = high_resolution_clock::now(); //Время
    //Инициализация счётчиков 
    long long int C = 0;
    long long int M = 0;

    quicksort(arr, 0, n - 1, C, M);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Время выполнения алгоритма: "
        << (double)duration.count() / 100.0 << " мс" << endl;
    cout << "C = " << C << endl;
    cout << "M = " << M << endl;
    cout << "C + M = " << C + M << endl;


    cout << "Массив после сортировки:\n";
    printArray(arr, n);

    return 0;
}