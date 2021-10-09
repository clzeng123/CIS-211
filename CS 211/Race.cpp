#include <iostream>
using namespace std;


void scoring(string input)
{
  //TODO
  // detect the error condition
  // (1) create an array of 26 int 0
   //int teams[26] = {0}; 
  // (2) read the input, + 1 at the letter location(loop)
  // (3) count the letter > 0 are same or not (loop)
   int totalTeam= 0;
   int teams[26] = {0}; 
   
   // count the team member on each team
   for(int i = 0; i < input.length(); i++)
   {   
      teams[input[i] -'A']++;
   } 
   
   // find the total team
   for(int k = 0; k < 26; k++)
   {
     if(teams[k] > 0){
       totalTeam ++;
     }
   }
  
  // find the repeate runner size for later comparesion
   int runners = 0;
   for(int j = 0; j < 26; j++){
     if(teams[j] > 0 && teams[j] != teams[j+1]){
       runners = teams[j];
     }
   }

   // compare each team whatever have same number of people.
    for(int m = 0; m < 26;  m++){
      if(teams[m] > 0 && teams[m]!= runners)
      {
        cout << "the teams does not have same number of runner." << endl;
        return;
      }
    }
  //TODO;
  // print the scoring of each team
  // (1) create an array of 26 int 0 for scores
  // calculate the total finish place.
   int totalFinsihPlace[26] = {0};
   for(int n = 0; n < input.length(); n++){
      totalFinsihPlace[input[n]- 'A'] += n + 1;
   }
   
   cout << "There are" << " " << totalTeam << " " <<"teams." << endl << endl;
   cout << "Each team has" << " " << runners << " "<< "runners." << endl << endl;;
  // calculate total team score.
   double teams_scores[26] = {0};
   for(int p = 0; p < 26; p++){
       teams_scores[p] += (float)((int)((totalFinsihPlace[p]/(runners * 1.0))*100))/100;
   }
     
   cout << "Team \t" << "Score" << endl ;  
   for(int x = 0; x < 26; x++)
   {
      if(teams[x] > 0){
        cout << (char) (x + 'A') << "\t\t" <<  teams_scores[x] << endl;
      }
   }
   
  cout << "\n";
  // find the team that has max socre and print it out
  double min =  teams_scores[0];
  for(int t = 1; t < 26; t++)
  {
     if(teams_scores[t] > 0){
        if(teams_scores[t] < min){
          min = teams_scores[t];
        }
     }
     if(t == 25){
       cout << "The winning team is team" << " "<< (char) (t + 'A') <<" "<<"with a score of "<< min <<"." <<endl;  
     }
  } 
}
  
int main() 
{
  //string input = "ZBZABBZBAABB";
  string input = "ZZAZAA";
  scoring(input);
  return 0;
}

