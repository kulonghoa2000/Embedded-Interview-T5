#include <stdio.h>
#include <math.h>


class Diem{
    private:
        int X;
        int Y;
    public:
        Diem(int X = 0, int Y = 0);
        int getX();
        int getY();
};


Diem::Diem(int x, int y){
    Diem::X = x;
    Diem::Y = y;
}

int Diem::getX(){
    return Diem::X;
}

int Diem::getY(){
    return Diem::Y;
}


class calData{
    private:
        Diem A;
        Diem B;
        Diem C;
    typedef enum{
        KHOANG_CACH,
        DIEN_TICH
    }PhepToan;

    PhepToan kiemTra;
    public:
        calData(Diem a, Diem b, Diem c);
        calData(Diem a, Diem b);
        void khoangCachHaiDiem();
        void dienTichTamgiac();
};


calData::calData(Diem a, Diem b){
    calData::A = a;
    calData::B = b;
    kiemTra = KHOANG_CACH;
}

calData::calData(Diem a, Diem b, Diem c){
    calData::A = a;
    calData::B = b;
    calData::C = c;
    kiemTra = DIEN_TICH;
}

void calData::khoangCachHaiDiem(){
    if ( kiemTra == KHOANG_CACH){
        double khoangCach = (double)sqrt((A.getX()-B.getX())*(A.getX()-B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
        printf("%f\n",khoangCach);
    }
    else 
        printf("Day khong phai 3 diem cua tam giac\n");
}

void calData::dienTichTamgiac(){
    if ( kiemTra == DIEN_TICH){
        double dienTich = (double)abs((B.getX() - A.getX()) * (C.getY() - A.getY()) - (C.getX() -A.getX()) * (B.getY() - A.getY())) / (double)2;
        printf("%.2f\n",dienTich);
    }
    else 
        printf("Day khong phai 3 diem cua tam giac\n");
}


int main(){
    calData point(Diem(1,2), Diem(1,5), Diem(5,5));
    point.khoangCachHaiDiem();
    point.dienTichTamgiac();
}