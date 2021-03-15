void bubbleSort(float *arr, int arrSize) {
    bool swapped;
    for (int i = 0; i < arrSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < arrSize - i - 1; j++) {
           if (arr[j] > arr[j+1]) {
               int tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
               swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}