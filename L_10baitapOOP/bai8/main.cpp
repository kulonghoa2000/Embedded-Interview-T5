#include <iostream>
#include <stdio.h>

using namespace std;


class account {
    private:
        string accName; 
        int accNumber;
        int accBalance;
    public:
        account(string name, int number, int balance);
        uint16_t getBalance();
        void napTien(int soTien);
        void rutTien(int soTien);
};

account::account(string name, int number, int balance){
    account::accName = name;
    account::accNumber = number;
    account::accBalance = balance;
}

void account::napTien(int soTien){
    printf("So tien hien co la: %d\n", account::accBalance);
    account::accBalance += soTien;
    printf("So tien sau khi nap la: %d\n", account::accBalance);
}

void account::rutTien(int soTienRut){
    if(soTienRut > account::accBalance) printf("So du khong du de rut\n");
    else{
        account::accBalance -= soTienRut;
        printf("So tien sau khi rut la: %d\n",account::accBalance);
    }
}

int main() {
    account *setData;
    setData = new account("DuyTruong", 86315972, 90000);
    setData->napTien(15000);
    setData->rutTien(12000);
    setData->rutTien(11000);
    return 0;
}
