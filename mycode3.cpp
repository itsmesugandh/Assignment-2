#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Design a class to manage a hierarchical structure and facilitate issue escalation
class Hierarchy {
private:
    static const int MAX = 100;  // Specify the maximum no. of positions in the hierarchy
    string positions[MAX];  // declare an array to store the positions in the hierarchy
    string names[MAX];  // declare an array to store the names
    string emails[MAX];  // declare an array to  store emails
    string phones[MAX];  // declare an  Array to store phone numbers
    string rooms[MAX];  // declare an Array to store room numbers
    int levels[MAX];  // declare an  Array to store levels
    string issueTypes[5] = {"Academics", "Accounts", "IRD", "Store & Purchase", "Student Affairs"};
    int count;  // Total number of entries

    // Implement a private method to calculate the level of a position with in the hierarchy
    int getLevel(const string &position) {
        if (position.find("Deputy Administrative Officer") != string::npos ||
            position.find("Junior Administrative Officer") != string::npos ||
            position.find("Assistant Administrative Officer") != string::npos) {
            return 1;
        }
        if (position.find("Administrative Officer") != string::npos) {
            return 2;
        }
        if (position.find("Dean") != string::npos) {
            return 3;
        }
        if (position.find("Registrar") != string::npos) {
            return 4;  // Registrar is now Level 4
        }
        if (position.find("Director") != string::npos) {
            return 5;  // Directors are Level 5
        }
        return 0;  // Not More level listed
    }

public:
    // Create a constructor to initialize a counter to 0
    Hierarchy() : count(0) {}

    // Method to load the hierarchy from CSV file
    void loadHierarchy(const string &filePath) {
        ifstream file(filePath);
        string line;

        // Skip the header
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string position, name, title, email, phone, room;

            // Split the line by commas
            getline(ss, position, ',');
            getline(ss, name, ',');
            getline(ss, title, ',');  // title read , but not used
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, room, ',');  // Read the room

            // Store the details in the arrays
            positions[count] = position;
            names[count] = name;
            emails[count] = email;
            phones[count] = phone;
            rooms[count] = room;  // Store room
            levels[count] = getLevel(position);  // Determine level for each position
            count++;
        }

        file.close();
    }

    // "Create a method to present the available issue types .
    void displayIssueTypes() {
        cout << "Select the type of issue:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << issueTypes[i] << endl;
        }
        cout << "Enter the number corresponding to the issue type: ";
    }

    // Implement a method to accept an issue as input and initiate the escalation process
    void submitIssue() {
        int issueChoice;

        // Display issue types and get user choice
        displayIssueTypes();
        cin >> issueChoice;

        // Validate user input
        if (issueChoice < 1 || issueChoice > 5) {
            cout << "Invalid choice. Please select a number between 1 and 5." << endl;
            return;
        }

        // Get the selected issue type
        string issue = issueTypes[issueChoice - 1];
        cout << "Issue submitted: " << issue << endl;
        cout << "Submitting the issue to Level 1 officers..." << endl;

        escalateIssue(issueChoice);
    }

    // Method to escalate the issue
    void escalateIssue(int issueChoice) {
        string response;

        // Function to handle resolution checking
        auto checkResolution = [&response]() {
            while (true) {
                cout << "Has the issue been resolved after 3 days? (yes/no): ";
                cin >> response;
                if (response == "yes" || response == "no") {
                    break;
                } else {
                    cout << "Incorrect input. Please enter 'yes' or 'no'." << endl;
                }
            }
        };

        // Level 1 (comprising Junior, Assistant, or Deputy Administrative Officers.)
        cout << "\nLevel 1 (Junior/Assistant/Deputy Administrative Officers):" << endl;
        bool foundLevel1 = false;

        for (int i = 0; i < count; i++) {
            if (levels[i] == 1) {
                foundLevel1 = true;
                cout << "Position: " << positions[i] << "\n"
                     << "Name: " << names[i] << "\n"
                     << "Email: " << emails[i] << "\n"
                     << "Phone: " << phones[i] << "\n"
                     << "Room: " << rooms[i] << "\n" << endl;  // Print room
            }
        }

        if (!foundLevel1) {
            cout << "No Level 1 officers found for the selected issue type.\n";
            return;
        }

        checkResolution();
        if (response == "yes") {
            cout << "Issue resolved at Level 1." << endl;
            return;
        }

        // Level 2 (Administrative Officers)
        cout << "\nLevel 2 (Administrative Officers):" << endl;
        bool foundLevel2 = false;

        for (int i = 0; i < count; i++) {
            if (levels[i] == 2) {
                foundLevel2 = true;
                cout << "Position: " << positions[i] << "\n"
                     << "Name: " << names[i] << "\n"
                     << "Email: " << emails[i] << "\n"
                     << "Phone: " << phones[i] << "\n"
                     << "Room: " << rooms[i] << "\n" << endl;  // Print room
            }
        }

        if (!foundLevel2) {
            cout << "No Level 2 officers found for the selected issue type.\n";
            return;
        }

        checkResolution();
        if (response == "yes") {
            cout << "Issue resolved at Level 2." << endl;
            return;
        }

        // Level 3 (Deans)
        cout << "\nLevel 3 (Deans):" << endl;
        bool foundLevel3 = false;
        for (int i = 0; i < count; i++) {
            if (levels[i] == 3) {
                foundLevel3 = true;
                cout << "Position: " << positions[i] << "\n"
                     << "Name: " << names[i] << "\n"
                     << "Email: " << emails[i] << "\n"
                     << "Phone: " << phones[i] << "\n"
                     << "Room: " << rooms[i] << "\n" << endl;  // Print room
            }
        }
        if (!foundLevel3) {
            cout << "No Level 3 officers found.\n";
            return;
        }

        checkResolution();
        if (response == "yes") {
            cout << "Issue resolved at Level 3." << endl;
            return;
        }

        // Level 4 (Registrar)
        cout << "\nLevel 4 (Registrar):" << endl;
        bool foundRegistrar = false;
        for (int i = 0; i < count; i++) {
            if (levels[i] == 4) {  // Check if the position is Registrar
                foundRegistrar = true;
                cout << "Position: " << positions[i] << "\n"
                     << "Name: " << names[i] << "\n"
                     << "Email: " << emails[i] << "\n"
                     << "Phone: " << phones[i] << "\n"
                     << "Room: " << rooms[i] << "\n" << endl;  // Print room
            }
        }
        if (!foundRegistrar) {
            cout << "No Registrar found in the system.\n";
            return;
        }

        checkResolution();
        if (response == "yes") {
            cout << "Issue resolved at Level 4." << endl;
            return;
        }

        // Level 5 (Directors)
        cout << "\nLevel 5 (Directors):" << endl;
        bool foundDirector = false;
        for (int i = 0; i < count; i++) {
            if (levels[i] == 5) {  // Check if the position is Director
                foundDirector = true;
                cout << "Position: " << positions[i] << "\n"
                     << "Name: " << names[i] << "\n"
                     << "Email: " << emails[i] << "\n"
                     << "Phone: " << phones[i] << "\n"
                     << "Room: " << rooms[i] << "\n" << endl;  // Print room
            }
        }
        if (!foundDirector) {
            cout << "No Director found in the system.\n";
        } else {
            cout << "Issue has been escalated to the Director. Further action will be taken against the issue." << endl;
        }
    }
};

int main() {
    Hierarchy hierarchy;

    // Load the hierarchy from the CSV file
    hierarchy.loadHierarchy("administrative.csv");

    // Submit and escalate the issue
    hierarchy.submitIssue();

    return 0;
}
