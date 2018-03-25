#include <iostream>
#include <map>
#include <string>
#include <iterator>
 
struct WordGreaterComparator
{
    bool operator()(const std::string & left, const std::string & right) const
    {
        return (left > right);
    }
};
 
int main()
{
 
    std::cout<<"Default sorting criteria for keys i.e. operator < for std::string"<<std::endl;
    // Default sorting criteria for keys i.e. operator < for std::string
    std::map<std::string, int> mapOfWords;
 
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords.insert(std::make_pair("sun", 3));
 
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    for( ; it != mapOfWords.end(); it++)
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
 
    std::cout<<"External sorting criteria for keys "<<std::endl;
    std::map<std::string, int, WordGreaterComparator > mapOfWords_2;
 
    mapOfWords_2.insert(std::make_pair("earth", 1));
    mapOfWords_2.insert(std::make_pair("moon", 2));
    mapOfWords_2.insert(std::make_pair("sun", 3));
    for(std::map<std::string, int>::iterator it = mapOfWords_2.begin(); it != mapOfWords_2.end(); it++)
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
    std::cout << std::endl;

    //Compilation Error : As the sorting criteria is not same
    /* 
    if(mapOfWords == mapOfWords_2)
        std::cout<< "Maps are same" <<std::endl;
    else
        std::cout<< "Maps are not same" << std::endl;
    */
    return 0;
}