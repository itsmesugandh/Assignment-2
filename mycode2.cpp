#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

const int MAX_DEPARTMENTS = 10; // Number of departments
const int MAX_FACULTY = 100;     //Number of faculty per department

class Faculty {
public:
    std::string name;
    std::string title;
    std::string contactNumber;
    std::string email;
    std::string room;

    // "Create a constructor that initializes all member variables, including the positions array, names array, and issue count
    Faculty(const std::string& n = "", const std::string& t = "", 
            const std::string& cn = "", const std::string& e = "", 
            const std::string& r = "") 
        : name(n), title(t), contactNumber(cn), email(e), room(r) {}
};

class Department {
public:
    std::string name;
    Faculty facultyList[MAX_FACULTY];
    int facultyCount;

    Department() : name(""), facultyCount(0) {}

    void addFaculty(const Faculty& faculty) {
        if (facultyCount < MAX_FACULTY) {
            facultyList[facultyCount++] = faculty;
        }
    }

    void displayFaculty() const {
        std::cout << "Faculty in " << name << " Department:\n";
        
        // Initilize the HOD's Name
        for (int i = 0; i < facultyCount; i++) {
            if (facultyList[i].title.find("Head") != std::string::npos) {
                std::cout << "HOD: " << facultyList[i].name 
                          << ", Title: " << facultyList[i].title
                          << ", Contact: " << facultyList[i].contactNumber 
                          << ", Email: " << facultyList[i].email 
                          << ", Room: " << facultyList[i].room << '\n';
                break; // Only display one HOD
            }
        }

        // Display other faculty staf's
        for (int i = 0; i < facultyCount; i++) {
            if (facultyList[i].title.find("Head") == std::string::npos) {
                std::cout << "Name: " << facultyList[i].name 
                          << ", Title: " << facultyList[i].title
                          << ", Contact: " << facultyList[i].contactNumber 
                          << ", Email: " << facultyList[i].email 
                          << ", Room: " << facultyList[i].room << '\n';
            }
        }
    }
};

class University {
private:
    Department departments[MAX_DEPARTMENTS];
    int departmentCount;

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

public:
    University() : departmentCount(0) {}

    void loadFacultyData(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file.\n";
            return;
        }

        std::string line;
        while (getline(file, line)) {
            std::istringstream ss(line);
            std::string name, title, department, contactNumber, email, room;
            std::getline(ss, name, ',');
            std::getline(ss, title, ',');
            std::getline(ss, department, ',');
            std::getline(ss, contactNumber, ',');
            std::getline(ss, email, ',');
            std::getline(ss, room, ',');

            // Implement a method to trim and normalize the department name
            department = trim(department);
            for (char& c : department) c = toupper(c);

            // 	Implement a mechanism to handle multiple departments
            std::istringstream deptStream(department);
            std::string singleDept;
            while (std::getline(deptStream, singleDept, ';')) {
                singleDept = trim(singleDept);
                for (char& c : singleDept) c = toupper(c);

                // Check if the department already exists
                bool found = false;
                for (int i = 0; i < departmentCount; i++) {
                    if (departments[i].name == singleDept) {
                        departments[i].addFaculty(Faculty(name, title, contactNumber, email, room));
                        found = true;
                        break;
                    }
                }

                // If not found, create a new department
                if (!found && departmentCount < MAX_DEPARTMENTS) {
                    departments[departmentCount].name = singleDept;
                    departments[departmentCount].addFaculty(Faculty(name, title, contactNumber, email, room));
                    departmentCount++;
                }
            }
        }

        file.close();

        // Print loaded departments for debugging
        std::cout << "Loaded Departments:\n";
        for (int i = 0; i < departmentCount; i++) {
            std::cout << departments[i].name << std::endl;
        }
    }

    void displayDepartment(const std::string& deptName) {
        std::string normalizedDeptName = deptName;
        for (char& c : normalizedDeptName) c = toupper(c);

        for (int i = 0; i < departmentCount; i++) {
            if (departments[i].name == normalizedDeptName) {
                departments[i].displayFaculty();
                return;
            }
        }
        std::cout << "Department not found.\n";
    }
};

int main() {
    University uni;
    uni.loadFacultyData("academic.csv");

    std::string deptName;
    std::cout << "Enter the department name (ECE, SSH, Math, CB, CSE): ";
    std::getline(std::cin, deptName);
    
    uni.displayDepartment(deptName);

    return 0;
}
