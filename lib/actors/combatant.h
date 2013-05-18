#ifndef COMBATANT_H
#define COMBATANT_H

#include <iostream>

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

	stats_set_t  stats_set() const;
  stats_set_t* mutable_stats_set();
	experience_t xp() const;
  void         increment_ct_meter();
  void         reset_ct_meter();
  speed_t      ct_meter() const;
  void      set_ct_meter(const speed_t);

  void act();

	bool operator==(const combatant_t them) const;
	bool operator!=(const combatant_t them) const;
  bool operator>(const combatant_t them)  const;
	

  private:
  name_t 			  m_char_name;
	stats_set_t 	m_stats_set;
	experience_t 	m_xp;
  speed_t       m_ct_meter;

	//skill_set_t m_skills;

};

#endif
