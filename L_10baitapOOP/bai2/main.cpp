#include <stdio.h>
#include <math.h>


class hinhChuNhat {
  private:  
    int chieuDai;
    int chieuRong;
  public:
    hinhChuNhat(int dai , int rong );
    int chuVi();
    int dienTich();
    double duongCheo();
    bool kiemTra();
};

hinhChuNhat::hinhChuNhat(int dai, int rong){
  chieuDai = dai;
  chieuRong = rong;
}


int hinhChuNhat::chuVi() {
  return (hinhChuNhat::chieuDai + hinhChuNhat::chieuRong) * 2;
}


int hinhChuNhat::dienTich() {
  return (hinhChuNhat::chieuDai * hinhChuNhat::chieuRong);
}


double hinhChuNhat::duongCheo() {
  return sqrt( pow(hinhChuNhat::chieuDai, 2) + pow(hinhChuNhat::chieuRong, 2));
}


bool hinhChuNhat::kiemTra() {
  if(hinhChuNhat::chieuDai == hinhChuNhat::chieuRong) return true;// kiem tra hinh vuong
  else return false;
}

int main() {
  hinhChuNhat hinh(20,20);
  
  printf("Chu vi: %d\n", hinh.chuVi());
  printf("Dien tich: %d\n",hinh.dienTich());
  printf("Duong cheo: %.3f\n", hinh.duongCheo());

  if(hinh.kiemTra()) 
        printf("Day la hinh vuong");
  else  printf("Day la hinh chu nhat");

  return 0;
}