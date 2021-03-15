#include <stdlib.h>
#include <time.h>

void shuffleArray(float *arr, int arrSize) {
    if(arrSize > 1) {
        srand(time(NULL));
        for(int i = 0; i < arrSize - 1; i++) {
            int newVal = i + rand() / (RAND_MAX / (arrSize - i) + 1);
            int tmp = arr[newVal]; //
            arr[newVal] = arr[i]; //swap values
            arr[i] = tmp; //
        }
    }
}