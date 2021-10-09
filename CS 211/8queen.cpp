#include <iostream>
using namespace std;

// 8 queens 2 dimensional array
void eightQueen()
{
    int b[8][8] = {0}, row,colum = 0;
    b[0][0] = 1;
    // next col
    NC: colum++;
    if(colum == 8) goto print;
    row = -1;

    NR: row++;
    if(row == 8) goto backtrack;
    
    //row test
    for(int i = 0; i < colum; i++)
    {
        if(b[row][i] == 1)
        {
            goto NR;
        }
    }

    // up diagonal
    for(int i = 0; (row - i) > -1 && (colum - i) > -1; i++)
    {
        if(b[row - i][colum - i] == 1)
        {
            goto NR;
        }
    }

    // down diagonal 
    for(int i = 0; (row + i) < 8 && (colum - i) > -1; i++)
    {
        if(b[row + i][colum - i] == 1)
        {
            goto NR;
        }
    }
    b[row][colum] = 1;
    goto NC;

    backtrack: colum--;
    if(colum == -1) return;
    row = 0; 
    while(b[row][colum] != 1)
    {
        row++;
    }
    b[row][colum] = 0;
    goto NR;
    
   print:
   static int solution = 0;
   solution++;
   cout << "Solution #" << solution << ":\n";
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
         cout << b[i][j] << " ";
      cout << "\n";
   }
   goto backtrack;
}        


bool test(int q[])
{
  for(int c = 7; c > -1 ; c--)
  {
    for (int i = 0; i < c ; i++)
    {
      if(q[i] == q[c] || (c-i) == abs(q[c]-q[i]))
        {
        return false;
      } 
    }
  }
  return true;
}

void print(int b[])
{
  for (int x = 0; x < 8 ; x++)
  {
    for (int y = 0; y < 8 ; y++)
    {
      if (b[y] == x) 
      {
          cout << "1";
      }else {
          cout <<"0";
      }
    }
    cout << endl;
  }
}

void dumbEightQueen(){
    int solution = 0;
    int b[8] = {0};
    for(int i0 = 0; i0 < 8; i0++)
        for(int i1 = 0; i1 < 8; i1++)
            for(int i2 = 0; i2 < 8; i2++)
                for(int i3 = 0; i3 < 8; i3++)
                    for(int i4 = 0; i4 < 8; i4++)
                        for(int i5 = 0; i5 < 8; i5++)
                            for(int i6 = 0; i6 < 8; i6++)
                                for(int i7 = 0; i7 < 8; i7++){
                                    b[0] = i0;
                                    b[1] = i1;
                                    b[2] = i2;
                                    b[3] = i3;
                                    b[4] = i4;
                                    b[5] = i5;
                                    b[6] = i6;
                                    b[7] = i7;
                                    if(test(b))
                                    {
                                        solution++;
                                        cout << "Solution #" << solution << "\n";
                                        print(b);
                                    }
                                }
}


int main() 
{
  cout << "Eight queen"<< endl;
 // eightQueen();
  cout << endl;
  cout << "Dumb Eight Queen" << endl;
  dumbEightQueen();
  return 0;
}