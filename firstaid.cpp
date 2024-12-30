#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string condition;   // Condition name
    string firstAid;    // First aid information
    int severity;       // Severity level (1-5)
    Node* next;         // Pointer to the next node

    // Constructor to initialize node
    Node(string cond, string aid, int sev) : condition(cond), firstAid(aid), severity(sev), next(nullptr) {}
};

// Function to add a condition to the linked list
void addCondition(Node*& head, const string& condition, const string& firstAid, int severity) {
    Node* newNode = new Node(condition, firstAid, severity);
    newNode->next = head;
    head = newNode;
}

// Function to retrieve first aid information for a specific condition
void getFirstAidInfo(Node* head, const string& condition) {
    Node* current = head;
    while (current) {
        if (current->condition == condition) {
            cout << "\n=====================================\n";
            cout << "First Aid for " << condition << ":\n" << current->firstAid << endl;
            cout << "Severity Level: " << current->severity << "/5" << endl;
            cout << "=====================================\n";
            return;
        }
        current = current->next;
    }
    cout << "\nCondition not found! Please consult a medical professional.\n";
}

// Function to sort the linked list alphabetically by condition name
void sortConditionsByName(Node*& head) {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->condition > current->next->condition) {
                swap(current->condition, current->next->condition);
                swap(current->firstAid, current->next->firstAid);
                swap(current->severity, current->next->severity);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Function to sort the linked list by severity level (descending)
void sortConditionsBySeverity(Node*& head) {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->severity < current->next->severity) {
                swap(current->condition, current->next->condition);
                swap(current->firstAid, current->next->firstAid);
                swap(current->severity, current->next->severity);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Function to display all conditions and their first aid information
void displayAllConditions(Node* head) {
    if (!head) {
        cout << "\nNo conditions available.\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "Conditions and First Aid Information:\n";
    cout << "=====================================\n";
    Node* current = head;
    while (current) {
        cout << "- " << current->condition << "\n  First Aid: " << current->firstAid << "\n  Severity Level: " << current->severity << "/5\n";
        cout << "-------------------------------------\n";
        current = current->next;
    }
}

// Function to list basic first aid kit items
void listFirstAidKitItems() {
    cout << "\n=====================================\n";
    cout << "Essential items in a First Aid Kit:\n";
    cout << "=====================================\n";
    cout << "1. Sterile gauze and bandages\n";
    cout << "2. Antiseptic wipes\n";
    cout << "3. Pain relievers (ibuprofen, paracetamol)\n";
    cout << "4. Adhesive bandages (band-aids)\n";
    cout << "5. Tweezers\n";
    cout << "6. Scissors\n";
    cout << "7. Elastic bandages\n";
    cout << "8. Antiseptic cream\n";
    cout << "9. Hand sanitizer\n";
    cout << "10. Burn ointment\n";
    cout << "11. Cotton balls/swabs\n";
    cout << "12. Thermometer\n";
    cout << "13. Ice packs (instant cold packs)\n";
    cout << "14. Disposable gloves\n";
    cout << "15. CPR mask\n";
    cout << "16. Eye wash solution\n";
    cout << "17. Cough syrup\n";
    cout << "18. Hydrocortisone cream\n";
    cout << "19. Oral rehydration salts\n";
    cout << "20. Antibiotics (if prescribed)\n";
}

// Function to display emergency contact numbers
void displayEmergencyContacts() {
    cout << "\n=====================================\n";
    cout << "Emergency Contacts:\n";
    cout << "=====================================\n";
    cout << "1. Ambulance: 108\n";
    cout << "2. Police: 100\n";
    cout << "3. Fire Brigade: 101\n";
    cout << "4. Women Helpline: 1091\n";
    cout << "5. Disaster Management Services: 108\n";
    cout << "6. Child Helpline: 1098\n";
    cout << "7. National Poison Control: 1800-11-7575\n";
    cout << "8. Blood Bank: 104\n";
    cout << "9. Road Accident Emergency: 1033\n";
    cout << "10. NATIONAL EMERGENCY NUMBER: 112\n";
}

// Function to dynamically add a condition via user input
void addConditionFromUser(Node*& head) {
    cin.ignore(); // Clear input buffer
    string condition, firstAid;
    int severity;

    cout << "\nEnter the condition name: ";
    getline(cin, condition);
    cout << "Enter the first aid instructions: ";
    getline(cin, firstAid);
    do {
        cout << "Enter the severity level (1-5): ";
        cin >> severity;
        if (severity < 1 || severity > 5)
            cout << "Invalid severity level. Please enter a value between 1 and 5.\n";
    } while (severity < 1 || severity > 5);

    addCondition(head, condition, firstAid, severity);
    cout << "\nCondition added successfully!\n";
}

// Main function
int main() {
    Node* firstAidList = nullptr;

    // Load first aid information into the linked list
    addCondition(firstAidList, "burn", "Cool the burn with running water for at least 10 minutes. Cover with sterile gauze.", 3);
    addCondition(firstAidList, "asthma", "Help the person sit upright. Assist them with their inhaler if they have one. Call emergency if condition worsens.", 4);
    addCondition(firstAidList, "seizure", "Clear the area of harmful objects. Don't restrain the person. Roll them onto their side after the seizure stops.", 5);
    addCondition(firstAidList, "choking", "Give 5 back blows between the shoulder blades with the heel of your hand. Perform abdominal thrusts if needed.", 5);
    addCondition(firstAidList, "snake bite", "Keep the person calm and still. Immobilize the limb and keep it lower than the heart. Seek emergency medical help.", 5);
    addCondition(firstAidList, "heart attack", "Call emergency services immediately. Keep the person calm and seated. Provide aspirin if not allergic.", 5);
    addCondition(firstAidList, "stomach ache", "Drink plenty of fluids. Avoid solid food for a while. If severe or persistent, seek medical advice.", 2);
    addCondition(firstAidList, "low blood pressure", "Help the person lie down. Elevate their legs above heart level. Provide fluids if they're conscious.", 3);
    addCondition(firstAidList, "nausea", "Encourage them to sit in a well-ventilated area. Provide clear fluids and avoid strong smells.", 1);
    addCondition(firstAidList, "nosebleed", "Have the person sit and lean forward. Pinch their nose for 10 minutes.", 2);
    addCondition(firstAidList, "fracture", "Immobilize the affected area. Avoid movement. Seek medical help.", 4);
    addCondition(firstAidList, "heat stroke", "Move the person to a cool place. Provide cool water to drink. Cool their body with wet cloths.", 4);
    addCondition(firstAidList, "frostbite", "Move the person to a warm place. Warm the affected area with body heat or warm water.", 3);
    addCondition(firstAidList, "drowning", "Call for emergency help. Begin CPR if trained and needed.", 5);
    addCondition(firstAidList, "poisoning", "Identify the substance. Call a poison control center or seek immediate medical help.", 5);
    addCondition(firstAidList, "allergic reaction", "Administer antihistamines or an epinephrine injection if prescribed. Call emergency services if severe.", 4);
    addCondition(firstAidList, "head injury", "Apply a cold pack to reduce swelling. Seek immediate medical attention if severe.", 4);
    addCondition(firstAidList, "sprain", "Apply ice to the injured area. Elevate the limb and wrap it with a bandage.", 2);
    addCondition(firstAidList, "diabetic emergency", "Provide sugary drinks or glucose tablets if the person is conscious. Call emergency services if needed.", 4);
    addCondition(firstAidList, "eye injury", "Rinse the eye with clean water. Avoid rubbing. Cover with a sterile dressing and seek medical attention.", 3);

    int choice;
    do {
        cout << "\n---- Digital First Aid App ----\n";
        cout << "1. Get First Aid Info\n";
        cout << "2. Display All Conditions (Sorted by Name)\n";
        cout << "3. Display All Conditions (Sorted by Severity)\n";
        cout << "4. List First Aid Kit Items\n";
        cout << "5. Display Emergency Contacts\n";
        cout << "6. Add a New Condition\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear input buffer
                string condition;
                cout << "Enter the condition (e.g., burn, asthma): ";
                getline(cin, condition);
                getFirstAidInfo(firstAidList, condition);
                break;
            }
            case 2:
                sortConditionsByName(firstAidList);
                displayAllConditions(firstAidList);
                break;
            case 3:
                sortConditionsBySeverity(firstAidList);
                displayAllConditions(firstAidList);
                break;
            case 4:
                listFirstAidKitItems();
                break;
            case 5:
                displayEmergencyContacts();
                break;
            case 6:
                addConditionFromUser(firstAidList);
                break;
            case 7:
                cout << "Exiting the app. Stay safe!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    // Free memory allocated for the linked list
    while (firstAidList) {
        Node* temp = firstAidList;
        firstAidList = firstAidList->next;
        delete temp;
    }

    return 0;
}