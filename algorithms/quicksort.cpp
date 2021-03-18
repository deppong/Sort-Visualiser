#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "../renderer.hpp"

void swap(float* a, float* b) { 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 

int partition (float *arr, int low, int high, sf::RenderWindow &window, float *compArr, sf::Sound &sound) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            sound.setPitch((1.0f + arr[j]) / 100.f);
            sound.play();
            updateRects(window, arr, 255, j);
            delay(1);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    updateRects(window, arr, 255, i);
    delay(1);
    return (i + 1);
}

void quicksort (float *arr, int low, int high, sf::RenderWindow &window, sf::Sound &sound) {
    float compArr[255];
    for (int i = 0; i < 255; i++)
        compArr[i] = arr[i];
    if (low < high) {
        int p = partition(arr, low, high, window, compArr, sound);
        quicksort(arr, low, p - 1, window, sound);
        quicksort(arr, p + 1, high, window, sound);
    }
}