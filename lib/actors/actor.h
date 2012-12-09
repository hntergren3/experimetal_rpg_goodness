#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "definitions.h"

#define MAX_HP 1000000 //1 million
#define MIN_HP 100

class actor_t {
	public:
	    actor_t(const std::string name, const hit_point_t max){
			m_name = name;
            m_max_hp = max;
			m_cur_hp = max;
		}

		actor_t(const actor_t& rhs){
			m_name = rhs.m_name;
			m_max_hp = rhs.m_max_hp;
			m_cur_hp = m_cur_hp;
		}

		hit_point_t get_cur_hp() const {
			return m_cur_hp;
		}

		hit_point_t get_max_hp() const {
			return m_max_hp;
		}

		std::string get_name() const {
			return m_name;
		}

		void set_max_hp(hit_point_t hp){
			if(hp < 0) return;

			hp > MAX_HP ? m_max_hp = MAX_HP : m_max_hp = hp;
           
            if(m_max_hp < MIN_HP)
				m_max_hp = MIN_HP;

			if(m_max_hp < m_cur_hp)
				m_cur_hp = m_max_hp;
		}

		void inc_max_hp(hit_point_t amount){
            set_max_hp(m_cur_hp + amount);
		}
		void dec_max_hp(hit_point_t amount){
			set_max_hp(m_cur_hp - amount);
		}

        void set_cur_hp(hit_point_t hp){
			hp > m_max_hp ? m_cur_hp = m_max_hp : m_cur_hp = hp;
			if(m_cur_hp < 0) 
				m_cur_hp = 0;

		}

        template <class T>
		void set_stat(T& my_stat, const T in_stat, int min, int max){
			in_stat > max : my_stat = max : my_stat = min;
			my_stat < min : my_stat = min : return;
	    }

		void inc_cur_hp(hit_point_t amount){
			set_cur_hp(m_cur_hp + amount);
		}
		void dec_cur_hp(hit_point_t amount){
			set_cur_hp(m_cur_hp - amount);
		}

		void operator+(const hit_point_t amount){
			inc_cur_hp(amount);
		}

		void operator-(const hit_point_t amount){
			dec_cur_hp(amount);
		}

	private:
	    std::string m_name;
        hit_point_t m_max_hp;
		hit_point_t m_cur_hp;
};

#endif
