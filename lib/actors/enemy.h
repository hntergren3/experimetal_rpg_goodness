#include "combatant.h"

class enemy_t : public combatant_t{

  public:

    enemy_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m) 
     : combatant_t(name, hp, s, a, p, m)

     {
     }

     void act() override final{
     
       std::cout << name() << " is an acting enemy who has " << cur_hp() << " hp" << std::endl;
       dec_cur_hp(10); //to ensure test battle actually ends, since no one can do damage
       std::cout << name() << " now has " << cur_hp() << " hp" << std::endl;
       set_ct_meter(0);
     
     }

    private:
	    //item_drop_t items;

};
