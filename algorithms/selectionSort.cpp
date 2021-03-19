#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../renderer.hpp"
 
void selectionSort(sf::RenderWindow &window, float* arr, int arrSize, sf::Sound &sound) {
    int tmp, min;

    for(int i = 0; i < arrSize - 1; i++) {
        min = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[min] > arr[j]) {
                min = j;
                sound.setPitch((1.0f + arr[i])/ 100.0f);
                sound.play();
                updateRects(window, arr, arrSize, j);
                delay(1);
            }

        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        sound.setPitch((1.0f + arr[i])/ 100.0f);
        sound.play();
        updateRects(window, arr, arrSize, i);
        delay(1);
    }
    for(int i = 0; i < arrSize; i++) {
        sound.setPitch((1.0f + arr[i])/ 100.f);
        sound.play();
        updateRects(window, arr, arrSize, i);
        delay(1);
    }
}

