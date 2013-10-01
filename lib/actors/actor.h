#ifndef ACTOR_H
#define ACTOR_H

//#include <string>
#include "definitions.h"

static const hit_point_t MAX_HP = 1000000; //1 mil
static const hit_point_t MIN_HP = 0;

class actor_t {
	public:
    actor_t(){
      m_name = "default";
      set_max_hp(10);
      set_cur_hp(10);
    }
	  actor_t(const std::string name, const hit_point_t max);
		actor_t(const actor_t&) = default;
    ~actor_t() = default;

		hit_point_t cur_hp() const ;
		hit_point_t * mutable_cur_hp();
		hit_point_t max_hp() const ;
    hit_point_t * mutable_max_hp();

		std::string name() const ;

		void set_max_hp(hit_point_t hp);
		void inc_max_hp(hit_point_t amount);
		void dec_max_hp(hit_point_t amount);
    void set_cur_hp(hit_point_t hp);

		void inc_cur_hp(hit_point_t amount);
		void dec_cur_hp(hit_point_t amount);

    //Not sure how I feel about this...might make more sense in code to say
		//actor + # and then let these overloads worry about calling the right
		//functions...we'll see
		void operator+(const hit_point_t amount);
		void operator-(const hit_point_t amount);
    //void operator=(const actor_t& rhs){
    //  m_name = rhs.name();
    //}
	private:
	  std::string m_name;
    hit_point_t m_max_hp;
		hit_point_t m_cur_hp;
};

#endif
