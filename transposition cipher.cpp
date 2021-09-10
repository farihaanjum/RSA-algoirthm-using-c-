#include<bits/stdc++.h>
using namespace std;
int main()
{
    int transpose,k, p, casenum,num=1;
    string plaintext, key;
    cout<<"key:";
    cin>> key;
    cout<<"plaintext:";
    cin>>plaintext;
    cout<<"transpose:";
    cin>>transpose;
    k = key.size();
    p = (plaintext.size())/k;
    double m, minval=100;
    int cipher[p+10][k+10], a[10000];
    char ciphertext[p+10][k+10];
    cout<<"Original sequence:\n";
    for(int z=1;z<=(plaintext.size());z++)
    {
         a[z]=z;
         cout<<a[z]<<"\t";
    }
    while(transpose--)
    {
        int r=0, match=0,l=0;
       for(int j=0;j<p;j++)
       {
           for(int i=0;i<k;i++)
           {
               ciphertext[j][key[i]-48] = plaintext[l++];
               cipher[j][key[i]-48]=a[l];
           }
       }
       cout<<"\n\nCase "<<num<<": "<<endl;
       for(int j=1;j<=k;j++)
       {
           for(int i=0;i<p;i++)
           {
               cout<<ciphertext[i][j];
               plaintext[r]=ciphertext[i][j];
               r++;
               a[r]=cipher[i][j];
               if(cipher[i][j]==r)
               {
                   match++;
               }

           }
       }
       cout<<endl;
       for(int y=1;y<=r;y++)
        cout<<a[y]<<'\t';
       cout<<endl;
       m = (double(match)/ r)*100;
       cout<<"\nPercentage of matched elements = "<<m<<"%"<<endl;
       if(minval>=m)
       {
           {
               minval=m;
               casenum=num;
           }
       }
       num++;
    }
    cout<<"\nCase "<<casenum<<" has the least matching elements with original sequence"<<endl;
    cout<<"Percentage of matched elements = "<<minval<<"%"<<endl;
    return 0;

}
