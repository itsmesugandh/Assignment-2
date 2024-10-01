#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_OFFICERS = 100;

class Officer {
public:
    char name[100];
    char position[100];
    char email[100];
    char phone[15];
    char room[15];

    Officer() {
        name[0] = '\0';
        position[0] = '\0';
        email[0] = '\0';
        phone[0] = '\0';
        room[0] = '\0';
    }

    Officer(const char* name, const char* position,
            const char* email, const char* phone,
            const char* room) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        strncpy(this->position, position, sizeof(this->position) - 1);
        this->position[sizeof(this->position) - 1] = '\0';
        strncpy(this->email, email, sizeof(this->email) - 1);
        this->email[sizeof(this->email) - 1] = '\0';
        strncpy(this->phone, phone, sizeof(this->phone) - 1);
        this->phone[sizeof(this->phone) - 1] = '\0';
        strncpy(this->room, room, sizeof(this->room) - 1);
        this->room[sizeof(this->room) - 1] = '\0';
    }
};

class Registry {
private:
    Officer officers[MAX_OFFICERS];
    int count;

public:
    Registry() : count(0) {}

    void loadFromCSV(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file." << std::endl;
            return;
        }

        char line[256];
        // Skip the header line
        file.getline(line, sizeof(line)); 

        while (file.getline(line, sizeof(line)) && count < MAX_OFFICERS) {
            char title[100], name[100], position[100], email[100], phone[15], room[15];
            sscanf(line, "%99[^,],%99[^,],%99[^,],%99[^,],%14[^,],%14[^,]",
                   title, name, position, email, phone, room);
            officers[count++] = Officer(name, position, email, phone, room);
        }
        file.close();
    }

    void fetchOfficerDetails(const char* name) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(officers[i].name, name) == 0) {
                std::cout << "Name: " << officers[i].name << "\n"
                          << "Position: " << officers[i].position << "\n"
                          << "Email: " << officers[i].email << "\n"
                          << "Phone: " << officers[i].phone << "\n"
                          << "Room: " << officers[i].room << "\n";
                return;
            }
        }
        std::cout << "Officer not found.\n";
    }
};

int main() {
    Registry registry;
    registry.loadFromCSV("administrative.csv");

    char name[100];
    std::cout << "Enter the name of the officer: ";
    std::cin.getline(name, sizeof(name));

    registry.fetchOfficerDetails(name);

    return 0;
}
