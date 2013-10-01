#include "battle.h"

void defeat(){
  std::cout << "You lose.";
}

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
 //i am going to cs hell for passing a reference to a pointer
void SortedCombatantQueue::retrieveNextActor(combatant_t *& next){

  maxCtMeter(next);
  while(next->ct_meter() < actionThreshold()){
    updateQueue();
    maxCtMeter(next);
  }

}

void SortedCombatantQueue::updateQueue(){
  updateCombatantVectorByCt(m_internal_party_vec);
  updateCombatantVectorByCt(m_internal_enemy_vec);
}

bool SortedCombatantQueue::sortByCt(const combatant_t& a, const combatant_t& b){
  std::cout << (a.ct_meter() > b.ct_meter()) << std::endl;
  return (a.ct_meter() > b.ct_meter());
}

template <class T>
void SortedCombatantQueue::updateCombatantVectorByCt(T& vec){

  for(auto& fighter: vec){
    fighter.increment_ct_meter();
  }

  std::sort(vec.begin(), vec.end(), sortByCt);
}

void SortedCombatantQueue::maxCtMeter(combatant_t *& next){
  if(m_internal_party_vec.front().ct_meter() >= m_internal_enemy_vec.front().ct_meter())
    next = &m_internal_party_vec.front();
    //next = &m_internal_party_vec[0];
  else
    //next = &m_internal_enemy_vec[0];
    next = &m_internal_enemy_vec.front();
  next->ct_meter();
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

Battle::Battle(party_vec& p, enemy_vec& e)
: m_party_vec_ptr(&p)
, m_enemy_vec_ptr(&e)
, m_queue(std::make_shared<SortedCombatantQueue>(p, e))
{
}

void Battle::main_loop(){

  combatant_t* meh = nullptr;
  while(m_queue->battleContinues()){
    m_queue->retrieveNextActor(meh);
    (*meh).act(); 
  }
}
