#include <iostream>
using namespace std;
namespace ConOngA{
    int A = 10;
    class ToanHoc {
        public:
            void nhapABC();
            void getX1X2();
        private:
        int A;
        int B;
        int C;
        int X1;
        int X2;
        int delta;
        int getDelta();
    };
}
namespace ConOngB{
    int A = 20;
}

using namespace ConOngA;

int main(){
    int A;
    cout<< "A = " << ConOngA::A << endl;
    cout<< "A = " << ConOngB::A << endl;

return 0;
}