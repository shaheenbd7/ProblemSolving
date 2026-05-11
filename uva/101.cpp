#include <iostream>
#include <vector>

using namespace std;

vector<int> piles[100];

pair<int, int> findBlock(int x) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < piles[i].size(); j++) {
      if (piles[i][j] == x) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

void clearAbove(int stackNum, int pos) {
  while ((int)piles[stackNum].size() > pos + 1) {
    int topBlock = piles[stackNum].back();
    piles[stackNum].pop_back();

    piles[topBlock].push_back(topBlock);
  }
}

void pileBlocks(int fromStack, int fromPos, int toStack) {
  vector<int> temp;

  for (int i = fromPos; i < piles[fromStack].size(); i++) {
    temp.push_back(piles[fromStack][i]);
  }

  while ((int)piles[fromStack].size() > fromPos) {
    piles[fromStack].pop_back();
  }

  for (int x : temp) {
    piles[toStack].push_back(x);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    piles[i].push_back(i);
  }

  string cmd1, cmd2;
  int a, b;

  while (cin >> cmd1) {
    if (cmd1 == "quit") break;

    cin >> a >> cmd2 >> b;

    auto posA = findBlock(a);
    auto posB = findBlock(b);

    int stackA = posA.first;
    int heightA = posA.second;

    int stackB = posB.first;
    int heightB = posB.second;

    if (stackA == stackB) continue;

    if (cmd1 == "move") {
      clearAbove(stackA, heightA);

      if (cmd2 == "onto") {
        clearAbove(stackB, heightB);
      }

      pileBlocks(stackA, heightA, stackB);
    }

    else if (cmd1 == "pile") {
      if (cmd2 == "onto") {
        clearAbove(stackB, heightB);
      }

      pileBlocks(stackA, heightA, stackB);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << ":";

    for (int x : piles[i]) {
      cout << " " << x;
    }

    cout << "\n";
  }

  return 0;
}