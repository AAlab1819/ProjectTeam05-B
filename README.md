# Solving Codeforces Problem 62A using Greedy & Dynamic Programming
This Repository will solve Codeforces' problem [62A](http://codeforces.com/problemset/problem/62/A) using Dynamic Programming and Greedy.

## Team Member
- Calvindo Chandra
- David K. Koswari
- Herbie Sinadia
- Louis Alvaro

## Requirement
- [C++ 14] 

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
 
 -coming soon-





