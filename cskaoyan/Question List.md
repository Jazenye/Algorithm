

#### chapter 1  经典入门

- 1.1 运用stl进行结构体排序

  - 输入N（N<=1000）个学生的姓名、年龄、成绩，按照成绩高低排序，若相同，则次关键字依次为 成绩>姓名>年龄

  - ```c++
    input:
    3
    abc 20 99
    bcd 19 97
    bed 20 97
    
    output:
    bcd 19 97
    bed 20 97
    abc 20 99
    ```

- 1.2 求两日期之间的差值

  - 输入两个格式为YYYYMMDD（Y代表四位数的年份，M和D分别代表两位数的月份）的数字串，判断两个日期之间间隔多少天

  - ```
    input:
    20110412
    20110422
    
    output:
    11
    ```

- 1.3 给定日月年，日期

  - 可以学习使用蔡勒（Zeller）公式

  - ```
    input:
    9 October 2001
    14 Ocotber 2001
    
    output:
    Tuesday
    Sunday
    ```

- 1.4 Hash

  - 