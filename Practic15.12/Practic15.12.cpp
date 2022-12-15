#include <iostream>

using namespace std;

void printArr(int arr[][4], int s, int r) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < r; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
   
}
    /*
    Дан одномерный массив целых чисел. Напишите
    рекурсивную функцию, которая осуществляет нахождения
    искомого значения с помощью бинарного поиска. 
    Функция возвращает позицию вхождения искомого значения.
    */
void sortArr(int arr[], int s) {
    int temp;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int f1(int arr[], int start, int end, int elem) {
    int num = (start + end) / 2;
    if (elem < arr[num]) {
        end = num - 1;
    }
    else if (elem > arr[num]) {
        start = num + 1;
    }
    else return num;

    if (start > end)
        return -1;

    f1(arr, start, end, elem);
}
/*
Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива вправо.
Например:
Дан массив:
    4 5 6 7
    1 2 4 1
    4 5 6 9
Сдвигаем на три вправо:
    5 6 7 4
    2 4 1 1
    5 6 9 4
*/
void f2(int arr[][4], int row, int col, int k) {
    if (k > 0) {
        for (int i = 0; i < row; i++) {
            int temp = arr[i][col - 1];
            for (int j = col - 1; j >= 1; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
        f2(arr, row, col, --k);
    }
}
/*
    Напишите рекурсивную функцию, которая
    принимает двухмерный массив целых чисел и количество
    сдвигов и выполняет круговой сдвиг массива влево.
    Например
    Дан массив:
        4 5 6 7
        1 2 4 1
        4 5 6 9
    Сдвигаем на два влево:
        6 7 4 5
        4 1 1 2
        6 9 4 5
    */
void f3(int arr[][4], int row, int col, int k) {
    if (k > 0) {
        for (int i = 0; i < row; i++) {
            int temp = arr[i][0];
            for (int j = 0; j < col - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][col - 1] = temp;
        }
        f3(arr, row, col, --k);
    }
}
/*
Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива вниз.
Например:
Дан массив:
    4 5 6 7
    1 2 4 1
    4 3 6 8
Сдвигаем низ на один:
    4 3 6 8
    4 5 6 7
    1 2 4 1
*/
void f4(int arr[][4], int row, int col, int k) {
    if (k > 0) {
        for (int j = 0; j < col; j++) {
            int temp = arr[row - 1][j];
            for (int i = row - 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = temp;
        }
        f4(arr, row, col, --k);
    }
}

int main()
{
    /*const int size = 10;
    int arr[size]{ 5,9,3,1,7,6,4,5,0,8 };
    sortArr(arr, size);
    printArr(arr, size);
    cout << f1(arr, 0, size - 1, 15);*/

    const int row = 3;
    const int col = 4;
    int arr[row][col] = 
    { 4, 5, 6, 7,
      1, 2, 4, 1,
      4, 5, 6, 9 };

    f4(arr, row, col, 2);
    printArr(arr, row, col);


}
