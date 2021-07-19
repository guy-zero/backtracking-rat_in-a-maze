#include<iostream>
#include<conio.h>

using namespace std;

bool isafe(int** arr, int x, int y, int n )
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    else return false;
}

bool ratin(int** arr, int x, int y, int n, int** sol)
{
    if(x==n-1 && y==n-1)
    {
        sol[x][y]==1;
        return true;
    }

    if(isafe(arr,x,y,n))
    {
        sol[x][y]=1;
        if(ratin(arr, x+1, y, n, sol))
        {
            return true;
        }
        if(ratin(arr, x, y+1, n, sol))
        {
            return true;
        }
        sol[x][y]=0;            //backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

     int** sol = new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        } 
    }

    if(ratin(arr,0,0,n,sol))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}