//pa1.cpp
//Michael Arboleda

#include <iostream>
#include <iomanip>
using namespace std;

//Prototypes
int validRow(int a, int c);
int validCol(int b, int c);
int down(int a, int c);
int left(int b, int c);

int main()
{	
	int n = 0;
	cout << "Enter the size of a magic square: ";
	cin >> n;
	//Invalid if Less then 3, greater then 15, and even 
	while (n < 3 or n > 15 or (n%2 != 1)){
		cout << "Enter the size (Valid) of a magic square: ";
		cin >> n;
	}
	
	//Make array and set equal to zero
	int msq[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			msq[i][j] = 0; 
		}
	}	
	
	//Place Numbers
	int x = 0;
	int y = ((n/2));
	for(int num = 1; num < ((n*n)+1); num++){
		//Check if next array already has value or not
		if (msq[x][y] > 0){
			x = down(x, n);
			y = left(y, n);
		}
		//Move to next valid point
		msq[x][y] = num;
		x = validRow(x, n);
		y = validCol(y, n);
	}
	//set width
	int sw = 0;
	if(n == 3 or n ==5){
		sw = 3;
	}
	else{
		sw = 4;
	}

	//Display Magic Square
	cout << "One Magic Square is: " << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cout << setw(sw) << msq[i][j]; 
		}
		cout << endl;
	}
	
	//Sum of rows
	cout << setw(38) << left <<"Checking the sums of every row:"; 
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = 0; j< n; j++)
		{
			sum += msq[i][j]; 
		}
		cout << sum  << " ";
	}
	
	//Sum of column
	cout << "\n" << setw(38) << left <<"Checking the sums of every column:"; 
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = 0; j< n; j++)
		{
			sum += msq[j][i]; 
		}
		cout << sum  << " ";
	}
	
	//Sum of diagonals
	cout << "\n" << setw(38) << left <<"Checking the sums of every diagonals:"; 
	int d1sum = 0, d2sum =0;
	//Diagonal 0,0 to n-1,n-1
	for(int i = 0; i < n; i++)
	{
		d1sum += msq[i][i]; 
	}
	cout << d1sum << " ";
	//Diagonal from 0,n-1 to n-1,0
	for(int i =0, j= n-1; i < n; i++, j--){
		d2sum += msq[i][j]; 
	}	
	cout << d2sum  << " ";
}		


int validRow(int a, int c){
	//if at the top of matrix, then go to the bottom
	if(a == 0){
		a = c-1;
	}
	else{
		a -= 1;
	}
	return(a);
}

int validCol(int b, int c){
	//if at right edge of matrix, go back to the first column
	if(b == c-1){
		b = 0;
	}
	else{
		b += 1;
	}
	return(b);
}

int down(int a, int c){
	//Go down one and see if place is valid
	if (a == c-1){
		a = 0;
	}
	else{
		a += 1;
	}
	//Go down one again and see if place is valid	
	if (a == c-1){
		a = 0;
	}
	else{
		a += 1;
	}
		return(a);
}	

int left(int b, int c){
	//if at left edge, go to last column
	if(b == 0){
		b = c-1;
	}
	else{
		b -= 1;
	}
	return(b);
}