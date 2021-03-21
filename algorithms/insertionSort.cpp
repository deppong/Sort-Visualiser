#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "../renderer.hpp"

void insertionSort(sf::RenderWindow &window, float *arr, int arrSize, sf::Sound &sound) {
    int i = 1;
    while (i < arrSize) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            int tmp;
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j - 1] = tmp;
            sound.setPitch((1.0f + arr[j]) / 100.f);
            sound.play();
            updateRects(window, arr, 255, j);
            j = j - 1;
        }
        sound.setPitch((1.0f + arr[i]) / 100.f);
        sound.play();
        updateRects(window, arr, 255, i);
        i += 1;
    }
}