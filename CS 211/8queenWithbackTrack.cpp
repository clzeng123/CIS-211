#include <iostream>
using namespace std;

void eightQueenWithBackTrack(){
    int q[8],c = 0;
    int solution = 0;
    q[0] = 0;
    NC: c++;
    if(c == 8)
    {   
        solution++;
        cout << "solution count #" << solution << endl;
        for(int x=0;x<8;x++){
            for(int s=0;s<8;s++){
                if(q[s]==x){
                    cout << 1 << " ";
                }else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
        c--;
        goto NR;
    }
    q[c] = -1;
    NR: q[c]++;
    if(q[c] == 8) {
     goto backtrack;   
    }
    
    for(int i = 0; i < c; i++)
    {
        if(q[i] == q[c] || (c-i) == abs(q[c]-q[i]))
        {
            goto NR;
        }
    }
    goto NC;
    backtrack: c--;
    if(c == -1) return;
    goto NR;
}

void print(int arr[],int max)
{
    for(int x=0;x<max;x++){
                for(int s=0;s<max;s++){
                    if(arr[s]==x){
                        cout << 1 << " ";
                    }else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
}
bool test(int q[], int c)
{
    for (int i = 0; i < c ; i++)
    {
      if(q[i] == q[c] || (c-i) == abs(q[c]-q[i]))
        {
        return false;
      } 
    }
  
  return true;
}

void eightQueenWithOutGoto()
{
    int q[8],c = 0;
    int solution = 0;
    q[0] = 0;
    //NC: c++;
    while(1)
    {
        c++;
        if(c == 8)
        {   
            solution++;
            cout << "solution count #" << solution << endl;
            print(q,8); 
        } 
     //goto NR;
    q[c] = -1;
    //NR: q[c]++
        while(1)
        {   
          q[c]++;
          if(q[c] == 8) 
          {
            c--;   
            if(c == -1) return;
               continue;//goto NR;
            }
            if(test(q,c) == false){
                continue;
            }else{
              break;
            }
        }
    }
}

int main() {
  cout << "Eight queen with goto"<< endl;
  eightQueenWithBackTrack();
  cout << "Eight queen without goto"<< endl;
  eightQueenWithOutGoto();
  return 0;
}