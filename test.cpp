#include <iostream>
#include <string>
#define MAX_LENGTH  1000
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    
    freopen("test_input.txt", "r", stdin);

    for(int t=1;t<=10;t++)
    {
       int length;
       cin>>length;

       int cnt=0;

       cout<<'#'<<t<<' '<<cnt<<"\n";  
    }   
    return 0;
}