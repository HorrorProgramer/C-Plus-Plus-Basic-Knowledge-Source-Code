## C++的注释
C++的注释分为多行注释`/**/`和单行注释`//`

多行注释必须以`/*`开始，同时也必须以`*/`结尾，单行以`//`开始，直到这一千结束。

在注释的内部 ，以上的符号都是无意义的。

块状注释:
注释可以在执行的层面上忽略代码的执行，却不可以忽略代码的编译，要从逻辑上删除一段代码可以用条件编译：

```
#if 0

#endif
```

## C++的数据类型
### 基本的内置类型

类型 | 关键字
------------- | -------------
布尔  | bool
字符型  | char
整型  | int
浮点型  | float
双浮点型  | double
无类型  | void
宽字符型  | wchar_t

基本类型可以被一个或多个类型修饰符进行修饰:

* signed
* unsigned
* short
* long



| 类型  | 位 | 范围 |
|:-------------:|:---------------:|:-------------:|
| char     | 1个字节 |-128 到 127 或者 0 到 255|
| unsigned char      | 1个字节        | 0 到 255 |
| signed char | 1个字节        | -128 到 127 |
| int | 4个字节        | -2147483648 到 2147483647 |
| signed int | 4个字节        | -2147483648 到 2147483647 |
| unsigned int | 4 个字节        | 	0 到 4294967295 |
| short int | 2个字节        | -32768 到 32767 |
| long int | 8个字节        | 	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| unsigned short int | 1个字节        | 0 到 65,535 |
| unsigned long int | 8个字节        | 0 to 18,446,744,073,709,551,615 |
| signed short int | 1个字节        | -32768 到 32767 |
| signed long int | 8个字节        | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| float | 4个字节 | +/- 3.4e +/- 38 (~7 个数字) |
| double | 8个字节 | +/- 1.7e +/- 308 (~15 个数字) |
| long double | 8个字节 | +/- 1.7e +/- 308 (~15 个数字) |
| wchar_t | 2个或4个字节 | 	1 个宽字符 |

## typedef 声明
可以使用typedef为一个已有的类型取一个新的名字，使用方法如下所示:

```
typedef type newname;
```


## 枚举类型
枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量集合而成的。
创建枚举，需要使用关键字enum来定义，如下为enum的使用方法:

```
enum 枚举名 {
	标识符[=整型常数],
	标识符[=整型常数],
	...
	标识符[=整型常数]
} 枚举变量;
```

