//Brandon Ruiz
//Section 02

#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.cpp"

using namespace std;

void readFile(LinkedList & list, string & file) {
ifstream readData;
int number;

readData.open(file);
while(readData >> number) {
list.addToFront(number);
}

readData.close();
}

int main() {
string file = "list.txt";
LinkedList newList;
double average = 0.0;

readFile(newList, file);
average = newList.average();
cout << "The average is: " << average << endl;
newList.writeInorder(file);
newList.writeReversed(file);

return 0;
}
