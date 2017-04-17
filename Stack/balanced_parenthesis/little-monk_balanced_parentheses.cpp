#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main() {
  int size, parantheses, streak = 0, highest_steak = 0, last_streak_index = 0, last_streak_val = 0;
  scanf("%d", &size);
  stack<int> checker;
  for (int i = 0 ; i < size; ++i) {
    scanf("%d", &parantheses);
    if (!checker.empty() && parantheses < 0 && checker.top() == (-1* parantheses)) {
      checker.pop();
 
      if (last_streak_index + 2 == i) {
        streak = last_streak_val + 1;
      } else {
        streak++;
      }
      last_streak_index = i;
      last_streak_val = streak;
      highest_steak = max(highest_steak, streak);
    } else {
      checker.push(parantheses);
      streak = 0;
    }
  }
 
  printf ("%d" , 2*highest_steak);
  return 0;
}