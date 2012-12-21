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

bool combatant_t::operator==(const combatant_t them) const{
	return (this->name() == them.name() && this->max_hp() == them.max_hp() && 
	        this->cur_hp() == them.cur_hp() && this->m_stats_set == them.stats_set());
}
bool combatant_t::operator!=(const combatant_t them) const{
	return *this == them;
}
