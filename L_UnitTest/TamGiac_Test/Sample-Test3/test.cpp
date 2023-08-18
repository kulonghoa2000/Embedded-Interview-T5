#include "pch.h"

enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    

    if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}

TEST(XacDinhLoaiTamGiac, tamGiacKhongTonTai) {
    EXPECT_EQ(XacDinhLoaiTamGiac(0, 2, 3), TamGiacKhongTonTai);
    EXPECT_EQ(XacDinhLoaiTamGiac(7, 0, 0), TamGiacKhongTonTai);
    EXPECT_EQ(XacDinhLoaiTamGiac(10, 8, 0), TamGiacKhongTonTai);
}


TEST(XacDinhLoaiTamGiac, tamGiacDeu) {
    EXPECT_EQ(XacDinhLoaiTamGiac(7, 7, 7), TamGiacDeu);
}


TEST(XacDinhLoaiTamGiac, tamGiacCan) {
    EXPECT_EQ(XacDinhLoaiTamGiac(12, 10,12), TamGiacCan);
    EXPECT_EQ(XacDinhLoaiTamGiac(10, 12, 12), TamGiacCan);
    EXPECT_EQ(XacDinhLoaiTamGiac(12, 12, 10), TamGiacCan);
}


TEST(XacDinhLoaiTamGiac, tamGiacVuong) {
    EXPECT_EQ(XacDinhLoaiTamGiac(3, 4, 5), TamGiacVuong);
}


TEST(XacDinhLoaiTamGiac, tamGiacThuong) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 3, 4), TamGiacThuong);
}