## 习惯C++

### 将C++视为一个语言联邦:

	* **C :** C++仍是以C语言为基础的，区块、语句、预处器、内置数据类型、数组指针等统统来自C，许多时候C++对问题的解法其实不过就是较高级的C的解法，但当你以C成分工作时，高级编程守则映照出C的局限：没有模板、没有重载、没有异常等
	* **object-Oriented-C++ :** 这部分也是`C with classes`所诉求的：类、封装、继承、多态、virtual函数等，这一部分是面对对象设计之古典守则在C++上最直接的实现
	* **Template C++ :** 这是C++的泛型编程部分，也是多数程序员经验最少的部分。Tmeplate相关的考虑和设计已经在C++中普遍的使用，
	* **STL :** STL是个Template程序库，它对容器、迭代器、算法以及函数对象的规约有极佳的紧密配合与协调，然而templates及程序库也可以其他方法建置出来；

	
### 尽量以const、enum、inline 替换#define使用

	__#define__的问题：
		`#define AESPACT_RATIO 1.653;`
	* `#define` 不被视为语言的一部分
	* 预处理命令可能不会被记入`符号表(symbol table)`内，当运行这个常量却收到一个错误信息时，可能不能清晰的定位当前错误的位置；
	* 误用`#define`来实现宏
	
	
	__解决办法__
	
	可以使用一个常量代替上面的宏；
	
	`const double AespactRatio = 1.653;`
	
	作为常量，AespactRatio肯定会被编译器看到并加入`符号表(symbol table)`中，另外使用常量可能比#define使用的量更小，因为预处理器程序所有的相应的AESPACT_RATIO都替换为1.653；
	
	使用const常量时，有二种情况需要注意:
	
	2.1.1 定义常量指针
		
	由于常量定义式通常被放在头文件中，因此有必要将指针声明为const
	
	2.1.2 class专属常量
	
	为了将常量的作用域限制在class内，必须要将这个常量成为class的成员；而为确保此常量至多只有一份实体，必须要让这个常量成为一个static成员；
	
	```
	class GamePlayer {
		private:
			static const int NumTurns = 5;
			int scores[NumTurns];
			...
	}
	```
	
	这段代码里面有一些值得注意的地方：
	NumTurns是声明式而不是定义式；
	
	在通常情况下，C++要求对所使用的任何东西都需要一个定义式，但如果它是个class专属常量又是static且是整数类型，则需要特殊处理；
	
	只要不提取它们的地址，就可以使用它们而不用提供定义式；
	
	当需要使用常量的地址时，则需要提供该常量的定义式了；
	
	`const int GamePlayer::NumTurns;`
	
	**#define** 是无法定义class常量的；
	
	当编译器不支持上述语法时，可以在定义式中实现：
	
	```
	class GamePlayer {
		private:
			static const int NumTurns;
			int scores[NumTurns];
			...
	}
	
	GamePlayer::NumTurns = 5;
	```
	
	或者使用所谓的**the enum hack**的补偿方法：
	
	> 一个属于枚举类型的数值可权充ints使用的
	
	```
	class GamePlayer {
		private:
			enum { int NumTurns = 5 };
			int scores[NumTurns];
			...
	}
	```
	
	使用**the enum hack**的几个理由:
	
	1.	enum hack 的行为在某些方面比较像#define 而不是const
	2. 纯粹是为了实用主义

	
### 尽可能使用const

使用const是一件奇妙的事是，它允许你指定一个语义约束，而编译器会强制实施这些约束，它允许你告诉编译器和其他程序员某值应该保持不变；

const 也可以被用在指针上面： 在`*`号左面，表示被指物为常量， 在`*`号右面表明指针自己是常量

const最常用的方法是面对函数声明时的应用，可以和函数自身、返回值、参数相结合

#### 函数返回值常量

令函数返回一个常量值，往往可以降低客户错误而造成的意外，而又不至于放弃安全性和高效性；

#### const成员函数

将const实施于成员函数的目的，是为了确认该成员函数可作用于const对象上，这一类成员函数之所以的重要，基于两个理由:

1.	它们使class接口比较容易被理解，这是因为可以很容易的知道哪个函数可以改动对象内容哪些不行
2. 它们使`操作const对象`成为可能


biswise constness 和 logical constness 的区别

### 确定对象被使用前已经初始化

最好的处理办法是： 永远在使用对象之前先将它初始化，对于无任何成员的内置类型，你必须手工完成这件事；至于内置类型以外其他的任何类型，初始化的责任落在了构造函数上面；确保每一个构造函数都将对象的的每一个成员初始化；

需要注意的是： 区分赋值和初始化的区别

```
class Box {
	private:
		int width;
		int height;
		
	public:
		Box();
		Box(int w, int h);
};

Box::Box(int w, int h) {
	width = w; // 这些都是赋值而不是初始化
	height = h; // 这些都是赋值而不是初始化
}

```

这是因为C++规定，对象成员的初始化发生在进入构造函数本体之前，因此width和height都不是初始化而是被赋值了， 初始化发生时间更早，发生在**default**构造函数被自动调用之时；

一种更佳的方法是： member intialization list (成员初值列)

```
Box::Box(int w, int h): width(w), height(h) {}
```

这个构造函数和上个的最终结果相同，但是效率更高，

甚至也可以使用**default** 无参构造函数：

```
Box::Box(): width(), height() {}
```

