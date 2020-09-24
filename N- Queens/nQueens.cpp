/*
 * Name: Palmer Cone
 * Date Submitted: 3/30/2020
 * Lab Section:1
 * Assignment Name:Lab 8
 */

#include <iostream>
#include <vector>

using namespace std;
void printArray(vector<vector<int>> &arr){
    cout<< "{";
    for (int i = 0; i < arr.size(); i++){
        cout<<endl;
        for (int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j] <<"\t";
        }
    }
    cout<<"}"<<endl;
}
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
bool checkIfGood(vector<vector<int>> &arr,int row,int col){
  
    int i,j;
    if (row >= arr.size() || col >= arr.size()){
        return false;
    }
    for (j=0; j < arr.size(); j++){
        if (arr[row][j]==1){
            return false;
        }
    }
    for (j=0; j < arr.size(); j++){
        if (arr[j][col]==1){
            return false;
        }
    }
   
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){//&& > >
        if (arr[i][j]==1){
            return false;
        }
    }
    for (i = row, j = col; i < arr.size() && j < arr.size(); i++, j++ ){//&& > >
        if (arr[i][j]==1){
            return false;
        }
    }
    for (i = row, j = col; j >= 0 && i < arr.size(); i++, j--){
        if ( arr[i][j] == 1 ){
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j < arr.size(); j++, i--){
        if ( arr[i][j] == 1 ){
            return false;
        }
    }
    
    return true;
}
int findNumOnes(vector<vector<int>> &arr){
    int count = 0; 
   
    cout<<endl;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++){
            if (arr[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}
bool canContinue (vector<vector<int>> &arr, int col, int &count, int start){
    int n = arr.size();
    if (col >= n){
     
      count++;
        return true;
    }
    bool anyMatches = false;
    if (col == start){
        if (canContinue(arr, (col + 1), count, start)){
            anyMatches = true;
        }
    }
    for (int i = 0; i < arr.size() ; i++){
        if ( checkIfGood(arr, i, col)){ 
            arr[i][col] = 1;
        
            if (canContinue(arr, ( col + 1 ),count, start)){
                anyMatches=true;
                
            }
            
            arr[i][col] = 0;
            
        }
        
        
    }
    return anyMatches;
}
void clearBoard (vector<vector<int>> &arr){
   for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++ ){
            arr[i][j] = 0;
        }
    } 
   
}
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    //n is the number of queens
    //the size of the board is also nxn.
    vector<vector<int>> arr;
    
    for (int i = 0; i < n; i++){
        arr.emplace_back(0);
        for (int j = 0; j < n; j++ ){
            arr[i].emplace_back(0);
        }
    } 
    
    
   
    int c = 0;
    
    clearBoard(arr);
    
    for (int i = 0; i < n; i++){
        arr[0][i] = 1;
        if (canContinue(arr,0,c,i)){
          
        }
        clearBoard(arr);
    }
    return c;
    
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}