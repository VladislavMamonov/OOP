#include "set.hpp"
#include <iostream>

using namespace std;

int main()
{
  Stack stk;
  Queue turn;

  cout << "press '1' to add element in stack" << endl;
  cout << "press '2' to remove element from stack" << endl;
  cout << "press '3' to get stack info" << endl;
  cout << "press '4' to delete stack" << endl;

  for (int i = 0; stk.GetSize() != 10; i++) {
    cout << endl;
    cout << "selection: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
      cout << "value: ";
      int user_data;
      cin >> user_data;
      stk.push(user_data);
    }

    if (choice == 2) {
      if (stk.GetSize() == 0) {
        cout << "the stack is empty" << endl;
        continue;
      }
      cout << "delete method" << endl;
      stk.pop();
    }

    if (choice == 3) {
      if (stk.GetSize() == 0) {
        cout << "the stack is empty" << endl;
      }
      for (int i = 0; i < stk.GetSize(); i++) {
        cout << stk[i] << endl;
      }
    }

    if (choice == 4) {
      cout << "clear stack" << endl;
      stk.~Stack();
    }
  }


  system("clear");
  cout << "press '1' to add element in queue" << endl;
  cout << "press '2' to remove element from queue" << endl;
  cout << "press '3' to get queue info" << endl;
  cout << "press '4' to delete queue" << endl;

  for (int i = 0; turn.GetSize() != 10; i++) {
    cout << endl;
    cout << "selection: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
      cout << "value: ";
      int user_data;
      cin >> user_data;
      turn.push(user_data);
    }

    if (choice == 2) {
      if (turn.GetSize() == 0) {
        cout << "the queue is empty" << endl;
        continue;
      }
      cout << "delete method" << endl;
      turn.pop();
    }

    if (choice == 3) {
      if (turn.GetSize() == 0) {
        cout << "the queue is empty" << endl;
      }
      for (int i = 0; i < turn.GetSize(); i++) {
        cout << turn[i] << endl;
      }
    }

    if (choice == 4) {
      cout << "clear queue" << endl;
      turn.~Queue();
    }

}

  return 0;
}
