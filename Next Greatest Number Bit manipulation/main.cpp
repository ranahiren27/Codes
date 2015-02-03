#include <iostream>

using namespace std;

int greatestNext(int x)
{
    int rightOne,nextHigherOneBit,rightOnesPattern;

    int next=0;
    rightOne = x&-x;
    cout<<rightOne<<endl;

    nextHigherOneBit = x+rightOne;
    cout<<nextHigherOneBit<<endl;
    rightOnesPattern = x ^ nextHigherOneBit;


    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/(rightOne*4);
    cout<<rightOnesPattern<<endl;

    // correction factor
    //rightOnesPattern >>= 2;

    // rightOnesPattern is now part [A] of the above explanation.

    // integrate new pattern (Add [D] and [A])
    cout<<"nextHigherOneBit is"<<nextHigherOneBit<<endl;
    cout<<"rightOnesPattern is"<<rightOnesPattern<<endl;
    next = nextHigherOneBit | rightOnesPattern;

    return next;

}

int main()
{
    cout<<greatestNext(59)<<endl;

}
