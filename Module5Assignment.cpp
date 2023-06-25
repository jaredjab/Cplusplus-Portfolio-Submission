#include <iostream>
#include <fstream>
using namespace std;

double FtoC(int cityTempF) { // Funtion for converting temperature to celsius
	double cityTempC;
	cityTempC = (cityTempF - 32) * (5.0 / 9.0);

	return cityTempC;
}

int main() {
	ifstream inFS; // Input stream for reading a file
	ofstream outFS; // Output stream for writing a file

	string cityName; // Vairable for storing city name
	int cityTempF; // Variable for storing city temp in fahrenheit

	inFS.open("FahrenheitTemperature.txt"); // Opens fahrenheit file

	if (!inFS.is_open()) { // Prints error message if file fails to open
		cout << "Could not open file \"FahrenheitTemperature.txt\"." << endl;
		return 1;
	}

	outFS.open("CelsiusTemperature.txt"); // Creates file for converted information

	while (!inFS.eof()) { // Reads file and converts to celsius on a new created file
		inFS >> cityName;
		inFS >> cityTempF;

		if (!inFS.fail()) { // Continues as long as no errors have occurred
			double cityTempC = FtoC(cityTempF);
			outFS.precision(2);
			outFS << fixed << cityName << " " << cityTempC << endl;
		}
	}

	inFS.close(); // Closes the file being read

	return 0;
}