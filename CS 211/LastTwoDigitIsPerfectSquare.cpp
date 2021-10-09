#include<iostream>  
  
using namespace std; 
  
// main function - 
// where the execution of program begins 
#include <iostream>
using namespace std;

int main() {
  int value = 1;
  bool start = false;
  while(!start){
      int result = value * value;// get the perfect square
      int lastDigit = (result) % 10; // extract last digit
      int digitBeforeLast = (result / 10) % 10; //extract the digit before lest digit 
      if(lastDigit % 2 ==1  &&  digitBeforeLast % 2 == 1 ){
        cout << "The first perfect square that whose last two digits are both odd is " << result << endl;
        break;
      }
      value++;     
  }
  return 0;
  // the number does not look like to be a perfect square
  // when 131073 get square root is 362.04005...
  // but the last two digit are odd
}
 
    
  

