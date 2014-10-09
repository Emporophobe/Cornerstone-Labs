#include <iostream> /* Standard console interaction */ 
#include <fstream> /* Read/write files */
#include <iomanip> /* Allow for parametric manipulators */

using namespace std; /* Allow for basic C++ commands and operations */

#define HEIGHT 7. /* Define a constant value for height */

int main (void)
{
    cout << "Vladislav E. Martin.. PYRvem.cpp Lab# C++ Tutorial \n" << endl;
    
    double side1, side2, volume;
    
    ofstream outfile;
    outfile.open("PYRvem.out");
    
    //C++ command to print to the console window
    cout << "ENTER TWO LENGTHS FOR THE BASE SIDES: ";
    
    //C++ command to read values inputted by the user & assign them names side1 and side2
    cin >> side1 >> side2;
    
    //Write to the output file called PYRvem.out
    outfile << "Vladislav E. Martin \n\n";
    outfile << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    
    volume = side1 * side2 * HEIGHT/3.0; /* calculate volume from input */
    
    cout << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    cout << "Pyramid volume is " << volume << " cubic cm.  n\n\n";
   
    outfile << "Pyramid vloume is " << setprecision(6) << volume << " cubic cm. \n\n\n";
    
    //Repeat the volume calculation with your own custom lengths
    cout << "ENTER TWO NEW LENGTHS FOR THE BASE SIDES: ";
    cin >> side1 >> side2;
    
    outfile << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    
    volume = side1 * side2 * HEIGHT/3.0; /* calculate the volume from custom input */
    
    cout << "Height is " << HEIGHT << ", base side lengths are " << side1 << " and " << side2 << ".\n";
    
    //Utilize the iomanip library's setprecision operation to display the volume of the pyramid to the 6th decimal place
    cout << "Pyramid volume is " << fixed << setprecision(6) << volume << " cubic cm.  \n\n";
    outfile << "Pyramid vloume is " << fixed << setprecision(6) << volume << " cubic cm. \n\n";
    
    system ("pause"); /* Tells the console window to wait for a user command to exit */
    
    return 0;
}
