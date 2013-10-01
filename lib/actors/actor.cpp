#include "actor.h"
actor_t::actor_t(const std::string name, const hit_point_t max){
	m_name = name;
    m_max_hp = max;
	m_cur_hp = max;
}

hit_point_t actor_t::cur_hp() const {
	return m_cur_hp;
}

hit_point_t * actor_t::mutable_cur_hp() {
	return &m_cur_hp;
}

hit_point_t actor_t::max_hp() const {
	return m_max_hp;
}

hit_point_t * actor_t::mutable_max_hp(){
	return &m_max_hp;
}

std::string actor_t::name() const {
	//return m_name;
  return "segfault averted?";
}

void actor_t::set_max_hp(hit_point_t hp){
	if(hp < 0) return;
    set_stat(m_max_hp, hp, MIN_HP, MAX_HP);
}

void actor_t::inc_max_hp(hit_point_t amount){
    set_max_hp(m_cur_hp + amount);
}
void actor_t::dec_max_hp(hit_point_t amount){
	set_max_hp(m_cur_hp - amount);
}

void actor_t::set_cur_hp(hit_point_t hp){
	set_stat(m_cur_hp, hp, MIN_HP, m_max_hp);
}

template <class T>
void actor_t::set_stat(T& my_stat, const T in_stat, int min, int max){
	in_stat > max ? my_stat = max : my_stat = min;
	if(my_stat < min)  my_stat = min;
}

void actor_t::inc_cur_hp(hit_point_t amount){
	set_cur_hp(m_cur_hp + amount);
}
void actor_t::dec_cur_hp(hit_point_t amount){
	set_cur_hp(m_cur_hp - amount);
}

void actor_t::operator+(const hit_point_t amount){
	inc_cur_hp(amount);
}

void actor_t::operator-(const hit_point_t amount){
	dec_cur_hp(amount);
}
