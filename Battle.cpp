#include "Battle.h"
#include "Pokemon.h"


Battle::Battle() {};

Battle::~Battle() {
	// Delete teamA
	// Deltete teamB
	if (teamA.size() != 0) {
		for (int i = 0; i < teamA.size(); i++)
		{
			delete teamA[i];
		}
		teamA.clear();
	}

	if (teamB.size() != 0) {
		for (int i = 0; i < teamB.size(); i++)
		{
			delete teamB[i];
		}
		teamB.clear();
	}

};

Battle& Battle::addTeamA(Pokemon* p) {
	teamA.push_back(p);
	return *this;
};

Battle& Battle::addTeamB(Pokemon* p) {
	teamB.push_back(p);
	return *this;
};

string Battle::checkIfNewPokemon(string lastP, string currP, char teamChar) {
	if (lastP != currP) {
		cout << "Team " << teamChar << " sends out " << currP << endl;
	}
	lastP = currP;
	return lastP;
};

void Battle::checkWinner(int sizeA, int sizeB) {
	bool aliveA = false;
	bool aliveB = false;

	for (int i = 0; i < teamA.size(); i++)
	{
		if (teamA[i]->health > 0) {
			aliveA = true;
		}
	}

	for (int i = 0; i < teamB.size(); i++)
	{
		if (teamB[i]->health > 0) {
			aliveB = true;
		}
	}

	if (aliveA) {
		cout << "Team A is the winner!" << endl;
	}
	else if (aliveB) {
		cout << "Team B is the winner!" << endl;
	}
	else {
		cout << "its a draw, both teams lost" << endl;
	}
};

void Battle::start() {
	int indexA = 0;
	int indexB = 0;
	string lastPa;
	string lastPb;

	if (teamA.size() == 0 || teamB.size() == 0) {
		throw runtime_error("One of the teams are empty");
	}

	cout << "The battle has started! " << endl;

	while (indexA < teamA.size() && indexB < teamB.size()) {
		if (teamA[indexA]->health == 0) {
			indexA++;
			continue;
		}
		if (teamB[indexB]->health == 0) {
			indexB++;
			continue;
		}
		int randVal = rand() % 2;

		//auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
		//auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);

		lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');
		lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');

		if (teamA[indexA]->speed > teamB[indexB]->speed) {
	/*		lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');
			lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');*/

			auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
			auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);

			cout << "\n";
			stratA->perform(teamA[indexA], teamB[indexB]);
			stratB->perform(teamB[indexB], teamA[indexA]);
		}

		else if (teamB[indexB]->speed > teamA[indexA]->speed) {

			/*lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');
			lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');*/

			auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
			auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);

			cout << "\n";
			stratB->perform(teamB[indexB], teamA[indexA]);
			stratA->perform(teamA[indexA], teamB[indexB]);
		}
		else {
			if (randVal == 1) {
				/*lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');
				lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');*/

				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);

				cout << "\n";
				stratA->perform(teamA[indexA], teamB[indexB]);
				stratB->perform(teamB[indexB], teamA[indexA]);
			}
			else {
				//lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');
				//lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');
				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);

				cout << "\n";
				stratB->perform(teamB[indexB], teamA[indexA]);
				stratA->perform(teamA[indexA], teamB[indexB]);
			}
		}
	}

	checkWinner(teamA.size(), teamB.size());
};

//void Battle::start() {
//	int indexA = 0;
//	int indexB = 0;
//	string lastPa;
//	string lastPb;
//
//	if (teamA.size() == 0 || teamB.size() == 0) {
//		throw runtime_error("One of the teams are empty");
//	}
//
//	cout << "The battle has started! " << endl;
//
//	while (indexA < teamA.size() && indexB < teamB.size()) {
//		if (teamA[indexA]->health == 0) {
//			indexA++;
//			continue;
//		}
//		if (teamB[indexB]->health == 0) {
//			indexB++;
//			continue;
//		}
//		int randVal = rand() % 2;
//
//		//auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//		//auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//
//		lastPa = checkIfNewPokemon(lastPa, teamA[indexA]->name, 'A');
//		lastPb = checkIfNewPokemon(lastPb, teamB[indexB]->name, 'B');
//
//		if (lastPa != teamA[indexA]->name || lastPb != teamB[indexB]->name) {
//			if (teamA[indexA]->speed > teamB[indexB]->speed) {
//
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//
//				cout << "\n";
//				stratA->perform(teamA[indexA], teamB[indexB]);
//				stratB->perform(teamB[indexB], teamA[indexA]);
//			}
//			else if (teamB[indexB]->speed > teamA[indexA]->speed) {
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//
//				cout << "\n";
//				stratB->perform(teamB[indexB], teamA[indexA]);
//				stratA->perform(teamA[indexA], teamB[indexB]);
//			}
//			else if (randVal == 1) {
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//
//				cout << "\n";
//				stratA->perform(teamA[indexA], teamB[indexB]);
//				stratB->perform(teamB[indexB], teamA[indexA]);
//			}
//			else {
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//
//				cout << "\n";
//				stratB->perform(teamB[indexB], teamA[indexA]);
//				stratA->perform(teamA[indexA], teamB[indexB]);
//			}
//		}
//		else {
//			if (randVal == 1) {
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//
//				cout << "\n";
//				stratA->perform(teamA[indexA], teamB[indexB]);
//				stratB->perform(teamB[indexB], teamA[indexA]);
//			}
//			else {
//				auto stratB = teamB[indexB]->stratPtr(teamB[indexB], teamA[indexA]);
//				auto stratA = teamA[indexA]->stratPtr(teamA[indexA], teamB[indexB]);
//
//				cout << "\n";
//				stratB->perform(teamB[indexB], teamA[indexA]);
//				stratA->perform(teamA[indexA], teamB[indexB]);
//			}
//		}
//	}
//
//	checkWinner(teamA.size(), teamB.size());
//};
