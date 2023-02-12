/*Программа сравнения скорости разных методов сортировки*/

#include <chrono>

#include <algorithm>
#include <iostream>

void randArray(float array[], int size)
{
	for (int i = 0; i < size; i++) {
		array[i] = rand();
	}

}

void heapify(float arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(float arr[], int n)
{
	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		std::swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

void insertionSort(float array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && array[j - 1] < array[j])
		{
			std::swap(array[j - 1], array[j]);
			j--;
		}
	}
}

void bubbleSort(float array[], int size)
{
	bool b = true;
	while (b)
	{
		b = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] < array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
				b = true;
			}
		}
	}
}

// Основная функция, выполняющая  сортировку пузырьком
void bubbleSortMy(float arr[], int n)
{
	// Двойной проход по массиву
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void shakeSort(float array[], int size)
{
	bool b = true;
	int beg = 0 - 1; // Imaginative int l = 0.
	int end = size - 1;

	while (b)
	{
		b = false;
		beg++;
		for (int i = beg; i < end; i++)
		{
			if (array[i] < array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
				b = true;
			}
		}
		if (!b)
			break;

		end--;

		for (int i = end; i > beg; i--)
		{
			if (array[i] > array[i - 1])
			{
				std::swap(array[i], array[i - 1]);
				b = true;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int r = 20000; // 1'000'000;
	float numbers[20000];

	
	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		insertionSort(numbers, r);
		/*for (int i = 0; i < r; i++) {
		std::cout << numbers[i] << " ";
	}*/
	std::cout << std::endl;
		std::cout << "insertionSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		bubbleSort(numbers, r);
		std::cout << "bubbleSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}


	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		bubbleSort(numbers, r);
		std::cout << "bubbleSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		shakeSort(numbers, r);
		std::cout << "shakeSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		heapSort(numbers, r);
		std::cout << "heapSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

	{
		randArray(numbers, r);
		auto start = std::chrono::system_clock::now();
		std::sort(numbers, &numbers[r]);
		std::cout << "std::sort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}
}