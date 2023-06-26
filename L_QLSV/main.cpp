#include <iostream>
#include <string>

using namespace std;

typedef enum{
    NAM,
    NU
} TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
} TypeHocLuc;

typedef enum{
    TEN,
    TUOI,
    GIOI_TINH,
    DIEM
} TypeInput;

class HocSinh{
    private:
        int ID;
        string NAME;
        int TUOI;
        float DIEM_TOAN;
        float DIEM_LY;
        float DIEM_HOA;
        TypeGioiTinh GIOI_TINH;

    public:
        HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa);
        HocSinh() = default;

        void setTen(string ten);
        string getTen();

        void setGioiTinh(TypeGioiTinh gioitinh);
        TypeGioiTinh getGioiTinh();

        void setTuoi(int tuoi);
        int getTuoi();

        void setDiemToan(float diemtoan);
        float getDiemToan();
        void setDiemLy(float diemly);
        float getDiemLy();
        void setDiemHoa(float diemhoa);
        float getDiemHoa();

        int getId();
        float DiemTrungBinh();
        TypeHocLuc HocLuc();
};

HocSinh::HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa){
    static int id = 100;
    HocSinh::ID = id;
    HocSinh::NAME = name;
    HocSinh::TUOI = tuoi;
    HocSinh::DIEM_TOAN = diemtoan;
    HocSinh::DIEM_LY = diemly;
    HocSinh::DIEM_HOA = diemhoa;
    HocSinh::GIOI_TINH = gioitinh;
    id++;
}

void HocSinh::setTen(string ten){
    this->NAME = ten;
}

string HocSinh::getTen(){
    return HocSinh::NAME;
}

void HocSinh::setGioiTinh(TypeGioiTinh gioitinh){
    this->GIOI_TINH = gioitinh;
}

TypeGioiTinh HocSinh::getGioiTinh(){
    return HocSinh::GIOI_TINH;
}


void HocSinh::setTuoi(int tuoi){
    this->TUOI = tuoi;
}

int HocSinh::getTuoi(){
    return HocSinh::TUOI;
}

float HocSinh::DiemTrungBinh(){
    return (HocSinh::DIEM_TOAN + HocSinh::DIEM_LY + HocSinh::DIEM_HOA) / 3;
}

void HocSinh::setDiemToan(float diemtoan){
    this->DIEM_TOAN = diemtoan;
}

float HocSinh::getDiemToan(){
    return this->DIEM_TOAN;
}

void HocSinh::setDiemLy(float diemly){
    this->DIEM_LY = diemly;
}

float HocSinh::getDiemLy(){
    return this->DIEM_LY;
}

void HocSinh::setDiemHoa(float diemhoa){
    this->DIEM_HOA = diemhoa;
}

float HocSinh::getDiemHoa(){
    return this->DIEM_HOA;
}

TypeHocLuc HocSinh::HocLuc()
{
    if (HocSinh::DiemTrungBinh() >= 8)
        return GIOI;
    else if (HocSinh::DiemTrungBinh() >= 6.5)
        return KHA;
    else if (HocSinh::DiemTrungBinh() >= 5)
        return TRUNG_BINH;
    else
        return YEU;
}

int HocSinh::getId(){
    return HocSinh::ID;
}

int main () {



    
}