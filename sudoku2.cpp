#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


void printSudoku9x9(int arr[9][9]) {
	cout << "-------------------------" << endl;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			cout << arr[y][x] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;

}

bool canPlace9x9(int arr[9][9], int row, int col, int n)
{
	if (arr[row][col] != 0) return false;
	bool status = true;
	int gridx = (col / 3) * 3; // for finding cell 
	int gridy = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == n) { status = false; break; }
		if (arr[i][col] == n) { status = false; break; }
		if (arr[gridy + i / 3][gridx + i % 3] == n) { status = false; break; }
	}
	return status;
}

bool solveSudoku9x9(int arr[9][9])
{
	for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(canPlace9x9(arr,i,j,val)){
                        arr[i][j]=val;
                        bool nextsolution=solveSudoku9x9(arr);
                        if(nextsolution)
                        return true;
                        else //backtrack
                        arr[i][j]=0;
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}
int main(int argc, char** argv)
{
	int board[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	int board2[9][9] = {
		{8,0,0,0,0,0,0,0,0},
		{0,0,3,6,0,0,0,0,0},
		{0,7,0,0,9,0,2,0,0},
		{0,5,0,0,0,7,0,0,0},
		{0,0,0,0,4,5,7,0,0},
		{0,0,0,1,0,0,0,3,0},
		{0,0,1,0,0,0,0,6,8},
		{0,0,8,5,0,0,0,1,0},
		{0,9,0,0,0,0,4,0,0}
	};
	
	if (solveSudoku9x9(board)) cout << "successfully solved board!" << std::endl;
	printSudoku9x9(board);
	if (solveSudoku9x9(board2)) cout << "successfully solved board 2!" << std::endl;
	printSudoku9x9(board2);

	return 0;
}
