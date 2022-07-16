#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;


int main () {
  int a;
  int b;
  while (cin >> a) {
     bool prime = true;

     if (a < 2) {
         prime = false;
      }

      else {

          for (b = 2; b <= sqrt(a); b++) {
              if (a % b == 0) {
                  prime = false;
                  break;
               }
           }
       }

    if (prime) {
       cout << a << " is prime" << endl;
     } else {
       cout << a << " is not prime" << endl;
      }
  }
 return 0;
 }
