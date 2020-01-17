#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


bool isSafe(int sudoku[9][9])
{
	
	for(int i=0;i<9;i++)
	{
		//checking row
		int x[10]={0};
		for(int j=0;j<9;j++)
		{
			x[sudoku[i][j]]++;
		}
		for(int j=1;j<10;j++)
		{
			if(x[j]>1)
			{
				return false;
			}
			x[j]=0;
		}

		//checking cloumn
		for(int j=0;j<9;j++)
		{
			x[sudoku[j][i]]++;
		}
		for(int j=1;j<10;j++)
		{
			if(x[j]>1)
			{
				return false;
			}
			x[j]=0;
		}
		if(i%3==0)
		{
			int p=0;
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					x[sudoku[i][p+k]]++;
				}
				
				for(int k=0;k<3;k++)
				{
					x[sudoku[i+1][p+k]]++;
				}

				for(int k=0;k<3;k++)
				{
					x[sudoku[i+2][p+k]]++;
				}
				for(int j=1;j<10;j++)
				{
					if(x[j]>1)
					{
						return false;
					}
					x[j]=0;
				}
				p=p+3;
			}
						
		}
	}
	return true;
}


bool sudokuSolver(int sudoku[9][9],int i,int j)
{
	if(i==9)
		return true;

	if(sudoku[i][j]!=0)
	{
		if(j==8)
			return sudokuSolver(sudoku,i+1,0);
		return sudokuSolver(sudoku,i,j+1);
	}

	for(int k=1;k<10;k++)
	{
		sudoku[i][j]=k;
		if(isSafe(sudoku))
		{
			if(j==8 && sudokuSolver(sudoku,i+1,0))
				return true;

			else if(j!=8 &&sudokuSolver(sudoku,i,j+1))
				return true;
			sudoku[i][j]=0;
		}
		else
		{
			sudoku[i][j]=0;
		}
	}
	return false;
}



void print(int sudoku[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<sudoku[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	// int sudoku[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
 //                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
 //                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
 //                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
 //                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
 //                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
 //                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
 //                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
 //                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	int sudoku[9][9];
    string input;
    cin>>input;
	fstream file;
	file.open(input,ios::in);
	char ch;
	int i=0,j=0;
	while(file>>ch)
	{
		sudoku[i][j]=ch-'0';
		j++;
		if(j==9)
		{
			i++;
			j=0;
		}
		if(i==9) break;
	}


	if(sudokuSolver(sudoku,0,0))
	{
		print(sudoku);
	}
	else
	{
		cout<<"No soultion present for the given sudoku\n";
	}
	return 0;
}