#include "Set.h"
#include <iostream>
#include <string>
using namespace std;

bool IsEven(int value) {
	return value % 2 == 0;
}

bool IsOver50(int value) {
	return value > 50;
}

int Times10(int value) {
	return value * 10;
}

int Mod10(int value) {
	return value % 10;
}

void ShowSet(const Set& set, const string& setName) {
	cout << setName << ": ";
	for (int element : set) {
		cout << element << " ";
	}
	cout << endl;
}

int main() {
	Set SetA = Set();
	Set SetB = Set();
	SetA.Add(-24);
	SetA.Add(19);
	SetA.Add(64);
	SetA.Add(67);
	SetA.Add(90);
	SetA.Add(95);

	SetB.Add(-84);
	SetB.Add(42);
	SetB.Add(67);
	SetB.Add(90);

	ShowSet(SetA,"Set A");
	ShowSet(SetB, "Set B");

	ShowSet(SetA.Union(SetB), "A union B");
	ShowSet(SetA.Intersection(SetB),"A intersect B");
	ShowSet(SetA.Difference(SetB), "A \\ B");
	ShowSet(SetB.Difference(SetA), "B \\ A");

	ShowSet(SetA.Filter(IsEven), "Set A filtered for evens");
	ShowSet(SetB.Filter(IsEven), "Set B filtered for evens");
	ShowSet(SetA.Filter(IsOver50), "Set A filtered for elements > 50");
	ShowSet(SetB.Filter(IsOver50), "Set B filtered for elements > 50");

	ShowSet(SetA.Map(Times10), "Set A mapped * 10");
	ShowSet(SetB.Map(Times10), "Set B mapped * 10");
	ShowSet(SetA.Map(Mod10), "Set A mapped % 10");
	ShowSet(SetB.Map(Mod10), "Set B mapped % 10");

	return 0;
}
