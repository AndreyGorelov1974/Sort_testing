#include <chrono>

#include <algorithm>
#include <iostream>

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
    int r = 1000000; // 1'000'000;
    float numbers[1000000];

    {
        for (int i = 0; i < r; i++)
            numbers[i] = rand();

        auto start = std::chrono::system_clock::now();
        insertionSort(numbers, r);
        std::cout << "insertionSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
    }

    {
        for (int i = 0; i < r; i++)
            numbers[i] = rand();

        auto start = std::chrono::system_clock::now();
        bubbleSort(numbers, r);
        std::cout << "bubbleSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
    }

    {
        for (int i = 0; i < r; i++)
            numbers[i] = rand();

        auto start = std::chrono::system_clock::now();
        shakeSort(numbers, r);
        std::cout << "shakeSort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
    }

    {
        for (int i = 0; i < r; i++)
            numbers[i] = rand();

        auto start = std::chrono::system_clock::now();
        std::sort(numbers, &numbers[r]);
        std::cout << "std::sort - " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
    }
}