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
void SortedCombatantQueue::retrieveNextActor(combatant_t& next){

  maxCtMeter(next);

  while(next.ct_meter() < actionThreshold()){
    updateQueue();
    std::cout << "need to do another loop" << std::endl;
    maxCtMeter(next);
    std::cout << "maxct didn't kill it yay" << std::endl;
  }

}

void SortedCombatantQueue::updateQueue(){
  std::cout << "party" << std::endl;
  updateCombatantVectorByCt(m_internal_party_vec);
  std::cout << "enemy" << std::endl;
  updateCombatantVectorByCt(m_internal_enemy_vec);
  std::cout << "queue updated " << std::endl;
}

bool SortedCombatantQueue::sortByCt(const combatant_t& a, const combatant_t& b){
  std::cout << "sorty" << std::endl;
  std::cout << "a.ct " << a.ct_meter() << std::endl;
  std::cout << "b.ct " << b.ct_meter() << std::endl;
  std::cout << (a.ct_meter() > b.ct_meter()) << std::endl;
  return (a.ct_meter() > b.ct_meter());
}

template <class T>
void SortedCombatantQueue::updateCombatantVectorByCt(T& vec){

  for(auto& fighter: vec){
    fighter.increment_ct_meter();
  }

  std::cout << "starting sort" << std::endl;
  std::sort(vec.begin(), vec.end(), sortByCt);
  std::cout << "done with sort?" << std::endl;
}

void SortedCombatantQueue::maxCtMeter(combatant_t& next){
  if(m_internal_party_vec.front().ct_meter() >= m_internal_enemy_vec.front().ct_meter())
    next = m_internal_party_vec.front();
  else
    next = m_internal_enemy_vec.front();
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

  combatant_t meh;
  while(m_queue->battleContinues()){
    std::cout << "retrieving" << std::endl;
    m_queue->retrieveNextActor(meh);
    std::cout << "retrieval didn't kill it, either" << std::endl;
    meh.act(); 
  }
}
