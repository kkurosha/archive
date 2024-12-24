#include <iostream>
using namespace std;

void stooge_sort(int arr[], int start, int end) {
	if (arr[start] > arr[end]) {    // если первый элемент больше последнего, 
		swap(arr[start], arr[end]); // меняем их местами
	}
	if (end - start + 1 > 2) {                 // если в отрезке не менее трех элементов 
		int temp = (end - start + 1) / 3;	   // 1/3 элемента
		stooge_sort(arr, start, end - temp);   // вызываем stooge sort для первых 2/3 отрезка
		stooge_sort(arr, start + temp, end);   // вызываем stooge sort для последних 2/3 отрезка
		stooge_sort(arr, start, end - temp);   // вызываем stooge sort для первых 2/3 отрезка снова
	}
	return;
}
int main() {
	int arr[] = {2, 4, 5, 3, 1};            // массив чисел
	stooge_sort(arr, 0, size(arr) - 1);     // сортируем с помощью функции
	for (int i = 0; i < size(arr); i++) {   // вывод
		cout << arr[i] << " ";
	}
}