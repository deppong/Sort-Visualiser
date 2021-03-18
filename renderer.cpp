#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>



void delay(int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void updateRects(sf::RenderWindow &window, float *arr, int numOfRect, int pointerIndex) {

    static int width = 1280;
    static int height = 720;
    float deltaX = width/float(numOfRect);
    float deltaY = height/float(numOfRect);


    window.clear(sf::Color::Black);
    for(int i = 0; i < numOfRect; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(deltaX , deltaY*arr[i]));//make a rectangle with the width being deltaX and the height the size of the monitor - the value it corrisponds to.
        if(arr[pointerIndex] == arr[i]) {
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
    sf::SoundBuffer buffer;
    buffer.loadFromFile("audio/beep.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.0f);
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
            sound.setPitch((1.0f + arr[i]) / 100.0f);
            sound.play();
            delay(1);
            updateRects(window, arr, arrSize, i);
        }
        
    }
    window.setTitle("Sort Visualizer - Shuffled");
}

