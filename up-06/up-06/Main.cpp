#include "Add.h"

int main() {
  WorldPopulation World;
  World.ReadWorld();
  World.CalcWorldPopulation();
  World.WriteYearPopulation();
  system("pause");
  return 0;
}