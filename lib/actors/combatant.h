#ifndef COMBATANT_H
#define COMBATANT_H

#include "actor.h"
#include "definitions.h"

#define MAX_STAT 1000
#define MIN_STAT 10

class combatant_t : public actor_t {

  public:
    combatant_t() : actor_t(" ", 1) {
		set_speed(0);
		set_accuracy(0);
		set_phys(0);
		set_mag(0);
	}

	combatant_t(std::string name) :
	actor_t(name, 1)
	{
		set_speed(0);
		set_accuracy(0);
		set_phys(0);
		set_mag(0);
	}

	combatant_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m)
	: actor_t(name, hp) {
		set_speed(s);
		set_accuracy(a);
		set_phys(p);
		set_mag(m);
	}

	~combatant_t();

	combatant_t(const combatant_t& other)
	: actor_t(other.get_name(), other.get_max_hp())
	{
		m_speed = other.m_speed;
		m_accuracy = other.m_accuracy;
		m_phys = other.m_phys;
		m_mag = other.m_mag;
	}
	
	speed_t get_speed () const {
		return m_speed;
	}
	acc_t get_accuracy() const{
		return m_accuracy;
	}
	phys_t get_phys() const{
		return m_phys;
	}
	mag_t get_mag() const{
		return m_mag;
	}
	experience_t get_xp() const{
		return m_xp;
	}

	void set_speed(speed_t speed){

		set_stat(m_speed, speed, MIN_STAT, MAX_STAT);
	}

	void set_accuracy(acc_t acc){
		set_stat(m_accuracy, acc, MIN_STAT, MAX_STAT);
	}

	void set_phys(phys_t phys){
		set_stat(m_phys, phys, MIN_STAT, MAX_STAT);
	}
	void set_mag(mag_t mag){
		set_stat(m_mag, mag, MIN_STAT, MAX_STAT);
	}

	void inc_speed(speed_t amount){
		set_speed(m_speed + amount);
	}
	void inc_accuracy(acc_t amount){
		set_accuracy(m_accuracy + amount);
	}
	void inc_phys(phys_t amount){
		set_phys(m_phys + amount);
	}
	void inc_mag(mag_t amount){
		set_mag(m_mag + amount);
	}

	void dec_speed(speed_t amount){
		set_speed(m_speed - amount);
	}
	void dec_accuracy(acc_t amount){
		set_accuracy(m_accuracy - amount);
	}
	void dec_phys(phys_t amount){
		set_phys(m_phys - amount);
	}
	void dec_mag(mag_t amount){
		set_mag(m_mag - amount);
	}

	bool operator==(const combatant_t them) const{
		return (this->get_name() == them.get_name() && this->get_max_hp() == them.get_max_hp() && 
		        this->get_cur_hp() == them.get_cur_hp() && this->m_speed == them.get_speed() &&
				this->m_accuracy == them.get_accuracy() && this->m_phys == them.get_phys() &&
				this->m_mag == them.get_mag());
	}
	bool operator!=(const combatant_t them) const{
		return *this == them;
	}
	

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
