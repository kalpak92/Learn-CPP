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
	friend std::ostream& operator<<(std::ostream& os, const Message& obj);
 
};

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os<<obj.m_sentBy<<" :: "<<obj.m_MsgContent<<" :: "<<obj.m_recivedBy<<std::endl;
	return os;
}

class MessageUserComparator
{
	std::string m_userName;

public:
	MessageUserComparator(std::string userName) :
		m_userName(userName)
	{}

	bool operator() (const Message& m1, const Message& m2) const
	{
		if (m1.m_sentBy < m2.m_sentBy)
			return true;
		else
			return false;
	}
};

int main()
{
	Message msg1("user_1", "Hello", "user_2");
	Message msg2("user_1", "Hello", "user_3");
	Message msg3("user_3", "Hello", "user_1");
	Message msg4("user_1", "Hello", "user_3");

	std::cout << "Set that contains Messages sent by user - user_1" << std::endl;

	std::set<Message, MessageUserComparator> setOfMsgs_1(MessageUserComparator("user_1"));

	setOfMsgs_1.insert(msg1);
	setOfMsgs_1.insert(msg2);
	setOfMsgs_1.insert(msg3);
	setOfMsgs_1.insert(msg4);

	// Iterate through all the elements in a set and display the value.
	for (std::set<Message>::iterator it=setOfMsgs_1.begin(); it != setOfMsgs_1.end(); ++it)
		std::cout << *it ;

	return 0;
}