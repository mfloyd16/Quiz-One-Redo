/**
 * @file main.cpp
 * @author Michael Floyd
 * @date 2025-01-27
 * @brief Quiz One Redo
 * 
 * I am redoing question 2 from our first quiz to hopefully get points back.
 */

#include <iostream>
#include <fstream>

using namespace std;


/**
 * Takes an array and fills it with numbers from a file.
 *
 * @param int* array will be the static array that the user chooses the size of.
 * @param int size will be the size of array and the amount of numbers we will pull from file.
 * @param string fileName The name of the file that will hold the numbers that fill array.
 * 
 * @return void  
 * 
 */
void fillArray(int* array, int size, string fileName);


/**
 * this function will pring out the array, atleast to the users size
 *
 * @param const int* array Our array of numbers gathered from file
 * @param int size user inputed size for array
 * 
 * @return void  
 * 
 */
void printArray(const int* array, int size);


/**
 * this will take the average of all the numbers in our array.
 *
 * @param const int* array the array with our numbers that are from a file
 * @param int size the user input size of the array
 * 
 * @return double  
 * 
 */
double averageOfArray(const int* array, int size);


int main() {

  int size; // The size variable for user input
  
  cout << "Please give me a size for our array: "; // Ask user for size of array
  cin >> size; // Recieves user input

  // Exception handling for size
  while (size > 100) {
    cout << "Sorry your number is greater than what I have in my file, Please pick a number 100 or below." << endl;
    cin >> size;
  }

  while (size < 1) {
    cout << "Sorry but we need atleast 1 number for this array, Please pick a number greater than 0." << endl;
    cin >> size;
  }
  
  int* array = new int[size]; // Dynamic array taking the users inputed size

  fillArray(array, size, "NUMBERS.txt"); // Filling array with numbers from file,up to user size

  printArray(array, size); // List of the numbers in the array

  cout << "The average of this array is " << averageOfArray(array, size) << endl; // Calculates total average of array and prints it

  delete [] array; // Deallocate the memory, dont want a leak
  return 0;
}

// All functions take a pointer array and user size input now.
void fillArray(int* array, int size, string fileName) {

  int i = 0;
  int value;
  
  ifstream infile(fileName); //opens up file also has exception handling
  if (!infile) {
    cerr << "Could not open file!" << endl;
    return;
  }

  cout << "This is the list of numbers in our array V" << endl;
  
  //priming read for sentinal loop V
  infile >> value;
  array[i] = value;
  
  while (infile && i < size) { //while loop that incriments up to user size while in file
    i++;
    infile >> value;
    array[i] = value;
  }

  infile.close(); // made sure to close file
}


void printArray(const int* array, int size) {

  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
  
}

double averageOfArray(const int* array, int size) {

  double sum = 0;
  
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }

  return sum/size; // Average = sum / size
}
