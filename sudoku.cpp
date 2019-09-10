#include<iostream>
using namespace std;
#define N 4
bool checkrow(int sud[4][4],int row,int num){
     for(int col=0;col<4;col++){
         if(sud[row][col]==num)
              return true;
        }
     return false;
 }
 bool checkcol(int sud[4][4],int col,int num){
     for(int row=0;row<4;row++){
         if(sud[row][col]==num)
         return true;
     }
     return false;
 }
bool usedinbox(int grid[N][N], int boxStartRow, int boxStartCol, int num)  
{  
    for (int row = 0; row < 3; row++)  
        for (int col = 0; col < 3; col++)  
            if (grid[row + boxStartRow][col + boxStartCol] == num)  
                return true;  
    return false;  
}
bool findlocation(int grid[N][N],  
                            int &row, int &col)  
{  
    for (row = 0; row < 4; row++)  
        for (col = 0; col < 4; col++)  
            if (grid[row][col] == 0)  
                return true;  
    return false;  
}   
bool  issafe(int grid[N][N], int row,  int col, int num)  
{  
    return !checkrow(grid, row, num) &&  
           !checkcol(grid, col, num) &&  
           !usedinbox(grid, row - row % 3 ,  
                      col - col % 3, num) &&  
            grid[row][col] == 0;  
}     
bool solvegrid(int sud[4][4]){
 int col,row;
   if (!findlocation(sud, row, col))  
    return true; 
 for(int num=1;num<=4;num++){
    if(issafe(sud,row,col,num))
        sud[row][col]=num;
        if(solvegrid(sud))
           return true;
        sud[row][col]=0;
           return false;
                                  } 

     }
 
int main(){
     int sud[4][4]={{0,0,3,4},{3,4,0,0},{0,0,4,3},{0,3,2,0}};
     
     if(solvegrid(sud)){
        
         cout<<"The solved sudoku is \n";
         for(int i=0;i<4;i++){
             for(int j=0;j<4;j++){
                 cout<<sud[i][j]<<" ";
             }
             cout<<"\n";
         }
     }
    else{
        cout<<"No solution exists\n";
    }
      return 0;
}


    