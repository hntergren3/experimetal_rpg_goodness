#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>
#include <iostream>

using exp_t = uint64_t;
using level_t = uint64_t;
using hit_point_t = int64_t;
using name_t = std::string;
using speed_t = short;
using acc_t = short;
using phys_t = short;
using mag_t = short;

template <typename StatType>
void set_stat(StatType& dest_stat, StatType const& in_stat, StatType min_stat, StatType max_stat){
  if(in_stat > max_stat)
    dest_stat = max_stat;
  else if(in_stat < min_stat)
    dest_stat = min_stat;
  else
    dest_stat = in_stat;

  //std::cout << "Stat is now " << dest_stat << std::endl;
}

#endif
