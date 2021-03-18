#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "../renderer.hpp"

void swap(float* a, float* b) { 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 

int partition (float *arr, int low, int high, sf::RenderWindow &window, float *compArr) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            updateRects(window, arr, 250, compArr);
            //delay(1);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    updateRects(window, arr, 250, compArr);
    //delay(1);
    return (i + 1);
}

void quicksort (float *arr, int low, int high, sf::RenderWindow &window) {
    float compArr[250];
    for (int i = 0; i < 250; i++)
        compArr[i] = arr[i];
    if (low < high) {
        int p = partition(arr, low, high, window, compArr);
        quicksort(arr, low, p - 1, window);
        quicksort(arr, p + 1, high, window);
    }
}