#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

string BigIntegerAddition(string number1, string number2)
{
    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());

    int len1=number1.size();
    int len2=number2.size();
    int carry=0,temp=0;
    string ans="";
    char ch;
    int i;

    int range=min(len1,len2);
    stringstream ss;

    for(i=0;i<range;i++)
    {
       temp=((number1[i]-'0')+(number2[i]-'0')+carry) ;
       carry=temp/10;
       temp=temp%10;
       ss<<temp;
       ss>>ch;
       ans.push_back(ch);
    }

    if(len1<len2)
        number1=number2;
    range=max(len1,len2);

    while(i<range)
    {
        temp=number1[i]-'0'+carry;
        carry=temp/10;
        temp=temp%10;
        ss<<temp;
        ss>>ch;
        ans.push_back(ch);
        i++;
    }
    if(carry>0){
        ss<<carry;
        ss>>ch;
        ans.push_back(ch);
    }

    reverse(ans.begin(),ans.end());

    return ans;

}

string BigIntegerDivide(string number,int divisor)
{
    string ans="";
    stringstream ss;
    int numberDigit=number.length();
    int Remainder=0,temp;
    bool flag=false;

    for(int i=0;i<numberDigit;i++)
    {
        temp=(Remainder*10 +number[i]-'0')/divisor;
        Remainder=(Remainder*10 +number[i]-'0')%divisor;

        if(!flag&&temp>0)
            flag=true;

        if(flag)
        {
            ss<<temp;
            char ch;
            ss>>ch;
            ans.push_back(ch);
        }

    }
    return ans;
}

string BigIntegerSubstraction(string number1, string number2)
{

    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());

    int len1=number1.size();
    int len2=number2.size();
    int i,temp=0,borrow=0;
    char ch;
    string ans="";

    stringstream ss;

    int range=min(len1,len2);

    for(i=0;i<range;i++)
    {
        if(number1[i]<number2[i])
        {
            temp=((number1[i]-'0')+10)-((number2[i]-'0')+borrow);
            borrow=1;
        }
        else{
            temp=(number1[i]-'0')-(number2[i]-'0'+borrow);
            borrow=0;
        }
        ss<<temp;
        ss>>ch;
        ans.push_back(ch);

    }
    range=number1.size();

    while(i<range)
    {
        if(number1[i]<borrow)
        {
            temp=((number1[i]-'0')+10)-borrow;
            borrow=1;
        }
        else
        {
            temp=(number1[i]-'0')-borrow;
            borrow=0;
        }

        ss<<temp;
        ss>>ch;
        ans.push_back(ch);
        i++;
    }

    range=ans.size();

    for(i=range-1;i>0;i--)
    {
        if(ans[i]>'0')
            break;
        else ans.erase(i);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<BigIntegerSubstraction(a,b)<<endl;
    return 0;
}
