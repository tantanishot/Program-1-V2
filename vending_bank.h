#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>
class VendingBank
{
public:
    //constructors
        VendingBank();
        VendingBank(int id);

    // Constructor with id and coin values
        VendingBank(int id, int quarters, int pennies, int nickels, int dimes);

    // Constructor with only coin values
        VendingBank(int quarters, int pennies, int nickels, int dimes);

    // Constructor with total amount (the bank calculates how many coins can be from that amount)
        VendingBank(int total_amount);


    //methods
        void VendItem();
        
    //getters-setters
        int size() const;
        int quarters() const;
        int pennies() const;
        int nickels() const;
        int dimes() const;
        int current_amount_held() const;

        void SetDimes(int new_dimes);
        void SetQuarters(int new_quarters);
        void SetPennies(int new_pennies);
        void SetNickels(int new_nickels);
    

    //coding guidelines example for setter
    //passing by value for small primitives
    //bool set_other_data(int val);

    //operator overloads
        bool operator<=(const VendingBank& bank) const;
        bool operator>=(const VendingBank& bank) const;
        bool operator==(const VendingBank& bank) const;
        VendingBank operator+(const VendingBank& other_bank) const;
        VendingBank operator-(const VendingBank& other_bank) const;

    friend std::ostream& operator<<(std::ostream& os, const VendingBank& bank);

    

private:
int id_;
int quarters_;
int pennies_;
int nickels_;
int dimes_;
int current_amount_held_;

};

#endif
