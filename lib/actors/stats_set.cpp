#include "stats_set.h"

stats_set_t::stats_set_t(){
	set_phys(0);
	set_mag(0);
	set_accuracy(0);
	set_speed(0);
}

stats_set_t::stats_set_t(phys_t p, mag_t m, speed_t s, acc_t a){
	set_phys( p );
	set_mag( m);
	set_accuracy( a );
	set_speed( s );
}

speed_t stats_set_t::speed () const {
	    return m_speed;
}
acc_t stats_set_t::accuracy() const{
	    return m_accuracy;
}
phys_t stats_set_t::phys() const{
	    return m_phys;
}
mag_t stats_set_t::mag() const{
	    return m_mag;
}

void stats_set_t::set_speed(speed_t speed){
	
	    set_stat(m_speed, speed, MIN_SPEED, MAX_SPEED);
}

void stats_set_t::set_accuracy(acc_t acc){
	    set_stat(m_accuracy, acc, MIN_ACC, MAX_ACC);
}

void stats_set_t::set_phys(phys_t phys){
	    set_stat(m_phys, phys, MIN_PHYS, MAX_PHYS);
}
void stats_set_t::set_mag(mag_t mag){
	    set_stat(m_mag, mag, MIN_MAG, MAX_MAG);
}

void stats_set_t::inc_speed(speed_t amount){
	    set_speed(m_speed + amount);
}
void stats_set_t::inc_accuracy(acc_t amount){
	    set_accuracy(m_accuracy + amount);
}
void stats_set_t::inc_phys(phys_t amount){
	    set_phys(m_phys + amount);
}
void stats_set_t::inc_mag(mag_t amount){
	    set_mag(m_mag + amount);
}
void stats_set_t::dec_speed(speed_t amount){
	    set_speed(m_speed - amount);
}
void stats_set_t::dec_accuracy(acc_t amount){
	    set_accuracy(m_accuracy - amount);
}
void stats_set_t::dec_phys(phys_t amount){
	    set_phys(m_phys - amount);
}
void stats_set_t::dec_mag(mag_t amount){
	    set_mag(m_mag - amount);
}

void stats_set_t::operator=(const stats_set_t& other){
	set_phys( other.phys() );
	set_mag( other.mag() );
	set_accuracy( other.accuracy() );
	set_speed( other.speed() );
}

bool stats_set_t::operator==(const stats_set_t& other){

	return ( phys() == other.phys() && mag() == other.mag() && 
	         accuracy() == other.accuracy() && speed() == other.speed() );

}
