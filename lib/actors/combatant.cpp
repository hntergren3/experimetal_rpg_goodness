#include "combatant.h"

combatant_t::combatant_t() : actor_t("caballo sin nombre", 1) {
}

combatant_t::combatant_t(std::string name) :
actor_t(name, 1)
{
}

combatant_t::combatant_t(std::string name, hit_point_t hp, speed_t s, acc_t a, phys_t p, mag_t m)
: actor_t(name, hp) {
}

combatant_t::combatant_t(const combatant_t& other)
: actor_t(other.name(), other.max_hp())
{
	m_stats_set = other.stats_set();
}
	
experience_t combatant_t::xp() const{
	return m_xp;
}

stats_set_t combatant_t::stats_set() const{
	return m_stats_set;
}

stats_set_t * combatant_t::mutable_stats_set(){
  return &m_stats_set;
}

bool combatant_t::operator==(const combatant_t them) const{
	return (this->name() == them.name() && this->max_hp() == them.max_hp() && 
	        this->cur_hp() == them.cur_hp() && this->stats_set() == them.stats_set());
}
bool combatant_t::operator!=(const combatant_t them) const{
	return *this == them;
}

bool combatant_t::operator>(const combatant_t them) const{
  return this->ct_meter() > them.ct_meter();
}

void combatant_t::act(){
  std::cout << "my turn to act!" << std::endl;
  reset_ct_meter();
}

void combatant_t::reset_ct_meter(){
  set_ct_meter(0);
}

/*void combatant_t::set_ct_meter(const speed_t newCt){
  m_ct_meter = newCt;
}*/

void combatant_t::increment_ct_meter(){
  set_ct_meter(m_ct_meter + stats_set().speed());
}

speed_t combatant_t::ct_meter() const {
    return m_ct_meter;
}

void combatant_t::set_ct_meter(const speed_t newSpeed){
  m_ct_meter = newSpeed;
}
