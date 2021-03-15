#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../renderer.hpp"

void bubbleSort(sf::RenderWindow &window, float *arr, int arrSize) {
    bool swapped;
    for (int i = 0; i < arrSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < arrSize - i - 1; j++) {
           if (arr[j] > arr[j+1]) {
               int tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
               swapped = true;
               delay(1);
               updateRects(window, arr, arrSize);
            }
        }
        if(!swapped) {
            break;
        }
    }
}