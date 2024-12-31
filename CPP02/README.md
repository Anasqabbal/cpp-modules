# CPP Module 02
## the goal of the Module


## what is Orthodox Canonical Class Form
 OCCF has four different methods

 - Defaul Constructor
 - Copy Constructor
 - Destructor
 - Copy assignment operator

### what is operator overloading
giving to the operators in our language that support OOP. the ability to does operations with our user-defined data types.
to overload the operator in c++ we use the keyword `operator`

#### overload comparison operators
[Comparison Operators](https://en.cppreference.com/w/cpp/language/operator_comparison)\
[Arithmitic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic)

### Ad-hoc Polymorphism
Ad-hoc Polymorphism, also called as Overloading Ad-hoc Polymorphism allows functions having same name to act differently for different types. For example: The + operator adds two integers and concatenates two strings.

### static in c++
##### at class level
in class level a member that is marked as `static` is shared between all instances of a given class.

## initializer list
in c++ initializer list is a special syntax used to initilaize member varaibles of a class during object construction

#### when we use the initializer list 
- for const or reference member variables. these types cannot modified after they are declared. Assigning them inside the constructor body would be an attempt to modify them after initializdtion, which is not correct.
- to improve efficiency
- for classes with multiple inheritance
#### syntax for initializer list

```
class MyClass{
private:
    int member1;
    const int member2;
public :
    MyClass(int a, const int b)
    : member1(a) memeber2(b) {}
}
 ```
## operator overloaded
