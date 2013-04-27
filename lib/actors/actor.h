#ifndef ACTOR_H
#define ACTOR_H

//#include <string>
#include "definitions.h"

#define MAX_HP 1000000 //1 million
#define MIN_HP 100

class actor_t {
	public:
	  actor_t(const std::string name, const hit_point_t max);
		actor_t(const actor_t& rhs);

		hit_point_t cur_hp() const ;
		hit_point_t * mutable_cur_hp();
		hit_point_t max_hp() const ;
    hit_point_t * mutable_max_hp();

		std::string name() const ;

		void set_max_hp(hit_point_t hp);
		void inc_max_hp(hit_point_t amount);
		void dec_max_hp(hit_point_t amount);
    void set_cur_hp(hit_point_t hp);

        //make life easier when I want to do min/max checking...this will probably end up
		//in some kind of overall utility file at some point, though then I'll have to
		//provide ways to get a references for various values instead of just values...bleh
    template <class T>
		void set_stat(T& my_stat, const T in_stat, int min, int max);

		void inc_cur_hp(hit_point_t amount);
		void dec_cur_hp(hit_point_t amount);

        //Not sure how I feel about this...might make more sense in code to say
		//actor + # and then let these overloads worry about calling the right
		//functions...we'll see
		void operator+(const hit_point_t amount);
		void operator-(const hit_point_t amount);

	private:
	    std::string m_name;
        hit_point_t m_max_hp;
		hit_point_t m_cur_hp;
};

#endif
