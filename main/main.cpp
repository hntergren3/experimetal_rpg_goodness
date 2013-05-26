#include "../lib/battle/battle.h"

int main(){

  party_vec p; 
  enemy_vec e;

  player_t wes("Wes", 100, 5, 5, 5, 5);
  player_t azn("Azn", 50 , 7, 7, 7, 7);
  player_t meh("Meh", 75 , 8, 8, 8, 8);

  enemy_t boss("Bossman", 300, 10, 10, 10, 10);
 
  p.push_back(wes);
  p.push_back(azn);
  p.push_back(meh);

  e.push_back(meh);

  Battle b(p, e);
  b.main_loop();

  std::cout << "Well, I compile and link correctly. Do I work? Prolly not." << std::endl;
}
