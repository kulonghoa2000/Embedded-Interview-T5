#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class Car{
    private:
        string color;
        string engine;
        int km;
    public:
        Car(string cl, string eng, float numkm);
        int cost();
        int checkCar();
        void exportData();
};

Car::Car(string car_color, string car_eng, float car_km) {
    Car::color = car_color;
    Car::engine = car_eng;
    Car::km = car_km;
}

int Car::cost(){
    return Car::km * 3;
};


int Car::checkCar() {
  return Car::km;
};


void Car::exportData(){
    printf("Mau sac: %s\n", Car::color.c_str());
    printf("Dong co: %s\n",Car::engine.c_str());
    printf("So km da di chuyen %.d\n", checkCar());
}

int main() {
    Car car("White", "4matic", 1500);
    car.exportData();
    printf("Chi phi bao tri: %d$\n", car.cost());
}