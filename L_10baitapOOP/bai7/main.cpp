#include <stdio.h>


class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y);
        int calAge(Date* setDate, Date* currentDate);
        bool checkHoliday();
};


Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}


int Date::calAge(Date* setDate, Date* currentDate) {
    return currentDate->year - setDate->year;
}


bool Date::checkHoliday() {
    if ((Date::day == 1 && Date::month == 1)||(Date::day == 30 && Date::month == 4)||(Date::day == 1 && Date::month == 5)||(Date::day == 2 && Date::month == 9))
    return true;
    return false;
}

int main() {
    Date *setDate, *currentDate;
    setDate = new Date(8, 7, 1997);
    currentDate = new Date(23, 6, 2023);
    printf("Tuoi: %d\n", setDate->calAge(setDate, currentDate));
    if(setDate->checkHoliday() == true)   printf("Day la ngay le\n");
    else  printf("Day khong phai ngay le");
    delete setDate, currentDate;
    return 0;
}
