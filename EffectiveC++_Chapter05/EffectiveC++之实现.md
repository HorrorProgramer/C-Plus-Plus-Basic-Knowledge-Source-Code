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


