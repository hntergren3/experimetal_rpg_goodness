#ifndef STATS_SET_H
#define STATS_SET_H

#define MIN_STAT 10
#define MAX_STAT 1000

#include "definitions.h"

class stats_set_t{
	public:

		stats_set_t();
		stats_set_t(phys_t, mag_t, speed_t, acc_t);
		stats_set_t(const stats_set_t&);
		~stats_set_t();

		speed_t speed () const ;
		acc_t accuracy() const;
		phys_t phys() const;
		mag_t mag() const;

        template <class T>
		void set_stat(T& my_stat, const T in_stat, int min, int max);

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

		void operator=(const stats_set_t& other);
		bool operator==(const stats_set_t& other);
	private:
		speed_t m_speed;
		acc_t m_accuracy;
		phys_t m_phys;
		mag_t m_mag;
};

#endif
