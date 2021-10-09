#include <iostream>
using namespace std;


void print(int q[])
{
    cout << "Man" << " " << "Woman"<< endl;
    for(int i = 0; i < 3; i++)
    {
        cout << i << " " <<  q[i] << endl;
    }
    cout << endl;
}

bool ok(int q[],int col)
{
     int mp[3][3]={0,2,1,
                   0,2,1,
                   1,2,0};
                  
     int wp[3][3]={2,1,0,
                   0,1,2,
                   2,0,1};
    
    //if the current man prefers the new woman to his partner and
    //if the new woman prefers the current man to her partner
    // cm = 0  cw = q[cm]  nm = col nw = q[col]
     int nm,nw,cm,cw;
     nm = col;
     nw = q[col];
     for(cm =0; cm < nm; cm++)
     {   
        cw = q[cm]; 
        //nw have some man
        if(cw == nw)
        {
            return false;
        }
        //if the current man prefers the new woman to his partner and
        //if the new woman prefers the current man to her partner
         //    cm  nw     cm cw           nw cm         nw  nm  
         if(mp[cm][nw] < mp[cm][cw] && wp[nw][cm] < wp[nw][nm])
         {
             return false;
         }

         //f the new man prefers the current woman to his partner and
         //if the current woman prefers the new man to her partner
         //   nm      cw                      nm    cw         nm   nw
         //   nm    cw         nm   nw            cw   nm        cw    cm
         if(mp[nm][cw] < mp[nm][nw] && wp[cw][nm] < wp[cw][cm]  )
         {
            return false;
         }
     }
     return true;
}


int main() {
    int q[3], c = 0;
    q[0] = 0;
    while(1)
    {  
        c++;
        if(c == 3) 
        {
            print(q);
        }
        q[c] = -1;
        while(1)
        {   
          q[c]++;
          if(q[c] == 3) 
          {
            c--;   
            if(c == -1) return 0;
               continue;
            }
            if(ok(q,c) == false){
                continue;
            }else{
              break;
            }
        }
    }
    return 0;
}
