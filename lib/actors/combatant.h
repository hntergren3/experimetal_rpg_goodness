#ifndef COMBATANT_H
#define COMBATANT_H

#include "actor.h"
#include "definitions.h"

#define MAX_STAT 1000
#define MIN_STAT 10

class combatant_t : public actor_t {

  public:
    combatant_t();
	combatant_t(std::string name);
	combatant_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m);
	~combatant_t();
	combatant_t(const combatant_t& other);
	
	speed_t speed () const ;
	acc_t accuracy() const;
	phys_t phys() const;
	mag_t mag() const;
	experience_t xp() const;

	void set_speed(speed_t speed);
	void set_accuracy(acc_t acc);
	void set_phys(phys_t phys);
	void set_mag(mag_t mag);

	void inc_speed(speed_t amount);
	void inc_accuracy(acc_t amount);
	void inc_phys(phys_t amount);
	void inc_mag(mag_t amount);

	void dec_speed(speed_t amount);
	void dec_accuracy(acc_t amount);
	void dec_phys(phys_t amount);
	void dec_mag(mag_t amount);
	bool operator==(const combatant_t them) const;
	bool operator!=(const combatant_t them) const;
	

  private:
    name_t m_char_name;
    speed_t m_speed;
	acc_t m_accuracy;
	phys_t m_phys;
	mag_t m_mag;
	experience_t m_xp;

	//skill_set_t m_skills;

};

#endif
