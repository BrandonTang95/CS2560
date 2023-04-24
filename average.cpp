// 
//  Name:   Tang, Brandon
//  Homework:  1
//  Due:        2/17/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//    The program will read floating point numbers from a file named "temps.dat". 
//    It will compute the average and out put the data 8 values per line, the count and average.
// 
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
       const int ITEM_PER_LINE = 8;

       cout << "Average by B. Tang" << endl;

       ifstream infile;
       infile.open("temps.dat");                                      // Create temps.dat file
       if (infile)                                                    // check if file to read from exists
       {
              double sum = 0, value;
              int counter = 0, perLine = 0;
              cout << fixed << setprecision(1);                       // formatting for listing data
              while (infile >> value)                                 // reads through all values in the file
              {
                     sum += value;                                    // sum of all values in file
                     counter++;                                       // increment count
                     cout << setw(6) << value;
                     if (++perLine == ITEM_PER_LINE)                  // pre increment before checking items per line
                     {
                            perLine = 0;                              // reset numbers per line and start new line
                            cout << endl;
                     }
                     else
                     {
                            cout << " ";
                     }
              }
              infile.close();

              // Create new line after listing values
              if (perLine != 0)
              {
                     cout << endl;
              }

              // Count and average
              cout << endl << endl;
              cout << "Count   = " << counter << endl;
              cout << "Average = " << setprecision(2) << setw(5) << sum / counter << endl;
       }
       else
       {
              cerr << "temps.dat not found" << endl;    // file to read from does not exists
       }
       
       return 0;
}
