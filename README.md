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

1. Download a reliable C++ compiler (GNU GCC or MinGW - https://sourceforge.net/projects/mingw/)
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
 The first test involves ```f1```and ```m2``` (boy goes to the left). The program will check whether their hands can fit together by checking the girl's fingers - ```1``` (without overlapping/extra finger) and then comparing it with the amount of fingers in the boy's right hand. The program will also test the size of ```2 x (girl's fingers + 1)``` (making sure that the number of girl's fingers isn't that much different than the boy's) and compare it with the boy's right hand to determine whether the two hands can fit together or not. The program determines this by checking if the amount of the boy's right hand fingers is equal to or more than the girl's left fingers. If ```f1``` and ```m2``` satisfies the two conditions above, the program will print ```YES```. 
 
 If not, the program will proceed to the second test with ```f2``` and ```m1``` (boy goes to the right). Compare the modified number of ```f2``` with ```m1``` and print ```YES``` if ```f2``` and ```m1``` satisfies the two conditions. 
 
 If all ```4``` variables failed the two tests above, print ```NO``` which means the two can't hold hands together comfortably.
 
 Complexity: ```O(1)```, the program only peforms variable initialization, user input, and comparisons within constant time
 
 ### DP Solution
Submission link: https://codeforces.com/contest/62/submission/46403380
 
Instead of using single use integers, this approach uses arrays to store the inputs and final results. After getting all ```4``` inputs, we first get the result for ```girl & boy``` (in that particular order). The program will go to the ```test``` function to see whether the two inputs are the correct answer or not:
```
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
```
The function will set the modifiers on the first function passed and perform two tests to determine whether the two can hold hands or not. The input is deemed a valid answer (```YES```) if the returned value of checker is ```2``` (all two tests passed).

We perform the check four times = first to compare ```f[0], m[1]``` with ```f[1], m[0]``` and ```m[1], f[0]``` with ```m[0], f[1]```.
Get the maximum checker value each two tests (girl first and boy first) and insert the values to their respective answer arrays (```pass``` and ```pass2```).

After that, the program will check whether the two can hold hands or not by comparing the two arrays. If either of those arrays' first index is equal to ```2```, print ```YES```, otherwise print ```NO```.

Complexity: ```O(n)```

### Comparison
We ran several different tests (with increasing values) to obtain the runtime differences between the two approaches:
```
f1   | f2   | m1   | m2   |  Greedy  |    Dp
5    | 1    | 10   | 5    |  374     | 1542944035
4    | 5    |  3   | 3    |  10806   | 1542944102
1    | 2    | 11   | 6    |  11788   | 1542944133
20   | 22   | 25   | 29   |  10148   | 1542944171
25   | 50   | 75   | 85   |  15722   | 1542944198
100  | 101  | 199  | 150  |  11764   | 1542944226
250  | 800  | 950  | 1500 |  16111   | 1542944257
2000 | 2018 | 5009 | 9999 |  18733   | 1542944288

(running time are in integer format)
```
Based on the following tests, we can conclude that the Greedy apporach is the most efficient approach to solve the problem since the Greedy approach tests at least one sub-problem instead of solving all two sub-problems sequentially. Greedy approach performs two comparisons for every sub-problem (each preceeded with two basic/simple calculations) whilst the DP approach solves every sub-problem in a seperate function and each solution is stored in the array. DP also involves the creation of an array with the size of ```2``` at the start of the program whilst the Greedy solution uses no array at all and directly performs all calculations needed to get the desired output.





