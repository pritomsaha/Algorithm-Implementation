#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string input;
    cin>>input;
    bool flag=false;

    stack<char> myStack;
    int i=0;
    while(true)
    {
        if(input[i]=='('||input[i]=='{'||input[i]=='[')
            myStack.push(input[i]);
        else if(input[i]==')')
        {
            if(myStack.top()=='(')
               myStack.pop();
            else
            {
                break;
            }

        }
        else if(input[i]=='}')
        {

            if(myStack.top()=='{')
               myStack.pop();
            else
            {
                break;
            }


        }
        else if(input[i]==']')
        {

            if(myStack.top()=='[')
               myStack.pop();
            else
            {
                flag=false;
                break;
            }

        }
        if(myStack.empty()||i==input.length()-1)
            break;
        i++;

    }

    if(myStack.empty()&&i==input.length()-1)
        flag=true;

    if(flag)
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
