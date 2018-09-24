// Author: Sean Davis
#ifndef evacH
#define evacH

#include "EvacRunner.h"


class Evac
{
public:
  int numCities; // added to stop error

  Evac(City *cities, int numCities, int numRoads);
  void evacuate(int *evacIDs, int numEvacs, EvacRoute *evacRoutes, int &routeCount); // student sets evacRoutes and routeCount

}; // class Evac

class City2
{
public:
  int ID;
  int Population;
  int Evacuees;
  Road *roads;
  
  City2() : Evacuees(0), roads(NULL) {}
  ~City2() { delete [] roads; }

}; // class City2

#endif
