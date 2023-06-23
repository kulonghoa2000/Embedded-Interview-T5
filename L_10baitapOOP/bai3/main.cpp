#include <bits/stdc++.h>
using namespace std;


class hinhtron {
private:
    float bankinh;
public:
    hinhtron(float r);
    float getbankinh();
    float getdientich();
    float getchuvi();
};


hinhtron::hinhtron(float r) {
    bankinh = r;
}


float hinhtron::getbankinh(){
    return bankinh;
}


float hinhtron::getdientich(){
    return M_PI * bankinh * bankinh;
}


float hinhtron::getchuvi(){
    return 2 * M_PI * bankinh;
}

int main() {
    float bankinh;
    cout << "Nhap vao ban kinh cua hinh tron: ";
    cin >> bankinh;

    hinhtron hinhtron(bankinh);

    cout << "bankinh: " << hinhtron.getbankinh() << endl;
    cout << "dientich: " << hinhtron.getdientich() << endl;
    cout << "chuvi: " << hinhtron.getchuvi() << endl;

    return 0;
}
