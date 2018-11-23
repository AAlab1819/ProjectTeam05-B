#include <iostream>
#include <omp.h>
#include <cstdio>
using namespace std;

int main()
{
    double start_time = omp_get_wtime();      //Get program runtime upon initialization
    
    int f1, f2;     //Initialize Venusian girl's fingers (left and right)
    int m1, m2;     //Initialize Martian boy's fingers (left and right)

    cin >> f1 >> f2;      //Input the amount of Venusian girl's fingers
    cin >> m1 >> m2;      //Input the amount of Martian boy's fingers
    
    //Set modifiers for the Venusian girl (number of fingers - 1) to test whether it can fit the boy's hands
    int t1 = f1 +1;       
    int t2 = f1 - 1;
    int t3 = f2 + 1;
    int t4 = f2 - 1;
    
    //Test #1 - Girl's left hand with boy's right hand
    if (t2 <= m2 && m2 <= 2*t1)
    {
        cout << "YES";      //If successful - print "YES"
    }
    
    //If Test #1 failed
    //Test #2 - Girl's right hand with boy's left hand
    else if (t4 <= m1 && m1 <= 2*t3)
    {
        cout << "YES";    //If successful - print "YES"
    }
    
    //If all tests failed
    //The two cannot hold hands comfortably
    else
    {
        cout << "NO";   //Print "NO" as all tests have failed
    }
    
    double time = omp_get_wtime() - start_time;     //Get program final runtime
    
    cout << "\nTime Taken = " << time << endl;      //Print program runtime
}
