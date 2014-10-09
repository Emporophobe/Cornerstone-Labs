#include <iostream>

using namespace std;

int main (void)
{
	const double FULLCIRCLE = 360.0;
	double angle;
	int quadrant;
	bool axis = true;
	
	cout << "What is the angle of your line in degrees? I will find the quadrant. ";
	cin >> angle;
	
	//Place the angle at an equivalent measurement between 0 and 360 degrees
	while (angle > FULLCIRCLE)
	{
		angle -= FULLCIRCLE;
	}
	while (angle < 0)
	{
		angle += FULLCIRCLE;
	}
	
	//Find out which quadrant the line, at the angle provided by the user, lies within
	for (int i = 1; i <= 4; i++)
	{
		if 	(angle < (i*90) && angle > ((i-1)*90))
		{
			quadrant = i;
			axis = false;
			cout << "Your line is contained within quadrant " << quadrant << "." << endl;
		}
	}
	
	//If the line is found to lie directly on an axis, find out which in particular
	if (axis)
	{
		for (int i = 1; i <= 4; i++)
		{
			if ((90*i) == (int)angle)
			{
				if (i == 4)
				{
					cout << "Your line lies exactly on the axis between quadrants " << i << " and " << 1 << "." << endl;
				}
				else
				{
					cout << "Your line lies exactly on the axis between quadrants " << i << " and " << (i+1) << "." << endl;
				}
			}
		}
	}
	
	system("pause");
	
	return 0;
}
