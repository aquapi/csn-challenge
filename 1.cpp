#include <iostream>
#include <map>
#include <set>
#include <stack>
using namespace std;

string input;
set<char> openBrackets;
map<char, char> closeBrackets;

const char *resultMap[2] = {"false", "true"};

// Solve each test
bool solveTest() {
  cin >> input;

  stack<char> brackets;
  for (char ch : input) {
    // Put the correspond close brackets in the stack
    if (openBrackets.count(ch)) {
      brackets.push(closeBrackets[ch]);
      continue;
    }

    // End the execution if current bracket does not match
    if (brackets.empty() || brackets.top() != ch)
      return false;

    brackets.pop();
  }

  // If all brackets are closed
  return brackets.empty();
}

// Preparations
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Assign to corresponding open and close bracket
  openBrackets.insert('{');
  openBrackets.insert('[');
  openBrackets.insert('(');

  closeBrackets['{'] = '}';
  closeBrackets['['] = ']';
  closeBrackets['('] = ')';

  int T;
  cin >> T;

  while (T--)
    cout << resultMap[solveTest()] << '\n';
}
