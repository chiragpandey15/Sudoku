#include<iostream>
using namespace std;
bool isSafe(int sudoku[9][9])
{
	
	for(int i=0;i<9;i++)
	{
		//checking row
		int x[10]={0};
		for(int j=0;j<9;j++)
		{
			x[abs(sudoku[i][j])]++;
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
			x[abs(sudoku[i][j])]++;
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
					x[abs(sudoku[i][p+k])]++;
				}
				
				for(int k=0;k<3;k++)
				{
					x[abs(sudoku[i+1][p+k])]++;
				}

				for(int k=0;k<3;k++)
				{
					x[abs(sudoku[i+2][p+k])]++;
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

int main()
{
	int sudoku[9][9]={{-3, 0, -6, -5, 0, -8, -4, 0, 0},  
                      {-5, -2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, -8, -7, 0, 0, 0, 0, -3, -1},  
                      {0, 0, -3, 0, -1, 0, 0, -8, 0},  
                      {-9, 0, 0, -8, -6, -3, 0, 0, -5},  
                      {0, -5, 0, 0, -9, 0, -6, 0, 0},  
                      {-1, -3, 0, 0, 0, 0, -2, -5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, -7, -4},  
                      {0, 0, -5, -2, -0, -6, -3, 0, 0}};

    while(1)
    {
    	system("clear");
    	for(int i=0;i<9;i++)
    	{
    		for(int j=0;j<9;j++)
    		{
    			cout<<abs(sudoku[i][j]);
    			cout<<"  ";
    		}
    		cout<<"\n";
    	}
    	cout<<"\n\n";
    	int x,y,val;
    	cout<<"Enter the cordinate: ";
    	cin>>x;
    	if(x=='c')
    		break;
    	cin>>y;
    	cout<<"Enter the number: ";
    	cin>>val;
    	x--;
    	y--;
    	if(sudoku[y][x]>=0)
    	{
    		int p=sudoku[y][x];
    		sudoku[y][x]=val;
    		if(!isSafe(sudoku))
    		{
    			cout<<"Alert: Wrong!! Wrong!!\n";
    			sudoku[y][x]=p;
    			system("sleep 2s");
    		}
    	}
    	else
    	{
    		cout<<"Alert!! Cannot change the value\n";
    		system("sleep 2s");
    	}
    	int flag=1;
    	for(int i=0;i<9;i++)
    	{
    		for(int j=0;j<9;j++)
    		{
    			if(sudoku[i][j]==0)
    				flag=0;
    		}
    	}
    	if(flag)
    		break;
    	
    }

}