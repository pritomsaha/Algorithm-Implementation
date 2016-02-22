#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> FailureFunction(string pattern)
{
    vector<int> F;
    int len=pattern.size();
    F.push_back(-1);
    int k=-1;

    for(int i=1;i<len;i++)
    {
        while(k>-1&&pattern[k+1]!=pattern[i])
            k=F[k];

        if(pattern[k+1]==pattern[i])
            k++;
        F.push_back(k);
    }

    return F;
}

int main()
{
    string word,pattern;
    cin>>word>>pattern;
    int len1=word.length();
    int len2=pattern.length();

    vector<int> f = FailureFunction(pattern);
    int q=-1;
    for(int i=0;i<len1;i++)
    {
        while(q>-1&&pattern[q+1]!=word[i])
            q=f[q];

        if(pattern[q+1]==word[i])
            q++;
        if(q==len2-1)
            cout<<"Match at "<<(i-len2+1)<<endl;

    }

    return 0;
}

