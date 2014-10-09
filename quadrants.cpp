//Michael Wong

#include <iostream>

using namespace std;

int main(void)
{
	double angle = 0;
	
	//get an angle from the user, ust be between 0 and 360, inclusive
	cout << "What is the angle of your line in degrees? I will find the quadrant. ";
	cin >> angle;

	while(angle < 0)
	{
		angle += 360;
	}
	
	while (angle > 360)
	{
		angle -= 360;
	}

	//the angle is on an axis if it is evenly divisible by 90	
	if ((int)angle % 90 == 0 && (int)angle == angle)
	{
		cout << "The angle is on the axis between quadrants " << (int)angle/90 << " and " << ((int)angle/90) % 5 + 1 << ". \n";
	}
	
	//the quadrant an angle is in increases every 90 degrees, with a maximum of 4 quadrants
	else
	{
		cout << "The angle is in quadrant " << ((int)angle / 90) % 5 + 1 << ". \n";
	}
	
	system("pause");
	return 0;
}
