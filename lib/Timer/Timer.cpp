/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    17/09/2017 20:16*/
/* P-Name:  Timer           */
/****************************/
#include "Timer.h"

Timer::Timer(unsigned long interval, std::function< void (Timer*)> handler, bool repeats)
: m_interval(0), m_last_run(0), m_cached_next_run(0), m_handler(handler), m_repeats(repeats), enabled(true), m_wasRunned(false) {

	id = (int)this;
	name = "Thread ";
	name = name + id;

	setInterval(interval);
};

void Timer::runned(unsigned long time){
	// Saves last_run
	m_last_run = time;

	// Cache next run
	m_cached_next_run = m_last_run + m_interval;

  m_wasRunned = true;
}

void Timer::setInterval(unsigned long interval){
	// Save interval
	m_interval = interval;

	// Cache the next run based on the last_run
	m_cached_next_run = m_last_run + m_interval;
}

bool Timer::shouldRun(unsigned long time){
	// If the "sign" bit is set the signed difference would be negative
	bool time_remaining = (time - m_cached_next_run) & 0x80000000;

	// Exceeded the time limit, AND is enabled? Then should run...
	return !time_remaining && enabled && (!m_repeats ? !m_wasRunned : true);
}

void Timer::setHandler(std::function< void (Timer*)> handler){
	m_handler = handler;
}

void Timer::run(){
	if(m_handler != NULL)
		m_handler(this);

	// Update last_run and _cached_next_run
	runned();
}
