#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class nguoi{
    private:
        string name;
        string address;
        int yearOfBirth;
    public:
        nguoi(string name, int yearOfBirth, string address);
        void getData();
        int getAge();
};

nguoi::nguoi(string name, int yearOfBirth, string address){
    nguoi::name = name;
    nguoi::yearOfBirth = yearOfBirth;
    nguoi::address = address;
};


void nguoi::getData(){
    printf("Ten: %s\n", nguoi::name.c_str());
    printf("Nam sinh: %d\n", nguoi::yearOfBirth);
    printf("Dia chi: %s\n", nguoi::address.c_str());
}


int nguoi::getAge() {
    return 2023 - nguoi::yearOfBirth;
}

int main() {
    nguoi Nguoi("Nguyen Duy Truong", 2000, "Binh Duong");

    Nguoi.getData();
    printf("Tuoi: %d\n", Nguoi.getAge());
    return 0;
}