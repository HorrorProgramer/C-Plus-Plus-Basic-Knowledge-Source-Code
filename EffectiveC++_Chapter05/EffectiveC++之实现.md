## 实现

### 尽可能延后变量定义式的出现时间

只要你定义了一个变量而其类型带有一个构造函数和析构函数，那么当程序的控制流到达这个变量定义式时，你便得承受构造成本，当这个变量离开其作用域时，你便得承受析构成本，即使这个变量最终并未被使用，仍需耗费这些成本，所以你尽可能避免这种情况。

```
std::string encryptPassword(const std::string& password) {
    using namespace std;
    string encrypted;
    
    if (password.length() < MininumPasswordLength) {
        throw logic_error("Password is too short!")
    }
    
    ...
    
    return encrypted;
}
```

上面这段代码是一个密码加密函数，如果密码太短，则回返回一个logic_error的错误；

对象encrypted在此函数中并未非完全未被使用，即使在抛出错误的时候，encrypted也需要构造成本和析构成本；

所以最好的方法是延迟encrypted的定义式，直到确定使用它；

如下例所示:

```
std::string encryptPassword(const std::string& password) {
    using namespace std;
    
    if (password.length() < MininumPasswordLength) {
        throw logic_error("Password is too short!")
    }
    
    string encrypted;
    
    ...
    
    return encrypted;
}
```

从之前的知识点可知，encrypted没有的初始化方法没有带有任何的参数，这就意味着其调用的是default构造函数；因此，上面的例子可能改为:


```
std::string encryptPassword(const std::string& password) {
    using namespace std;
    
    if (password.length() < MininumPasswordLength) {
        throw logic_error("Password is too short!")
    }
    
    string encrypted(password);
    
    ...
    
    return encrypted;
}
```

这就是我们要`尽可能延后变量定义式的出现时间`的意思了，我们不只应该延迟变量的定义，直到非得使用该变量的前一刻为止，甚至应该尝试，延后这份定义直到能够给它初值实参为止，如果这样，不仅能够避免构造和析构非必要对象，还可以避免毫无意义的default的构造行为，进一步说，以`具明显意义之初值`将变量初始化，还可以附带说明变量的目的。


* 如果有循环中需要定义变量怎么办？ 是放在循环内好还是定义在循环外定义好?

如下例所示:

```
1. Widget w;
   for (int i = 0; i < 10; i++) {
       w = i;
   }
   
2. for (int i = 0; i < 10; i++) {
      Widget w = i;
   }
```

1. 需要一个构造函数、一个析构函数 和 n个函数
2. 需要n个构造函数和n个析构函数

如果一个class的赋值成本低于一组构造和析构成本，做法A大体而言比较高效。


### 尽量少做转型动作

我们先回顾一下转型语法：

C语言的转型动作看起来是这样的：

(T)expression;

T(expression);

两种形式差不多，纯粹只是小括号的摆放位置不同而已

C++额外提供了四种转型方式:

const_cast<T>(expression);
dynamic_cast<T>(expression);
reinterpret_cast<T>(expression);
static_cast<T>(expression);

* const_cast 通常被用来将对象的常量性转除，它也是唯一有能力的C++ - style 转型操作符
* dynamic_cast 主要用来执行`安全向下转型`，也就是用来决定某对象是否归属继承体系中的某个类型，它是唯一的无法由旧式语法执行的动作，也是唯一可能耗费重大运行成本的转型动作
* reinterpret_cast 意图执行低级转型，实际动作可能取决于编译器，这也就表示它不可移植。例如将一个pointer to int转型为一个int， 这一类转型在低级代码以外很少见
* static_cast 用来强制隐式转换

旧式转型仍然合法，但是新式转型较受欢迎:

1. 它们很容易在代码中辨识出来
2. 各转型动作的目标愈窄化，编译器愈可能诊断出错误的运用


任何一个类型转换往往真的令编译器编译出执行期间执行的码。

### 避免返回handles指向对象内部成分

如源代码例2所示：
Rectangle成员方法upperLeft和lowerRight

这样的设计是可以编译的，但却是错误的。实际上它是自我矛盾的。

* 一方面upperleft和lowerright被声明为const成员函数，因为它们的目的只是为了提供客户一个得知Rectangle的相关坐标点的方法，而不是让客户修改Rectangle
* 另一方面两个函数却返回reference指向private内部数据，调用者于是可通过reference更改内部数据

```
Point coord1(0, 0);
Point coord2(100, 100);

const Rectangle rec(coord1, coord2);

rec.upperLeft().setX(50);
```

upperLeft的调用者能够使用被返回的reference, 来改变成员，但rect其实应该是不可变的。

从上面那个例子中，我们可以得到两个教训:

1. 成员变量的封装性最多只等于“返回其reference”的函数的访问级别。
2. 如果const成员函数传出一个reference，后者所指数据与对象自身有关联，而它又被存储于对象之外，那么这个函数的调用者可以修改那笔数据，这正是bitwise constness 的一个附带结果。

References、指针和迭代器统统都是所谓的handles，而返回一个“代表对象内部数据”的handle，随之而来的便是“降低对象封装性”的风险。

通常我们认为，对象的“内部”是指它的成员变量，但其实不被公开使用的成员函数也是对象“内部”的一部分，因此也应该留意不要返回它们的handles。
这意味着你绝对不该令成员函数返回一个指针指向“访问级别较低”的成员函数；

### 为异常安全(Exception Safety)而努力是值得的

从“异常安全”的角度来看，示例代码的成员函数很糟糕，“异常安全”有两个条件，而这个函数一个条件也没有满足其中任何一个；

当异常被抛出时，带有异常安全性的函数会：

1. **不泄漏任何资源** 
2. **不允许数据破坏**


异常安全函数提供以下三个保证之一：

* **基本承诺** 
如果异常被抛出，程序内的任何事物仍然保持在有效状态下，没有任何的对象或数据结构因此而败坏，所有对象都处于一种内部前后一致的状态，然而程序的现实状态恐怕不可预料。

* **强烈保证**
如果异常被抛出，程序状态不改变，调用这样的函数需要有这样的认知，如果函数成功，就是完全成功，如果函数失败，程序会回复到"调用函数前"的状态。

* **来抛掷(nonthrow)保证** 承诺绝不抛出异常，因为它们总是能够完成它们碑承诺的功能。作用于内置类型身上的所有操作都的提供nonthrow保证，这是异常安全中一个必不可少的关键基础材料。

异常安全码必须提供上述三种保证之一，如果它不这样做，它就不具备异常安全性；因此我们的抉择是，该为我们所写的每一个函数提供哪一个保证呢？

除非面对不具备异常安全性的传统代码，否则你应该只在一种情况下才不提供任何异常安全保证；

### 透彻了解inlining的里里外外


### 将文件问的编译依存关系降至最低

* 如果使用object references 或 object pointers 可以完成任务，就不要使用objects,你可以只靠一个类型声明式就定义出指向该类型的reference和pointers，如果定义某类型的objects,就需要用到该类型的定义式；

* 如果能够，尽量以class声明式替换class定义式；注意，当你声明一个函数而它用到某个class时，你并不需要该class的定义，纵使函数以by value方式传递该类型的参数亦然：

* 为声明式和定义式提供不同的头文件；

