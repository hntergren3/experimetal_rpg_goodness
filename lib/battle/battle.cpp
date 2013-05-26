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
boost::shared_ptr<combatant_t> SortedCombatantQueue::retrieveNextActor(){
  while(maxCtMeter()->ct_meter() < actionThreshold()){
    updateQueue();
  }

  return maxCtMeter();

}

void SortedCombatantQueue::updateQueue(){
  updateCombatantVectorByCt(m_internal_party_vec);
  updateCombatantVectorByCt(m_internal_enemy_vec);
}

bool SortedCombatantQueue::sortByCt(const combatant_t& a, const combatant_t& b){
  return (a.ct_meter() > b.ct_meter());
}

template <class T>
void SortedCombatantQueue::updateCombatantVectorByCt(T& vec){

  for(typename T::iterator it = vec.begin(); it != vec.end(); it++){
    it->increment_ct_meter();
  }

  std::sort(vec.begin(), vec.end(), sortByCt);
}

boost::shared_ptr<combatant_t> SortedCombatantQueue::maxCtMeter(){

  boost::shared_ptr<combatant_t> retChar;

  if(m_internal_enemy_vec[0].ct_meter() > m_internal_party_vec[0].ct_meter()){
    retChar.reset(&m_internal_enemy_vec[0]);
  }
  else {
    retChar.reset(&m_internal_party_vec[0]);
  }

  return retChar;

}

speed_t SortedCombatantQueue::actionThreshold() const{
  return m_action_threshold;
}

bool SortedCombatantQueue::enemiesLeft() const{
  return !m_internal_enemy_vec.empty();
}

bool SortedCombatantQueue::partyLeft() const{
  return !m_internal_party_vec.empty();
}

bool SortedCombatantQueue::battleContinues() const{
  return (enemiesLeft() && partyLeft());
}

Battle::Battle(party_vec& p){
  m_queue.reset(new SortedCombatantQueue(p, generateEnemies()));
}

Battle::Battle(party_vec& p, enemy_vec& e){
  m_queue.reset(new SortedCombatantQueue(p, e));
}

enemy_vec Battle::generateEnemies(){

  enemy_vec e;
  enemy_t placeholder("Gob", 1, 1, 1, 1, 1);
  e.push_back(placeholder);
  return e;

}

void Battle::main_loop(){

  while(m_queue->battleContinues()){
    m_queue->retrieveNextActor()->act(); 
  }
}
