#ifndef COMBATANT_H
#define COMBATANT_H

#include "actor.h"
#include "definitions.h"
#include "stats_set.h"
class combatant_t;

class combatant_t : public actor_t {

  public:
  combatant_t();
	combatant_t(std::string name);
	combatant_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m);
	~combatant_t();
	combatant_t(const combatant_t& other);

	stats_set_t stats_set() const;
	experience_t xp() const;
  void increment_ct();
  speed_t ct();
  void reset_ct();

  void act();

	bool operator==(const combatant_t them) const;
	bool operator!=(const combatant_t them) const;
  bool operator>(const combatant_t them) const;
	

  private:
  name_t 			  m_char_name;
	stats_set_t 	m_stats_set;
	experience_t 	m_xp;
  speed_t       m_ct_meter;

	//skill_set_t m_skills;

};

#endif
