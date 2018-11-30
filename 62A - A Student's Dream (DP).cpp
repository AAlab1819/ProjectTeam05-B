#include <iostream>
#include <omp.h>
#include <cstdio>
using namespace std;

int pass[2] = {0,0};
int pass2[2] = {0,0};    //Initialize result array

//Function to test whether the two can hold hands comfortably with the given parameters (check main function)
int test (int f, int m)
{
    //Initialize modifier for girl's left hand
    int t1 = f + 1;
    int t2 = f - 1;
    int checker = 0;

    //If the number of boy's fingers is equal to or more than the girl's fingers
    if (t2 <= m)
    {
        checker++;
    }

    //If the number of girl's fingers * 2 exceeds the boy's fingers
    if (m <= 2*t1)
    {
        checker++;            //Problem solved, set current index of array pass to 1
    }

    return checker;
}

//Main function
int main()
{
	int f[2];
	int m[2];

    	cin >> f[0] >> f[1];
	cin >> m[0] >> m[1];

	pass[0] = max(test(f[0],m[1]),test(f[1],m[0]));         //Test first two problems (girl first)
    
    	pass2[0] = max(test(m[1],f[0]),test(m[0],f[1]));        //Test next two problems (boy first)
    
    	//Get YES/No
    	if (pass[0] == 2 || pass[1] == 2)
    	{
       	   cout << "YES";
   	}

    	else
   	{
           cout << "NO";
    	}
}
