#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../renderer.hpp"

void bubbleSort(sf::RenderWindow &window, float *arr, int arrSize) {
    bool swapped;
    float compArr[arrSize];


    for (int i = 0; i < arrSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < arrSize - i - 1; j++) {
           if (arr[j] > arr[j+1]) {
                for (int i = 0; i < arrSize; i++)
                    compArr[i] = arr[i];
               int tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
               swapped = true;
               updateRects(window, arr, arrSize, compArr);
            }
        }
        if(!swapped) {
            break;
        }
    }
}