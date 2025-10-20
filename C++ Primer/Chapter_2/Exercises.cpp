#include <iostream>

// Exercise: change the value of a pointer and test with output

int main()
{
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;

    std::cout << i << std::endl;
    return 0;
}

/*The difference between pointers and references is that pointesr are objects pointing to the memory address of another object whilst references are not objects and cannot be pointed to by a pointer.
References are aliases of other objects. */
