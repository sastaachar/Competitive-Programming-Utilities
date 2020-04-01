#include<iostream>

using namespace std;

int main()
{
  long test;
  cin>>test;
  while(test--)
  {
    long n,FinalWeapon=0;
    cin>>n;
    string s;
    char contest[n][10];
    for(int i=0;i<n;i++)
    {
    cin>>s;
    for(long j=0;j<10;j++)
    {
        contest[i][j]=s[j];
    }
    }
    for(int i=0;i<10;i++)
    {
      long x = 0;
    for(int j=0;j<n;j++)
    {
    if(contest[j][i]=='1')
      x++;
    }
    if(x%2!=0)
    FinalWeapon++;
  }
  cout<<FinalWeapon<<"\n";
}
}
