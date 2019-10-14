#include "Functionr.h"

int main() {
  time_t t = time(NULL);
  struct tm now;
  localtime_s(&now, &t);
  Date UsersDate, Birthday, Today;
  Today.day = now.tm_mday;
  Today.month = now.tm_mon + 1;
  Today.year = now.tm_year + 1900;
  DateInput(Birthday, UsersDate);
  if (UsersDate.IsLeap()) {
    cout << "The year of your date is Leap" << endl;
  } else {
    cout << "The year of your date isn't Leap" << endl;
  }
  Date NextDay = UsersDate.NextDay();
  cout << "The date of next day = " << NextDay.day << " " << NextDay.month
       << " " << NextDay.year << endl;
  Date PreviousDate = UsersDate.PreviousDay();
  cout << "The date of previous day = " << PreviousDate.day << " "
       << PreviousDate.month << " " << PreviousDate.year << endl;
  short int week_number = Today.WeekNumber();
  cout << "The number of your week = " << week_number << endl;
  int days_till_birth = Today.DaysTillYourBirthday(Birthday);
  cout << "Days till my birthday = " << days_till_birth << endl;
  int days_till_date = Today.Duration(UsersDate);
  cout << "Days till Users Date = " << days_till_date << endl;
  system("pause");
  return 0;
}