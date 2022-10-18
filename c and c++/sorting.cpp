#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
void bubble_sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    display(a, size);
}
void selection_sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    display(a, size);
}
void insertion_sort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                while (i > j)
                {
                    a[i] = a[i - 1];
                    i--;
                }
                a[i] = temp;
                break;
            }
        }
    }
    display(a, size);
}
void merge_sort(int a[], int size)
{
    int c = size / 2;
    for (int i = 0; i < c - 1; i++)
        for (int j = i + 1; j < c; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for (int i = c; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    int i = 0, j = c, k = 0, b[size];
    while ((i < c) && (j < size))
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i < c)
        b[k++] = a[i++];
    while (j < size)
        b[k++] = a[j++];
    display(b, size);
}
int split(int a[], int lower, int upper)
{
    int pivot = a[upper];
    int i = (lower - 1);
    for (int j = lower; j <= upper - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[upper];
    a[upper] = temp;
    return (i + 1);
}
void quickSort(int a[], int lower, int upper, int size = 0)
{
    int i;
    if (lower < upper)
    {
        i = split(a, lower, upper);
        quickSort(a, lower, i - 1);
        quickSort(a, i + 1, upper);
    }
    display(a, size);
}
void shellSort(int a[], int size)
{
    for (int k = size / 2; k > 0; k /= 2)
    {
        for (int i = k; i < size; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= k && a[j - k] > temp; j -= k)
                a[j] = a[j - k];
            a[j] = temp;
        }
    }
    display(a, size);
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int a[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(a, size, i);
    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
    display(a, size);
}
int getMax(int a[], int size)
{
    int mx = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
void countSort(int a[], int size, int exp)
{
    int output[size];
    int i, count[10] = {0};
    for (i = 0; i < size; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < size; i++)
        a[i] = output[i];
}
void radix_sort(int a[], int size)
{
    int m = getMax(a, size);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, size, exp);
    display(a, size);
}
int main()
{
    int a[] = {101, 99, 88, 100, 77, 76, 40, 32, 33, 10};
    int size = 10;
    bubble_sort(a, size);
    getch();
    return 0;
}
