#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "renderer.hpp"
#include "algorithms/bubbleSort.hpp"
#include "algorithms/quickSort.hpp"
#include "algorithms/selectionSort.hpp"

void sortArr(sf::RenderWindow &window, int type, float *arr, int arrSize, sf::Text &text) {
    window.setTitle("Sorting...");
    sf::SoundBuffer buffer;
    buffer.loadFromFile("audio/beep.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.0f);

    float B [arrSize];
    switch (type) {
    case 0:
        text.setString("Bubble Sort - Delay: 0ms");
        bubbleSort(window, arr, arrSize);
        break;
    case 1:
        text.setString("Quick Sort  - Delay: 1ms");
        quicksort(arr, 0, arrSize - 1, window, sound);
        for(int i = 0; i < arrSize; i++) {
            sound.setPitch((1.0f + arr[i])/ 100.0f);
            sound.play();
            updateRects(window, arr, arrSize, i);
            delay(1);
        }
        window.setTitle("Sorting Visualizer - SORTED");
        break;
    case 2:
        text.setString("Selection Sort - Delay: 1ms");
        selectionSort(window, arr, arrSize, sound);
        window.setTitle("Sorting Visualizer - SORTED");
    default:
        break;
    }
}