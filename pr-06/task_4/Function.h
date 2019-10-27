#pragma once
#ifdef FUNCTION_H

#endif  // FUNCTION_H
#include <time.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Date {
  int day, month, year;
  Date NextDay();
  int NumberOfDay();
  int Duration(Date Day);
  bool IsLeap();
};
bool Date::IsLeap() {
  if (this->year % 400 == 0) {
    return true;
  } else {
    if (this->year % 100 == 0) {
      return false;
    } else {
      if (this->year % 4 == 0) {
        return true;
      } else {
        return false;
      }
    }
  }
}
Date Date::NextDay() {
  Date NextDay;
  int count_of_days;
  if (this->month < 8 && this->month % 2 == 0 && this->month != 2) {
    count_of_days = 30;
  } else if (this->month < 8 && this->month % 2 != 0 && this->month != 2) {
    count_of_days = 31;
  } else if (this->month > 8 && this->month <= 12 && this->month % 2 == 0 &&
             this->month != 2) {
    count_of_days = 31;
  } else if (this->month > 8 && this->month <= 12 && this->month % 2 == 1 &&
             this->month != 2) {
    count_of_days = 30;
  } else if (this->month == 2 && this->IsLeap()) {
    count_of_days = 29;
  } else if (this->month == 2 && !this->IsLeap()) {
    count_of_days = 28;
  }

  if (this->day > count_of_days) {
    cout << "You enter the incorrect parametres";
  } else if (this->day == count_of_days) {
    NextDay.day = 1;
    NextDay.month = this->month + 1;
    if (NextDay.month > 12) {
      NextDay.month = 1;
      NextDay.year = this->year + 1;
    }
  } else {
    NextDay.day = this->day + 1;
    NextDay.month = this->month;
    NextDay.year = this->year;
  }
  return NextDay;
}
int Date::NumberOfDay() {
  int day_number = 0;
  int feb_days = 0;
  if (this->IsLeap()) {
    feb_days = 29;
  } else {
    feb_days = 28;
  }
  switch (this->month) {
    case 1: {
      day_number = this->day;
      break;
    }
    case 2: {
      day_number = 31 + this->day;
      break;
    }
    case 3: {
      day_number = 31 + feb_days + this->day;
      break;
    }
    case 4: {
      day_number = 62 + feb_days + this->day;
      break;
    }
    case 5: {
      day_number = 92 + feb_days + this->day;
      break;
    }
    case 6: {
      day_number = 123 + feb_days + this->day;
      break;
    }
    case 7: {
      day_number = 153 + feb_days + this->day;
      break;
    }
    case 8: {
      day_number = 184 + feb_days + this->day;
      break;
    }
    case 9: {
      day_number = 215 + feb_days + this->day;
      break;
    }
    case 10: {
      day_number = 245 + feb_days + this->day;
      break;
    }
    case 11: {
      day_number = 276 + feb_days + this->day;
      break;
    }
    case 12: {
      day_number = 306 + feb_days + this->day;
      break;
    }
  }
  return day_number;
}
int Date::Duration(Date Day) {
  int to_new_year;
  if (Day.NumberOfDay() - this->NumberOfDay() < 0) {
    if (this->IsLeap()) {
      to_new_year = 366 - this->NumberOfDay();
    } else {
      to_new_year = 365 - this->NumberOfDay();
    }
    return to_new_year + Day.NumberOfDay();
  } else {
    return Day.NumberOfDay() - this->NumberOfDay();
  }
}

void InputVector(vector <Date> &v) { 
	ifstream fin("file.txt");
	int day, month, year; 
	while (!fin.eof()) {
          fin >> day >> month >> year;
          Date Day;
          Day.day = day;
          Day.month = month;
          Day.year = year;
          v.push_back(Day);
	}
	fin.close();
}