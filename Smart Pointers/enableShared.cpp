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