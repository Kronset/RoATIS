#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

// TODO: airport info save system
using namespace std;

string a, direct, vis, dep, arr, inf;
int b, c;
bool isKnown, isDefault;

int main() {
    int temp1;
    string temp2;

    // Banner
    cout << "  _____            _______ _____  _____ \n";
    cout << " |  __ \\        /\\|__   __|_   _|/ ____|\n";
    cout << " | |__) |___   /  \\  | |    | | | (___ \n";
    cout << " |  _  // _ \\ / /\\ \\ | |    | |  \\___ \\ \n";
    cout << " | | \\ \\ (_) / ____ \\| |   _| |_ ____) |\n";
    cout << " |_|  \\_\\___/_/    \\_\\_|  |_____|_____/ \n" << endl;
    cout << ">> Welcome in RoATIS!" << endl << ">> Application Version 0.0.2!" << endl << ">> Made by kronset_" << endl << ">> Follow me on github https://github.com/Kronset!\n" << endl;

    // Input airport ICAO code
    cout << "What's your airport ICAO code?" << endl << ">> ";
    cin >> a;

    // Check if ICAO is known
    // add if todo done a == "JTPH" || a == "JSLL" || a == "JC04"
    if (!a.empty()) {
        cout << "Your ICAO is: " << a << endl << endl;
        // change to true when todo done
        isKnown = false;
    }
    else if (!a.empty()) {
        cout << "Your ICAO is: " << a << endl << endl;
        isKnown = false;
    }
    else {
        cout << "Invalid Input!" << endl;
        return 0;
    }

    // Set wind speed
    cout << "Wind (in kts)" << endl << ">> ";
    cin >> b;
    if (b > 0) {
        cout << "Wind set to: " << b << " kts\n" << endl;
    }
    else {
        cout << "Invalid Input!" << endl;
        return 0;
    }

    // Set wind direction
    cout << "Wind direction (in degrees)" << endl << ">> ";
    cin >> c;
    if (c >= 0 && c <= 360) {
        if (c >= 1 && c <= 89) direct = "NW";
        else if (c >= 91 && c <= 179) direct = "SE";
        else if (c >= 181 && c <= 269) direct = "SW";
        else if (c >= 271 && c <= 359) direct = "NW";
        else if (c == 0) direct = "N";
        else if (c == 90) direct = "E";
        else if (c == 180) direct = "S";
        else if (c == 270) direct = "W";

        cout << "Wind direction set to hdg: " << c << " " << direct << endl << endl;
    }
    else {
        cout << "Error! (0x0002)" << endl;
        return 0;
    }

    // Set visibility
    cout << "Visibility (in km)" << endl << ">> ";
    cin >> temp1;
    if (temp1 >= 10) {
        vis = "10 KM OR MORE";
        cout << "Visibility set to: " << vis << endl << endl;
    }
    else if (temp1 < 10 && temp1 > 0) {
        vis = temp1;
    }
    else {
        cout << "Error! (0x0003)" << endl;
        return 0;
    }

    // Set departure and arrival runways
    if (isKnown) {
        cout << "We've detected your ICAO in our database! So you don't have to set up runways!" << endl << "Do you want to use default dep / arr config for " << a << "? (yes/no)" << endl;
        cin >> temp2;
        if (!temp2.empty() && temp2 == "yes") {
            isDefault = true;
        }
        else if (!temp2.empty() && temp2 == "no") {
            isDefault = false;
        }
        else {
            cout << "Error! (0x0004)" << endl;
            return 0;
        }
    }
    //change before 1.0.1
    else {
        cout << "Your airport isn't in our database, you have to insert your runways manually"<< endl;
    }
    //Runway set
    cout << "Insert runway for departures" << endl << ">> ";
    cin >> dep;
    cout << "Insert runway for arrivals" << endl << ">> ";
    cin >> arr;
    //Information end...
    cout << "Name wanted information (A-Z)" << endl << ">> ";
    cin >> inf;
    cout << "Generated ATIS: " << endl;
    cout << "THIS IS " << a << " INFROMATION " << inf << " WIND " << c << " KTS " << "HEADING " << direct << " VISIBILITY " << vis << " KM " << "EXPECT APPROACH TO RUNWAY " << arr << " ON INITIAL CONTACT ADVICE " << inf << " ON BOARD " << a << " OUT ";
    system("PAUSE");
    return 0;
}
