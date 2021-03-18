#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>



void delay(int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void updateRects(sf::RenderWindow &window, float *arr, int numOfRect, float *compArr = NULL) {

    static int width = 1280;
    static int height = 720;
    float deltaX = width/float(numOfRect);
    float deltaY = height/float(numOfRect);


    window.clear(sf::Color::Black);
    for(int i = 0; i < numOfRect; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(deltaX , deltaY*arr[i]));//make a rectangle with the width being deltaX and the height the size of the monitor - the value it corrisponds to.
        if(compArr[i] != arr[i]) {
            rectangle.setFillColor(sf::Color::Red);
        } else {
            rectangle.setFillColor(sf::Color(64, 128, arr[i]));
        }
        rectangle.move(deltaX*i, height-(deltaY*arr[i]));

        window.draw(rectangle);
    }
    window.display();
}

void shuffleArray(sf::RenderWindow &window, float *arr, int arrSize) {
    window.setTitle("Shuffling... ");
    if(arrSize > 1) {
        srand(time(NULL));
        float compArr[arrSize];

        for(int i = 0; i < arrSize - 1; i++) {
            for (int i = 0; i < arrSize; i++)
                compArr[i] = arr[i];
            int newVal = i + rand() / (RAND_MAX / (arrSize - i) + 1);
            int tmp = arr[newVal]; //
            arr[newVal] = arr[i]; //swap values
            arr[i] = tmp; //
            delay(1);
            updateRects(window, arr, arrSize, compArr);
        }
        
    }
    window.setTitle("Sort Visualizer - Shuffled");
}

