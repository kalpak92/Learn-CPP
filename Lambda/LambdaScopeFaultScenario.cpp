#include <iostream>
#include <string>
#include <functional>
 
std::function<void ()> getCallBack()
{
	// Local Variable
	int counter = 10;
 
	// Defining Lambda function and
	// Capturing Local variables by Reference
	auto func = [&counter]  () mutable {
		std::cout<<"Inside Lambda :: counter = "<< counter <<std::endl;
 
		// Change the counter
		// Change will affect the outer variable because counter variable is
		// captured by Reference in Lambda function
		counter = 20;
 
		std::cout<<"Inside Lambda :: After changing :: counter = "<<counter<<std::endl;
 
		};
 
	return func;
}
 
int main(int argc, char **argv)
{
 
	std::function<void ()> func = getCallBack();
 
	//Call the Lambda function
	func();
 
	// Lambda function will access and modify the variable that has been captured it by reference
	// But that variable was actually a local variable on stack which was removed from stack when getCallbacK() returned
	// So, lambda function will basically corrupt the stack
 
	return 0;
}