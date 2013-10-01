#include "../lib/battle/battle.h"

int main(){

  for(auto i : {1,2,3,4})
    std::cout << i << std::endl;

  party_vec p; 
  enemy_vec e;

  p.emplace_back("Wes", 100, 5, 5, 5, 5);
  p.emplace_back("Azn",  50, 7, 7, 7, 7);
  p.emplace_back("Meh",  75, 8, 8, 8, 8);

  e.emplace_back("Bossman", 300, 10, 10, 10, 10);

  Battle b(p, e);
  b.main_loop();

  std::cout << "Well, I compile and link correctly. Do I work? Prolly not." << std::endl;
}
