#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Create 3x4 grid
    vector< vector< int> > grid(3, vector<int>(4,7));


    for (int row=0; row<grid.size();row++) {
        for (int col=0;col<grid[row].size();col++) {
            cout << grid[row][col] << flush;
        }
        cout << endl;
    }

    //Exercise: create multiplication table of 12
    int rows = 5;
    int cols = 5;
    vector< vector<int> > table(rows,vector<int>(cols,1));

    for (int row=0;row<table.size();row++) {
        for (int col=0;col<table[row].size();col++) {
            int n = (row+1)*(col+1);
            table[row][col] = 12*n;
        }
    }

    for (int row=0;row<table.size();row++) {
        for (int col=0;col<table[row].size();col++) {
            cout << table[row][col] << " " << flush;
        }
        cout << endl;
    }



    return 0;
}