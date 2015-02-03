#include <iostream>

using namespace std;

template <class Type>
Type maximum(Type a,Type b)
{
    if(a>b)
        return a;
    else
    {
        return b;
    }
}



int main()
{
    string s1="worlo";
    string s2="wodld";
    cout<<maximum(s1,s2)<<endl;
}
