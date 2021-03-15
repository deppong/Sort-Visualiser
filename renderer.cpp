#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>

void delay(int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void updateRects(sf::RenderWindow &window, float *arr, int numOfRect) {
    static int width = 1280;
    static int height = 720;
    float deltaX = width/float(numOfRect);
    float deltaY = height/float(numOfRect);


    window.clear(sf::Color::Black);
    for(int i = 0; i < numOfRect; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(deltaX , deltaY*arr[i]));//make a rectangle with the width being deltaX and the height the size of the monitor - the value it corrisponds to.
        rectangle.setFillColor(sf::Color::White);
        rectangle.move(deltaX*i, height-(deltaY*arr[i]));

        window.draw(rectangle);
    }
    window.display();
}
void shuffleArray(sf::RenderWindow &window, float *arr, int arrSize) {
    if(arrSize > 1) {
        srand(time(NULL));
        for(int i = 0; i < arrSize - 1; i++) {
            int newVal = i + rand() / (RAND_MAX / (arrSize - i) + 1);
            int tmp = arr[newVal]; //
            arr[newVal] = arr[i]; //swap values
            arr[i] = tmp; //
            delay(1);
            updateRects(window, arr, arrSize);
        }
        
    }
}

