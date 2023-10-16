#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<int> Solution::buildRow(vector<int>& previous, int rowIndex, int currentRow) {
    vector<int> row(currentRow + 1, 1);
    for(int i = 1; i < currentRow; i++) 
        row[i] = (previous[i-1] + previous[i]); 
    if (currentRow == rowIndex) return row;
    else return buildRow(row, rowIndex, currentRow+1);
}
vector<int> Solution::getRow(int rowIndex) {
    vector<int> row(1, 1);
    if (rowIndex == 0) return row;
    else return buildRow(row, rowIndex, 1);
}