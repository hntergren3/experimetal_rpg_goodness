#include "combatant.h"
#include "definitions.h"

using exp_table_t = std::vector<uint64_t>;
//you end up at level 1 to start, so who cares about exp for levels 0 and 1?
static const exp_table_t exp_table{0, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

#define MAX_LEVEL 256

class player_t : public combatant_t {

  public:
    player_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m) 
      : combatant_t(name, hp, s, a, p, m)
    {
    }

    void act() override final {
      std::cout << "player action" << std::endl;
      set_ct_meter(0);
    }

	  bool increment_xp(exp_t e) { //returned bool is whether or not there's a level up waiting
      m_xp += e;
      if(not m_level == MAX_LEVEL and m_xp >= exp_table[m_level + 1])
        return true;
       else
         return false;
    }
	private:
		level_t m_level = 1;
		//equipment_set_t m_equipment;
};
