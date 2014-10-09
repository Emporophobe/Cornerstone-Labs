#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void)
{
	double total, average, numbers = 0, number;
	ifstream infile("numbers.txt");
	ofstream outfile("average.txt");
	
	cout << "The numbers being average are displayed below: \n" << endl;
	
	while(infile >> number)
	{
		total += number;
		numbers++;
		cout << numbers << ") " << setw(5) << number << endl;
		outfile << numbers << ") " << setw(5) << number << endl;
	}
	
	average = total/numbers;
	
	cout << "\nThe average of the numbers is " << average << endl;
	outfile << "\nThe average of the numbers is " << average << endl;
	
//	infile.close();
//	outfile.close();

	return 0;
}
