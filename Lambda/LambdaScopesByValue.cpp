#include <iostream>
#include <string>
 
int main(int argc, char **argv)
{
	std::string msg = "Hello";
	int counter = 10;
 
	// Defining Lambda function and
	// Capturing Local variables by Value
	auto func = [msg, counter]  () mutable {
		std::cout<<"Inside Lambda :: msg = "<<msg<<std::endl;
		std::cout<<"Inside Lambda :: counter = "<<counter<<std::endl;
 
		// Change the counter & msg
		// Change will not affect the outer variable because counter variable is
		// captured by value in Lambda function
		msg = "Temp";
		counter = 20;
 
		std::cout<<"Inside Lambda :: After changing :: msg = "<<msg<<std::endl;
		std::cout<<"Inside Lambda :: After changing :: counter = "<<counter<<std::endl;
 
		};
 
	//Call the Lambda function
	func();
 
	//Values of local variables are not changed.
	std::cout<<"msg = "<<msg<<std::endl;
	std::cout<<"counter = "<<counter<<std::endl;
 
	return 0;
}