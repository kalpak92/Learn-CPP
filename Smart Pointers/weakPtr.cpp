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