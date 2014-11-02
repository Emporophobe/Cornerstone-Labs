/*
Authors: Michael Wong, Vladislav Martin
Filename: checkers.cpp
Description: outputs to console a representation of a (10x10) checkerboard, with 1 representing black squares, 0 representing white squares,
			 and two other digits representing the pieces
               1. Specifics: manipulated values are all ints
               2. Input: two digits for the piece representations
               3. Output: a blank checkerboard and then a filled version
               4. Functions: int main(), void printArr(int[][SIZE], int), void fillBoard(int[][SIZE], int, int, int)
               5. Updated: 11/2/2014
*/

#include <iostream>

using namespace std;

const int SIZE = 10; //size of the square matrix
int board[SIZE][SIZE]; //matrix to represent board

void printArr(int[][SIZE], int);
void fillBoard(int[][SIZE], int, int, int);

int main(void)
{
	for(int i=0; i<SIZE; i++) //iterate through the rows
	{
		for(int j=0; j<SIZE; j++) //interating through the columns
		{
			board[i][j] = (i+j+1) % 2; //alternate 0s and 1s
		}
		
	}
	printArr(board, SIZE); //print the blank board
	
	cout << endl << endl << endl;
	
	int p1, p2;
	
	//get the digits to use for each color piece
	cout << "What digit to use for player 1? ";
	cin >> p1;
	
	cout << "What digit to use for player 2? ";
	cin >> p2;
	
	cout << endl << endl;
	
	//fill the first and last three rows with the new digits
	fillBoard(board, SIZE, p1, p2);
	
	//print the new board
	printArr(board, SIZE);
	
	cout << endl << endl << endl;
	
	system("pause");
	return 0;
}

void printArr(int arr[][10], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " "; //print each entry
		}
		
		cout << "\n"; //newline after each row
	}
}

void fillBoard(int arr[][10], int size, int p1, int p2)
{
	for(int i=0; i<3; i++) //iterate through the first three rows
	{
		for(int j=0; j<size; j++) //iterate through each entry in the row
		{
			if(board[i][j] == 1)
			{
				board[i][j] = p1; //replace the black squares with the first symbol
			}
		}	
	}
	
	for(int i=size-3; i<size; i++) //iterate through the last three rows
	{
		for(int j=0; j<size; j++) //iterate through each entry
		{
			if(board[i][j] == 1)
			{
				board[i][j] = p2; //replace the black squares with the second symbol
			}
		}	
	}
}
