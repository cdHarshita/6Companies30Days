#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isvalid(vector<vector<char>>& soduko,int row,int col,char target){
        for(int i=0 ; i<9 ; i++){
            if(i!=col && soduko[row][i]==target) return false;
            if(i!=row && soduko[i][col]==target) return false;
             int subgridRow = 3 * (row / 3) + i / 3;
            int subgridCol = 3 * (col / 3) + i % 3;
            if (subgridRow != row && subgridCol != col && soduko[subgridRow][subgridCol] == target) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j]!='.'){
                    if(!isvalid(board,i,j,board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    cout<<s.isValidSudoku(board)<<endl;
    return 0;
}