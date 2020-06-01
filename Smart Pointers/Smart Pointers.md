# Smart Pointers

Smart pointers are one of the most important additions to C++ because they enable us to implement explicit memory management in C++. 

Beyond the **deprecated** `std::auto_ptr`, C++ offers three different smart pointers. They are defined in the header `<memory>`.

First, there is `std::unique_ptr`, which models the concept of **exclusive ownership**. Second, there is `std::shared_ptr`, which models the concept of shared ownership. Lastly, there is the `std::weak_ptr`. 

`std::weak_ptr` is not smart, as it has only a thin interface, and it serves only to break cycles of `std::shared_ptr`. It models the concept of temporary ownership.

Smart pointers manage their resources according to the RAII idiom. Therefore, the resource is automatically released if the smart pointer goes out of scope.

> ℹ️ **Resource Acquisition Is Initialization** 
**R**esource **A**cquisition **I**s **I**nitialization, also known as RAII, is a popular technique in C++. Resource acquisition and release are bound to the lifetime of an object. This means that the memory for the smart pointer is allocated in the constructor and deallocated in the destructor. 
We can use this technique in C++ because the destructor is called when the object goes out of scope.

# Unique Pointers

An `std::unique_ptr` automatically and exclusively manages the lifetime of its resource according to the RAII idiom. `std::unique_ptr` should be our first choice since it functions without memory or performance overhead.

`std::unique_ptr` exclusively controls its resource. It automatically releases the resource if it goes out of scope. No copy semantics are required, and it can be used in containers and algorithms of the Standard Template Library. `std::unique_ptr` is as cheap and fast as a raw pointer when no special delete function is used.

## Characteristics

Before we go into the usage of `std::unique_ptr`, here are its characteristics in a few bullet points.

The `std::unique_ptr`:

- can be instantiated with and without a resource.
- manages the life cycle of a single object or an array of objects.
- transparently offers the interface of the underlying resource.
- can be parametrized with its own deleter function.
- can be moved (move semantics).
- can be created with the helper function `std::make_unique`.

> Classical C++98 has a smart pointer `std::auto_ptr`, which exclusively addresses the lifetime of a resource.
`std::auto_ptr` has a conceptual issue. If we implicitly or explicitly copy an `std::auto_ptr`, the resource is moved. Therefore, rather than utilizing copy semantic, we have a hidden move semantic, leading to undefined behavior. So `std::auto_ptr` is deprecated in C++11 and removed in C++17. 
Instead, use `std::unique_ptr`. We can neither implicitly nor explicitly copy an `std::unique_ptr`; only moving it is possible.

```cpp
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> up1(new int(2011));
    // std::unique_ptr<int> up2 = up1;             // ERROR
    std::unique_ptr<int> up2 = std::move(up1);     // Ownership handover

    return 0;
}
```

## Methods

These are the methods of `std::unique_ptr`:

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_4.30.19_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_4.30.19_PM.png)

### **Special Deleters**

`std::unique_ptr` can be parametrized with special deleters:

`std::unique_ptr<int, MyIntDeleter> up(new int(2011), myIntDeleter())`.

`std::unique_ptr` uses, by default, the deleter of the resource.

## **`std::make_unique`**

The helper function `std::make_unique` was unlike its sibling `std::make_shared`, and was forgotten" in the C++11 standard. Therefore, `std::make_unique` was added with the C++14 standard. `std::make_unique` enables us to create an `std::unique_ptr` in a single step:

```cpp
std::unique_ptr<int> uniqPtr1= std::make_unique<int>(2011);
auto uniqPtr2= std::make_unique<int>(2014);
```

Using `std::make_unique` in combination with automatic type deduction means typing is reduced to its bare minimum.

Always use `std::make_unique`.

If we use

```cpp
func(std::make_unique<int>(2014), functionMayThrow());
func(std::unique_ptr<int>(new int(2011)), functionMayThrow());
```

and `functionMayThrow` throws, we have a memory leak with `new int(2011)` for this possible sequence of calls:

```cpp
new int(2011)
functionMayThrow()
std::unique_ptr<int>(...)
```

Rarely, when we create `std::unique_ptr` in an expression and the compiler optimizes this expression, a memory leak may occur with an `std::unique_ptr` call. 

Using `std::make_unique` guarantees that no memory leak will occur.

Under the hood, `std::unique_ptr` uses the **perfect forwarding pattern**. The same holds for the other factory methods such as `std::make_shared`, `std::make_tuple`, `std::make_pair`, or an `std::thread` constructor.

```cpp
#include <iostream>
#include <memory>
#include <utility>

struct MyInt{

    // Constructor
    MyInt(int i):i_(i){}

    // Destructor
    ~MyInt(){
        std::cout << "Good bye from " << i_ << std::endl;
    }

    int i_;

};

int main()
{

    std::cout << std::endl;

    std::unique_ptr<MyInt> uniquePtr1{ new MyInt(1998) };

    std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;

    std::unique_ptr<MyInt> uniquePtr2;
    uniquePtr2= std::move(uniquePtr1);

    std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;
    std::cout << "uniquePtr2.get(): " << uniquePtr2.get() << std::endl;

    std::cout << std::endl;

    // Local Pointer gets created and deallocated once the block of execution gets 
    {
        std::unique_ptr<MyInt> localPtr{ new MyInt(2003) };
    }

    std::cout << std::endl;

    // we assign a new resource to the uniquePtr2. 
    // Therefore, the destructor of MyInt(1998) will be executed. 
    // After the resource in line 43 is released, 
    // we can explicitly invoke the destructor.
    uniquePtr2.reset(new MyInt(2011));
    MyInt* myInt= uniquePtr2.release();
    delete myInt;

    std::cout << std::endl;

    std::unique_ptr<MyInt> uniquePtr3{ new MyInt(2017) };
    std::unique_ptr<MyInt> uniquePtr4{ new MyInt(2022) };

    std::cout << "uniquePtr3.get(): " << uniquePtr3.get() << std::endl;
    std::cout << "uniquePtr4.get(): " << uniquePtr4.get() << std::endl;

    // Swap the resources
    std::swap(uniquePtr3, uniquePtr4);

    std::cout << "uniquePtr3.get(): " << uniquePtr3.get() << std::endl;
    std::cout << "uniquePtr4.get(): " << uniquePtr4.get() << std::endl;

    std::cout << std::endl;

    // Destructor gets called on uniquePtr3 and uniquePtr4

}
```

```
uniquePtr1.get(): 0x7fe4d1c05860
uniquePtr1.get(): 0x0
uniquePtr2.get(): 0x7fe4d1c05860

Good bye from 2003

Good bye from 1998
Good bye from 2011

uniquePtr3.get(): 0x7fe4d1c05870
uniquePtr4.get(): 0x7fe4d1c05860
uniquePtr3.get(): 0x7fe4d1c05860
uniquePtr4.get(): 0x7fe4d1c05870

Good bye from 2017
Good bye from 2022
```

`std::unique_ptr` has a specialization for arrays. The access is **transparent**, meaning that if the `std::unique_ptr` manages the lifetime of an object, the operators for the object access are **overloaded** (`operator*` and `operator->`). 

If `std::unique_ptr` manages the lifetime of an array, the index operator `[]` is overloaded. The invocations of the operators are, therefore, transparently forwarded to the underlying resource.

```cpp
#include <iomanip>
#include <iostream>
#include <memory>

class MyStruct
{
    public:
        MyStruct()
        {
            std::cout << std::setw(15) << std::left << (void*) this << " Hello "  << std::endl;
        }
        
        ~MyStruct()
        {
            std::cout << std::setw(15) << std::left << (void*)this << " Good Bye " << std::endl;
        }
};

int main()
{

    std::cout << std::endl;

    std::unique_ptr<int> uniqInt(new int(2011));
    std::cout << "*uniqInt: " << *uniqInt << std::endl;

    std::cout << std::endl;

    // Local Block. Constructor and Destructor both gets called.
    {
        std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[5]};
    }

    std::cout << std::endl;

    {
        std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
        MyStruct myStruct;
        myUniqueArray[0]=myStruct;
    }

    std::cout << std::endl;

    {
        std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
        MyStruct myStruct;
        myStruct= myUniqueArray[0];
    }

    std::cout << std::endl;

}
```

```
*uniqInt: 2011

0x7fc032c05878  Hello 
0x7fc032c05879  Hello 
0x7fc032c0587a  Hello 
0x7fc032c0587b  Hello 
0x7fc032c0587c  Hello 
0x7fc032c0587c  Good Bye 
0x7fc032c0587b  Good Bye 
0x7fc032c0587a  Good Bye 
0x7fc032c05879  Good Bye 
0x7fc032c05878  Good Bye 

0x7fc032c05878  Hello 
0x7ffee82bc718  Hello 
0x7ffee82bc718  Good Bye 
0x7fc032c05878  Good Bye 

0x7fc032c05878  Hello 
0x7ffee82bc708  Hello 
0x7ffee82bc708  Good Bye 
0x7fc032c05878  Good Bye
```

# Shared Pointers

`std::shared_ptr` shares ownership of the resource. 

They have two handles: one for the resource, and one for the reference counter. 

By copying an `std::shared_ptr`, the reference count is increased by one. It is decreased by one if the `std::shared_ptr` goes out of scope. If the reference counter becomes the value 0, the C++ runtime automatically releases the resource, since there is no longer an `std::shared_ptr` referencing the resource. The release of the resource occurs exactly when the last `std::shared_ptr` goes out of scope. 

The C++ runtime guarantees that the call of the reference counter is an **atomic** operation. Due to this management, std::shared_ptr consumes more time and memory than a raw pointer or std::unique_ptr.

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_6.12.23_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_6.12.23_PM.png)

Due to `shared1`, `shared2` is initialized. In the end, the reference count is 2 and both smart pointers have the same resource.

## Methods

In the following table, we will see the methods of `std::shared_ptr`.

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_6.13.46_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_6.13.46_PM.png)

## `std::make_shared`

The helper function `std::make_shared` creates the resource and returns it in an `std::shared_ptr`. 

Use `std::make_shared` rather than directly creating an `std::shared_ptr` because `std::make_shared` is much faster. Additionally, such as in the case of `std::make_unique`, `std::make_shared` guarantees no memory leaks.

## `std::shared_ptr` from `this`

> This unique technique, in which a class derives from a class template having itself as a parameter, is called **CRTP** and stands for **C**uriously **R**ecurring **T**emplate **P**attern.

Using the class `std::enable_shared_from_this`, we can create objects that return an `std::shared_ptr` to themselves. 

To do so, we must publicly derive the class from `std::enable_shared_from_this`. So the class `ShareMe` support the method `shared_from_this`, and return `std::shared_ptr`:

```cpp
#include <iostream>
#include <memory>

class ShareMe: public std::enable_shared_from_this<ShareMe>
{
    public:
        std::shared_ptr<ShareMe> getShared()
        {
            return shared_from_this();
        }
};

/**
 * The smart pointer shareMe (line 27) is copied by shareMe1 (line 28) and shareMe2 (line 31), and all of them
 * reference the very same resource.
 * increment and decrement the reference counter.
 * 
 * The call shareMe->getShared() in line 18 creates a new smart pointer. 
 * getShared() (line 9) internally uses the function shared_from_this.
 */

int main()
{

    std::cout << std::endl;

    std::shared_ptr<ShareMe> shareMe(new ShareMe);
    std::shared_ptr<ShareMe> shareMe1= shareMe->getShared();
    
    {
        auto shareMe2(shareMe1);
        std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;
    } 
    
    std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;

    shareMe1.reset();
  
    std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;

    std::cout << std::endl;

}
```

```
Output

shareMe.use_count(): 3
shareMe.use_count(): 2
shareMe.use_count(): 1
```

The call `shareMe->getShared()` in line 28 creates a new smart pointer. `getShared()` (line 9) internally uses the function `shared_from_this`.

### Example 1

```cpp
#include <iostream>
#include <memory>

using std::shared_ptr;

struct MyInt
{
    MyInt(int v):val(v)
    {
        std::cout << "  Hello: " << val << std::endl;
    }

    ~MyInt()
    {
        std::cout << "  Good Bye: " << val << std::endl;
    }
  
    int val;
};

int main()
{

    std::cout << std::endl;

    shared_ptr<MyInt> sharPtr(new MyInt(1998));
    std::cout << "    My value: " << sharPtr->val << std::endl;
    std::cout << "sharedPtr.use_count(): " << sharPtr.use_count() << std::endl;

    {
        shared_ptr<MyInt> locSharPtr(sharPtr);
        std::cout << "locSharPtr.use_count(): " << locSharPtr.use_count() << std::endl;
    }
    
    std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

    shared_ptr<MyInt> globSharPtr= sharPtr;
    std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;
    globSharPtr.reset();
    std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

    sharPtr= shared_ptr<MyInt>(new MyInt(2011));

    std::cout << std::endl;
  
}
```

- **Explanation**
    - In line 22, we create `MyInt(1998)`, which is the resource that the smart pointer should address. By using `sharPtr->val`, we have direct access to the resource (line 23).
    - The output of the program shows the number of references counted. It starts in line 24 with 1. It then has a local copy `shartPtr` in line 28 and goes to 2. The program then returns to 1 after the block (lines 27-30).
    - The copy assignment call in line 33 modifies the reference counter. The expression `sharPtr= shared_ptr<MyInt>(new MyInt(2011)` in line 38 is more interesting.
    - First, the resource `MyInt(2011)` is created in line 38 and assigned to `sharPtr`. Consequently, the destructor of `sharPtr` is invoked. `sharedPtr` was the exclusive owner of the resource new `MyInt(1998)` (line 22).
    - The last new resource `MyInt(2011)` will be destroyed at the end of main.

### Example 2

```cpp
// sharedPtrDeleter.cpp

#include <iostream>
#include <memory>
#include <random>
#include <typeinfo>

template <typename T>
class Deleter{
public:
  void operator()(T *ptr){
    ++Deleter::count;
    delete ptr;
  }
  void getInfo(){
    std::string typeId{typeid(T).name()};
    size_t sz= Deleter::count * sizeof(T);
    std::cout << "Deleted " << Deleter::count << " objects of type: " << typeId << std::endl;
    std::cout <<"Freed size in bytes: "  << sz << "." <<  std::endl;
    std::cout << std::endl;
  }
private:
  static int count;
};

template <typename T>
int Deleter<T>::count=0;

typedef Deleter<int> IntDeleter;
typedef Deleter<double> DoubleDeleter;

void createRandomNumbers(){

  std::random_device seed;

  std::mt19937 engine(seed());

  std::uniform_int_distribution<int> thousand(1,1000);
  int ranNumber= thousand(engine);
  for ( int i=0 ; i <= ranNumber; ++i) std::shared_ptr<int>(new int(i),IntDeleter());

}

int main(){

  std::cout << std::endl;

  {
    std::shared_ptr<int> sharedPtr1( new int,IntDeleter() );
    std::shared_ptr<int> sharedPtr2( new int,IntDeleter() );
    auto intDeleter= std::get_deleter<IntDeleter>(sharedPtr1);
    intDeleter->getInfo();
    sharedPtr2.reset();
    intDeleter->getInfo();

  }
  createRandomNumbers();
  IntDeleter().getInfo();

  {
    std::unique_ptr<double,DoubleDeleter > uniquePtr( new double, DoubleDeleter() );
    std::unique_ptr<double,DoubleDeleter > uniquePtr1( new double, DoubleDeleter() );
    std::shared_ptr<double> sharedPtr( new double, DoubleDeleter() );

    std::shared_ptr<double> sharedPtr4(std::move(uniquePtr));
    std::shared_ptr<double> sharedPtr5= std::move(uniquePtr1);
    DoubleDeleter().getInfo();
  }

  DoubleDeleter().getInfo();

}
```

```
Deleted 0 objects of type: i
Freed size in bytes: 0.

Deleted 1 objects of type: i
Freed size in bytes: 4.

Deleted 842 objects of type: i
Freed size in bytes: 3368.

Deleted 0 objects of type: d
Freed size in bytes: 0.

Deleted 3 objects of type: d
Freed size in bytes: 24.
```

- **Explanation**
    - In lines 8 - 24, `Deleter` is the special deleter. The deleter is parametrized by the type `T`. It counts, alongside the static variable `count` (line 23), how often the call operator (lines 11 - 14) was used.
    - `Deleter` returns all the information with `getInfo` (lines 15-21).
    - The function `createRandomNumbers` (lines 32-42) creates between 1 to 1000 `std::shared_ptr` (line 40) parametrized by the special deleter `intDeleter()`.
    - The first usage of `intDeleter->getInfo()` shows that no resource has been released. This changes with the call `sharedPtr2.reset()` in line 53.
    - An `int` variable with 4 bytes has been released. The call `createRandomNumbers()`, in line 57, creates 74 `std::shared_ptr<int>`.
    - Of course, we can use the deleter for an `std::unique_ptr` (line 60 - 68).
    - The memory for the double objects will be released after the end of the block, in line 68.

The classic issue of smart pointers using a reference count is to have **cyclic references**. 
Therefore, `std::weak_ptr` solves our problems. 

# Weak Pointers

To be honest, `std::weak_ptr` is not a classic smart pointer, since it supports no transparent access to the resource; it only borrows the resource from an `std::shared_ptr`.

## Methods

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.12.13_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.12.13_PM.png)

There is one main reason for the existence and use of `std::weak_ptr`. It breaks the cycle of `std::shared_ptr`.

```cpp
#include <iostream>
#include <memory>

int main()
{

    std::cout << std::boolalpha << std::endl;

    auto sharedPtr=std::make_shared<int>(2011);
    // create a weak pointer that borrows the resource from the shared pointer.
    std::weak_ptr<int> weakPtr(sharedPtr);        

    // The output of the program shows that the reference counter is 1, 
    // meaning that std::weak does not increment the counter.
    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;

    // The call weakPtr.expired() checks if the resource was already deleted. 
    // That is equivalent to the expression weakPtr.use_count() == 0.
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;   // gives false.

    // If the std::weak_ptr shared a resource, 
    // we could use weakPtr.lock() to create an std::shared_ptr out of it.
    if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) 
    {
        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
        // The reference counter will now be increased to 2 .
        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
    }
    else
    {
        std::cout << "Don't get the resource!" << std::endl;
    }

    // After resetting the weakPtr, the call weakPtr.lock() fails.
    weakPtr.reset();

    if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) 
    {
        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
    }
    else
    {
        std::cout << "Don't get the resource!" << std::endl;
    }

    std::cout << std::endl;

}
```

```
weakPtr.use_count(): 1
sharedPtr.use_count(): 1
weakPtr.expired(): false
*sharedPtr: 2011
sharedPtr1.use_count(): 2
Don't get the resource!
```

# Cyclic References

We get cyclic references of `std::shared_ptr` if they refer to each other.

## **The issue**

If we have a cyclic reference of `std::shared_ptr`, the reference counter will never become 0. 

We can break this cycle if by embedding an `std::weak_ptr` in the cycle. `std::weak_ptr` does not modify the reference counter.

> Theoretically, we can use a raw pointer to break the cycle of `std::shared_ptr`'s, but a raw pointer has two disadvantages. 
First, they don’t have a well-defined interface. 
Second, they don’t support an interface that can create an `std::shared_ptr` out of it.

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.41.05_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.41.05_PM.png)

There are two cycles in the graphic below: 

- first, between the mother and her daughter;
- second, between the mother and her son.

The subtle difference is that the mother references her daughter with an `std::weak_ptr`. Therefore, the `std::shared_ptr` cycle is broken.

![Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.45.01_PM.png](Smart%20Pointers%20c6499680f2e94adeb0e0b3df6646d862/Screen_Shot_2020-05-31_at_11.45.01_PM.png)

```cpp
#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother
{
    ~Mother()
    {
        std::cout << "Mother gone" << std::endl;
    }

    void setSon(const std::shared_ptr<Son> s )
    {
        mySon=s;
    }

    void setDaughter(const std::shared_ptr<Daughter> d )
    {
        myDaughter=d;
    }

    std::shared_ptr<const Son> mySon;
    std::weak_ptr<const Daughter> myDaughter;
};

struct Son
{
    Son(std::shared_ptr<Mother> m):myMother(m){}

    ~Son()
    {
        std::cout << "Son gone" << std::endl;
    }

    std::shared_ptr<const Mother> myMother;
};

struct Daughter
{
    Daughter(std::shared_ptr<Mother> m):myMother(m){}

    ~Daughter()
    {
        std::cout << "Daughter gone" << std::endl;
    }

    std::shared_ptr<const Mother> myMother;
};

/**
 * Due to the artificial scope, the lifetime of the mother, the son, and the daughter are limited. 
 * In other words, mother, son, and daughter go out of scope, 
 * therefore the destructor of the class Mother, Son, Daughter should automatically be invoked.
 * 
 * We state should, because only the destructor of the class Daughter is called.
 * 
 * We have a cyclic reference of std::shared_ptr between mother and son. 
 * Therefore, the reference counter is always greater than 0, 
 * and the destructor will not automatically be invoked.
 * 
 * That observation does not hold true for mother and daughter. 
 * If the daughter goes out of scope, the reference counter of the std::shared_ptr myMother 
 * becomes 0 and the resource will automatically be deleted.
 */

int main()
{
    std::cout << std::endl;
    {
        std::shared_ptr<Mother> mother = std::shared_ptr<Mother>( new Mother);
        std::shared_ptr<Son> son = std::shared_ptr<Son>( new Son(mother) );
        std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>( new Daughter(mother) );

        mother->setSon(son);

        mother->setDaughter(daughter);
    }
    std::cout << std::endl;
}
```