# ex03


## thing to remember

### access specifier inside the class


#### public
you can access the members form anywhere

#### protected 
you can access the members inside your class and from the derived classes

#### private
you can access the members only inside your class

### protected keyword inside the class
the members that are inside the keyword protected in the base class, you can access them from the

## inheritance

means creats a new classes from an existing or base classes

the dirived class inherts all the capabilities of the base class, and it can add its own features without affecting the base class members

### modes of inheritance

#### public mode
if we derived a child class from a public parent class, then the public member of the parent calss becomes a public member for the child class and protected members of parent class becomes protected members of the child class

#### Protected
the public as well as protected member of the parent class becomes the protected members of the child class.

#### Private
if we derive a chld class from a private class base, then the public as well as protected members, becomes private for the derived class.

the private members in the base class you can't access them in the child class.

#### syntax of inheritance

```
    #include "name_of_base_class.hpp"

    class name_of_child_class : public nam_of_base_class
    {
        // you can add your members as you want
    };
```

- any edite you apply in your base class will automaticaly affected on the child class.
- if you don't set your own constructor in the child class the compiler will automaticaly call the default one that is in the base class to build the initialize the members.
- wheter the parameterized or default constructor of the derived class called, it calls the default constructor of the base class or the parent class.
- to call the base class parameterized constructor inside derived class's parameterized constructor, we must mention it explicitly while declaring derived class's parameterized constructor.

---
## why destractor in reverse oreder

the reason for this is that the derived class typically relies on resources or behabiors defined in the base class, if the base class destructor we called first, it could prematurely release or invalidate resources that the derived class still depends on.

### Summary 
when the object is created the constructor of the base class called first, and when the object is destroyed the desctructor of the derived class called first.


