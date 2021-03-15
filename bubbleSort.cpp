//#include <windows.h>

void bubbleSort(float *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
       for (int j = 0; j < arrSize - i; j++) {
           if (arr[j] > arr[j+1]) {
               int tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
//               Sleep(2);
           }
       }
    }
}