#include <iostream>
using namespace std;

    void print(int q[])
    {
        cout << " " << q[0] << q[1] << " " << endl;
        cout << q[2] << q[3] << q[4] << q[5] << endl;
        cout << " " << q[6] << q[7] << endl;      
    }

    bool ok(int q[],int a[][5], int c){
    // row test
      for(int i = 0; i < c; i++)
      {
        if(q[i] == q[c])
        {
            return false;
        }
      }

    // adjcent test
    for(int j = 0; a[c][j] != -1; j++)
    {
        if(abs(q[c] - q[a[c][j]]) == 1)
        {
            return false;
        }
    }
     return true;
  }

void eightNumbercross(){
    int q[8],c,solutions = 0;
    q[0] = 1;
    int array[8][5] = { 
                        {-1}, //0
                        { 0,-1}, // 1
                        { 0,-1},  // 2
                        { 0, 1, 2,-1}, // 3
                        { 0, 1, 3,-1}, // 4
                        { 1, 4,-1}, // 5
                        { 2, 3, 4,-1,}, // 6
                        { 3, 4, 5, 6,-1} // 7
                    };


    NC:c++;
    if(c == 8) goto print;
    q[c] = 0;
    NR: q[c]++;
    if(q[c] == 9) goto backtrack;
    if(ok(q,array,c))
    {
      goto NC;
    }
    goto NR;

  backtrack: c--;
    if(c == -1) return;
    goto NR;

  print:
    cout << "solutions: "<< ++solutions <<endl;
    print(q);
    goto backtrack;
 }

int main() {
    eightNumbercross();
    return 0;
}