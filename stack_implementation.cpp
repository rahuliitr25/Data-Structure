#include<iostream>
#include<stack>
#include<string>
using namespace std;

// 1. Parenthesis Balanced OR not.

bool AreparenthesisPaired(char a, char b)
{
    if (a=='(' && b == ')'|| a=='['&& b == ']'|| a=='{'&& b == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool AreParanthesesBalanced(string exp)
{
    stack <char> s;
    for (int  i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (s.empty() || !AreparenthesisPaired(s.top(),exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 2. Infix to Postfix..

int prec(char c)
{
    if(c=='^'){
        return 3;
    }
    if (c=='*' || c=='/'){
        return 2;
    }
    if(c == '+' || c== '-' ){
        return 1;
    }
    else 
    return -1;
}

void infixtopostfix(string exp)
{
    string res ;
    stack <char> s;
    char c;
    for (int i = 0; i < exp.length(); i++)
    {
        c = exp[i];
        if (isdigit(c))
        {
            res+=c;
        }
        else if (c=='(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() !='(')
            {
                res+=s.top();
                s.pop();
            }

            s.pop();  
        }
        else
        {
            while (!s.empty() && s.top() != '(' && prec(c)<=prec(s.top()))
            {
                res+=s.top();
                s.pop();
            }

            s.push(c);

        }   
    }

    while (!s.empty())
    {
        res+=s.top();
        s.pop();
    }
    cout<<res<<endl;
    
}

// 3. Evaluation of Postfix

void evaluatepostfix(string exp)
{
    stack <char> s;
    char c;
    
    for (int i = 0; i < exp.length(); i++)
    {
        c = exp[i];
        if (isdigit(c))
        {
            s.push(c-'0');
        }
        else
        {
            int op2 = s.top(); 
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (c)  
            {  
            case '+': s.push( (op2 + op1)-'0'); break;  
            case '-':s.push( (op2 - op1)-'0'); break;  
            case '*':s.push( (op2 * op1)-'0'); break;  
            case '/': s.push( (op2/op1)-'0'); break;  
            }
        }   
    }
    cout<<s.top()<<endl;
}

int main()
{
    cout<<"Enter the expression :  ";
    string exp;
    cin>>exp;

    if(AreParanthesesBalanced(exp)){
        cout<<"Balanced !!"<<endl;
    }else
    {
    cout<<" Not Balanced !!"<<endl;
  } 

}