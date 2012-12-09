#include "combatant.h"

combatant_t::combatant_t() : actor_t(" ", 1) {
	set_speed(0);
	set_accuracy(0);
	set_phys(0);
	set_mag(0);
}

combatant_t::combatant_t(std::string name) :
actor_t(name, 1)
{
	set_speed(0);
	set_accuracy(0);
	set_phys(0);
	set_mag(0);
}

combatant_t::combatant_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m)
: actor_t(name, hp) {
	set_speed(s);
	set_accuracy(a);
	set_phys(p);
	set_mag(m);
}

combatant_t::combatant_t(const combatant_t& other)
: actor_t(other.name(), other.max_hp())
{
	m_speed = other.m_speed;
	m_accuracy = other.m_accuracy;
	m_phys = other.m_phys;
	m_mag = other.m_mag;
}
	
speed_t combatant_t::speed () const {
	return m_speed;
}
acc_t combatant_t::accuracy() const{
	return m_accuracy;
}
phys_t combatant_t::phys() const{
	return m_phys;
}
mag_t combatant_t::mag() const{
	return m_mag;
}
experience_t combatant_t::xp() const{
	return m_xp;
}

void combatant_t::set_speed(speed_t speed){

	set_stat(m_speed, speed, MIN_STAT, MAX_STAT);
}

void combatant_t::set_accuracy(acc_t acc){
	set_stat(m_accuracy, acc, MIN_STAT, MAX_STAT);
}

void combatant_t::set_phys(phys_t phys){
	set_stat(m_phys, phys, MIN_STAT, MAX_STAT);
}
void combatant_t::set_mag(mag_t mag){
	set_stat(m_mag, mag, MIN_STAT, MAX_STAT);
}

void combatant_t::inc_speed(speed_t amount){
	set_speed(m_speed + amount);
}
void combatant_t::inc_accuracy(acc_t amount){
	set_accuracy(m_accuracy + amount);
}
void combatant_t::inc_phys(phys_t amount){
	set_phys(m_phys + amount);
}
void combatant_t::inc_mag(mag_t amount){
	set_mag(m_mag + amount);
}

void combatant_t::dec_speed(speed_t amount){
	set_speed(m_speed - amount);
}
void combatant_t::dec_accuracy(acc_t amount){
	set_accuracy(m_accuracy - amount);
}
void combatant_t::dec_phys(phys_t amount){
	set_phys(m_phys - amount);
}
void combatant_t::dec_mag(mag_t amount){
	set_mag(m_mag - amount);
}

bool combatant_t::operator==(const combatant_t them) const{
	return (this->name() == them.name() && this->max_hp() == them.max_hp() && 
	        this->cur_hp() == them.cur_hp() && this->m_speed == them.speed() &&
			this->m_accuracy == them.accuracy() && this->m_phys == them.phys() &&
			this->m_mag == them.mag());
}
bool combatant_t::operator!=(const combatant_t them) const{
	return *this == them;
}
