#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> reducing_of_Grid(int n, int k, vector<vector<char>> &grid) {
    vector<vector<char>> reduced_Grid_matrix(n/k, vector<char>(n/k));
    for (int i = 0; i < n;i += k) {
        for (int j = 0; j < n;j += k) {
            char val = grid[i][j];
            reduced_Grid_matrix[i/k][j/k] = val;
        }
    }
    return reduced_Grid_matrix;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> grid(n, vector<char>(n));
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                cin >> grid[j][l];
            }
        }
        vector<vector<char>> reducedGrid = reducing_of_Grid(n, k, grid);
        for (int j = 0; j < n/k; j++) {
            for (int l = 0; l < n/k; l++) {
                cout << reducedGrid[j][l];
            }
            cout << endl;
        }
    }
    return 0;
}