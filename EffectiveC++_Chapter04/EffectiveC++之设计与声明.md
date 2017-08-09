## 让接口容易被正确使用，不易被误用

* 首先需要考虑客户可能做出什么样的错误, 详情见sample01.cpp

假设你为一个用来表现日期的class设计构造函数:

```
class Date {
    private:
        int day;
        int month;
        int year;
        
    public:
        Date(int month, int day, int year);
};

Date::Date(int month, int day, int year): month(month), day(day), year(yearN) {}

```

我们通过之前教程中学习到的方法可以很轻易的把构造函数写出来，但是里面有几个问题：

* 可能会以错误的次序来传输参数 如30.3.2016
* 可能会传递一个无效的月份或天数

以上两个问题可以使用一种称为`类型系统` 来解决；

如上所言，我们可以使用`外覆盖类型`来区别天数、月份和年份，如下例所示:

```
struct Day {
  int day;
  explicit Day(int val):day(val) {};
};

struct Month {
  int month;
  explicit Month(int val):month(val) {};
};

struct Year {
  int year;
  explicit Year(int val):year(val) {};
};

Date::Date(const Month& month, const Day& day, const Year& year): month(month), day(day), year(year) {}

```

如果数据的类型已经正确定立了，还需要限制数据的值的范围。

例如一年只有12个月，所以month应该反映这个事实。

1. 第一种方法是enum实现月份，但是enums不具备我们认为的类型安全性，例如enums可被拿来当一个ints使用
2. 限制类型内什么事可做，什么事不能做，常见的限制是加上const


### 让types容易被使用，不容易被误用

除非有好理由，否则应该尽量令你的types的行为与内置types的行为一致

避免无端与内置类型不兼容，真正的理由是为了提供一致的接口，



## 设计class犹如设计type

设计一个高效的class需要满足以下问题:

* 新的type对象应该如何被创建和销毁？ -> 这会影响到你的class的构造函数和析构函数以及内存分配函数和释放函数久设计，如果你需要的话
* 对象的初始化和对象的赋值该有什么样的差别？ -> 这个影响你的构造函数和赋值操作符的行为以及其间的差异，很重要的是别混淆了`初始化`和`赋值`，因为它们对应于不同的函数调用。
* 新的type对象如果被passed by value，意味着什么？ -> 记住copy函数用来定义一个type的passed-by-value该如何实现
* 什么是新的type的合法值？ -> 对class成员变量而言，通常只有某些数值集是有效的，那些数值集决定了你的class必须维护的约束条件，也就决定了你的成员函数必须进行的错误检查，它也影响函数抛出的异常，以及函数异常明细列。
* 你的新的type需要配合某个继承图系么？ -> 如果你继承自某些既有的classes，你就受到那些classes的设计的束缚，特别是受到"它们的函数是virtual或no-virtual"的影响，如果你允许其他的classes继承你的class，那会影响你所声明的函数-尤其是析构函数是不为虚函数
* 你的新的type需要什么样的转换？ -> 你的type与其他type之间，因而彼此之间该有转换行为么？如果你希望类型T1之物这被隐式转换为类型T2之物，就必须在class T1内写一个类型转换函数，或者在class T2内写一个non-explicit-one-argument 的构造函数，如果你只允许expilit函数存在，就得写出专门负责执行转换的函数，且不得为类型转换操作符，或no-explicit-one-argument的构造函数。
* 什么样的操作符和函数对此新type而言是合理的？ -> 这个问题的答案决定于你将为你的classes声明哪些函数，其中某些是member函数，某些则否
* 什么样的标准函数应该驳回？ -> 那些你必须声明为private 的函数或者函数
* 谁该取用新type的成员？ -> 这个问题的答案可以帮助你决定哪个成员是public等的访问权限等问题
* 什么是新type的"未声明接口"? -> 它对效率、异常安全性以及资源运用提供何种保证，你在这方面提供的保证将为你的class实现代码加上相应的约束条件
* 你的新type有多一般化?
* 你真的需要一个新type么？


## 宁以pass-by-reference-to-const 替换 pass-by-value

缺省状态下C++以by value 方式传递对象至函数。除非你另外指定，否则函数参数都是以实参的副件为初值，而调用端所获得的也是函数返回值的一个复件，这个复件是由对象的copy函数决定的，这可能使用passed-by-value 成为昂贵的操作。


pass by reference to const 这种传递方式高效的多，因为没有任何构造函数或析构函数被调用，因为没有任何新的对象被创建，
以by reference 方式传递参数也可以避免slicing的问题，当一个derived class对象以by value方式传递并被视为一个base class 对象，base class的copying函数会被调用而造成"此对象的行为像个derived class"的那些特化性质被切割掉了，仅仅留下了一个base class 对象。


reference 往往以指针实现出来的，因此，pass by reference 通常意味真正传递的是指针，因此，如果你有个对象属于内置类型，pass by value 往往比pass by reference 效率要高。

### 必须返回对象时，别妄想返回其reference

在学习了上面的知识后，在实践的过程中可能会因此产生一些问题。
当开始传递reference 指向其实并不存在的对象时，会产生一些问题。


### 将成员变量声明为private

### 宁以non-member, non-friend替换member函数

我们在示例代码中定义了一个WebBrowser类，这个类有清除缓存、清除历史记录和cookies的功能

我们需要提供一个可以执行上面所有的动作的接口，现在有两种方法: 

1. 使用member函数来处理这些函数
2. 使用non-member函数来处理这些函数

根据面对对象守则要求，数据以及操作数据的那些函数应该被捆绑在一块儿，这意味着member函数是比较好的函数，不幸的是这个建议不正确，这是基于面对对象的一个误解。面对对象守则要求数据应该尽可能被封装，然而与直观相反的，member函数excuteAllFunction带来的封装性比non-member函数clearWebBrowserAll低。此外，提供non-member函数可允许对WebBrowser相关机能有效大的包裹弹性(packaging flexibility),而那最终导致较低的编译相依性，增加WebBrowser的可伸展性:

### 若所有的参数皆需类型转换，请为此采用no-member函数




