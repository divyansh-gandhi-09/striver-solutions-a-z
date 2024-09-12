#include<stdio.h>
void bubble_sort(int arr1[], int size_arr) {
    for (int i = 0; i < size_arr - 1; i++) {
        for (int j = 0; j < size_arr - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr1[], int size_arr) {
    for (int i = 0; i < size_arr - 1; i++) {
        int min_ele = i;
        for (int j = i + 1; j < size_arr; j++) {
            if (arr1[j] < arr1[min_ele]) {
                min_ele = j;
            }
        }
        int temp = arr1[min_ele];
        arr1[min_ele] = arr1[i];
        arr1[i] = temp;
    }
}

void insertion_sorting(int arr1[], int size_arr) {
    int key, j;
    for (int i = 1; i < size_arr; i++) {
        key = arr1[i];
        j = i;
        while ((j > 0) && (arr1[j-1] > key)) {
            arr1[j] = arr1[j-1];
            j--;
        }
        arr1[j] = key;
    }
}

int main() {
    printf("Menu driven program\nChoose the option to sort the array:\n(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n");
    int size_arr, choice;

    printf("Enter the size of array to be sorted: ");
    scanf("%d", &size_arr);

    int arr1[size_arr];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size_arr; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubble_sort(arr1, size_arr);
            break;
        case 2:
            selection_sort(arr1, size_arr);
            break;
        case 3:
            insertion_sorting(arr1, size_arr);
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Sorted array:\n");
    for (int i = 0; i < size_arr; i++) {
        printf("%d ", arr1[i]);
    }
    return 0;
}