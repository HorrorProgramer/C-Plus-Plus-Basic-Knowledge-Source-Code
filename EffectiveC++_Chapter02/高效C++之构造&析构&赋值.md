## 构造&析构&赋值

### 了解C++自动生成的函数

在创建一个类的时候，如果没有声明构造函数、析构函数、copy构造函数和copy assignment操作符，则编译器会自动声明这些函数的，编译器也会自动声明一个default构造函数，且这些函数都是public且inline的

```
class Empty {};
```

就好像你已经添加了如下代码：

```
class Empty {
	public:
		Empty() {} //default constructer
		~Empty() {} //destructer
		Empty(const Empty& rhs) {} //copy constructer
		Empty& operator= (const Empty& rhs) {}; //copy assignment
};
```

下面这些代码可以调用这些：

```
Empty e1;
Empty e2(e1);
e2 = e1;
```

* **default** 构造函数和析构函数主要是给编译器一个地方用来放置`藏身幕后`的代码，像是调用base classes 和 non-static成员变量的构造函数和析构函数；**需要注意**：编译器产生的析构函数是个non-virtual函数，除非这个class的base class自身声明有virtual析构函数
* **copy析构函数和copy assignment操作符'** 编译器创建的版本只是单纯的将来源对象的每一个non-static 成员变量拷贝到目标对象。


###  可以拒绝定义系统自动生成的函数

为了拒绝编译器自动提供的机能，可将相应的成员函数声明为private类型眀不予实现，使用像Uncopyable这样的base class也是一种方法

###  为多态基类声明virtual析构函数

当derived class经由一个base class指针被删除，而该base-class带有一个non-virutal析构函数其结果未有定义；

实际执行时通常发生的是对象derived成分没有被销毁。

消除这个问题的方法也很简单：
给base class 一个virtual析构函数

virtual函数的目的是允许derivedclass客制化；

任何class只要带有virtual几乎可以确定应该也有一个virtual析构函数，如果一个class没有virtual函数，则意味着该class不作为baseclass使用


欲实现virtual函数，对象必须携带某些信息，主要用来在运行期决定哪个virtual函数被调用。
这个信息通常由一个所谓的vptr(virtual table pointer)指针指出

vptr指向一个函数指针的数组，称为vtbl，每一个带有virtual函数的class都有一个对应的vtbl，当对象调用某一vitual函数时，实际被调用的函数取决于该对象的vptr所指的那个vtbl-编译器在其中寻找适当的函数指针；

所以只有当class里面含有至少一个virtual函数时才为它声明virtual析构函数

#### 纯虚函数

纯虚函数：pure virtual 会造成抽象类，也就是不能被实体化的类


### 别让异常逃离析构函数

C++不禁止析构函数吐出异常，但是不推荐这么做，


### 绝不在构造和析构过程中使用virtual函数

不能在构造函数和析构函数期间使用virtual函数，因为这样的调用不会给你带来预想的结果

在derived class对象的base class构造期间，对象的类型是base class而不是derived class类型，不只virtual函数会被编译器解析至base class， 若使用运行期类型信息(runtime type information) 也会把对象视为base clase类型。


相同道理，析构函数也适用，一旦derived class 析构函数开始执行，对象内的derived class成员变量便呈现未定义值，所以C++视它们仿佛不在存在；

### 令operator=返回一个 __refrence to `*this`__

令同仁(assignment) 操作符返回一个reference to *this

### 在operator=中处理自我赋值

`自我赋值`发生在对象被赋值给自己时：

### 复制对象时勿忘其每一个成分

设计良好的面向对象的系统，会将对象的内部封闭起来，只留两个函数钥同对象拷贝，那命题带着适合名称的copy构造函数和copy assignment操作符，被称为copying函数

梁我编写一个copying函数时，请确保:

1.	复制所有local成员变量
2. 调用所有base classes 内的适当的copying函数

