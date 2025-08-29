#include <iostream>
#include "task1.h"

int parceStringTimeToIntTimeSec(std::string str) {
  std::string departHours;
  std::string departMinutes;

  bool flag = false;

  for (int i = 0; i < str.length(); ++i) {
      if (str[i] == ':') {
          flag = true;
          continue;
      }

      if(flag == true) {
          departMinutes += str[i];
          continue;
      }

      departHours += str[i];
  }

  if(departHours == "00") {
      departHours = "24";
  }

  return atoi(departMinutes.c_str()) * 60 + atoi(departHours.c_str()) * 3600;
}

std::string parceIntTimeToStringTime(int hours, int minutes) {
  std::string tempHours;
  std::string tempMinutes;

  if(hours < 10 && hours >= 0) {
      tempHours = "0" + std::to_string(hours);
  } else {
      tempHours += std::to_string(hours);
  }

  if(minutes < 10) {
      tempMinutes = "0" + std::to_string(minutes);
  } else {
      tempMinutes += std::to_string(minutes);
  }

  return tempHours + " h. " + tempMinutes + " min.";
}

void calcTraveTime(std::string depart, std::string arrival) {
  int departSec = parceStringTimeToIntTimeSec(depart);
  int arrivalSec = parceStringTimeToIntTimeSec(arrival);

  int diffTimeSec = arrivalSec - departSec;
  int hours = diffTimeSec / 3600;
  int minutes = (diffTimeSec - (hours * 3600)) / 60;

  if (hours < 0) {
      hours = 24 - (hours * (-1));
  }

  if (minutes < 0) {
      minutes = 60 - (minutes * (-1));
  }

  std::cout <<  "The trip took " << parceIntTimeToStringTime(hours, minutes) << std::endl;
}

bool isValidTime(std::string str) {
  const int timeSec = parceStringTimeToIntTimeSec(str);

  if (timeSec / 3600 > 24) {
      return false;
  }

  if(str[3] > '5') {
      return false;
  }

  if (str.length() < 5) {
      return false;
  }

  for(int i = 0; i < str.length(); i++) {
      if(str[i] < 48 && str[i] > 58) {
          return false;
      }
  }

  return true;
}

std::string transformValidTime(std::string str) {
  if(str.length() > 5) {
      str = str.substr(0, 5);
  }

  if(str[2] != ':') {
      str[2] = ':';
  }

  return str;
}

void task1() {
  std::string departure;

  std::cout << "Enter departure time (HH:MM):";
  std::cin >> departure;

  departure = transformValidTime(departure);

  if(bool flag = isValidTime(departure)) {
      std::string arrival;
      std::cout << "Enter arrival time (HH:MM):";
      std::cin >> arrival;

      arrival = transformValidTime(arrival);

      if(isValidTime(arrival)) {
          calcTraveTime(departure, arrival);
      } else {
          std::cout << "Invalid arrival time!" << std::endl;
      }
  } else {
      std::cout << "Invalid departure time!" << std::endl;
  }
}