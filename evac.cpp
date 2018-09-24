#include <cstdlib>
  #include "evac.h"
  #include "EvacRunner.h"

  using namespace std;

  City *city2;
  int adjacencyMatrix[10000][10000];

  Evac::Evac(City *citie, int numCitie, int numRoads) : numCities(numCitie)
  {
    city2 = new City[numCities];

    for(int i = 0; i < numCities; i++)
    {
      for(int j = 0; j < numCities; j++)
        adjacencyMatrix[i][j] = 0;
    }

    for(int i = 0; i < numCities; i++)
    {
      for(int j = 0; j < citie[i].roadCount; j++)
      {
        int dest = citie[i].roads[j].destinationCityID;
        adjacencyMatrix[i][dest] = citie[i].roads[j].peoplePerHour;
      }
    }

    // code for copying info from citie to city2
    for (int i = 0; i < numCities; i++)
   {
     city2[i].ID = citie[i].ID;
     city2[i].x = citie[i].x;
     city2[i].y = citie[i].y;
     city2[i].population = citie[i].population;
     city2[i].evacuees = citie[i].evacuees;
     city2[i].roadCount = citie[i].roadCount;
     city2[i].roads = new Road[city2[i].roadCount];
     for (int j = 0; j < citie[i].roadCount; j++)
     {
       city2[i].roads[j].ID = citie[i].roads[j].ID;
       city2[i].roads[j].peoplePerHour = citie[i].roads[j].peoplePerHour;
       city2[i].roads[j].destinationCityID = citie[i].roads[j].destinationCityID;
     }
   }
  } // Evac()


  void Evac::evacuate(int *evacIDs, int numEvacs, EvacRoute *evacRoutes, int &routeCount)
  {
    int time = 1;
    routeCount = 0;
    int evacCityID = 0;
    int arr[numCities];
    int citiesAdjToEverything[numCities];

    int size2 = 5;
    int routes2[size2][size2];

        for(int i = 0; i < numCities; i++) {
          citiesAdjToEverything[i] = -1;
        }

        for(int numCitiesEvac = 0; numCitiesEvac < numEvacs; numCitiesEvac++) {

          for(int i = 0; i < numCities; i++) {
            arr[i] = i;
          }

          // creates the roads with everything initalized to -1
          for(int i = 0 ; i < size2; i++) {
            for(int j = 0; j < size2; j++) {
              routes2[i][j] = -1;
            }
          }

          evacCityID = evacIDs[numCitiesEvac];

          for(int i = 0 ; i < size2; i++) {
            for(int j = 0; j < size2; j++) {
              routes2[j][0] = evacCityID;
            }
          }

          for(int index = 0; index < numEvacs; index++) {
            arr[evacIDs[index]] = -1;
          }

          int source = 0;
          int i = 0;
          bool end = true;
          for(int allLayers = 0; allLayers < 2; allLayers++) {

            i = 0;
            for(int j = 0; j < size2; j++) {
              i = 0;
              end = false;
              //cout << routes[j][1] << endl;
              if(routes2[j][allLayers] != -1) {
                source = routes2[j][allLayers];
                end = true;
              }
              while(end) {
                // found something adjacent to it
                if(i == numCities) {
                  end = false;
                  break;
                }
                if(adjacencyMatrix[source][i] != 0 && arr[i] != -1 && i != evacCityID) {
                  arr[i] = -1;
                  routes2[j][allLayers + 1] = i;
                  end = false;
                }
                i++;
              }
            }
          }

          if(routes2[0][1] == -1)
            citiesAdjToEverything[evacCityID] = evacCityID;
      }


int count = 0;
  for(int i = 0; i < numCities; i++) {
    if(citiesAdjToEverything[i] != -1) {
      count++;
    }
  }

  int tempArr[numEvacs];
  int pos = 0;
  for(int i = 0; i < numCities; i++) {
    if(citiesAdjToEverything[i] != -1) {
      tempArr[pos] = i;
      pos++;
    }
    for(int j = 0; j < numEvacs; j++) {
      if(evacIDs[j] == citiesAdjToEverything[i]) {
        evacIDs[j] = -1;
      }
    }
  }


  int max = 0;
  bool firstVal = true;
  for(int i = 0; i < numEvacs; i++) {
    for(int j = 0; j < numEvacs; j++) {
      if(evacIDs[j] != -1 && firstVal) {
        max = j;
        firstVal = false;
      }
      if(evacIDs[j] != -1 && city2[evacIDs[j]].population > city2[evacIDs[max]].population) {
        max = j;
      }
    }
    tempArr[pos] = evacIDs[max];
    evacIDs[max] = -1;
    pos++;
    firstVal = true;
  }

  for(int i = 0; i < numEvacs; i++) {
    evacIDs[i] = tempArr[i];
  }

  int size = 1000;
  int routes[size][size];

  int num = 0;
  for(int numCitiesEvac = 0; numCitiesEvac < numEvacs; numCitiesEvac++) {
    evacCityID = evacIDs[numCitiesEvac];

    for(int i = 0; i < numCities; i++) {
      arr[i] = i;
    }

    // creates the roads with everything initalized to -1
    for(int i = 0 ; i < size; i++) {
      for(int j = 0; j < size; j++) {
        routes[i][j] = -1;
      }
    }

    for(int i = 0 ; i < size; i++) {
      for(int j = 0; j < size; j++) {
        routes[j][0] = evacCityID;
      }
    }

    if(num < count) {
      for(int index = 0; index < count; index++) {
        arr[tempArr[index]] = -1;
      }
    }
    else {
      for(int index = 0; index < numEvacs; index++) {
        arr[evacIDs[index]] = -1;
      }
    }

int source = 0;
int i = 0;
bool end = true;
for(int allLayers = 0; allLayers < 1; allLayers++) {

  i = 0;
  for(int j = 0; j < size; j++) {
    i = 0;
    end = false;
    if(routes[j][allLayers] != -1) {
      source = routes[j][allLayers];
      end = true;
    }
    while(end) {
      // found something adjacent to it
      if(i == numCities) {
        end = false;
        break;
      }
      if(adjacencyMatrix[source][i] != 0 && arr[i] != -1 && i != evacCityID) {
        arr[i] = -1;
        routes[j][allLayers + 1] = i;
        end = false;
      }
      i++;
    }
  }
}

int realSize = 0;
for(realSize = 0; realSize < size; realSize++) {
  if(routes[realSize][1] == -1) {
    break;
  }
}

for(int allLayers = 1; allLayers < 999; allLayers++) {

  i = 0;
  for(int j = 0; j < realSize; j++) {
    i = 0;
    end = false;
    if(routes[j][allLayers] != -1) {
      source = routes[j][allLayers];
      end = true;
    }
    while(end) {
      // found something adjacent to it
      if(i == numCities) {
        end = false;
        break;
      }
      if(adjacencyMatrix[source][i] != 0 && arr[i] != -1 && i != evacCityID) {
        arr[i] = -1;
        routes[j][allLayers + 1] = i;
        end = false;
      }
      i++;
    }
  }
}

    if(city2[evacCityID].evacuees != 0) {
      city2[evacCityID].population += city2[evacCityID].evacuees;
      city2[evacCityID].evacuees = 0;
    }

    int cap = 0;
    int spicyCheetos = 0;
    while(city2[evacCityID].population != 0) {
      for(int i = 0; routes[i][0] != -1 && routes[i][1] != -1; i++) {
        for(int j = 0; routes[i][j+1] != -1; j++) {
          spicyCheetos++;

          if(routes[i][j+1] == -1)
            break;

          if(j > 100) {
            if(city2[routes[i][j]].evacuees <= ((city2[routes[i][j]].population) * (.50))) {
              break;
            }
          }

          if(j > 400) {
            return;
          }

          if(j == 0) {
            for(int index = 0; index < city2[routes[i][j]].roadCount; index++) {
              if(city2[routes[i][j]].roads[index].destinationCityID == routes[i][j+1]) {
                cap = city2[routes[i][j]].roads[index].peoplePerHour;
                  if(city2[routes[i][j]].population < cap) {
                    cap = city2[routes[i][j]].population;
                  }
                  if(city2[routes[i][j+1]].population < cap) {
                    cap = city2[routes[i][j+1]].population;
                  }
                  if (city2[routes[i][j+1]].evacuees + cap <= city2[routes[i][j+1]].population) {
                    city2[routes[i][j+1]].evacuees += cap;
                    city2[routes[i][j]].population -= cap;
                    evacRoutes[routeCount].time = time;
                    evacRoutes[routeCount].numPeople = cap;
                    evacRoutes[routeCount].roadID = city2[routes[i][j]].roads[index].ID;
                    routeCount++;
                  }
                }
              }
            }
            else if(j > 0 && routes[i][j] != -1 && routes[i][j+1] != -1) {
              for(int index = 0; index < city2[routes[i][j]].roadCount; index++) {
                if(city2[routes[i][j]].roads[index].destinationCityID == routes[i][j+1]) {
                  cap = city2[routes[i][j]].roads[index].peoplePerHour;
                  if(city2[routes[i][j]].evacuees < cap) {
                    cap = city2[routes[i][j]].evacuees;
                  }
                  if(city2[routes[i][j+1]].population < cap) {
                    cap = city2[routes[i][j+1]].population;
                  }
                  if (city2[routes[i][j+1]].evacuees + cap <= city2[routes[i][j+1]].population) {
                    city2[routes[i][j+1]].evacuees += cap;
                    city2[routes[i][j]].evacuees -= cap;
                    evacRoutes[routeCount].time = time;
                    evacRoutes[routeCount].numPeople = cap;
                    evacRoutes[routeCount].roadID = city2[routes[i][j]].roads[index].ID;
                    routeCount++;
                  }
                }
              }
            }
          }
        }
        time++;
      }

        for(int i = 0 ; i < size; i++) {
          for(int j = 0; j < size; j++) {
            routes[i][j] = -1;
          }
        }

        for(int i = 0; i < numCities; i++) {
          arr[i] = i;
        }

        num++;
    }
} // evacuate
