11.	Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue.






#include <iostream>
#include <queue>
#include <string>
using namespace std;
// Function to add a job to the queue
void addJob(queue<string>& jobQueue, const string& job) {
 jobQueue.push(job); 
 cout << "Job '" << job << "' added to the queue." << endl;
}
// Function to delete a job from the queue
void deleteJob(queue<string>& jobQueue) {
 if (!jobQueue.empty()) {
 cout << "Job '" << jobQueue.front() << "' completed and removed from the queue." 
<< endl;
 jobQueue.pop(); 
 } else {
 cout << "No jobs in the queue to delete." << endl;
 }
}
// Function to display the current jobs in the queue
void displayJobs(queue<string> jobQueue) {
 if (jobQueue.empty()) {
 cout << "No jobs in the queue." << endl;
 } else {
 cout << "Current jobs in the queue: ";
 while (!jobQueue.empty()) {
 cout << jobQueue.front() << " "; // Display the job at the front
 jobQueue.pop(); // Move to the next job
 }
 cout << endl;
 }
}
int main() {
 queue<string> jobQueue; // Job queue to store jobs
 int choice;
 string job;
 do {
 // Display menu for the user
 cout << "\nJob Queue Simulation Menu\n";
 cout << "1. Add Job\n";
 cout << "2. Delete Job\n";
 cout << "3. Display Jobs\n";
 cout << "4. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter job description: ";
 cin.ignore(); // To ignore the newline character left by cin
 getline(cin, job); // Read the job description
 addJob(jobQueue, job);
 break;
 case 2:
 deleteJob(jobQueue);
 break;
 case 3:
 displayJobs(jobQueue);
 break;
 case 4:
 cout << "Exiting..." << endl;
 break;
 default:
 cout << "Invalid choice, please try again." << endl;
 }
 } while (choice != 4);
 return 0;
}

