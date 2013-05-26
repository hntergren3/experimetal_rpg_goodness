#include "combatant.h"

class enemy_t : public combatant_t{

  public:

    enemy_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m) 
     : combatant_t(name, hp, s, a, p, m)

     {
     }

     void act(){
     
       std::cout << "I am an enemy acting." << std::endl;
       dec_cur_hp(10); //to ensure test battle actually ends, since no one can do damage
     
     }

    private:
	    //item_drop_t items;

};
