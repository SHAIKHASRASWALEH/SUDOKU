#include<bits/stdc++.h>
using namespace std;
int error(int sudoku[9][9],int row,int column,int value)
{
    for(int i=0;i<9;i++)
    {
       if(sudoku[row][i]==value)
       return 0;
    }
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][column]==value)
        return 0;
    }
    row-=row%3;
    column-=column%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(sudoku[row+i][column+j]==value)
            return 0;
        }
    }
    return 1;
}
void print_sudoku(int sudoku[9][9])
{
    
    cout<<"SUDOKU\n";
    for (int row = 0; row < 9; row++)
     {
        for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << sudoku[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout <<"\n";
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout <<"\n";
   }      
}
bool solve(int sudoku[9][9],int row,int column)
{
    if (row==8 && column == 9)
     return true;
    if (column == 9) 
    {  
        row++;
        column = 0;
    }

    if (sudoku[row][column] != 0)
        return solve(sudoku, row, column + 1);

    for (int value = 1;value <= 9;value++) 
    {
           if (error(sudoku,row,column,value)) 
           { 
            sudoku[row][column] =value;

            if (solve(sudoku,row,column+1))
                return true;

            sudoku[row][column] = 0;
           }
    }
    return false;
}
int Is_sudoku_solved(int sudoku[9][9])
{
    for(int row=1;row<=9;row++)
    {
        for(int column=1;column<=9;column++)
        {
            if(sudoku[row][column]==0)
            return 0;
        }
    }
    return 1;
}
void play(int sudoku[9][9])
{
   int row,column,value;
   print_sudoku(sudoku);
    cout<<"\n\n";
   while(1)
   {
      cout<<"Want to exit and see the answer,enter row,column,and value as 0\n";
      cout<<"Enter row:";
      cin>>row;
      cout<<"\nEnter column:";
      cin>>column;
      cout<<"\nEnter value:";
      cin>>value;
      cout<<"\n";
      if(row==0 && column==0 && value==0)
      {
        solve(sudoku,0,0);
        print_sudoku(sudoku);
        cout <<"\n";
        cout << "You can try again\n";
        return;
      }
        if (Is_sudoku_solved(sudoku))
        break;
        row--;
        column--;
        if (!error(sudoku,row,column,value)) {
            cout << "INVALID.\n";
            continue;
        }
        sudoku[row][column]=value;
    }
    int completed = 1;
    for (int i = 0;i < 9;i++) 
        {
            for (int j = 0;j < 9;j++) 
            {
                if (sudoku[i][j] == 0) 
               {
                completed=0;
                break;
               }
            }
        }

    if (completed) {
        cout << "WIN WIN WIN.\n";
        print_sudoku(sudoku);
    }
    else {
        cout << "TRY AGAIN\n";
    }

}

int main()
{
    
    int sudoku[9][9] = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };
    cout<<"\t\t---------------------------------\t\t\n";
    cout<<"\t\t|\t  SUDOKU GAME\t\t|\t\n";
    cout<<"\t\t---------------------------------\t\t\n";
    while(1)
    {
        int choose;
        
        cout<<"[1]:Start playing\n";
        cout<<"[2]:Exit\n";
        cout<<"Enter your choice\n";
        cin>>choose;
        if(choose!=1 && choose !=2)
        {
            cout<<"Invalid Choice";
            exit(1);
        }
        switch(choose)
        {
            case 1:
            {
                play(sudoku);
                break;
            }
            case 2:
            {
                return 0;
                break;
            }
            default:
            {
                cout<<"Invalid choice\n";
                break;
            }
        }
    }
}