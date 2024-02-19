// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 4
// Submission code: 021513 (provided by your TA-s)

#include <stdio.h>

// linear search
int search_number(int number, int tab[], int size) {
  // Loop through each element in the array
  for (int i = 0; i < size; i++) {
    // If the current element matches the number we're looking for
    if (number == tab[i])
      // Return the position (1-indexed) of the found number
      return (i + 1);
  }
  // If the number is not found in the array, return -1
  return -1;
}

// Swap two elements in an array
void swap(int* arr, int i, int j) {
  // Store the first element in a temporary variable
  int temp = arr[i];
  // Swap the first element with the second
  arr[i] = arr[j];
  // Place the temporary (initial first element) into the second's position
  arr[j] = temp;
}

// Print all elements of an array, separated by dashes
void printArray(int tab[], int size){
  // Loop through each element in the array
  for (short i = 0; i < size; i++) {
    // Print the current element followed by a dash
    printf("%d-", tab[i]);
  }
  // End the line after printing all elements
  printf("\n");
}

// Sort an array using a simple sorting algorithm
void sort(int tab[], int size){
  // Loop through the array elements
  for (int i = 0; i < size - 1; i++) {
    // Nested loop to compare array elements
    for (int j = i + 1; j < size - i - 1; j++) {
      // If the current element is greater than the next
      if (tab[i] > tab[j]) {
        // Swap them to sort
        swap(tab, i, j);
      }
    }
  }
}

// Main function to execute the program
int main(void) {
  // Initialize an array with some test numbers
  int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
  // Calculate the size of the array
  int size = sizeof(test) / sizeof(test[0]);
  // Search for the number 34 in the array and print its position
  printf("Search in position Number:%d\n", search_number(34, test, size));

  // Sort the array
  sort(test, size);
  // Print the sorted array
  printf("sorted array: ");
  printArray(test, size);

  // Search again for the number 34 in the sorted array and print its new position
  printf("Search after sorting in position Number :%d\n", search_number(34, test, size));
  
  // End of the main function
  return 0;
}
