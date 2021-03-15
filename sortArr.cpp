#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "algorithms/bubbleSort.hpp"
#include "algorithms/gnuSort.hpp"

void sortArr(sf::RenderWindow &window, int type, float *arr, int arrSize) {
    switch (type) {
    case 0:
        bubbleSort(window, arr, arrSize);
        break;
    case 1:
        gnuSort(window, arr, arrSize);
    default:
        break;
    }
}