对C++中一些常用的处理方法进行记录，避免遗忘



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

- **int 的范围**：-2^31~2^31  大约在 `-2*10^9 ~2*10^9`

- 有格式获取输入：如`14.1.28`  => `scanf("%d.%d.%d", &a, &b, &c)`

  - `scanf（“%c", &a);`是可以读入空格跟换行的。有时先用scanf再用getline时中间就需要这条语句去吸收多余的换行符
  - `getchar()`与`putchar()`可以获取或输出一个字符。可获取换行符
  - `sscanf(str, "%d", &n)` 与 `sprintf(str, "%d", n);`：第一个s可以理解为string，用处是把str中的内容以%d的格式写到n中（从左往右）。sprintf则是把n以%d的格式写到str中（从右往左）。 str为字符型数组。

- **输出**保留一位小数`printf("%.1f", tmp);`

  - 输出百分号%或斜杠 \ 则需将字符重复一次：`printf("%%  \\");`

  - `%md`与`%0md` 不足m位的int型变量以m位进行右对齐输出，其中高位用空格或者0补齐：如`%05d`， 不足5位的整数前面用0补齐
  - 浮点数尽量使用double类型而float，double 类型输入/输出：`scanf("%lf, &d");`/`printf("%f", d);`  

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

- 部分需要头文件 `#include <string>`
- 数字转字符： `to_string()`
- 字符串转数字(string to int、string to double )：  `stoi(str)；`  \ `stod(str);`
  - 如果是浮点型使用`stoi` 会自动截取最前面的数字直到非数字为止；若开头就不是数字则会发生错误
  - `stod` 若最前面是小数点，自动转换后会补上0
  - 类似的还有`stof`  \ `stold` \ `stolld`
- 返回字符串长度: `s.length()`、`strlen(s)`、`s.size()`
- 数字字符转为int类型：`a - '0'`
- 用 cin 读入字符串时，以空格为分隔符，若想读入整行字符串需用 `getline`
- 末尾添加制定个数字符：`str.append(len, ch);` 在字符串str的末尾添加len个长度的ch
- 插入insert 与字符串拼接

```c++
 string s, s1, s2;   // 声明为字符串类型： string s
 s.insert(0, 2, a);  // 即在下标为0 的地方 插入 2 个字符 a
 s = s1 + s2;       // 直接相加即可
```

- 截取子串：`str.substr(int pos = 0, int len = npos);`

  - 这个函数的作用是取字符串string中位置为pos开始（包含pos这个字符）的len个字符，返回一个字符串。
  - 若仅一个参数，则代表从该位置到最后一位

- 删除字符：`str.erase(pos, n);`   pos代表删除的起始位置，参数n 表示从pos开始删除n个字符。若省略n则一直删除到末尾

- 替换字符：`str.replace(pos, len, str2);`  从pos位置开始的len个字符替换成str2

- find() 函数：在字符串中查找第一次出现的目标字符串位置（返回int），查找失败则返回-1
  ```c++
  str.find(str2);
  str.find(str2, 2);  // 从第二个字符开始查找字符串str2
  ```
  - find_last_of() ：逆序查找，与find_first_of()基本一致

  - find_first_of() ：查找子串中的某个字符最先出现的位置。find_first_of()不是全匹配，而find()是全匹配
    ```c++
    str.find_first_of(str2);
    str.find_first_of(str2, 2);
    ```

  - `string::npos`：可理解为一个返回值，代表在字符串中寻找失败返回的下标

    ```c++
    if(s1.find(s2) == string::nops)
        cout << "未在s1字符串中找到字符s2";
    ```





### vector容器

- 使用头文件 `#include <vector>`
- 向量 **vector** 是一种对象实体, 能容纳许多其他类型相同的元素, 因此又被称为容器。 与string相同, vector 同属于STL(Standard Template Library, 标准模板库)中的一种自定义的数据类型, 可以广义上认为是数组的增强版。（动态数组）
- vector 、 stack 、 queue 、 map 、 set 这些在C++中都叫做容器，这些容器的大小都可以用 `.size()`获取到，就像` string s `的长度用` s.length() `获取一样（实际上 ： string.length() = string.size()）

```c++
vector<int> a ;            //声明一个int型向量a，默认初始化为0
vector<int> a(10, 8) ;     //声明一个初始大小为10且初始值都为8的向量（初始值可省略）
vector<int> b(a.begin(), a.begin()+3) ;   //将a向量中从第0个到第2个(共3个)作为向量b的初始值
vector<student> a[4];     //声明一个结构体student类型的4维向量a （类似二维数组

a.size()                 //获取向量中的元素个数
a.empty()                //判断向量是否为空
a.clear()                //清空向量中的元素
a.push_back(i)           //在vector a 的末尾添加一个元素i
```





### 集合 set

- 使用头文件 `#include <set>`

- 一个`set`里面的元素各不相同，且它会按照元素大小升序排列

- ```
  set<int> s;   // 定义一个空集合s
  s.insert(1);  // 向集合中插入 1
  cout << *(s.begin()) << endl; // 输出集合s的第⼀一个元素 (前⾯面的星号表示要对指针取值)
  
  if(s.find(2) == s.end())  cout << "未找到元素2";
  s.erase(1); // 删除集合s中的1这个元素
  ```



### 映射 map

- 需要头文件 `#include <map>`

- Map是STL的一個容器，它提供一對一的hash。（键值对）

  - 第一個称为关键字(key)，每個关键字只能在map中出現一次；第二個称为关键字的值(value)
  - `map<key, value> mapStudent; `  // key代表关键字的类型，value代表对应值的类型，mapStudent代表实例名称
  - 声明举例：`map<char,int> count;` 设置一个名为count的map容器它关键字类型为char,对应hash值的类型为int。
  - 还可以用`array`的方式**插入**：`count['a'] = 1;` ,  
  - 可以使用`hash`的方式来**查找**：`int num = count['a'];`  ->  num = 1
  - `mapStudent.size() ` 返回**元素个数**

- ```c++
  // 用迭代器遍历，输出map中所有的元素，键用it->first获取，值⽤用it->second获取
  // auto 是C++11里面的新特性，可以让编译器根据初始值类型直接推断变量的类型
  for (auto it = m.begin(); it != m.end(); it++) {
  	cout << it->first << " " << it->second << endl;
  }
  // 访问map的最后一个元素，输出它的键和值
  cout << m.rbegin()->first << " " << m.rbegin()->second << endl;
  ```

- `#include <unordered_map>` 与 `#include <unordered_set>`  
  `unordered_map`和` map `（或者 `unordered_set` 和 `set` ）的区别： `map` 会按照键值对的键 key 进行排序（` set` 里面会按照集合中的元素大小进行升序排列）；而 `unordered_map` （或
  者 `unordered_set` ）省去了这个排序的过程
- 如果偶尔刷题时候用 `map` 或 `set` 超时了，可以考虑用` unordered_map` （或者 `unordered_set` ）缩短代码运行时间。用法和map 、 set 相同





### 栈 stack 、队列 queue

- 使用头文件 `#include <stack>`
- 栈操作：
  - 声明： `stack<string> s;`  string可以换成其它的type
  - 判断栈空：`s.empty()`  当栈空时返回true
  - 返回栈中元素个数：`s.size();`
  - 入栈：`s.push(s);`   、 出栈：`s.pop();`  、返回栈顶元素：`s.top()`
  - 注意：无法直接输出弹出的栈顶元素

- 使用头文件 `#include <queue>`

- 其余操作基本与栈一致

- ```c++
  cout << q.front() << " " << q.back() << endl; // 访问队⾸元素和队尾元素
  ```





### STL 之 algorithm（算法）

- 使用头文件 `#include <algorithm>`
- `reverse`函数可以实现将一个数组或者vector中元素倒置，参数为数组的起始地址和结束地址
- sort（start，end, cmp); 默认是升序排列，若是要降序则要自定义规则.（自定义规则方法参见Algorithm/cskaoyan/ 1.1.cpp）







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