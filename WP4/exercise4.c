// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 4
// Submission code: 4468947 (provided by your TA-s)

#include <stdio.h>

// Function to search for a number in an array
int search_number(int number, int tab[], int size);

// Function to sort an array using bubble sort
void sort(int tab[], int size);

int main()
{
  // Array initialization
  int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
  int arraySize = sizeof(test) / sizeof(test[0]);

  // Test the search function
  int searchNumber = 23;
  int searchResult = search_number(searchNumber, test, arraySize);

  // Output search result
  if (searchResult != -1)
  {
    printf("%d is found at index %d\n", searchNumber, searchResult);
  }
  else
  {
    printf("%d is not found in the array\n", searchNumber);
  }

  // Test the sorting function
  sort(test, arraySize);

  // Print the sorted array
  printf("Sorted array: ");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", test[i]);
  }
  printf("\n");

  return 0;
}

// Function to search for a number in an array
int search_number(int number, int tab[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (tab[i] == number)
    {
      return i; // Return the index of the first occurrence
    }
  }
  return -1; // Number not found in the array
}

// Function to sort an array using bubble sort
void sort(int tab[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (tab[j] > tab[j + 1])
      {
        // Swap the elements if they are in the wrong order
        int temp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = temp;
      }
    }
  }
}
