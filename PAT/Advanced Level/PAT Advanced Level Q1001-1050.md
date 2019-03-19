PAT advanced level 没有固定的几题一组，难度比basic要高但也分为三个等级，分别为：20分、25分、30分。



#### 1001 A+B Format （20 分)[字符串处理]

Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

- Input Specification:

Each input file contains one test case. Each case contains a pair of integers *a* and *b* where −10^6≤*a*,*b*≤10^6. The numbers are separated by a space.

- Output Specification:

For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.

- Sample Input:

```in
-1000000 9
```

- Sample Output:

```out
-999,991
```

- My idea： 先对字符串进行处理，判断位数能否被3整除后插入（insert）逗号，其中使用cnt来记录插入个数并纠正判断的位数
- 大神做法：逐个字符输出，位置正确的地方直接插入输入一个逗号





#### 1002 A+B for Polynomials （25 分）[模拟]

This time, you are supposed to find *A*+*B* where *A* and *B* are two polynomials.

- Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

 K N 1 aN1 N2 aN2 ... NK aNK

where *K* is the number of nonzero terms in the polynomial, *Ni* and *a**N**i* (*i*=1,2,⋯,*K*) are the exponents and coefficients, respectively. It is given that 1≤*K*≤10，0≤*NK*<⋯<*N*2<*N*1≤1000.

- Output Specification:

For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

- Sample Input:

```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

- Sample Output:

```out
3 2 1.5 1 2.9 0 3.2
```

- 模拟的内容是两个多项式相加，最后输出项数、各项的指数和系数。
- 注意：1、要精确到小数点后一位；2、系数可能为零；3、有些在数组或map中记录的系数可能为0，若用size等方法来计算长度时会偏大





#### 1003 Emergency （25 分)[Dijkstra算法]

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

- Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: *N* (≤500) - the number of cities (and the cities are numbered from 0 to *N*−1), *M* - the number of roads, *C*1 and *C*2 - the cities that you are currently in and that you must save, respectively. The next line contains *N* integers, where the *i*-th integer is the number of rescue teams in the *i*-th city. Then *M* lines follow, each describes a road with three integers *c*1, *c*2 and *L*, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from *C*1 to *C*2.

- Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between *C*1 and *C*2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

- Sample Input:

```in
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```

- Sample Output:

```out
2 4
```





#### 1025 PAT Ranking （25 分）

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

- Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number *N* (≤100), the number of test locations. Then *N* ranklists follow, each starts with a line containing a positive integer *K* (≤300), the number of testees, and then *K* lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

- Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

```
registration_number final_rank location_number local_rank
```

The locations are numbered from 1 to *N*. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

- Sample Input:

```in
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
```

- Sample Output:

```out
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
```