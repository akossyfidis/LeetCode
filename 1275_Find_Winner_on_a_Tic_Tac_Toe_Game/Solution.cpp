#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;


/*
string tictactoe(vector<vector<int>>& moves) {
    int n=moves.size();
    vector<int> row(3,0),col(3,0);
    int diag=0,antidiag=0;
    for(int i=0;i<n;i++)
    {
        int x=moves[i][0];
        int y=moves[i][1];
        if(i%2==0)
        {
            row[x]++;
            col[y]++;
            if(x==y) diag++;
            if(x==2-y) antidiag++;
        }
        else
        {
            row[x]--;
            col[y]--;
            if(x==y) diag--;
            if(x==2-y) antidiag--;
        }
        if(row[x]==3 || col[y]==3 || diag==3 || antidiag==3) return "A";
        if(row[x]==-3 || col[y]==-3 || diag==-3 || antidiag==-3) return "B";
    }
    if(n==9) return "Draw";
    return "Pending";
}*/


string Solution::checkWinner(vector<string>& grid, int m) {
    string player = m % 2 ? "X" : "O";
    vector<vector<int>> win = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    vector<int> p;
    for(int i = 0; i < grid.size(); i++)
        if(grid[i] == player) p.push_back(i);
    
    for(auto w : win)
        if(binary_search(p.begin(), p.end(), w[0]) && binary_search(p.begin(), p.end(), w[1]) && binary_search (p.begin(), p.end(), w[2]))
            return (player == "X") ? "A" : "B";

    return m == 9 ? "Draw" : "Pending";
}


string Solution::tictactoe(vector<vector<int>>& moves) {
    int m = moves.size();
    vector<string> grid(9, " ");
    if(m < 5) return "Pending";
    for(int i = 0; i < m; i++) i % 2 ? grid[3*moves[i][0] + moves[i][1]] = "O" : grid[3*moves[i][0] + moves[i][1]] = "X";  

    return checkWinner(grid, m);
}