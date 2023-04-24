// 
// Name: Tang, Brandon
// Project: 3
// Due: 3/3/23
// Course: cs-2560-01-sp23 
// 
// Description: 
// A program that will perform statistical analysis for a set of integer values from a data file.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int readData(string infile_name, int numbers[], const int array_size);              
double calculateStats(int numbers[], int &count, double &SD, int &max, int &min);

int main()
{
       const int VALUE_PER_LINE = 10;                                               // Initialize variables                                 
       const int MAX_SIZE = 256;
       long int sum = 0;
       double SD, average = 0;
       int count = 0, perLine = 0;
       int max, min;

       ifstream infile;                                                             // Initialize in/out file streams
       ofstream outfile;

       int numbers[MAX_SIZE];                                                       // Initialize array

       cout << "Data Analysis by B. Tang" << endl;                                  // Project title
       cout << endl;

       string infile_name;                                                          // Initialize file names
       string outfile_name;
       
       cout << "Enter the input file name: ";                                       // User prompts
       cin >> infile_name;
       cout << endl;

       cout << "Enter the output file name: ";
       cin >> outfile_name;
       cout << endl;

       outfile.open(outfile_name);                                                  // Open output file

       if(!outfile)                                                                 // Check if output file can be created
       {      
              cerr << "Unable to create " << outfile_name << endl;                  // Error message
              outfile.close();
              return 1;
       }

       count = readData(infile_name, numbers, MAX_SIZE);                            // Call functions 
       average = calculateStats(numbers, count, SD, max, min);

       outfile << fixed;                                                            // Display calculated values in output file
       outfile << "File:    " << outfile_name << endl;
       outfile << "Count:   " << setw(4) << count << endl;
       outfile << "Highest: " << setw(4) << max << endl;
       outfile << "Lowest:  " << setw(4) << min << endl;
       outfile << "Average: " << fixed << setw(7) << setprecision(2) << average << endl;
       outfile << "Std Dev: " << fixed << setw(7) << setprecision(2) << SD << endl;
       outfile << "Data: " << endl;
       
       // Printing data in output file
       for (int i = 0; i < count; i++)                                              
       {
              outfile << setw(4) << numbers[i];
              if (++perLine == VALUE_PER_LINE)
              {
                     perLine = 0;
                     outfile << endl;
              }
              else 
              {
                     outfile << " ";
              }
       }

       // Reset line after printing
       if (perLine != 0)
       {
              outfile << endl;
       }

       outfile.close();

       return 0;
}

int readData(string infile_name, int numbers[], const int array_size)
{
       int count = 0;
       
       ifstream infile(infile_name);
       if (infile)                                                                  // Check if file exists
       {
              int value;                                               // Initialize variables
              while (infile >> value && count < array_size)                         // Read all values in file and check array size limit
              {
                     numbers[count] = value;                                        // Set array indexes to values
                     count++;                                                       // Increment count to update index
              }                                                 

              infile.close();                                                       // Close input file

              if (count == 0)                                                       // Check if file is empty
              {
                     cerr << "Empty input file." << endl;                           // Empty file message
                     exit(1);
              }
              else
              {
                     cout << count << " numbers processed." << endl;                // Read data successful message
              }
       }
       else
       {
              cerr << infile_name << " not found." << endl;                         // File not found message
              exit(1);
       }

       return count;
}

double calculateStats(int numbers[], int &count, double &SD, int &max, int &min)    // Call by reference
{
       long int sum = 0;                                                            // Initialize variables
       long double variance = 0;
       double average = 0, sum_dev = 0;
       max = numbers[0];
       min = numbers[0];

       for (int i  = 0; i < count; i++)                                             // Loop through array
       {
              if (numbers[i] > max)                                                 // Find maximum value
              {
                     max = numbers[i];
              }

              if (numbers[i] < min)                                                 // Find minimum value
              {
                     min = numbers[i];
              }

              sum += numbers[i];                                                    // Calculating sum
       }

       average = static_cast<double>(sum) / count;                                  // Calculating average

       for (int i = 0; i < count; i++)                                              // Loop through array
       {
              sum_dev += pow( (numbers[i] - average), 2);                           // Calculating sum deviation
       }

       variance = sum_dev / count;                                                  // Calculating variance
       SD = sqrt(variance);                                                         // Calculating standard deviation                                  

       return average;
}
