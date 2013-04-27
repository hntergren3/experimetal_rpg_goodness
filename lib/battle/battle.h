#include <boost/noncopyable.hpp>
#include "../actors/combatant.h"
#include "../actors/enemy.h"
#include "../actors/stats_set.h"

#define CT_ACTION_THRESHOLD 1000

typedef std::vector<Combatant> enemy_vec;
typedef std::vector<Combatant> party_vec; 

/*
 * SortedCombatantTree takes the party and enemy
 * vectors by reference. Whether or not the
 * Good Guys are healed after every battle or not,
 * that's handled by the Battle class. There's 
 * no point in doing a second copy, even if 
 * the number of party members and enemies we're
 * dealing with will probablybe pretty small.
 */

class SortedCombatantQueue : boost::noncopyable {

  public:

    SortedCombatanQueue(party_vec p, enemy_vec e);
    ~SortedCombatantQueue();

    boost::shared_ptr<Combatant> retrieveNextActor(); 
    bool battleContinues();

  private:
    bool enemiesLeft();
    bool partyLeft();
    speed_t actionThreshold();
    boost::shared_ptr<Combatant> maxCtMeter();
    template <class T>
    void updateCombatantVectorByCt(T&);
    bool sortByCt(Combatant&, Combatant&);

    enemy_vec m_internal_enemy_vec;
    party_vec m_internal_party_vec; 

    speed_t   m_action_threshold; 
};

class Battle : boost::noncopyable{
  public:
    Battle(party_vec&);
    ~Battle(); //distribute rewards!

  private:
    boost::shared_ptr<SortedCombatantQueue> m_queue;
};
