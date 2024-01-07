#include <iostream>
using namespace std;

int main() {
   double feet = 30.48;
   int mile = 160934;

   cout << fixed;
   cout.precision(1);
   cout << "9.2ft = " << feet*9.2 << "cm" << endl;
   cout << "1.3mi = " << mile*1.3 << "cm";
    return 0;
}