## C++命名空间

为了区分相同名字的函数，引入了命名空间这个概念，它可作为附加信息来区分不同库中相同名称的函数、类、变量等

使用命名空间即定义了上下文，本质上命名空间就是定义了一个范围

### 定义命名空间

```
namespace namespace_name {

}
```

为了调用带有命名空间的函数或变量，需要在前面加上命名空间的名称

`name::code;`

### using指令

可以使用using namespace 指令，这样在使用命名空间时就可以不用在前面加上命名空间的名称了，这个指令会告诉编译器后续的代码将使用指定的命名空间中的名称

using 指令也可以用来指定命名空间中的特定项目

`using std::cout;`

using 指令引入的名称遵循正常的范围规则，名称从使用using命令开始是可见的，直到该范围结束，此时，在范围以外定义的同名实体是隐藏的

### 不连续的命名空间

命名空间可以定义在几个不同的部分中，因此命名空间是由几个单独定义的部分组成的。一个命名空间的各个组成部分可以分散在多个文件中。

所以，如果命名空间中的某个组成部分需要请求定义在另一个文件中的名称，则仍然需要声明该名称

### 嵌套的命名空间

命名空间可以嵌套，您可以在一个命名空间中定义另一个命名空间



## C++模板

模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。

模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。

每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 `vector <int>` 或 `vector <string>`

### 函数模板

```
template <class type> ret-type func-name(parameter list) {
	//function body
}
```

type是函数所使用的数据类型的占位符， 这个名称可以在函数定义中使用

### 类模板

泛型类声明:

```
template <class type> class class-name {

};
```

type 是占位符类型名称，可以在类被实例化的时候进行指定。您可以使用一个逗号分隔的列表来定义多个泛型数据类型

### typename和class的区别
**在 C++ Template 中很多地方都用到了 typename 与 class 这两个关键字，而且好像可以替换，是不是这两个关键字完全一样呢?
相信学习 C++ 的人对 class 这个关键字都非常明白，class 用于定义类，在模板引入 c++ 后，最初定义模板的方法为：
**

**`template<class T>......`**

**这里 class 关键字表明T是一个类型，后来为了避免 class 在这两个地方的使用可能给人带来混淆，所以引入了 typename 这个关键字，它的作用同
class 一样表明后面的符号为一个类型，这样在定义模板的时候就可以使用下面的方式了：**

**```
template <typename 
T>....
```**


**在模板定义语法中关键字 class 与 typename 的作用完全一样。
typename 难道仅仅在模板定义中起作用吗？其实不是这样，typename 另外一个作用为：使用嵌套依赖类型(nested depended name)**

```
class MyArray 
{ 
	public：
	typedef int LengthType;
.....
}

template<class T>
void MyMethod( T myarr ) 
{ 
	typedef typename T::LengthType LengthType; 
	LengthType length = myarr.GetLength; 
}
```

**这个时候 typename 的作用就是告诉 c++ 编译器，typename 后面的字符串为一个类型名称，而不是成员函数或者成员变量，这个时候如果前面没有
typename，编译器没有任何办法知道 T::LengthType 是一个类型还是一个成员名称(静态数据成员或者静态函数)，所以编译不能够通过。**



## C++信号处理

信号是由操作系统传给进程的中断，会提早终止一个程序。在 UNIX、LINUX、Mac OS X 或 Windows 系统上，可以通过按 Ctrl+C 产生中断。

有些信号不能被程序捕获，但是下表所列信号可以在程序中捕获，并可以基于信号采取适当的动作。这些信号是定义在 C++ 头文件 `<csignal> `中

| 信号 | 描述 |
|:---:|:---:|
| SIGABRT | 程序的异常终止，如调用 abort |
| SIGFPE	| 错误的算术运算，比如除以零或导致溢出的操作。|
| SIGILL | 检测非法指令。 |
| SIGINT | 接收到交互注意信号。 |
| SIGSEGV	| 非法访问内存。 |
| SIGTERM | 发送到程序的终止请求。 |

### signal()函数

C++ 信号处理库提供了 signal 函数，用来捕获突发事件。以下是 signal() 函数的语法：

`void (*signal (int sig, void (*func)(int)))(int); `

这个函数接收两个参数：第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。

### raise()函数

您可以使用函数 raise() 生成信号，该函数带有一个整数信号编号作为参数，语法如下：

`int raise (signal sig);`

在这里，sig 是要发送的信号的编号，这些信号包括：SIGINT、SIGABRT、SIGFPE、SIGILL、SIGSEGV、SIGTERM、SIGHUP

