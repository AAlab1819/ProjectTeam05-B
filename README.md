# Solving Codeforces Problem 62A using Greedy & Dynamic Programming
This Repository will solve Codeforces' problem [62A](http://codeforces.com/problemset/problem/62/A) using Dynamic Programming and Greedy.

## Team Member
- Calvindo Chandra
- David K. Koswari
- Herbie Sinadia
- Louis Alvaro

## Requirement
- [C++ 14] 

## Compiling/Running Instructions
You can install CodeBlocks or Dev-C++ with their preinstalled compilers and running the program through there.

For manual compiling, follow the steps below:

1. Download a relaible C++ compiler (GNU GCC or MinGW - https://sourceforge.net/projects/mingw/)
2. Install the compiler at your prefered directory
3. Open ```File Explorer```, right click ```This PC```
4. Click ```Advanced System Settings```
5. Click ```Envinronment Variables```
6. On ```System Variables```, find ```Path```, click it to highlight the option and click ```Edit```
7. Click ```Browse``` and find the ```bin``` folder of the recently installed compiler on your computer
   Location should be in ```drivename\...\(installation folder\MinGW\bin```
8. Click ```OK``` on all windows and then open ```Command Prompt```
9. Use ```cd\(folder where the code is downloaded and stored)``` to navigate the terminal to the folder where you stored the code.
10. Use the following command to compile the code: ```g++ (filename).cpp -o (programname).exe -fopenmp```
    
    ```Note: remove the brackets - for filename.cpp, enter the exact same name as the code file in the folder. For programname.exe, enter any name you want for the executable file that will be created.```
11. If succeeded, click ```(programname).exe``` to run the program

Note: The above guide was written with Windows 10 in mind

Video reference: https://www.youtube.com/watch?v=xuQL_BZydS0

## Sample I/O
**Sample #1:**

_In:_
```
5 1
10 5
```

_Out:_
```
YES
```
**Sample #2:**

_In:_
```
4 5
3 3
```

_Out:_
```
YES
```
**Sample #3:**

_In:_
```
1 2
11 6
```

_Out:_
```
NO
```

## Explanation
### Problem Statement
In this problem, we must find out whether the boy and girl can hold hands comfortably together or not. Since the two are basically aliens, they can have fingers less than, equal to, or more than human fingers. The user determines the number of fingers by input:
```
    int f1, f2;
    int m1, m2;

    cin >> f1 >> f2;        //f1 = girl's left  f2 = girl's right
    cin >> m1 >> m2;        //m1 = boy's left   m2 = boy's right
```
Note that no three fingers of the boy may touch each other.
### Greedy Solution
Submission link: https://codeforces.com/contest/62/submission/45874756

After the user inputs the amount of fingers on those two weird creatures, the program will set ```4``` modifiers for the girl's fingers:
```
    int t1 = f1 +1;
    int t2 = f1 - 1;
    int t3 = f2 + 1;
    int t4 = f2 - 1;
```
This is done so that we can test whether the two can hold hands together accounting without accounting for overlapping fingers to check whether their two hands can fit each other or not (depends on which goes left/right) and also testing with an additional finger. 

Afterwards, the program goes to a series of ```if``` conditions to check whether the two can holds hands or not:
```
    if (t2 <= m2 && m2 <= 2*t1)
    {
        cout << "YES";
    }
    else if (t4 <= m1 && m1 <= 2*t3)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
 ```
 The first test involves ```f1```and ```m2``` (boy goes to the left). The program will check whether their hands can fit together by checking the girl's fingers - ```1``` (without overlapping/extra finger) and then comparing it with the amount of fingers in the boy's right hand. The program will also test the size of ```2 x (girl's fingers + 1)``` and compare it with the boy's right hand to determine whether the two hands can fit together or not. The program determines this by checking if the amount of the boy's right hand fingers is equal to or more than the girl's left fingers. If ```f1``` and ```m2``` satisfies the two conditions above, the program will print ```YES```. 
 
 If not, the program will proceed to the second test with ```f2``` and ```m1``` (boy goes to the right). Compare the modified number of ```f2``` with ```m1``` and print ```YES``` if ```f2``` and ```m1``` satisfies the two conditions. 
 
 If all ```4``` variables failed the two tests above, print ```NO``` which means the two can't hold hands together comfortably.
 
 Complexity: ```O(1)```, the program only peforms variable initialization, user input, and comparisons within constant time
 
 ### DP Solution
 Submission link: https://codeforces.com/contest/62/submission/45871856
 
The DP approach for this particular problem isn't much different than using Greedy. Instead of solving one problem first and proceed to the next if no desirable result is found, the program will test the two possibilites (left and right) seperately. First the program will declare an array as global variable:
```
int pass[4] = {0,0,0,0}; 
```
Next, the program will declare a ```void``` function called ```test``` where each individual problems with variable values taken from the ```main``` function whenever it is called:
```
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
```
The function will check whether the values satisfy the conditions on the ```if``` using the same checking formula as the Greedy solution. If a condition is passed, the function will write the current index of the array ```pass``` to ```1``` (the index is determined by the variable ```checker``` which starts from ```0``` each time the function ```test``` is called) and increase the index count by ```1``` and proceed to the second test.

In the main function, the program will intialize the variables and get user input for the ```4``` variables before initializing the modofiers for the girl's arms based on the user input. Then the program will go into a ```for``` loop and test ```f1``` and ```m2``` by passing their values to the function ```test``` and write the results to the array ```pass```. After that, repeat the loop and test ```f2``` and ```m1```.

Afterwards, verify whether the two can hold hands or not by checking the ```pass``` array. If either index ```0``` and ```1``` or ```2``` and ```3``` equals to ```1```, print ```YES```, otherwise, print ```NO```

Complexity:  -coming soon-







