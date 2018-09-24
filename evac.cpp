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
     //cout << "i = " << i << " cityID = " << city2[i].ID << " pop = " << city2[i].population << " evacs = " << city2[i].evacuees << endl;
     for (int j = 0; j < citie[i].roadCount; j++)
     {
       city2[i].roads[j].ID = citie[i].roads[j].ID;
       city2[i].roads[j].peoplePerHour = citie[i].roads[j].peoplePerHour;
       city2[i].roads[j].destinationCityID = citie[i].roads[j].destinationCityID;
       //cout << "j = " << j << " roadID = " << city2[i].roads[j].ID << " cap = " << city2[i].roads[j].peoplePerHour << " destCityID = " << city2[i].roads[j].destinationCityID << endl;
     }
     //cout << endl;
   }
  } // Evac()





  /*
  for(int i = 0 ; i < numCities; i++) {
    for(int j = 0; j < numCities; j++) {
      cout << routes[i][j] << ",";
    }
    cout << endl;
  }
  cout << endl;
  */
  /*
  int jVals[numCities];

  for(int i = 0; i < numCities; i++) {
    jVals[i] = 0;
  }

  for(int i = 0; i < numCities; i++) {
    for(int j = 0 ; j < numCities; j++) {
      source = false;
      for(int k = 0; k < numCities; k++) {
        if(routes[i][j] == evacIDs[k]) {
          cout << "ITS A SOURCE" << endl;
          source = true;
        }
        if(source)
          break;
      }
      if(source == false) {
        jVals[i] = j;
        break;
      }
    }
  }

  bool isSource = false;
  for(int i = 0 ; i < numCities; i++) {

  for(int j = 0; j < numCities; j++) {

    for(int k = 0; k < numEvacs; k++) {
      if(routes[i][j] == evacIDs[k]) {
        isSource = true;
        break;
      }
    }

    if(routes[i][j] != -1 && isSource) {
      cout << routes[i][j] << "**,";
    }
    else if(routes[i][j] != -1) {
      cout << routes[i][j] << ",";
    }
    isSource = false;
  }
  cout << endl;
  }
  cout << endl;

  for(int i = 0; i < numCities; i++) {
  cout << "j vals at " << i << " is " << jVals[i] << endl;
  }
  */
  /*
  int count = 0;
  for(int i = 0; i < numCities; i++) {
  for(int j = 0; j < numCities; j++) {
    if(routes[i][j] != -1)
      count++;
  }
  }

  if(count == numCities) {
  cout << "THIS CITY IS ADJACENT TO EVERYTHING " << evacCityID << endl;
  }
  count = 0;

      for(int i = 0 ; i < numCities; i++) {
        for(int j = 0; j < numCities; j++) {
          routes[i][j] = -1;
        }
      }

      for(int i = 0; i < numCities; i++) {
        arr[i] = i;
      }
  */


  /*
  if(!space) {

    space = true;

    int size = 1000;
    int routes2[size][size];
    int arr2[numCities];

    int cityToClear = routes[i][j+1];

      cout << cityToClear << endl;
      cout << city2[cityToClear].evacuees << endl;
      cout << city2[cityToClear].population << endl;

      cout << "second part" << endl;

      for(int i = 0; i < numCities; i++) {
        arr2[i] = i;
      }

      // creates the roads with everything initalized to -1
      for(int i = 0 ; i < size; i++) {
        for(int j = 0; j < size; j++) {
          routes2[i][j] = -1;
        }
      }

      for(int i = 0 ; i < size; i++) {
        for(int j = 0; j < size; j++) {
          routes2[j][0] = cityToClear;
        }
      }

      for(int index = 0; index < numEvacs; index++) {
        arr2[evacIDs[index]] = -1;
      }

      int source = 0;
      int i = 0;
      bool end = true;
      for(int allLayers = 0; allLayers < 100; allLayers++) {

        i = 0;
        for(int j = 0; j < size; j++) {
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
            if(adjacencyMatrix[source][i] != 0 && arr2[i] != -1 && i != evacCityID) {
              arr2[i] = -1;
              routes2[j][allLayers + 1] = i;
              end = false;
            }
            i++;
          }
        }
      }

      //for(int i = 0; i < numEvacs; i++) {
        //cout << evacIDs[i] << endl;
      //}


      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < size; j++) {
          cout << routes2[i][j] << ", ";
        }
        cout << endl;
      }

      int cap = 0;
      while(city2[cityToClear].evacuees != 0) {
        for(int i = 0; routes2[i][0] != -1 && routes2[i][1] != -1; i++) {
          for(int j = 0; routes2[i][j+1] != -1; j++) {

              if(routes2[i][j] != -1 && routes2[i][j+1] != -1) {
                //cout << "atleast tell me it's getting in there" << endl;
                //cout << "goes inside here too " << endl;
                for(int index = 0; index < city2[routes2[i][j]].roadCount; index++) {
                  //cout << "3" << endl;
                  if(city2[routes2[i][j]].roads[index].destinationCityID == routes2[i][j+1]) {
                    cap = city2[routes2[i][j]].roads[index].peoplePerHour;
                    if(city2[routes2[i][j]].evacuees < cap) {
                      cap = city2[routes2[i][j]].evacuees;
                    }
                    if (city2[routes2[i][j+1]].evacuees + cap <= city2[routes2[i][j+1]].population) {
                      city2[routes2[i][j+1]].evacuees += cap;
                      city2[routes2[i][j]].evacuees -= cap;
                      //if(city2[routes[i][j]].evacuees < (city2[routes[i][j]].population)/2) {
                        //break;
                      //}
                      evacRoutes[routeCount].time = time;
                      evacRoutes[routeCount].numPeople = cap;
                      evacRoutes[routeCount].roadID = city2[routes2[i][j]].roads[index].ID;
                      routeCount++;
                    }
                  }
                }
              }
            }
            if (city2[cityToClear].evacuees == 0) {
              break;
              return;
            }
          }
          time++;
        }

        for(int i = 0; i < numCities; i++) {
          arr2[i] = i;
        }

        // creates the roads with everything initalized to -1
        for(int i = 0 ; i < size; i++) {
          for(int j = 0; j < size; j++) {
            routes2[i][j] = -1;
          }
        }
      }
      */





/*
int routes2[size][size];
int arr2[numCities];

int cityToClear = routes[i][j];

  cout << cityToClear << endl;
  cout << city2[cityToClear].evacuees << endl;
  cout << city2[cityToClear].population << endl;

  cout << "second part" << endl;

  for(int i = 0; i < numCities; i++) {
    arr2[i] = i;
  }

  // creates the roads with everything initalized to -1
  for(int i = 0 ; i < size; i++) {
    for(int j = 0; j < size; j++) {
      routes2[i][j] = -1;
    }
  }

  for(int i = 0 ; i < size; i++) {
    for(int j = 0; j < size; j++) {
      routes2[j][0] = cityToClear;
    }
  }

  for(int index = 0; index < numEvacs; index++) {
    arr2[evacIDs[index]] = -1;
  }

  arr2[cityToClear] = -1;
    }
    cout << endl;

  int source = 0;
  int i = 0;
  bool end = true;
  for(int allLayers = 0; allLayers < 999; allLayers++) {

    i = 0;
    for(int j = 0; j < size; j++) {
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
        if(adjacencyMatrix[source][i] != 0 && arr2[i] != -1 && i != evacCityID) {
          arr2[i] = -1;
          routes2[j][allLayers + 1] = i;
          end = false;
        }
        i++;
      }
    }
  }

  //for(int i = 0; i < numEvacs; i++) {
    //cout << evacIDs[i] << endl;
  //}


  cout << evacCityID << endl;

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < size; j++) {
      cout << routes2[i][j] << ", ";
    }
    cout << endl;
  }


  int cap = 0;
  while(city2[cityToClear].evacuees != 0) {
    for(int i = 0; routes2[i][0] != -1 && routes2[i][1] != -1; i++) {
      for(int j = 0; routes2[i][j+1] != -1; j++) {

          if(routes2[i][j] != -1 && routes2[i][j+1] != -1) {
            //cout << "atleast tell me it's getting in there" << endl;
            //cout << "goes inside here too " << endl;
            for(int index = 0; index < city2[routes2[i][j]].roadCount; index++) {
              //cout << "3" << endl;
              if(city2[routes2[i][j]].roads[index].destinationCityID == routes2[i][j+1]) {
                cap = city2[routes2[i][j]].roads[index].peoplePerHour;

                if(city2[routes2[i][j]].evacuees < cap) {
                  cap = city2[routes2[i][j]].evacuees;
                }
                //if(cityToClear == 516 && j == 0) {
                  //cap = 0;
                //}
                if (city2[routes2[i][j+1]].evacuees + cap <= city2[routes2[i][j+1]].population) {
                  city2[routes2[i][j+1]].evacuees += cap;
                  city2[routes2[i][j]].evacuees -= cap;
                  //if(city2[routes[i][j]].evacuees < (city2[routes[i][j]].population)/2) {
                    //break;
                  //}
                  evacRoutes[routeCount].time = time;
                  evacRoutes[routeCount].numPeople = cap;
                  evacRoutes[routeCount].roadID = city2[routes2[i][j]].roads[index].ID;
                  routeCount++;
                }
              }
            }
          }
        }
        if (city2[cityToClear].evacuees == 0) {
          break;
        }
      }
      time++;
    }

    for(int i = 0; i < numCities; i++) {
      arr2[i] = i;
    }

    // creates the roads with everything initalized to -1
    for(int i = 0 ; i < size; i++) {
      for(int j = 0; j < size; j++) {
        routes2[i][j] = -1;
      }
    }
    count = 9000;
  }
  */

  void Evac::evacuate(int *evacIDs, int numEvacs, EvacRoute *evacRoutes, int &routeCount)
  {
    //cout << "test" << endl;
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
      //cout << citiesAdjToEverything[i] << ", ";
      count++;
    }
  }

  //cout << "again" << endl;
  //cout << "yes" << endl;

  int tempArr[numEvacs];
  int pos = 0;
  for(int i = 0; i < numCities; i++) {
    if(citiesAdjToEverything[i] != -1) {
      tempArr[pos] = i;
      //cout << tempArr[pos] << "," << endl;
      pos++;
    }
    for(int j = 0; j < numEvacs; j++) {
      if(evacIDs[j] == citiesAdjToEverything[i]) {
        evacIDs[j] = -1;
      }
    }
  }

  //cout << "Wow, please work" << endl;


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

  //for(int i = 0; i < numEvacs; i++) {
    //cout << tempArr[i] << "," << endl;
  //}

  for(int i = 0; i < numEvacs; i++) {
    evacIDs[i] = tempArr[i];
  }

  //cout << "lets see" << endl;

  //for(int j = 0; j < numEvacs; j++) {
    //cout << evacIDs[j] << "," << endl;
  //}

///// second half of code




  //for(int i = 0; i < numEvacs; i++) {
    //if(evacIDs[i] != -1)
      //cout << evacIDs[i] << "--" << city2[evacIDs[i]].population << endl;
  //}

  int size = 1000;
  int routes[size][size];

  int num = 0;
  for(int numCitiesEvac = 0; numCitiesEvac < numEvacs; numCitiesEvac++) {

    //cout << evacIDs[numCitiesEvac] << endl;
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
    //cout << routes[j][1] << endl;
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

/*
int layer = 1;
for(int i = 0; i < realSize; i++) {
    source = routes[i][1];

    for(int j = 0; j < numCities; j++) {
      if(adjacencyMatrix[source][j] != 0 && arr[j] != -1 && j != evacCityID) {
        arr[j] = -1;
        layer++;
        routes[i][layer] = j;
      }
    }
    layer = 1;
}
*/

for(int allLayers = 1; allLayers < 999; allLayers++) {

  i = 0;
  for(int j = 0; j < realSize; j++) {
    i = 0;
    end = false;
    //cout << routes[j][1] << endl;
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

  //bool check = true;
  //for(int i = 0; i < realSize; i++) {
    //if(routes[i][allLayers] != -1) {
      //check = false;
    //}
  //}

  //if(check) {
    //break;
  //}
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
          //cout << "5" << endl;
          //cout << "routes at i,j " << routes[i][j] << endl;
          //cout << "routes at i,j+1 " << routes[i][j+1] << endl;
          //cout << "1" << endl;
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

          /*
          if(spicyCheetos  == 2000001) {
            cout << "The evacCityID is " << evacCityID << endl;
            cout << "the amount of evacuees at " << routes[0][0] << " is " << city2[routes[0][0]].evacuees << endl;
            cout << "the amount of population at " << routes[0][0] << " is " << city2[routes[0][0]].population << endl;
            for(int i = 0; i < 10; i++) {
              for(int j = 1; j < 100; j++) {
                if(routes[i][j] != -1) {
                  cout << "the amount of evacuees at " << routes[i][j] << " is " << city2[routes[i][j]].evacuees << endl;
                  cout << "the amount of population at " << routes[i][j] << " is " << city2[routes[i][j]].population << endl;
                }
              }
            }
            cout << "GO IN GO IN GO IN GO IN GO IN GO IN GO IN GO IN GO IN GO IN" << endl;
          }

          if(spicyCheetos  == 2000005) {
            cout << "The evacCityID is " << evacCityID << endl;
            cout << "the amount of evacuees at " << routes[0][0] << " is " << city2[routes[0][0]].evacuees << endl;
            cout << "the amount of population at " << routes[0][0] << " is " << city2[routes[0][0]].population << endl;
            for(int i = 0; i < 10; i++) {
              for(int j = 1; j < 100; j++) {
                if(routes[i][j] != -1) {
                  cout << "the amount of evacuees at " << routes[i][j] << " is " << city2[routes[i][j]].evacuees << endl;
                  cout << "the amount of population at " << routes[i][j] << " is " << city2[routes[i][j]].population << endl;
                }
              }
            }
            cout << "FASDFASDFHASDJKFHASDHFJKLASDHFJKLAHSDJKLFHASDHFJKLASDHFJKLASDHKLFJASDHKL" << end;
            return;
          }
          */
/*
          if(evacCityID == 9959) {
            cout << routeCount << endl;
            cout << "NOOOOO" << endl;
            return;
          }
          if(routeCount == 20000000) {
            cout << evacCityID << endl;
            cout << "BUCKLOUU" << endl;
            return;
          }
*/

          if(j == 0) {
            for(int index = 0; index < city2[routes[i][j]].roadCount; index++) {
              //cout << "2" << endl;
              if(city2[routes[i][j]].roads[index].destinationCityID == routes[i][j+1]) {
                //cout << "4" << endl;
                //cout << " pplPerHour = " << city2[routes[i][j]].roads[index].peoplePerHour << endl;
                cap = city2[routes[i][j]].roads[index].peoplePerHour;
                //cout << "THE CAP FIRST TIME AROUND IS " << cap << endl;
                  if(city2[routes[i][j]].population < cap) {
                    cap = city2[routes[i][j]].population;
                  }
                  if(city2[routes[i][j+1]].population < cap) {
                    cap = city2[routes[i][j+1]].population;
                  }
                  //if(evacCityID == 1328) {
                    //cout << "THE CAP THE SECOND TIME AROUND IS " << cap << endl;
                  //}
                  //if(evacCityID == 1328) {
                      //cout << "The city " << evacCityID << " is the city that we're trying to evacuate" << endl;
                      //cout << "Right now it is sending " << cap << " to city " << routes[i][j+1] << " lets see what happens" << endl;

                      //cout << "These are the stats before sending\n";
                      //cout << city2[routes[i][j]].evacuees << " , " << city2[routes[i][j]].population << " , " << endl;
                    //  cout << city2[routes[i][j+1]].evacuees << " , " << city2[routes[i][j+1]].population << " , " << endl;
                  //}
                  if (city2[routes[i][j+1]].evacuees + cap <= city2[routes[i][j+1]].population) {
                    city2[routes[i][j+1]].evacuees += cap;
                    city2[routes[i][j]].population -= cap;
                    evacRoutes[routeCount].time = time;
                    evacRoutes[routeCount].numPeople = cap;
                    evacRoutes[routeCount].roadID = city2[routes[i][j]].roads[index].ID;
                    routeCount++;
                  }
                  //if(evacCityID == 1328) {
                      //cout << "These are the stats after ending\n";
                      //cout << city2[routes[i][j]].evacuees << " , " << city2[routes[i][j]].population << " , " << endl;
                    //  cout << city2[routes[i][j+1]].evacuees << " , " << city2[routes[i][j+1]].population << " , " << endl;
                  //}
                }
              }
            }
            else if(j > 0 && routes[i][j] != -1 && routes[i][j+1] != -1) {
              //cout << "atleast tell me it's getting in there" << endl;
              //cout << "goes inside here too " << endl;
              for(int index = 0; index < city2[routes[i][j]].roadCount; index++) {
                //cout << "3" << endl;
                if(city2[routes[i][j]].roads[index].destinationCityID == routes[i][j+1]) {
                  cap = city2[routes[i][j]].roads[index].peoplePerHour;
                  if(city2[routes[i][j]].evacuees < cap) {
                    cap = city2[routes[i][j]].evacuees;
                  }
                  if(city2[routes[i][j+1]].population < cap) {
                    cap = city2[routes[i][j+1]].population;
                  }
                  if (city2[routes[i][j+1]].evacuees + cap <= city2[routes[i][j+1]].population) {
                    //if (evacCityID == 1328)
                      //cout << "pop1 = " << city2[routes[i][j]].population << " " << "RC1 = " << routeCount << endl;
                    city2[routes[i][j+1]].evacuees += cap;
                    city2[routes[i][j]].evacuees -= cap;
                    //if(city2[routes[i][j]].evacuees < (city2[routes[i][j]].population)/2) {
                      //break;
                    //}
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
