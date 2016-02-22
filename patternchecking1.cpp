#include<iostream>
#include<string>

using namespace std;

int main()
{
    string word,pattern;
    cin>>word>>pattern;

    int len1=word.length();
    int len2=pattern.length();

    int j,k;
    bool flag=true;
    for(int i=0;i<=(len1-len2);i++)
    {
        j=i;
        k=0;
        flag=false;
        while(k<len2)
        {
           if(word[j++]!=pattern[k++])
           {
               flag=true;
               break;
           }
        }
        if(!flag)
        {
            cout<<i<<" shift"<<endl;
        }

    }
    if(flag)
        cout<<"did not match"<<endl;

    return 0;
}
