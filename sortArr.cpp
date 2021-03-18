#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "renderer.hpp"
#include "algorithms/bubbleSort.hpp"
#include "algorithms/quickSort.hpp"

void sortArr(sf::RenderWindow &window, int type, float *arr, int arrSize) {
    window.setTitle("Sorting...");
    float B [arrSize];
    switch (type) {
    case 0:
        bubbleSort(window, arr, arrSize);
        break;
    case 1:
        quicksort(arr, 0, arrSize - 1, window);
        window.setTitle("Sorting Visualizer - SORTED");
    default:
        break;
    }
}