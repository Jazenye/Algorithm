对C++中一些常用的处理方法进行记录，避免遗忘

**如何在Dev-Cpp中使⽤用C++11中的函数？**
若想在 Dev-Cpp 里面用⽤用C++11特性的函数，比如刷算法中常用的stoi 、 to_string 、unordered_map 、 unordered_set 、 auto 这些，需要在设置里让dev⽀持C++11
=> 在菜单栏中 工具-编译选项-编译器器-编译时加入 `-std=c++11` 

若在**codeblock**中，则是设置 setting-compiler-compiler flags中勾选：`havegcc follow the 2011 ISO c language standar[-std=c11]`



在机试中，由于某些本地IDE会自动引入库，到在OJ时可能会发生编译不通过的情况，若是看不到反馈容易GG，所以保险起见记一些常见的头文件：`iostream`、`cstdio`、`cmath`、`cctype`、`cstring`、`string`、`algorithm`、`vector`、`map`、`unorderedmap`、`set`、`queue`、`stack`



### 语言基础用法

- C++中头⽂件一般是没有像C语言的` .h` 这样的扩展后缀，C语⾔里面的头文件去掉` .h `然后在前⾯面加个 c 就可以继续在C++文件中使用C语言头文件中的函数。`#include <cmath>`

- `#include <math.h>`

  - 次方运算： `pow(a, b);` -> a^b
  - 开平方根：`double db = sqrt(2.0);`
  - 还可以取log（单参数以自然数为底，若想以其它数为底需要换底公式）、用三角函数（sin\cos\tan）、反三角（asin\acos\atan）。圆周率 π = acos(-1.0);
  - 取绝对值：`fabs(d);`  -> |d|
  - **四舍五入**的技巧：`(int)(s+0.5);`  \  `n = (n+0.5*f) / f;`
    - `double db = round(3.40);`
  - double型 向上取整、向下取整：`floor()` \ `ceil()`

- 头文件：`#include <ctype.h>`   // 若是c++中则写为 cctype

  - 转换为大（小）写字母：`toupper(c);`   、`tolower(c);`
  - 判断是否是字母、大写、小写、大小写+数字：`isalpha、islower、isupper、isalnum`
  - 手动方法： 大写转小写 ` c = c + 32;` （记住小写字母的ASCII码比大写字母大32，且数字字符也有ASCII码）

- C语言**强制类型转换**： （待转换类型）变量a    `(int)a;`

- 三目运算符，若A为真则执行并返回B的结果，否则执行并返回C的：`A ? B : C;`

  ```
  switch(a + b){
      case 1:
      	printf("1");
      	break;
      case 2:
      	printf("2");
      	break;
      default:
      	printf("nn");
  }
  ```

- 结束本次循环` continue; ` // 与break不同 

- **int 的范围**：-2^31~2^31  大约在 `-2*10^9 ~2*10^9`  （数组一般开在main函数外，且注意是10的多少次方，范围被开小了），如果范围不够则使用 `long long int`（可以简写为 `long long `）

- 有格式获取输入：如`14.1.28`  => `scanf("%d.%d.%d", &a, &b, &c)`

  - `scanf（“%c", &a);`是可以读入空格跟换行的。有时先用scanf再用getline时中间就需要这条语句去吸收多余的换行符

  - `getchar()`与`putchar()`可以获取或输出一个字符。可获取换行符

  - `sscanf(str, "%d", &n)` 与 `sprintf(str, "%d", n);`：第一个s可以理解为string，用处是把str中的内容以%d的格式写到n中（从左往右），从一个字符串中读进与指定格式相符的数据。`sprintf`则是把n以%d的格式写到str中（从右往左），字符串格式化命令，把格式化的数据写入某个字符串中。 str为字符型数组（`char str[N];`）。（在头文件`#include <stdio.h>` 中， 使用时 可先建立一个字符数组+scanf+%s 接收输入的字符串再用该方法导入）

    ```c++
    str = "china beijing 123";
    str2 = "abcd";
    ret = sscanf(str, "%s %s %d", s1, s2, &num);
    sscanf(str2, "%2s", s3); //取指定长度字符串， s3 = ab
    /*
    **ret = 3, s1 = china, s2 = beijing, num = 123
    **可以看出,sscanf的返回值是读取的参数个数
    ** 
    */
    ```

- **输出**保留一位小数`printf("%.1f", tmp);`

  - 输出百分号%或斜杠 \ 则需将字符重复一次：`printf("%%  \\");`

  - `%md`与`%0md` 不足m位的int型变量以m位进行右对齐输出，其中高位用空格或者0补齐：如`%05d`， 不足5位的整数前面用0补齐
  - 浮点数尽量使用double类型而非float，double 类型输入/输出：`scanf("%lf, &d");`/`printf("%f", d);`  

- **判断是否为素数**

  ```
  bool isprime(int a) {
      for (int i = 2; i * i <= a; i++)
          if (a % i == 0) return false;
      return true;
  }
  ```

- 寻找最大（最小）值：先赋值一个最小（最大）的边界值，而后与数组内容进行比较

- c++中新增bool变量：有 `ture\false `两种值

- c++中有`getline()`用于获取整行的输入，不像`cin`以空格分割，`getline()`以换行符或第三个参数作为结束符

  ```
  in -> MAP.
  string s;
  getline(cin, s, '.');    //  此时 s = MAP
  ```

- c++中的逐字符输入：`while ((c = cin.get()) != EOF)  map[c]++;`

- `cin` 与  `getline()` 混用时中间可以用 `getchar() ` 获取空的换行符。




### 字符串 String

- 部分需要头文件 `#include <string>` （注意，与`#include <string.h>`不同）
- **访问**时可以按照 字符数组 的方式访问字符串中的字符。也可以使用迭代器`string::iterator it`来访问 ）
- 数字转字符： `to_string()`
- 字符串转数字(string to int、string to double )：  `stoi(str)；`  \ `stod(str);`
  - 如果是浮点型使用`stoi` 会自动截取最前面的数字直到非数字为止；若开头就不是数字则会发生错误
  - `stod` 若最前面是小数点，自动转换后会补上0
  - 类似的还有`stof`  \ `stold` \ `stolld`
  - **数字 字符 转为int类型**：`a - '0'`
- 返回字符串长度: `s.length()`、`strlen(s)`、`s.size()`。 `strlen`也可范围字符数组的长度
- 用 cin 读入字符串时，以空格为分隔符，若想**读入整行字符串**需用 `getline(cin, str);`
- 字符串拼接与比较：

  - `s = s1 + s2; `    // 直接相加即可
  - 末尾添加制定个数字符：`str.append(len, ch);`  在字符串str的末尾添加len个长度的ch
  - 插入insert  ：`s.insert(0, str);`，即在下标为0 的地方 插入字符串str
  - C++中可以直接使用运算符进行**字符串比较**，比较的是字典序：`if(str1 != str2) `，还有>、>=等系列运算符
- 字符串替换与截取：
  - 删除字符：`str.erase(pos, n);`   pos代表删除的起始位置，参数n 表示从pos开始删除n个字符。若省略n则一直删除到末尾。 单个位置也可以使用迭代器来指定，如`str.begin()+i`
  - 替换字符：`str.replace(pos, len, str2);`  从pos位置开始的len个字符替换成str2
  - 清除：`str.clear()`
  - 截取子串：`str.substr(int pos = 0, int len = npos);`
    - 这个函数的作用是取字符串string中位置为pos开始（包含pos这个字符）的len个字符，返回一个字符串。
    - 若仅一个参数，则代表从该位置到最后一位


- find() 函数：在字符串中查找第一次出现的目标字符串位置（返回int），查找失败则返回-1
  ```c++
  str.find(str2);  // 在str中寻找str2是否出现，若出现则返回str2的初次出现位置
  str.find(str2, 2);  // 从第二个字符开始查找字符串str2
  ```
  -  `string::npos`：可理解为一个返回值，代表在字符串中寻找失败返回的下标
    ```c++
    if(s1.find(s2) == string::nops)
        cout << "未在s1字符串中找到字符s2";
    ```
  - find_last_of() ：逆序查找，与find_first_of()基本一致

  - find_first_of() ：查找子串中的某个字符最先出现的位置。find_first_of()不是全匹配，而find()是全匹配
    ```c++
    str.find_first_of(str2);
    str.find_first_of(str2, 2);
    ```





### vector容器

- 使用头文件 `#include <vector>`
- 向量 **vector** 是一种对象实体, 能容纳许多其他类型相同的元素, 因此又被称为容器。 与string相同, vector 同属于STL(Standard Template Library, 标准模板库)中的一种自定义的数据类型, 可以广义上认为是数组的增强版。（动态数组）
- vector 、 stack 、 queue 、 map 、 set 这些在C++中都叫做容器，这些容器的大小都可以用 `.size()`获取到，就像` string s `的长度用` s.length() `获取一样（实际上 ： string.length() = string.size()）

```c++
vector<int> a ;            //声明一个int型向量a，默认初始化为0
vector<int> a(10, 8) ;     //声明一个初始大小为10且初始值都为8的向量（初始值可省略）
vector<int> b(a.begin(), a.begin()+3) ;   //将a向量中从第0个到第2个(共3个)作为向量b的初始值，这种写法只有vector与string中可用 （v.begin()+i)

a.size()                 //获取向量中的元素个数
a.empty()                //判断向量是否为空
a.clear()                //清空向量中的元素
a.erase(a.begin(), a.begin()+2); //若省略后一参数即删除单个元素，若两个参数都在则按照左闭右开的规则，删除a[0]、a[1]
 
a.insert(a.begin()+1, -1); //在a[1]处插入-1
a.push_back(i)    //在vector a 的末尾添加一个元素i，未指定大小时可以配合它当栈用
a.pop_back(i)            // 删除vector中的尾元素
    
a.begin()； // 取的是a的首元素地址
a.end()；  // 取的是尾元素地址的下一个地址
for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d", *it);
```

- 二维数组

```c++
vector<vector<int> > v(10, vector<int>(5, 100));        //创建一个10*5的int型二维向量,并且初始化为100（此参数可省略）
// 注意就是把一维中的typename(int) 换成了vector<int>，两个 >> 之间应有空格
v.size();  // 返回v的行数，10
v[0].size();  // 返回v的列数， 5
```







### 集合 set

- 使用头文件 `#include <set>`
- `set`是一个内部自动有序（升序），且不含重复元素的容器。可以用它来去重，保留元素本身而不考虑它的个数。若使用 `unordered_set`可以实现只去重不排序的需求，且速度快很多。（需要不一样的头文件，同该容器名称）
- 同样包含`set.size()` 、 `set.clear()` 

```
set<int> s;   // 定义一个空集合s
s.insert(1);  // 向集合中插入 1
cout << *(s.begin()) << endl; // 输出集合s的第⼀一个元素 (前⾯面的星号表示要对指针取值)
  
if(s.find(2) == s.end())  cout << "未找到元素2";
s.erase(s.find(1));  // 删除集合s中的1这个元素,s.erase(1)

// 删除某一区间的元素，下面是删除元素30至set末尾之间的元素
set<int>::iterator it = st.find(30);
st.erase(it, st.end());  
```



### 映射 map

- 需要头文件 `#include <map>`

- 数组只能提供整型到其它类型的映射 且还要受限于数组的大小限制，而map可以提供不同类型之间的映射，包括STL容器到STL容器之间的映射，或是String到int的映射。

- Map是STL的一個容器，它提供一對一的hash。（键值对）map会以键的升序在内部自动排序。所以类似于set,它也有`unordered_map`。 ps：map的键值一一对应，若想一个键对应多个值可以使用multimap

  - 第一個称为关键字(key)，每個关键字只能在map中出現一次；第二個称为关键字的值(value)

  - `map<key, value> mapStudent; `  // key代表关键字的类型，value代表对应值的类型，mapStudent代表实例名称。**如果是字符串到整型的映射，必须使用string 而非char数组**

  - 声明举例：

    ```c++
    map<int, int> ary;  //  与数组相似。
    map<char,int> count;  //设置一个名为count的map容器它关键字类型为char,对应hash值的类型为int。
    map<set<int>, string> mp; // 将一个set容器映射到一个字符串
    ```

  - 还可以用`array`的方式**插入**：`count['a'] = 1;` ,  

  - 可以使用`hash`的方式来**查找**：`int num = count['a'];`  ->  num = 1

  - `mapStudent.size() ` 返回**元素个数**

  - 常见：`mp.clear()`、`mp.size()`、`mp.size()`

  - 删除元素：

    - `mp<char, int>::iterator it = mp.find('a');`  `mp.erase(it, mp.end());`
    - 两句话合在一起的作用即找到键值为'a'的元素，用迭代器指针指向它，并删除它到末尾之间的元素。若省略erase中的后一参数，则仅删除一个元素。
```c++
// 用迭代器遍历，输出map中所有的元素，键用it->first获取，值⽤用it->second获取
// auto 是C++11里面的新特性，可以让编译器根据初始值类型直接推断变量的类型
for (auto it = m.begin(); it != m.end(); it++) 
  	cout << it->first << " " << it->second << endl;
  
// 访问map的最后一个元素，输出它的键和值
cout << m.rbegin()->first << " " << m.rbegin()->second << endl;
```

- 用途：
  - 建立字符串（字符）到整数之间的映射
  - 将大整数或其他类型数据是否存在的题目可将map作为Bool数组使用
  - map对值的排序不太方便，不会的话还是用结构体来替代吧
- `#include <unordered_map>` 与 `#include <unordered_set>`  
  `unordered_map`和` map `（或者 `unordered_set` 和 `set` ）的区别： `map` 会按照键值对的键 key 进行排序（` set` 里面会按照集合中的元素大小进行升序排列）；而 `unordered_map` （或
  者 `unordered_set` ）省去了这个排序的过程。
- 如果偶尔刷题时候用 `map` 或 `set` 超时了，可以考虑用` unordered_map` （或者 `unordered_set` ）缩短代码运行时间。用法和map 、 set 相同





### 栈 stack 、队列 queue

- 使用头文件 `#include <stack>`  /  `#include <queue>`
- 栈操作：
  - 声明： `stack<string> s;`  string可以换成其它的type
  - 判断栈空：`s.empty()`  当栈空时返回true
  - 返回栈中元素个数：`s.size();`
  - 入栈：`s.push(s);`   、 出栈：`s.pop();`  、返回栈顶元素：`s.top()`
  - 注意：无法直接输出刚弹出的栈顶元素

- 队列其余操作基本与栈一致
- ```c++
  cout << q.front() << " " << q.back() << endl; // 访问队⾸元素和队尾元素
  // 使用这两个函数前，必须使用empty()方法判断是否为空，否则容易出现错误
  ```





### STL 之 algorithm（算法）

- 使用头文件 `#include <algorithm>`
- `reverse`函数可以实现将一个数组或者vector中元素倒置，参数为数组的起始地址和结束地址
- `sort（start，end, cmp); `默认是升序排列，若是要降序则要自定义规则.（自定义规则方法参见Algorithm/cskaoyan/ 1.1.cpp）
- `max(a, b)` \ `min(a, b)`： 返回两个参数值中的较大值/较小值。若想比较三个数，可以嵌套使用`max(a, max(b, c))`
- `swap(a, b);`：交换两个变量的值
- `fill(pos1, pos2, num);`：讲数组起始地址pos1到地址pos2的部分赋值为num。这里的赋值可以是数组类型对应范围中的任何值。







## 思路部分

#### 日期处理

- 处理闰年（被4整除但不能被100整除的，或者能被400整除的），然后对2月份的特殊情况进行记录（一般用二维数组）
- 日期差值：记录与同一天日期的差值然后进行相减；或对较小的日期进行count++ 直到遇到较大的日期。



#### 进制转换

- 将 P 进制数x（a1a2a3...an） 转换为十进制数 y = a1\*p^(n-1) + a2\*p^(n-2) +..+ an

  ```
  int y = 0, prodcut = 1;
  while(x != 0){
      y = y + (x % 10) * product;
      product *= p;
  }
  ```

- 



#### 辗转相除法找最大公约数

辗转相除法最大的用途就是用来求两个数的最大公约数。

**基本原理**：两个整数的最大公约数 = 其中较小的数和两数的差的最大公约数。

**个人解析**：若A、B有最大公约数K（A > B)，则，A、B、（A - B）、A mod B（A / B的余数），都是K的倍数。即余数（A - B）和 B 的最大公公约数也是 K 。由此递归，可知当 A mod B = 0，即 A 是 B 的倍数时，此时，B 即为 K 。

设两数为a、b(a>b)，求a和b最大公约数(a，b)的步骤如下:用a除以b，得a÷b=q......r1(0≤r1)。若r1=0，则(a，b)=b;若r1≠0，则再用b除以r1，得b÷r1=q......r2 (0≤r2).若r2=0，则(a，b)=r1，若r2≠0，则继续用r1除以r2，……如此下去，直到能整除为止。其最后一个非零除数即为(a，b)。

例：求 15750 与27216的最大公约数。
解：
∵27216=15750×1+11466 ∴（27216，15750）=（15750，11466）
∵15750=11466×1+4284 ∴（15750，11466）=（11466,4284）
∵11466=4284×2+2898 ∴（11466,4284）=（4284，2898）
∵4284=2898×1+1386 ∴（4284，2898）=（2898，1386）
∵2898=1386×2+126 ∴（2898，1386）=（1386，126）
∵1386=126×11 ∴（1386，126）=126

所以（15750，27216）=216  

```c++
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
```

