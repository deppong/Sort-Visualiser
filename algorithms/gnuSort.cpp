#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../renderer.hpp"

void gnuSort(sf::RenderWindow &window, float *arr, int arrSize) {
    std::sort(arr, arr + arrSize);
    //updateRects(window, arr, arrSize, arr);
}