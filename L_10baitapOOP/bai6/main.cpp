#include <stdio.h>


class phanSo{
    private:
        int tuSo;
        int mauSo;
    public:
        phanSo(int tu = 0, int mau = 1);
        float getPhanSo();
};


phanSo::phanSo(int tu, int mau){
        phanSo::tuSo = tu;
        phanSo::mauSo = mau;
}


float phanSo::getPhanSo() {
  return (float)phanSo::tuSo / (float)phanSo::mauSo;
};


class calPhanSo{
    private:
        phanSo A;
        phanSo B;
    public:
        calPhanSo(phanSo a, phanSo b);
        float congPhanSo();
        float truPhanSo();
        float nhanPhanSo();
        float chiaPhanSo();
};


calPhanSo::calPhanSo(phanSo a, phanSo b){
    calPhanSo::A = a;
    calPhanSo::B = b;
}


float calPhanSo::congPhanSo(){
  return A.getPhanSo() + B.getPhanSo();
}


float calPhanSo::truPhanSo() {
  return A.getPhanSo() - B.getPhanSo();
}


float calPhanSo::nhanPhanSo() {
  return A.getPhanSo() * B.getPhanSo();
}


float calPhanSo::chiaPhanSo(){
  return A.getPhanSo() / B.getPhanSo();
}

int main() {
  printf("Tong 2 phan so = %.2f\n", calPhanSo(phanSo(2,7), phanSo(9,5)).congPhanSo());
  printf("Hieu 2 phan so = %.2f\n", calPhanSo(phanSo(35,13), phanSo(8,55)).truPhanSo());
  printf("Tich 2 phan so = %.2f\n", calPhanSo(phanSo(8,9), phanSo(3,4)).nhanPhanSo());
  printf("Thuong 2 phan so = %.2f\n", calPhanSo(phanSo(7,15), phanSo(16,3)).chiaPhanSo());
  return 0;
}
