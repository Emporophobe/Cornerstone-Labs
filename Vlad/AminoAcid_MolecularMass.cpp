#include <iostream>
#include <iomanip>

using namespace std;

//COnstant atomic masses of each element
const double atomic_masses [5] = {15.9994, 12.011, 14.00674, 32.066, 1.007};
const int array_size = 5;

//Declare an array of the numbers of atoms in the specified amino acid
double atom_number [array_size];

//Declare a double of the calculated molecular mass of the specified amino acid
double final_molec_mass;

int main(void)
{
    //Prompt user for the number and type of atoms in the amino acid
    cout << "How many Oxygen atoms are in the amino acid? \n\n";
    cin >> atom_number[0];

    cout << "How many Carbon atoms are in the amino acid? \n\n";
    cin >> atom_number[1];
    
    cout << "How many Nitrogen atoms are in the amino acid? \n\n";
    cin >> atom_number[2];
    
    cout << "How many Sulfur atoms are in the amino acid? \n\n";
    cin >> atom_number[3];
    
    cout << "How many Hydrogen atoms are in the amino acid? \n\n";
    cin >> atom_number[4];
    
    //Variable to be iterated : n, Condition to continue iterating: n < size of our atom_number array, Rate of iteration: n++ or n + 1
    for (int n=0; n<array_size; n++)
    {
   	 final_molec_mass += (atom_number[n] * atomic_masses[n]);
    }
    //fixed: Applies precision filter starting at the decimal point, precision filter defines the number of digits (in this after the decimal point) to be displayed
    cout << "The mass of the amino acid is: " << fixed << setprecision(3) << final_molec_mass << "\n\n";
    
    //Exit the program
    system("pause");
    return 0;
}

