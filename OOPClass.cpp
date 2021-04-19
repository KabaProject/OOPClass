#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct character {
	int key; //yup
	int value;
};

bool isSet(vector<character> vect, int key) {

	if (vect.size() == 0) {
		return false;
	}

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].key == key) {
			return true;
		}
	}

	return false;
}

void updateVectorMatches(vector<character>& vect, int key) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].key == key) {
			vect[i].value += 1;
		}
	}
}

bool compareCharacter(character a, character b) {
	return (a.key < b.key);
}

void sortVector(vector<character>& vect) {

	sort(vect.begin(), vect.end(), compareCharacter);
}

vector<character> getMatches(string text) {

	vector<character> matches;

	for (int i = 0; i < text.size(); i++) {

		int key = int(text[i]);

		if (!(65 <= key && key <= 90) && !(97 <= key && key <= 122)) {
			continue;
		}

		if (!isSet(matches, key)) {
			character ch = { key, 1 };
			matches.push_back(ch);
		}
		else {
			updateVectorMatches(matches, key);
		}

	}

	sortVector(matches);

	return matches;
}

int main() {

	string text;
	vector<character> matches;
	char command;

	do {
		cout << "Ingresa el texto: ";
		getline(cin, text);

		matches = getMatches(text);

		cout << "\nListado de coincidencias (letra => cantidad)\n";

		for (int i = 0; i < matches.size(); i++) {
			cout << "  " << char(matches[i].key) << " => " << matches[i].value << endl;
		}

		cout << "\n¿Quieres volver a hacerlo? (Y/N): ";
		cin >> command;
		cin.ignore();
		system("CLS");

	} while (command != 'N' && command != 'n');

	cout << "Gracias por su preferencia!!\n";

	return 0;
}

