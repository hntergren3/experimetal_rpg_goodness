#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

#include "../actors/combatant.h"
#include "../actors/enemy.h"
#include "../actors/player.h"
#include "../actors/stats_set.h"

#define CT_ACTION_THRESHOLD 1000

#ifndef BATTLE_H
#define BATTLE_H

using party_vec = std::vector<player_t>;
using enemy_vec = std::vector<enemy_t>;
using party_vec_ptr = party_vec*;
using enemy_vec_ptr = enemy_vec*;

void defeat();

/*
 * SortedCombatantQueue takes the party and enemy
 * vectors by reference. Whether or not the
 * Good Guys are healed after every battle or not,
 * that's handled by the Battle class. There's 
 * no point in doing a second copy, even if 
 * the number of party members and enemies we're
 * dealing with will probablybe pretty small.
 */

class SortedCombatantQueue : boost::noncopyable {

  public:

    SortedCombatantQueue(party_vec p, enemy_vec e);
    ~SortedCombatantQueue() = default;

    void retrieveNextActor(combatant_t*&); 
    bool battleContinues() const;

  private:
    bool enemiesLeft() const;
    bool partyLeft() const;
    speed_t actionThreshold() const;
    void maxCtMeter(combatant_t*&);
    template <class T>
    void updateCombatantVectorByCt(T&);
    static bool sortByCt(const combatant_t&, const combatant_t&);
    void updateQueue();

    enemy_vec m_internal_enemy_vec;
    party_vec m_internal_party_vec; 

    speed_t   m_action_threshold; 
};

class Battle : boost::noncopyable{
  public:
    Battle(party_vec&, enemy_vec&);
    void main_loop();

    ~Battle(){
      if(m_victory){ //distribute rewards; would like to do the 
        for(auto const& e: *m_enemy_vec_ptr){
          //TODO: add gold to Party's coffers
          //TODO: drop items
          for(auto& p: *m_party_vec_ptr){
            p.increment_xp(e.xp());
          }
        }
      } else {
        defeat();
      }
    }

  private:

    party_vec_ptr m_party_vec_ptr = nullptr; //
    enemy_vec_ptr m_enemy_vec_ptr = nullptr;
    bool m_victory = false;
    std::shared_ptr<SortedCombatantQueue> m_queue;
};

#endif
