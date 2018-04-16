#include "HW1_Player.h"
#include "HW1_Player.cpp"
#include "HW1_Team.h"
#include "HW1_Team.cpp"
#include "HW1_League.h"
#include "HW1_League.cpp"

int main() {
	Player<int> p1("Stephen Curry", 190, 86);
	Player<int> p2("Klay Thompson", 201, 98);
	Player<int> p3("Kevin Durant", 206, 109);
	Player<int> p4("Lebron James", 203, 113);
	Player<int> p5("Kevin Love", 208, 114);

	Team<int> T1("Golden State Warriors", 3);
	T1[0] = p1;
	T1[1] = p2;
	T1[2] = p3;

	Team<int> T2("Cleveland Cavaliers", 2);
	T2[0] = p4;
	T2[1] = p5;

	League<int> L1("NBA", 2);
	L1[0] = T1;
	L1[1] = T2;

	cout << L1 << endl;

	system("pause");

	return 0;
}