#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {}

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
        {
            std::cout << "Copy Constructor." << std::endl;
        }
};

int main()
{
    std::vector<Vertex> vertices;

    vertices.push_back(Vertex(1, 2, 3));  // This invokes 1 copy constructor call that copies the Vertex object from the main function stack to the memory of the vector.
    std::cout << "End of 1 push back \n" << std::endl;
    vertices.push_back(Vertex(4, 5, 6));  // Reallocation of memory to resize the vector and then copy the new objects invokes 2 copy constructor calls.
    std::cout << "End of 2nd push back \n" << std::endl;
    vertices.push_back(Vertex(7, 8, 9)); // Similarly, resizing the vector and moving the around the existing objects and creating a new one invokes 3 copy constructor calls.
    std::cout << "End of the 3rd push back \n" << std::endl;

    /**
     * Now we can optimize by actually reserving space for 3 Vertex objects upfront.
     * This way, on-the-go reallocation of memory and thereby, multiple copy constructor calls are avoided.
     * 
     * But still, the objects are created on the memory stack of the main function
     * and then copied into the vectors.
     * So, we see 3 calls of the copy constructor for the 3 objects.
     */

    std::vector<Vertex> vertices1;
    vertices1.reserve(3);
    std::cout << "Reserving space upfront, considering we know how many objects need to be created. \n";
    std::cout << "This is create 3 calls to the copy constructor because we copy the objects from the main function stack to the vector's stack, each time for the 3 objects." << std::endl;
    vertices1.push_back(Vertex(1, 2, 3));
    vertices1.push_back(Vertex(4, 5, 6));
    vertices1.push_back(Vertex(7, 8, 9));

    /**
     * The above copying of the objects from the stack of the main function to the vector can be 
     * further optimized using emplace_back, 
     * which creates the objects inside the Vertices vector stack.
     * 
     * Note that we only need to pass the parameter list for the constructor and not the objects.
     */

    std::vector<Vertex> vertices2;
    vertices2.reserve(3);
    std::cout << "\nFurther optimising using emplace back involves passing the constructor parameters and creating the objects inside the vector stack, thereby involving no copying of objects." <<std::endl;
    std::cout << "This will have no copy constructor calls." << std::endl;
    vertices2.emplace_back(1, 2, 3);
    vertices2.emplace_back(4, 5, 6);
    vertices2.emplace_back(7, 8, 9);

}