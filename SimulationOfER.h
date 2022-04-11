#pragma once
void registerPatient(priority_queue<Patient> &waitingRoom)
{
    Patient buffer;
    buffer.setName(inputString("Enter the patient's name: ", true));
    buffer.setAge(inputInteger("Enter the patient's age in years: ", 0, 150));
    buffer.setGender(inputStatus("Enter the patient's gender (F-female or M-male)", 'F', 'M'));
    buffer.setCheckedInTime(time(0));
    buffer.setPriority(inputInteger("Choose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
    waitingRoom.push(buffer);
}

void transferPatient(priority_queue<Patient> &waitingRoom, priority_queue<Patient> &transfered)
{
    if (waitingRoom.size() == 0)
    {
        cout << "No patientes regestered." << endl;
        return;
    }
    Patient buffer = waitingRoom.top();
    cout << buffer.getName();

    if (buffer.getPriority() == 1)
        cout << " examines and gives prescription...";
    else if (buffer.getPriority() == 2)
        cout << " transfers to x-ray lab...";
    else if (buffer.getPriority() == 3)
        cout << " transfers to emergency room...";
    else if (buffer.getPriority() == 4)
        cout << " transfers to surgery room...";
    else if (buffer.getPriority() == 5)
        cout << " transfers to ICU...";

    waitingRoom.pop();
    transfered.push(buffer);

}

void displayTansferredPatients(priority_queue<Patient> transferred)
{
    if (transferred.size() == 0)
    {
        cout << "No patientes transferred." << endl;
        return;
    }

    int loopCount = transferred.size();
    for (int i = 0; i < loopCount; i++)
    {
        cout << transferred.top() << endl;
        transferred.pop();
    }
}

int patientMenuOption()
{
    
    cout << endl << "2 > Simulation of an emergency room(ER) using priority queue STL";
    cout << endl << "==========================================";
    cout << endl << "1> Register a patient";
    cout << endl << "2> Transfer patient(s) to the designation";
    cout << endl << "3> Display transferred patients";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}

void SimOfER()
{
	priority_queue<Patient> waitingRoom;
	priority_queue<Patient> transferred;

    do
    {
        switch (patientMenuOption())
        {
        case 0: return; break;
        case 1: registerPatient(waitingRoom); break;
        case 2: transferPatient(waitingRoom, transferred); break;
        case 3: displayTansferredPatients(transferred); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}