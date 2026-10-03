#include <iostream>
#include <vector>
using namespace std;

// class Payment{
// public:
//     double amount;

//     void process(){}
// };

// class UPIPayment : public Payment{
// public:
//     void verifyUPI() {}
// };

// int main(){
//     UPIPayment p;
//     p.amount = 5000;
//     p.process();
//     p.verifyUPI();
// }

class BankAccount {
private:
    double balance;

protected:
    void updateBalance(double amount) {
        balance += amount;
    }
};