class Account
{
    public:
        virtual ~Account() = default;
};

class BankAccount: virtual public Account{};

class WireAccount: virtual public Account{};

class CheckingAccount: public BankAccount, public WireAccount {};

class SavingAccount: public BankAccount, public WireAccount {};

int main()
{

    Account * a = nullptr;
    BankAccount * b = nullptr;
    WireAccount * w = nullptr;
    SavingAccount * s = nullptr;

    CheckingAccount c;

    a = dynamic_cast<Account*> (&c);                        // upcast
    a = &c;                                                 // upcast

    b = dynamic_cast<BankAccount*>(a);                      // downcast
    w = dynamic_cast<WireAccount*>(b);                      // crosscast
    s = dynamic_cast<SavingAccount*>(a);                    // downcast

}