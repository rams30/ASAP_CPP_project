#include<iostream>
using namespace std;

int c=0;
bool isPossible(int board[100][100],int n,int i,int j)
{

   //vertical case

   for(int m=i-1;m>=0;m--)
   {
      if(board[m][j]==1)
      {
         return false;
      }
   }

   //right diagonal

   int q=i-1;
   int r=j+1;

   while(q>=0 and r<n)
   {
      if(board[q][r]==1)
      {
         return false;
      }
      q--;
      r++;
   }

   //left diagonal 

   int u=i-1;
   int v=j-1;

   while(u>=0 and v>=0)
   {
      if(board[u][v]==1)
      {
         return false;
      }
      u--;
      v--;
   }

   return true; //if all are not cutting 
}


bool nqueen(int board[100][100],int n,int i)
{


//base case

if(i==n)
{

   //print solution
   cout<<endl;
   c++;
   
   for(int l=0;l<n;l++)
   {

      for(int m=0;m<n;m++)
      {

            cout<<board[l][m]<<" ";


      }

      cout<<endl;
   }
   

   return false;
}

//recursive case

for(int j=0;j<n;j++)
{

   board[i][j]=1;

   if(isPossible(board,n,i,j)==true)
   {

      bool curresult=nqueen(board,n,i+1);
      if(curresult==true)
      {
         return true;
      }


   }
   board[i][j]=0;//backtrack
}
return false;



}

int main()
{

   int board[100][100]={0};
   int n;

   cout<<"Enter size of the board ";
   cin>>n;

   nqueen(board,n,0);
   if(c>0)
   {
      cout<<"Yes solution Exist";
      cout<<"\nNumber of total solutions "<<c;
   }
   else
   {
      cout<<"No solution Exist ";
   }

   return 0;

}
