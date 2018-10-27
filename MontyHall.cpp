#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

void simulate(int i, int &w1, int &w2 );

Door hideCar();

Door openDoor( int c, int f );

Door makeFirstChoice();

Door makeSecondChoice( int f, int o );

int main()
{
	int win1 = 0, win2 = 0;
	srand(time(NULL));

   	cout << setw(4) << "#" << setw(12)<< "Car   " << "First  " << "Opened  " << "Second    " << "Win    " << "Win"<< endl;
   	cout << "         " << setw(4)<< "here  " << "choice    " << "door  " << "choice  " << "first " << "second"<< endl << endl;
    // Run the simulations.
   	for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);
    double x = float(win2)/float(win1);
    cout << endl << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice"<< endl << endl;
    cout << "Win ratio of switch over stay: " << setprecision(2) << x << endl;
}

Door hideCar()
{
	int c = rand()% 3 + 1;// c = Random generation of car value
	cout << setw(3)<< c << "       ";
	return c;
}

Door makeFirstChoice()
{
	int f = rand() % 3 + 1; // f = Random first choice
	cout << f << "       ";
	return f;
}

Door openDoor( int c, int f )  // Car and First choice are passed
{
	int o = 0; // o = open door
	if (f == c) // if the first choice is correct
	{
	if (c == 1)
	{
	    o = (rand() % 2) + 2; // Generate a random number between 2 and 3
	}
	else if (f == 3)
	{
	    o = rand() % 2 + 1; // Generate a random number between 1 and 2
	}
	else
	{
       int randVal = rand() % 2 + 1; // Generate a random number between 1 and 2
	    if (randVal == 2) // If the value is 2
	       o = 3; // return 3
	    else
	    	o = 1;
		}
	}
	else
	{
	if (c == 1)
	{
		if (f == 2)
			o = 3;
		else
			o = 2;
	}
	else if (c == 2 )
	{
		if (f == 1)
			o = 3;
		else
			o = 1;
	}
	else if(c == 3)
	{
		if (f == 1)
			o = 2;
		else
		o = 1;
	}
   }

	cout << o << "     ";
	return o;
}

Door makeSecondChoice( int f, int o ) // first choice and open door
{
	int s = 0; // second choice

	if (((f == 1) && (o == 2)) || ((f == 2) && (o == 1)))
	{
		s = 3;
	}
	else if (((f == 1) && (o == 3)) || ((f == 3) && (o == 1)))
	{
		s = 2;
	}
	else if (((f == 2) && (o == 3)) || ((f == 3) && ( o == 2)))
	{
		s = 1;
	}
	cout << "  " << s;
	return s;
}

void simulate(int i, int &w1, int &w2)
{
	cout << setw(4)<< i << "      ";
	int car = hideCar();
	int first = makeFirstChoice();
	int open = openDoor( car, first );
	int second = makeSecondChoice( first, open);

	if (car == first)
	{
		w1++; //Counter for win1
		cout << "    yes";
	}
	else if (car == second)
	{
		w2++; //Counter for win2
		cout << "           yes";
	}
	cout << endl;
}
