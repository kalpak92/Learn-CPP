#include<iostream>
#include<set>
#include<string>
 
class Message
{
public:
	std::string m_MsgContent;
	std::string m_sentBy;
	std::string m_recivedBy;
 
	Message(std::string sentBy, std::string recBy, std::string msg) :
		m_MsgContent(msg), m_sentBy(sentBy), m_recivedBy(recBy)
	{}
 
	bool operator< (const Message & msgObj) const
	{
		std::string rightStr = 	msgObj.m_MsgContent + msgObj.m_sentBy + msgObj.m_recivedBy;
		std::string leftStr = 	this->m_MsgContent + this->m_sentBy + this->m_recivedBy;
		return (leftStr < rightStr);
	}
	friend std::ostream& operator<<(std::ostream& os, const Message& obj);
 
};
std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os<<obj.m_sentBy<<" :: "<<obj.m_MsgContent<<" :: "<<obj.m_recivedBy<<std::endl;
	return os;
}

int main()
{
	std::set<Message> setOfMsgs;
 
	Message msg1("user_1", "Hello", "user_2");
	Message msg2("user_1", "Hello", "user_3");
	Message msg3("user_3", "Hello", "user_1");
	// A Duplicate Message
	Message msg4("user_1", "Hello", "user_3");
 
	setOfMsgs.insert(msg1);
	setOfMsgs.insert(msg2);
	setOfMsgs.insert(msg3);
	setOfMsgs.insert(msg4);
 
	// msg4 will not get inserted because its duplicate as per the current operator < implementation.
 
	// Iterate through all the elements in a set and display the value.
		for (std::set<Message>::iterator it=setOfMsgs.begin(); it!=setOfMsgs.end(); ++it)
		    std::cout << *it ;
 
	return 0;
}