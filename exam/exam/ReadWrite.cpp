#include "ReadWrite.h"
Table tab;
string month;
int temperature;
char ch;
Table ReadWrite::Read(string file) {
  NumberStream numberStream;

  ifstream in(file);
  in >> numberStream;
  numberStream.setPosition(0);
  while (numberStream.peek() != '\0') {
    month.clear();
    month.resize(20);
    ch = numberStream.get();
    size_t it = 0;
    while (ch != ' ') {
      month[it] = ch;
      ch = numberStream.get();
      it++;
    }
    temperature = numberStream.read();
    numberStream.get();
    tab.push_back(make_pair(month, temperature));
  }

  string year = "Average year temperature";
  int averageTemperature = 0;
  int tmpSum = 0;
  int count = 0;

  for (const auto& [month, temperature] : tab) {
    tmpSum += temperature;
    count++;
  }

  averageTemperature = tmpSum / count;

  tab.push_back(make_pair(year, averageTemperature));

  return tab;
}

void ReadWrite::Write(string file, const Table& tab) {
  NumberStream ns;
  for (const auto& [month, temperature] : tab) {
    ns << month << ' ' << temperature << '\n';
  }

  ofstream out(file);
  out << ns;
}