#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

#include "../actors/combatant.h"
#include "../actors/enemy.h"
#include "../actors/player.h"
#include "../actors/stats_set.h"

#define CT_ACTION_THRESHOLD 1000

typedef std::vector<combatant_t> enemy_vec;
typedef std::vector<combatant_t> party_vec; 

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
    ~SortedCombatantQueue(){
    }

    boost::shared_ptr<combatant_t> retrieveNextActor(); 
    bool battleContinues() const;

  private:
    bool enemiesLeft() const;
    bool partyLeft() const;
    speed_t actionThreshold() const;
    boost::shared_ptr<combatant_t> maxCtMeter();
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
    Battle(party_vec&);
    Battle(party_vec&, enemy_vec&);
    void main_loop();

    //TODO: distribute rewards here
    ~Battle(){
       std::cout << "would divvy experience, etc, here" << std::endl;
    }

  private:

    enemy_vec generateEnemies();
    boost::shared_ptr<SortedCombatantQueue> m_queue;
};
