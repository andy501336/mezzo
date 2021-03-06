/**
 * modification:
 *   add the access ports to originals, destinations, routes, odpairs
 *
 * Xiaoliang Ma 
 * last change: 2007-07-20 
 */

#ifndef NETWORK_HH
#define NETWORK_HH

//#undef _NO_GUI
//#define _DEBUG_NETWORK
//#define _DEBUG_SP // shortest path routines
#define _USE_VAR_TIMES   // variable link travel times



// standard template library inclusions

#include <vector>
#include <fstream>
#include <string>


//inclusion of parameter constants
#include "parameters.h"


//inclusion of label-correcting shortest path algorithm
#include "Graph.h"


// Mezzo inclusions
#include "server.h"
#include "link.h"
#include "node.h"
#include "sdfunc.h"
#include "turning.h"
#include "route.h"
#include "od.h"
#include "icons.h"
#include "vtypes.h"
#include "linktimes.h"
#include "eventlist.h"
#include "trafficsignal.h"
#include "busline.h"

// inclusions for the GUI
#ifndef _NO_GUI
//Added by qt3to4:
#include <QPixmap>
#include <Qt3Support> // new in QT4 to port from QT3
//#include <qpixmap.h>
#endif // _NO_GUI

//include the PVM communicator
#ifdef _PVM
#include "pvm.h"
#endif // _PVM

// Or include the VISSIMCOM communicator
#ifdef _VISSIMCOM
#include "vissimcom.h"
#endif //_VISSIMCOM

using namespace std;
class TurnPenalty;
class Incident;

class ODRate
{
  public:
  	odval odid;
  	int rate;
};


class ODSlice
{
	public:
		vector <ODRate> rates;	
};


class  ODMatrix
{
 	public:
	ODMatrix ();
	void add_slice(double time, ODSlice* slice);
 	private:
 		vector < pair <double,ODSlice*> > slices;	

};

class MatrixAction: public Action
{
 public:
 		MatrixAction(Eventlist* eventlist, double time, ODSlice* slice_, vector<ODpair*> *ods_);
      bool execute(Eventlist* eventlist, double time);
 private:
 	ODSlice* slice;
    vector <ODpair*> * ods;
};


class Network
{
  public:
  Network();
  ~Network();
  bool readmaster(string name); // reads the master file.
#ifndef _NO_GUI
  double executemaster(QPixmap * pm_, QMatrix * wm_); // starts the scenario, returns total running time
   double get_scale() {return scale;} // returns the scale of the drawing
#endif //_NO_GUI
  double executemaster(); // without GUI
  double step(double timestep); // executes one step of simulation, called by the gui, returns current value of time
  bool writeall();
  bool readnetwork(string name); // reads the network and creates the appropriate structures
  bool init(); // creates eventlist and initializes first actions for all turnings at time 0 and starts the Communicator
  bool init_shortest_path(); // builds the shortest path graph
  vector<Link*> get_path(int destid); //gives the links on the shortest path to destid (from current rootlink)
  bool shortest_paths_all(); // calculates shortest paths and generates the routes
  bool shortest_alternatives_all (int lid, double penalty); // finds the alternative paths 'without' link lid.
  void delete_spurious_routes(); // deletes all routes that have no OD pair.
  void renum_routes (); // renumerates the routes, to keep a consecutive series after deletions & additions
  bool run(int period); // RUNS the network for 'period' seconds
  bool addroutes (int oid, int did, ODpair* odpair); // adds routes to an ODpair
  bool add_od_routes()	; // adds routes to all ODpairs
  bool readinput(string name);  // reads the OD matrix and creates the ODpairs
  bool readlinktimes(string name); // reads historical link travel times
  bool setlinktimes();
  bool readpathfile(string name); // reads the routes
  bool readincidentfile(string name); // reads the file with the incident (for now only 1)
  bool writepathfile (string name); // appends the routes found to the route file
  bool writeoutput(string name); // writes detailed output, at this time theOD output!
  bool writesummary(string name); // writes the summary of the OD output
  bool writelinktimes(string name); //writes average link traversal times.
  bool writeheadways(string name); // writes the timestamps of vehicles entering a Virtual Link (i e Mitsim).
            //same format as historical times read by readlinktimes(string name)
  bool register_links();//registers the links at the origins and destinations
  void set_incident(int lid, int sid, bool blocked); // sets the incident on link lid (less capacity, lower max speed)
  void unset_incident(int lid); // restores the incident link to its normal behaviour
  void broadcast_incident_start(int lid); // informs the vehicles on the links of the incident on link lid
  void broadcast_incident_stop(int lid); // informs the vehicles that the incident on link lid has been cleared
  bool readturnings(string name); // reads the turning movements
  void create_turnings();          // creates the turning movements
  bool writeturnings(string name);  // writes the turing movements
  bool writemoes(); // writes all the moes: speeds, inflows, outflows, queuelengths and densities per link
  bool writeallmoes(string name); // writes all the moes in one file.
  bool writeassmatrices(string name); // writes the assignment matrices
  bool write_v_queues(string name); // writes the virtual queue lengths

  bool readassignmentlinksfile(string name); // reads the file with the links for which the assignment matrix is collected
  
  bool readvtypes (string name); // reads the vehicles types with their lentghs and percentages.
  bool readvirtuallinks(string name); // reads the virtual links that connect boundary out nodes to boundary in nodes.
  bool readserverrates(string name); // reads in new rates for specified servers. This way server capacity can be variable over time for instance for exits.
  bool readsignalcontrols(string name); // reads the signal control settings
  void seed (long int seed_) {randseed=seed_; vehtypes.set_seed(seed_);}          // sets the random seed
  
  void recenter_image();   // sets the image in the center and adapts zoom to fit window
  void redraw(); // redraws the image

 // access ports 
  Parameters* get_parameters () {return theParameters;} 
  vector <ODpair*>& get_odpairs () {return odpairs;}
  vector <Origin*>& get_origins(){return origins;}
  vector <Destination*>& get_destinations(){return destinations;}

  double calc_diff_input_output_linktimes (); // calculates the sum of the differences in output-input link travel times
  double calc_sumsq_input_output_linktimes (); // calculates the sum square of the differences in output-input link travel times

// Public transport
  bool readbusroutes(string name); // reads the busroutes, similar to readroutes
  bool readbusroute(istream& in); // reads a busroute
  bool readbuslines(string name); // reads the busstops, buslines, and trips
  bool readbusstop (istream& in); // reads a busstop
  bool readbusline(istream& in); // reads a busline
  bool readbustrip(istream& in); // reads a trip
#ifndef _NO_GUI
  double get_width_x() {return width_x;} // returns image width in original coordinate system
  double get_height_y() {return height_y;} // ... height ...
   void set_background (string name) {if (drawing) drawing->set_background(name.c_str());}
#endif // _NO_GUI 
  protected:

  vector <Node*> nodes;
  vector <Origin*> origins;
  vector <Destination*> destinations;
  vector <Junction*> junctions;
  vector <BoundaryOut*> boundaryouts;
  vector <BoundaryIn*> boundaryins;
  vector <Link*> links;
  vector <Sdfunc*> sdfuncs;
  vector <Turning*> turnings;
  vector <Server*> servers;
  vector <Route*> routes;	
  vector <ODpair*> odpairs;
  vector <Incident*> incidents;
  vector <VirtualLink*> virtuallinks;
  vector <double> incident_parameters; // yes this is very ugly, as is the web of functions added, but I'll take them out asap
  vector <Stage*> stages;
  vector <SignalPlan*> signalplans;
  vector <SignalControl*> signalcontrols;
  // Public Transport
  vector <Busline*> buslines; // the buslines that generate bus trips on busroutes, serving busstops
  vector <Bustrip*> bustrips;  // the trips list of all buses
  vector <Busstop*> busstops; // stops on the buslines
  vector <Busroute*> busroutes; // the routes that buses follow
  //Shortest path graph
#ifndef _USE_VAR_TIMES
  Graph<double, GraphNoInfo<double> > * graph;
#else
  Graph<double, LinkTimeInfo > * graph;
#endif
  // Random stream
  Random* random;
//GUI
#ifndef _NO_GUI
 Drawing* drawing; // the place where all the Icons live
 QPixmap* pm; // the place where the drawing is drawn
 QMatrix * wm; // worldmatrix that contains all the transformations of the drawing (scaling, translation, rotation, &c)
 double scale; // contains the scale of the drawing
 double width_x; // width of boundaries of drawing in original coordinate system
 double height_y; // height of boundaries of drawing in org. coord. sys.
#endif // _NO_GUI
  // Eventlist
  Eventlist* eventlist;
  // start of read functions
  bool readincidents(istream& in);
  bool readincident(istream & in);
  bool readincidentparams (istream &in);
  bool readincidentparam (istream &in);
  bool readx1 (istream &in);
  bool readtimes(istream& in);
  bool readtime(istream& in);
  bool readnodes(istream& in);
  bool readnode(istream& in);
  bool readsdfuncs(istream& in);
  bool readsdfunc(istream& in);
  bool readlinks(istream& in);
  bool readlink(istream& in);
  bool readservers(istream& in);
  bool readserver(istream& in);
  bool readturning(istream& in);
  bool readroutes(istream& in);
  bool readroute(istream& in);
  bool readods(istream& in);
  bool readod(istream& in, double scale=1.0);
  bool readvtype (istream & in);
  bool readvirtuallink(istream & in);
  bool readrates(istream & in);
  ODRate readrate(istream& in, double scale);
  bool readserverrate(istream& in);
  bool readsignalcontrol(istream & in);
  bool readsignalplan(istream& in, SignalControl* sc);
  bool readstage(istream& in, SignalPlan* sp);
  bool readparameters(string name);
  // end of read functions
   vector <string> filenames; // filenames for input/output as read in the master file
   int runtime; // == stoptime
   int starttime;
   bool calc_paths; // if true new shortest paths are calculated and new paths added to the route file
   double time;
   int no_ass_links; // number of links observed in assignment matrix
   // Linktimes
   int nrperiods; // number of linktime periods
   double periodlength; // length of each period in seconds.
   LinkTimeInfo* linkinfo;
   // Turning penalties
   vector <TurnPenalty*> turnpenalties;
   // Vehicle types
   Vtypes vehtypes;
   // PVM communicator
#ifdef _PVM   
   PVM * communicator;
   int friend_id;
#endif // _NO_PVM 
#ifdef _VISSIMCOM
   VISSIMCOM * communicator;
   string vissimfile;
#endif // _VISSIMCOM
   // ODMATRIX
   ODMatrix odmatrix;
};

class Incident: public Action
{
  public:
  		Incident (int lid_, int sid_, double start_, double stop_,double info_start_,double info_stop_, Eventlist* eventlist, Network* network_, bool blocked_);
  		bool execute(Eventlist* eventlist, double time);
  private:
       double start;
       double stop;
       double info_start;
       double info_stop;
       int lid;
       int sid;
       Network* network;
       bool blocked;
};

class TurnPenalty
{
  public:
  int from_link;
  int to_link;
  double cost;
};



#endif
