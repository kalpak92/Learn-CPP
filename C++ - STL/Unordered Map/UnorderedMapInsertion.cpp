#include <iostream>
#include <unordered_map>
#include <string>
 
int
main()
{
  // Creating an empty unordered_map
  std::unordered_map<std::string, int> wordMap;
 
  // Inserting elements through an initializer_list
  wordMap.insert({ {"First", 1}, {"Second", 2}, {"Third", 3} } );
   
  typedef std::unordered_map<std::string, int>::iterator UOMIterator;
   
  // Pair of Map Iterator and bool value
  std::pair< UOMIterator , bool> result;
   
  // Inserting an element through pair
  result = wordMap.insert(std::make_pair<std::string, int>("Second", 6));
   
  if(result.second == false)
    std::cout<<"Element 'Second' not inserted again"<<std::endl;
   
  // Inserting an element through value_type
  result = wordMap.insert({"Fourth", 4});

  if(result.second == false)
  {
      std::cout<<"Element 'Fourth' not inserted again"<<std::endl;
  }
  else
  {
    // Element inserted sucessfully, so first value in pair
    // is the iterator of newly inserted element
    std::cout<<"Element Inserted : ";
    std::cout << result.first->first << "::" << result.first->second << std::endl;
  }

  for (std::pair<std::string, int> element : wordMap)
      std::cout << element.first << " :: " << element.second << std::endl;
  
  return 0;
}