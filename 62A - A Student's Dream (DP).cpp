#include <iostream>
using namespace std;

int pass[4] = {0,0,0,0};    //Initialize result array

//Function to test whether the two can hold hands comfortably with the given parameters (check main function)
void test (int f, int m)
{
    //Initialize modifier for girl's left hand 
    int t1 = f + 1;   
    int t2 = f - 1;   
    int checker = 0;
    
    //If the number of boy's fingers is equal to or more than the girl's fingers
    if (t2 <= m)
    {
        pass[checker] = 1;    //Problem solved, set current index of array pass to 1 
        checker++;            //Problem solved, set current index of array pass to 1 
    }
    
    //If the number of girl's fingers * 2 exceeds the boy's fingers
    if (m <= 2*t1)
    {
        pass[checker] = 1;    //Problem solved, set current index of array pass to 1 
        checker++;            //Problem solved, set current index of array pass to 1 
    }

}

//Main function
int main()
{
    int f1, f2;     //Intialize number of girl's fingers
    int m1, m2;     //Initialize number of boy's fingers

    int pass1 = 0;
    int pass2 = 0;

    cin >> f1 >> f2;      //Input number of girl's fingers
    cin >> m1 >> m2;      //Input number of boy's fingers
    
    //Break the problem into two and solve each one of them
    for (int a = 0; a < 2; a++)
    {
        //Test whether the girl's left hand fits the boy's right hand
        if (a == 0)
        {
            test (f1,m2);
        }
        
        //Test whether the girl's right hand fits the boy's left hand
        if (a == 1)
        {
            test (f2,m1);
        }
    }
  
    //Following the previous tests, if they are successful as indicated with pass[0] & pass[1] == 1
    if (pass[0] == 1 && pass[1] == 1 || pass[2] == 1 && pass[3] == 1)
    {
        cout << "YES";      //Print "YES"
    }
    
    //If all previous tests failed
    else
    {
        cout << "NO";     //Print "NO"
    }
}
