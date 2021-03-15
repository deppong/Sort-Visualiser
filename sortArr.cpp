#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "algorithms/bubbleSort.hpp"

void sortArr(sf::RenderWindow &window, int type, float *arr, int arrSize) {
    switch (type) {
    case 0:
        bubbleSort(window, arr, arrSize);
        break;
    default:
        break;
    }
}