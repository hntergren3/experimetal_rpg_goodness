#include "combatant.h"
#include "definitions.h"

class player_t : public combatant_t {

  public:
    player_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m) 
      : combatant_t(name, hp, s, a, p, m)
    {
    }

    void act(){
      std::cout << "player action" << std::endl;
    }

	//inc_xp
	private:
	    //experience_t m_xp;
		//level_t m_lvl;
		//equipment_set_t m_equipment;
};
