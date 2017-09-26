/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    17/09/2017 20:16*/
/* P-Name:  Timer           */
/****************************/

#include "TimerController.h"

TimerController::TimerController()
 : Timer::Timer(0, [](Timer *timer) { }, false), m_cached_size(0) {
		name = "ThreadController ";
		name = name + id;
}

/*
	ThreadController run() (cool stuf)
*/
void TimerController::run(){
	// Run this thread before
	if(m_handler != NULL)
		m_handler(this);

	unsigned long time = millis();
  for(int i(0); i<m_timers.size(); ++i)
  {
			if(m_timers[i]->shouldRun(time)){
				m_timers[i]->run();
			}
	}

	// ThreadController extends Thread, so we should flag as runned thread
	runned();
}


/*
	List controller (boring part)
*/
bool TimerController::add(Timer* timer){
	// Check if the Thread already exists on the array
  for(int i(0); i<m_timers.size(); ++i)
  {
		if(m_timers[i] != NULL && m_timers[i]->id == timer->id)
			return true;
	}

  // Add
  m_timers.push_back(timer);

	return false;
}

void TimerController::remove(int id){
  std::vector<Timer*>::iterator it;

  for( it=m_timers.begin() ; it < m_timers.end(); ) {
      if ( (*it)->id == id) {
        it = m_timers.erase(it);
        break;
      } else {
        ++it;
      }
  }
}

void TimerController::remove(Timer* timer){
	remove(timer->id);
}

void TimerController::clear(){
	m_timers.clear();
}

int TimerController::size(){
	return m_timers.size();
}
