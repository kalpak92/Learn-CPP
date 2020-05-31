#include <iostream>
#include <string>

class String
{
    private:
        char* m_buffer;
        unsigned int m_Size;

    public:
        String(const char* string)
        {
            m_Size = strlen(string);
            m_buffer = new char[m_Size + 1];

            memcpy(m_buffer,string, m_Size);
            m_buffer[m_Size] = 0;
        }

        ~String()
        {
            delete[] m_buffer;
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buffer;
    return stream;
}


int main()
{
    String string = "Kalpak";
    String second = string;  // points to the same block of memory.

    

    std::cout << string << std::endl;
    std::cout << second << std::endl;  // there will be a runtime error as delete will be invoked twice.
    //std::cin.get();
}