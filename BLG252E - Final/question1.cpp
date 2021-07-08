/*
Student Name	: 	Ö. Malik KALEMBAŞI
Student ID		: 	150180112
Date			: 	23.06.2021
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Warlord {
private:
	int power;
	int magic;
public:
	/* Write a constructor */
	Warlord(int inputPower=0, int inputMagic=0)
	{
		if (inputPower < 0 )
			throw "A warlord cannot have negative power!";
		if (inputMagic <= 0)
			throw "A warlord cannot be a non-magic wielder!";
		magic=inputMagic;
		power =inputPower;
	}

	/* Write Print function */
	void Print()
	{
		cout << "Power: " << power <<" Magic: "<< magic << endl;
	}
	int getMagic(){return magic;}
	int getPower(){return power;}
	
};

/* Write a comparison function which will return true if first parameter is bigger than the second */
bool comparison(Warlord& w1 ,Warlord& w2)
{
	int Total1 = w1.getMagic()+w1.getPower();
	int Total2 = w2.getMagic()+w2.getPower();
	if (Total1>Total2)
		return true;
	else
		return false;
}

/* Define an STL container (vector, list, etc.) here. Use typedef to name it as "Container" */
typedef list<Warlord> Container;
typedef Container::iterator Iterator;

/* You should not change or remove the given code parts. Add necessary codes to get the same result with sample output */
int main() {
	
	try
	{

		Warlord w1(1, 1);
		Warlord w2(2, 2);
		Warlord w3(2, 1);

		/* Initialize the "Container" and put the w1,w2, and w3 into container */
		Container lords;
		lords.push_front(w3);
		lords.push_front(w2);
		lords.push_front(w1);

		cout << "Unsorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++) (*i).Print();

		/* Sort Warlords in the container */
		lords.sort(comparison);
		
		cout << endl << "Sorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++) (*i).Print();
		

			Warlord w4; /* by default warlords have zero power and zero magic*/
			w4.Print();
	}

	catch(const char *result){ //Catch block for exceptions of type char *
		cout << result << endl;
	}
	

	return 0;
}


