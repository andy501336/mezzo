// At this moment the standard time headway server creates N(mu,sd) distributed headways which are
// to be bigger than min_hdway. In the case the random draw generates a number smaller than min_hdway,
// the min_hdway value is returned.  I wonder how this affects the randomness and the spread
// of the generated numbers. Maybe a redraw would be better.
//
// The random number generator is initialised and randomised at the creation of the object


#ifndef SERVER_HH
#define SERVER_HH

#include "eventlist.h"
#include "Random.h"
#include "parameters.h"

// #define _DEBUG_SERVERS // uncomment to output debug info for servers

/*******************************************************************************
THis class defines the random time-headway servers that are used throughout the 
program. This means that any optimisation should start here :-)

Also, for the fun of it I'll start here to get things slightly correct, regarding
the c++ programming style. to do:
1. get const-correctness for both data members and functions
2. inspector functions are const as well.
3. put in try-catch bocks to get exceptions. Maybe not here though (performance)

Of course this will need to be done everywhere (when I have some months of spare time)
*******************************************************************************/



class Server  // standard n(mu,sd2) server  type: 1
{
  public:
  Server(const int id_, const int type_, const double mu_, const double sd_, const double delay_);
  virtual ~Server();
  const int get_id() const;
  virtual  double next(const double time);
  const double get_mu() const;
	void set_mu(const double mu_);
	const double get_sd() const;
	void set_sd(const double sd_);
	const double get_delay () {return delay;}
  protected:
  Random* random;
  
  int id;
  int type; // dummy, later more subclasses of server
  double mu;
  double sd;
  double delay;
};

class ConstServer : public Server // constant server that copies input to output  type: 0
/*
   after every successfull action directly a new action at the same time is performed with
	0 delay, untill all vehicles in the incoming link that have arrived at the end are processed and
	the next time is taken from the next vehicle to arrive at the stopline.
*/
{
	public:
		ConstServer(const int id_, const int type_, const double mu_, const double sd_, const double delay_):Server(id_,type_,mu_,sd_,delay_) {}		
		double next(const double time) {return time;}
} ;

class ODServer : public Server
/* specially designed for generating OD demand
	neg exponential.
*/
{
	public:
		ODServer(const int id_, const int type_, const double mu_, const double sd_);
		double next(const double time);
		void set_rate(double mu_, double sd_) {mu=mu_; sd=sd_;}
	private:
		
};


class DetServer : public Server
/* Delivers deterministic service time
  */
{
public:
	DetServer (const int id_, const int type_, const double mu_, const double sd_, const double delay_) :
		Server (id_,type_,mu_,sd_,delay_) {}
	double next (const double time) {return time+mu+delay;}
};

class OServer : public Server
/* specially designed for input flows. Designed to be a combination of a N(mu,sd) and EXP(beta) server,
	: output=alpha(N(mu_bound,sd_bound)) + (1-alpha)Exp(mu_unbound)
	- alpha: proportion of carfollowing headways
	- 1-alpha: proportion of non carfollowing headways
	- mu= alpha*mu_bound+(1-alpha)mu_unbound
	- 1 O server per lane!
*/

{
	public:
		OServer(const int id_, const int type_, const double mu_, const double sd_);
		double next(const double time);
		void set_lanes(double l) {lanes=l;}
		double get_lanes() {return lanes;}
	protected:
		double alpha;  // proportion of cars in carfollowing
		double mu_unbound; // mu for the unbound traffic, calculated from (mu-alpha*cf_hdway)/(1-alpha)
		double lanes;

};

class ChangeRateAction: public Action
// This class changes the rate of a server, once it's 'time' has come in the eventlist.

{
	public:
		ChangeRateAction (Eventlist* eventlist, double time, Server* server_, double mu_, double sd_);
		bool execute(Eventlist* eventlist, double time);
	private:
		Server* server;
		double mu, sd;
};


#endif

