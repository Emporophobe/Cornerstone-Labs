/*************************************************************
*  Author: Michael Wong
* Filename: PYRMW.cpp
* Assignment: Lab #1
* Description: Compute volume of pyramid withrectangular base
*              1. Specifics: all values are given in cm
               2. Input: 2 sides of pyramid base
               3. Output: volume of pyr in cm^3
               4. Functions: main()
               5. Updated: 9/16/14
**************************************************************/

#include <iostream>  // input and output
#include <fstream>   //file io
#include <iomanip>   //formatting library

using namespace std; //allows operations from standard library

# define HEIGHT 7   //define the value of HEIGHT

int main (void)
{
    cout << "Michael Wong.. PRYMW.cpp Lab 1 C++ Tutorial \n" << endl;
    
    double side1, side2, volume; //define variables
    ofstream outfile; //declare variable to write to a file
    outfile.open("pyramid.txt");
    
    cout << "ENTER TWO LENGTHS FOR THE BASE SIDES: "; //print to screen
    cin >> side1 >> side2;
    
    outfile << "Michael Wong \n\n"; //why??
    outfile << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    
    volume = side1 * side2 * HEIGHT/3.0; //calculate volume in cm^3
    
    //Display results with std output
    cout << "Height is " << HEIGHT << ", base sides lengths are " << side1 << " and " << side2 << ".\n";
    cout << "Pyramid volume is " << setprecision(6) << volume << " cubic centimeters. \n\n\n";
    
    outfile << "Pyramid volume is " << setprecision(6) << volume << " cubic centimeters. \n\n\n";
    
    
    //once more, with feeling
        
    cout << "ENTER TWO NEW LENGTHS FOR THE BASE SIDES: "; //print to screen
    cin >> side1 >> side2;
    
    outfile << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    
    volume = side1 * side2 * HEIGHT/3.0; //calculate volume in cm^3
    
    //Display results with std output
    cout << "Height is " << HEIGHT << ", base sides lengths are " << side1 << " and " << side2 << ".\n";
    
    //output volume
    cout << "Pyramid volume is " << setprecision(6) << volume << " cubic centimeters. \n\n\n";
    outfile << "Pyramid volume is " << setprecision(6) << volume << " cubic centimeters. \n\n\n";
    
    system("pause"); //pause the console to keep it open
    
    return 0; //end main function
    
}
    
    
