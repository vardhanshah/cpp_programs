#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<bool> > board;

bool issafe(int row,int col)
{
	for(int i=0;i<col;i++)
		if(board[row][i])
			return false;
	int i,j;
	for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
		if(board[i][j])
			return false;
	for(i=row+1,j=col-1;i<n&&j>=0;i++,j--)
		if(board[i][j])
			return false;
	return true;
}
		

bool fill(int col)
{
	if(col>=n)
		return true;
	for(int i=0;i<n;i++)
		if(issafe(i,col))
		{
			board[i][col]=true;
			if(fill(col+1))
				return true;
			board[i][col]=false;
		}
	return false;
}


int main()
{
	cin >> n;
	board.resize(n,vector<bool>(n));
	if(!fill(0))
	{
		cout << "solution doesn't exist" << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j])
				cout << "q ";
			else
				cout << "- ";
		}
		cout << endl;
	}
	return 0;
}
