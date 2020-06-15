#include <cstddef>
#include <iostream>

template<class P>
void functionTemplate(P p)
{
    int* a = p;
}

int main()
{
    int* a = 0;             // type int 
    int* b = NULL;          // type long int
    int* c = nullptr;       // type std::nullptr_t

    functionTemplate(0);
    functionTemplate(NULL);
    functionTemplate(nullptr);
}