对C++中一些常用的处理方法进行记录，避免遗忘



### Q 1002

- 部分需要头文件 `#include <string>`
- 声明为字符串类型： `string s`
- 数字转字符： `to_string()`
- 返回字符串长度: `s.length()`、`strlen(s)`、`s.size()`
- 数字字符转为int类型：`a - '0'`



### Q 1003

- 需要头文件 `#include <map>`

- Map是STL的一個容器，它提供一對一的hash。

  - 第一個可以稱為關鍵字(key)，每個關鍵字只能在map中出現一次，

  - 第二個可能稱為該關鍵字的值(value)

  - map<key, value> mapStudent;  // key代表关键字的类型，value代表对应值的类型，mapStudent代表实例名称

  - 声明举例：`map<char,int> count;` 设置一个名为count的map容器它关键字类型为char,对应hash值的类型为int。还可以用`array`的方式**插入**：`count['a'] = 1;` ,  可以使用`hash`的方式来**查找**：`int num = count['a'];`  ->  num = 1

  - `mapStudent.size() `返回key的个数



### Q 1005

- 使用头文件 `#include <vector>`

- 向量 **vector** 是一种对象实体, 能容纳许多其他类型相同的元素, 因此又被称为容器。 与string相同, vector 同属于STL(Standard Template Library, 标准模板库)中的一种自定义的数据类型, 可以广义上认为是数组的增强版。
- vector 容器与数组相比：它能够根据需要随时自动调整自身大小。此外, vector 也提供了许多的方法来对自身进行操作。

```c++
vector<int> a ;            //声明一个int型向量a
vector<int> a(10, 1) ;     //声明一个初始大小为10且初始值都为1的向量（初始值可省略）
vector<int> b(a.begin(), a.begin()+3) ;   //将a向量中从第0个到第2个(共3个)作为向量b的初始值

a.size()                 //获取向量中的元素个数
a.empty()                //判断向量是否为空
a.clear()                //清空向量中的元素
```



### Q 1008

- 使用头文件 `#include <algorithm>`

- `reverse`函数可以实现将一个数组或者vector中元素倒置，参数为数组的起始地址和结束地址



### Q1009

- 使用头文件 `#include <stack>`
- 栈操作：
  - 声明： `stack<string> v;`  string可以换成其它的type
  - 入栈：`v.push(s);`   、 出栈：`v.pop();`  、栈顶元素：`v.top()`
  - 注意：无法直接输出弹出的栈顶元素