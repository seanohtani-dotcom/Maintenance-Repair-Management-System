#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* =========================
   RepairJob CLASS
   ========================= */
class RepairJob {
private:
    int id;
    string device;
    string problem;
    string technician;
    string status;

public:
    RepairJob(int i, string d, string p) {
        id = i;
        device = d;
        problem = p;
        technician = "Not Assigned";
        status = "Pending";
    }

    int getId() {
        return id;
    }

    string getStatus() {
        return status;
    }

    void assignTechnician(string tech) {
        technician = tech;
        status = "In Progress";
    }

    void markFixed() {
        status = "Fixed";
    }

    void display() {
        cout << "Job ID     : " << id << endl;
        cout << "Device     : " << device << endl;
        cout << "Problem    : " << problem << endl;
        cout << "Technician : " << technician << endl;
        cout << "Status     : " << status << endl;
        cout << "-------------------------------\n";
    }
};

/* =========================
   RepairSystem CLASS
   ========================= */
class RepairSystem {
private:
    vector<RepairJob> jobs;
    int nextId;

public:
    RepairSystem() {
        nextId = 1;
    }

    void addJob() {
        string device, problem;
        cin.ignore();

        cout << "Enter device name: ";
        getline(cin, device);

        cout << "Enter problem description: ";
        getline(cin, problem);

        jobs.push_back(RepairJob(nextId, device, problem));
        cout << "Repair job added with ID " << nextId << endl;
        nextId++;
    }

    void viewJobs() {
        if (jobs.empty()) {
            cout << "No repair jobs found.\n";
            return;
        }

        for (int i = 0; i < jobs.size(); i++) {
            jobs[i].display();
        }
    }

    void assignTechnician() {
        int id;
        string tech;

        cout << "Enter Job ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter technician name: ";
        getline(cin, tech);

        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i].getId() == id) {
                jobs[i].assignTechnician(tech);
                cout << "Technician assigned successfully.\n";
                return;
            }
        }

        cout << "Job ID not found.\n";
    }

    void markJobFixed() {
        int id;
        cout << "Enter Job ID: ";
        cin >> id;

        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i].getId() == id) {
                jobs[i].markFixed();
                cout << "Job marked as FIXED.\n";
                return;
            }
        }

        cout << "Job ID not found.\n";
    }

    void viewByStatus() {
        string status;
        cin.ignore();

        cout << "Enter status (Pending / In Progress / Fixed): ";
        getline(cin, status);

        bool found = false;

        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i].getStatus() == status) {
                jobs[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "No jobs with status: " << status << endl;
        }
    }
};

/* =========================
   MAIN FUNCTION
   ========================= */
int main() {
    RepairSystem system;
    int choice;

    do {
        cout << "\n=== Maintenance & Repair Management System ===\n";
        cout << "1. Add Repair Job\n";
        cout << "2. View All Jobs\n";
        cout << "3. Assign Technician\n";
        cout << "4. Mark Job as Fixed\n";
        cout << "5. View Jobs by Status\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addJob();
                break;
            case 2:
                system.viewJobs();
                break;
            case 3:
                system.assignTechnician();
                break;
            case 4:
                system.markJobFixed();
                break;
            case 5:
                system.viewByStatus();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

