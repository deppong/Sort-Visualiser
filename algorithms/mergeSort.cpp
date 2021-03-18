#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../renderer.hpp"

//https://en.wikipedia.org/wiki/Merge_sort

void copyArray(float *A, int arrSize, float *B) {
    for(int i = 0; i < arrSize; i++) {
        B[i] = A[i];
    }
}

void merge(float arr[], int start, int middle, int end, sf::RenderWindow &window) {
    int n1 = middle - start + 1;
    int n2 = end - middle;

    float L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + 1];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    
    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    } 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    updateRects(window, arr, 250, k);
}

void splitMerge(float *arr, int start, int end, sf::RenderWindow &window) {
    if (start >= end) {
        return;
    }
    int middle = start +(end - start) / 2;
    splitMerge(arr, start, middle, window); //Left
    splitMerge(arr, middle + 1, end, window); //Right
    merge(arr, start, middle, end, window);
}

void mergeSort(float *arr, int arrSize, sf::RenderWindow &window) {
    //copyArray(arr, arrSize, B);
    splitMerge(arr, 0, arrSize, window);
}