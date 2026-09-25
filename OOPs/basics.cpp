#include <iostream>
#include <vector>
using namespace std;

// class Student{
//     public:
//     int age;
//     string name;

//     void show(){
//         cout<<name<<" is studying"<<endl;
//     }
// };

// int main(){
//     Student s1;

//     s1.name = "Jay";
//     s1.age = 21;

//     s1.show();

//     return 0;
// }

// class Bank{
// public:
//     string name;
//     double amount;

//     void account(double deposit){
//         deposit+=amount;
//     }
//     void show(){
//         cout<<name<<endl;
//         cout<<amount;
//     }
// };

// int main(){
//     Bank b1;
//     Bank b2;
//     b1.name = "patrick";
//     b1.amount = 10000;
//     b1.account(1200);


//     b1.show();
//     b2.show();

// }

// class Person {
// public:
//     string name;
//     int age;

//     Person& setName(string name) {
//         this->name = name;
//         return *this;
//     }

//     Person& setAge(int age) {
//         this->age = age;
//         return *this;
//     }
// };

// int main(){
//     Person p;

//     p.setName("Rahul").setAge(20);
// }

// class Student {
// public:
//     int age;

//     void show() {
//         cout << this->age;
//     }
// };

// int main() {
//     Student s1;
//     Student s2;

//     s1.age = 20;
//     s2.age = 30;

//     s1.show();
//     s2.show();
// }

// #include <iostream>
// using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }

        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {

    BankAccount account(10000);

    account.deposit(5000);

    account.withdraw(3000);

    cout << account.getBalance();
}