#include <iostream>
#include <string>
using namespace std;


string add(string a, string b)
{
  string newA, newB;
  // length of a is 16. 
  // length of b is 22
  // gap is 6
  
  int gap = b.length() - a.length();
  for(int i = 0; i < gap; i++)
  {
      a = '0' + a;
  }   
  
  
  // reverse a
  for(int i = a.length(); i >= 0;i--)
  {
      newA += a[i];
  }

  // reverse b 
  for(int j = b.length(); j >= 0; j--)
  {
      newB += b[j];
  }   

  int sum = 0;
  string result = "";
  int extractDigit = 0;
  for(int i = b.length()-1; i >= 0; i--)
  {
      sum = (a[i] - '0') + (b[i] - '0') + extractDigit;
      if(sum > 9)
      {
          // modify the extractDigit and extract digit for next round 
          // calculation
          extractDigit = 1;
          sum %= 10;
      }else
      {
        extractDigit = 0;
      }
      // add result to string after each caluclation
      result.insert(result.begin(), sum + '0'); 
      sum = 0;
  } 
    return result;
}   

int main() {
   string a = "2345566777844567";
   string b = "9999988777765768009998";
   cout << "The sum of two number are: " << add(a,b) << endl;
   return 0;
}