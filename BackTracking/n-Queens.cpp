#include<iostream>
using namespace std;

bool IsSafe(int** arr, int x, int y, int n) {
	
	// checking the columns
	for (int i = 0; i < n; i++) {
		if (arr[i][y]==1) {
			return false;
		}
	}

	// checking the diagonals
	int row = x;
	int col = y;

	while (row >= 0 && col >= 0) {
		if(arr[row][col]==1){
			return false;
		}
		row--;
		col--;
	}

	// reset the values
	row = x;
	col = y;

	while (row >= 0 && col < n) {
		if (arr[row][col]) {
			return false;
		}
		row--;
		col++;
	}

	// if the above cases passes, it's safe!
	return true;

}

bool queen_tracker(int** arr, int x, int n) {

	// if all the queens are placed
	// as we are placing by rows
	if (x >= n) {
		return true;
	}

	// running the loop for each column with respective rows
	for (int i = 0; i < n; i++) {
		if (IsSafe(arr, x, i, n)) {
			arr[x][i] = 1;			// queen placed!
			// traversing to next row
			if (queen_tracker(arr, x + 1, n)) {
				return true;
			}
			else {
				arr[x][i] = 0;		// backtracking
			}
		}
	}

	return false;
}


int main() {

	// taking the input for n-queens
	int n;
	cin >> n;

	// initializing the matrix or 2d-array for n-queen chessboard
	// using dynamic allocation
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	// calling the queen_tracker and printing the solution
	if (queen_tracker(arr, 0, n)) {
		cout << "Solved!" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Queens cannot be placed!" << endl;
	}

	return 0;
}