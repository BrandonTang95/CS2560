// 
//  Name:   Tang, Brandon 
//  Project:  2
//  Due:        2/20/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//    This program will output a monthly calendar for a given month and year into a file. 
// 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
       int month, year;

       cout << "Calendar by B. Tang" << endl;
       cout << endl;

       cout << "Enter month year? ";
       cin >> month >> year;
       cout << endl;

       // Opening created file
       ofstream outfile( to_string(month) + "-" + to_string(year) + ".txt" );
       cout << month << "-" << year << ".txt file generated." << endl;

       // Calculating day of the week
       int day = 1;                       // first day of the month
       int a, y, m, dow;                  // initialize variables
       a = (14.0 - month) / 12.0;         // cast double
       y = year - a;
       m = month + 12 * a - 2;
       dow = ( day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 ) % 7;    

       // Name of the Month
       string nameOfMonth;
       switch(month)
       {
              case 1: 
                     nameOfMonth = "January";
                     break;
              case 2: 
                     nameOfMonth = "February";
                     break;
              case 3: 
                     nameOfMonth = "March";
                     break;
              case 4: 
                     nameOfMonth = "April";
                     break;
              case 5: 
                     nameOfMonth = "May";
                     break;
              case 6: 
                     nameOfMonth = "June";
                     break;
              case 7: 
                     nameOfMonth = "July";
                     break;
              case 8: 
                     nameOfMonth = "August";
                     break;
              case 9: 
                     nameOfMonth = "September";
                     break;
              case 10: 
                     nameOfMonth = "October";
                     break;
              case 11:
                     nameOfMonth = "November";
                     break;
              case 12: 
                     nameOfMonth = "December";
                     break;
       }

       // Days in a month
       int daysInMonth;
       switch(month)
       {
              case 2:
                     if ( (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0) ) 
                     {
                            daysInMonth = 29;
                     }
                     else
                     {
                            daysInMonth = 28;
                     }
                     break;

              case 4: case 6: case 9: case 10:                    
                     daysInMonth = 30;
                     break;

              default:
                     daysInMonth = 31;
                     break;
       }

       // Calendar
       outfile << nameOfMonth << " " << year << endl;
       outfile << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
       outfile << "---------------------------------" << endl;
       
       for (int i = 0; i < dow; i++)
       {
              outfile << "     ";
       }

       for (int d = 1; d <= daysInMonth; d++)
       {
              outfile << setw(3) << d;
              if (dow++ == 6)
              {
                     dow = 0;
                     outfile << endl;
              }
              else
              {
                     outfile << "  ";
              }
       }

       outfile.close();

       return 0;
}
