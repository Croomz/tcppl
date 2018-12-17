#include <math.h>
#include <cstdlib>
#include<iostream>
#include <string>

using namespace std;

class Window {
public:
  void setWindow() {
    winWidth = 1 + rand() % 2;
    winHeight = 1 + rand() % 2;
  }

  void getWindow() {
    cout<<"\nWindow:\n"<<"\n Window width: "<< winWidth <<", Window height: "<< winHeight;
  }

  double windowArea() {
    winArea = winHeight * winWidth;
    return winArea;
  }

private:
  double winWidth;
  double winHeight;
  double winArea;
};

class Parquet {
public:
  void setParquet() {
    parqLength = 1 + rand() % 50;
    parqWidth = 1 + rand() % 50;
  }

  void getParquet() {
    cout<<"\nParquet:\n"<<"\n Parquet length: "<< parqLength <<", Parquet width: "<< parqWidth;
  }

  double parquetArea() {
    parqArea = parqLength * parqWidth;
    return parqArea;
  }
private:
  double parqLength;
  double parqWidth;
  double parqArea;
};

class Room {

public:
  int countColor[3] = { 0,0,0 };
  string colors[3] = { "blue", "red", "white" };

  void setRoom() {
    roomLength = 1 + rand() % 100;
    roomWidth = 1 + rand() % 100;
    roomHeight = 3;
    int index = rand() % 3;
    roomColor = colors[index];
    roomLitr = 1 + rand() % 100;
    colculateCountColor(index, roomLitr);
    countWindows = 1 + rand() % 5;
    parquet.setParquet();
    for (int i = 0; i<countWindows; ++i) {
      windows[i].setWindow();
    }
  }

  void getRoom() {
    cout<<"\nRoom:\n"<<" Room length: "<< roomLength <<", Room width: "<< roomWidth <<", Room height: "<< roomHeight <<"\n Color: "<< roomColor <<"\n Number of liters m2: "<<roomLitr<<"\n Number of windows: "<<countWindows;
    parquet.getParquet();
    for (int i = 0; i<countWindows; ++i) {
      windows[i].getWindow();
    }
  }

  void colculateCountColor(int index, int litrm2) {
    for (int i = 0; i<sizeof(countColor); ++i) {
      if (i == index) {
        countColor[i] = countColor[i] + litrm2;
      }
    }
  }

  int roomCapacity() {
    capacity = roomLength * roomWidth*roomHeight;
    return capacity;
  }

  int countParquet() {
    roomArea = roomLength * roomWidth;
    countParq = int(roomArea/ parquet.parquetArea());
    return countParq;
  }

private:
  double roomLength;
  double roomWidth;
  double roomHeight;
  double roomArea;
  int countParq;
  double capacity;
  Window windows[5];
  string roomColor;
  double roomLitr;
  int countWindows;
  Parquet parquet;

};

class Flat {
public:
  void setFlat() {
    cout<<"Number of rooms:\n";
    cin>>countRoom;
    room = new Room[countRoom];
    for (int i = 0; i<countRoom; ++i) {
      room[i].setRoom();
    }
  }

  void getFlat()
  {
    cout<<"\nNumber of rooms: "<<countRoom<<"\n";
    for (int i = 0; i<countRoom; ++i)
    {
      cout<<"\nRoom ¹:"<<i + 1;
      room[i].getRoom();
    }
  }

  int flatCapacity() {
    for (int i = 0; i<countRoom; ++i) {
      capacityFlat += room[i].roomCapacity();
    }
    return capacityFlat;
  }

  int countParquetFlat() {
    for (int i = 0; i<countRoom; ++i) {
     countFlatParquet += room[i].countParquet();
    }
    return countFlatParquet;
  }

public:
  int countRoom;
  double capacityFlat = 0;
  int countFlatParquet;
  Room *room;
};

class House {
public:
  void setHouse() {
    cout<<"\nNumber of floors:\n";
    cin>>countFloor;
    cout<<"\nNumber of flats on the floor:\n";
    cin>>countFlat;
    flats = new Flat[countFlat*countFloor];
    for (int i = 0; i<countFlat*countFloor; ++i) {
      flats[i].setFlat();
    }
  }

  void getHouse() {
    cout<<"Number of flats in one house:\n"<<countFlat * countFloor;
    for (int i = 0; i<countFlat*countFloor; ++i) {
      cout<<"\nFlat ¹ "<<i + 1;
      flats[i].getFlat();
    }
    for (int i = 0; i<countFlat*countFloor; ++i) {
      capacityHouse += flats[i].flatCapacity();
    }
    for (int i = 0; i<countFlat*countFloor; ++i) {
      countHouseParquet += flats[i].countParquetFlat();
    }
    for (int i = 0; i<countFloor; ++i) {
      houseHeigth = houseHeigth + 3;
    }
    cout<<"\n House height:\n"<<houseHeigth;
    cout<<"\nHouse capacity:\n"<<capacityHouse;
    cout<<"\nNumber of parquet per house:\n"<<countHouseParquet;
  }
private:
  int countFloor;
  int countFlat;
  int houseHeigth = 0;
  int capacityHouse = 0;
  int countHouseParquet = 0;
  Flat *flats;
};

class Street {
public:
  void setStreet() {
    cout<<"Number of houses: \n";
    cin>>countHouse;
    houses = new House[countHouse];
    for (int i = 0; i<countHouse; ++i) {
      houses[i].setHouse();
    }
  }

  void getStreet() {
    for (int i = 0; i<countHouse; ++i) {
      cout<<"\nHouse ¹ "<<i + 1;
      houses[i].getHouse();
    }
  }

private:
  int countHouse;
  House *houses;
};

int main(int argc, const char * argv[]) {
  setlocale(LC_CTYPE, "rus");
  Street street;
  street.setStreet();
  street.getStreet();
  int a;
  cin>>a;
  return 0;
}
