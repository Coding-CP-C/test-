#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 9
bool findEmtyLocation(int gird[N][N],int &row,int &col){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(gird[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeInRow(int gird[N][N],int row,int num){
    for(int i = 0;i < N;i++){ 
        if(gird[row][i] == num){
            return false;
        }
    }
    return true;
}
bool isSafeInCol(int gird[N][N],int col,int num){
    for(int i = 0;i < N;i++){ 
        if(gird[i][col] == num){
            return false;
        }
    }
    return true;
}
bool isSafeInBox(int gird[N][N],int row,int col,int num){
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(gird[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int gird[N][N],int row,int col,int num){
    if(isSafeInRow(gird,row,num) && isSafeInCol(gird,col,num) && isSafeInBox(gird,row,col,num)){
        return true;
    }
    return false;
}
bool solveSudoku(int gird[N][N]){
    int row,col;
    if(!findEmtyLocation(gird,row,col)){
        return true;
    }
    for(int i = 1;i <= N;i++){
        if(isSafe(gird,row,col,i)){
            gird[row][col] = i;
            //if the solveSudoku is true mean solve Sudoku
            //else check the diff value bracktrack and change to 0 
            if(solveSudoku(gird)){
                return true;
            }
            //backtrack
            //change to 0 for check diff value
            gird[row][col] = 0;
        }
    }
    return false;
}
int main (){
    
  int gird[N][N];
  //take input
  
  for(int i =0;i < N;i++){
      string s;
      cin>>s;
      for(int j = 0;j < s.length();j++){
          gird[i][j] = s[j] - '0';
      }
  }
   /* for(int i = 0; i < N ;i++){
      	for(int j = 0; j < N; j++){
        	cin >> gird[i][j];
    	}		
  	}*/
  
  solveSudoku(gird);
  
  //print 
  for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
          cout<<gird[i][j];
      }
      cout<<endl;
  }
  return 0;

}

