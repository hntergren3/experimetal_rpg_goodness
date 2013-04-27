#include "battle.h"

SortedCombatantQueue::SortedCombatantQueue(party_vec p, enemy_vec e){
  m_internal_enemy_vec = e;
  m_internal_party_vec = p;
  m_action_threshold = CT_ACTION_THRESHOLD; 
}

/*
 *assumes both that there are enemies and party members
 *left. After all, why are we still fighting if that's
 *not true?!
 */
boost::shared_ptr<Combatant> SortedCombatantQueue::retrieveNextActor(){

  while(maxCtMeter()->ct() < actionThreshold()){
    updateQueue();
  }

  return maxCtMeter();

}

void SortedCombatantQueue::updateQueue(){
  updateCombatantVectorByCt(m_internal_party_vec);
  updateCombatantVectorByCt(m_internal_enemy_vec);
}

bool SortedCombatantQueue::sortByCt(Combatant& a, Combatant& b){
  return (a.ct() > b.ct());
}

template <class T>
void SortedCombatantQueue::updateCombatantVectorByCt(T& vec){

  for(T::iterator it = vec.begin(); it != vec.end(); it++){
    it->increment_ct();
  }

  std::sort(vec.begin(), vec.end(), sortByCt);
}

boost::shared_ptr<Combatant> SortedCombatantQueue::maxCtMeter(){

  boost::shared_ptr<Combatant> retChar;

  if(m_internal_enemy_vec[0].ct() > m_internal_party_vec[0].ct()){
    retChar.reset(m_internal_enemy_vec[0]);
  }
  else {
    retChar.reset(m_internal_party_vec[0]);
  }

  return retChar;

}

speed_t SortedCombatantQueue::actionThreshold(){
  return m_action_threshold;
}

bool SortedCombatantQueue::enemiesLeft(){
  return !m_internal_enemy_vec.empty();
}

bool SortedCombatantQueue::partyLeft(){
  return !m_internal_party_vec.empty();
}

bool SortedCombatantQueue::battleContinues(){
  return (enemiesLeft() && partyLeft());
}

void Battle::main_loop(){
  while(m_queue.battleContinues()){
   m_queue.retrieveNextActor()->act(); 
  }
}
