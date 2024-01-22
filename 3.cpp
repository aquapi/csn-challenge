#include <iostream>
using namespace std;

int monsters, durability, repairCost, currentDurability, durabilityLost,
    totalCost = 0;

// Preparation
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> monsters >> durability >> durabilityLost >> repairCost;
  currentDurability = durability;

  if (durabilityLost > durability ||
      (durability == durabilityLost && monsters > 1)) {
    cout << -1;
    return 0;
  }

  while (--monsters) {
    if (currentDurability <= durabilityLost) {
      totalCost += repairCost;
      currentDurability = durability;
    }

    currentDurability -= durabilityLost;
  }

  if (currentDurability < durabilityLost)
    totalCost += repairCost;

  cout << totalCost;
}
