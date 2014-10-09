#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int score = 0;
	string grade;
	
	//get the score from the user
	cout << "What is your score? ";
	cin >> score;
	
	//check if the score should be weighted
	string scaled = "";
	cout << "Is the grade scaled? ";
	cin >> scaled;
	
	if (scaled == "yes")
	{
		//check the scale type
		string scaleType = "";
		cout << "Adding or proportional scale? ";
		cin >> scaleType;
		
		if (scaleType == "adding")
		{
			double weight = 0;
			cout << "Add how many points? ";
			cin >> weight;
			
			//add the points to the score
			score += weight;
		}
		else if (scaleType == "proportional")
		{
			double weight = 0;
			cout << "Add what percentage? ";
			cin >> weight;
			
			//multiply by 100% + the weight provided
			score *= (1+weight/100);
		}
	}
	
	//compare the (weighted) score to the limits in the table
	
	if (score >= 93 /*&& score <= 100*/)
	{
		grade = "A";
	}
	else if (score >= 90)
	{
		grade = "A-";
	}
	else if (score >= 87)
	{
		grade = "B+";
	}
	else if (score >= 83)
	{
		grade = "B";
	}
	else if (score >= 80)
	{
		grade = "B-";
	}
	else if (score >= 77)
	{
		grade = "C+";
	}
	else if (score >= 73)
	{
		grade = "C";
	}
	else if (score >= 70)
	{
		grade = "C-";
	}
	else if (score >= 67)
	{
		grade = "D+";
	}
	else if (score >= 63)
	{
		grade = "D";
	}
	else if (score >= 60)
	{
		grade = "D-";
	}
	else if (score >= 0)
	{
		grade = "F";
	}
	else
	{
		grade = "YOU DIDN'T PUT IN A PROPER VALUE ... NO WONDER YOU FAILED.";
	}
	
	//output the letter grade and exit
	cout << "The letter grade you have earned thus far is a(n) " << grade << ". \n\n";
	
	return 0;
}
