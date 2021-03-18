#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../renderer.hpp"

void bubbleSort(sf::RenderWindow &window, float *arr, int arrSize) {
    bool swapped;
    float compArr[arrSize];

    sf::SoundBuffer buffer;
    buffer.loadFromFile("audio/beep.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.0f);

    for (int i = 0; i < arrSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < arrSize - i - 1; j++) {
           if (arr[j] > arr[j+1]) {
                for (int i = 0; i < arrSize; i++)
                    compArr[i] = arr[i];
               int tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
               swapped = true;
               sound.setPitch((1.0f + arr[j])/ 100.0f);
               sound.play();
               updateRects(window, arr, arrSize, j);
               //delay(1);
            }
            sound.setPitch((1.0f + arr[j])/ 100.0f);
            sound.play();
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.setTitle("SORTING STOPPED");
            break;
        }
        if(!swapped) {
            for (int i = 0; i < arrSize; i++) {
                sound.setPitch((1.0f + arr[i])/ 100.0f);
                sound.play();
                updateRects(window, arr, arrSize, i);
                delay(1);
            }
            window.setTitle("Sort Visualizer - Sorted");
            break;
        } 
    }
}