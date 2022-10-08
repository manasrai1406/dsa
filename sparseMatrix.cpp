#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int s[3][100],k=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                s[0][k]=i;
                s[1][k]=j;
                s[2][k]=a[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<s[0][i]<<" "<<s[1][i]<<" "<<s[2][i]<<endl;
    }
    
    return 0;
    
}