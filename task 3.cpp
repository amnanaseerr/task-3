#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;
    Task(const string& desc):description(desc),completed(false) {}
};
class ToDoList {
private:
    vector<Task>tasks;
public:
    void addTask(const string& description) 
	{
        tasks.push_back(Task(description));
        cout<<"Task added successfully!"<<endl;
    }
    void viewTasks() {
        if(tasks.empty()) 
		{
            cout<<"No tasks available."<<endl;
            return;
        }
		cout<<"Tasks:"<<endl;
        for(size_t i=0;i<tasks.size();++i) 
		{
            cout<<i+1<<"."<<tasks[i].description<<"-"<<(tasks[i].completed?"Completed":"Pending")<<endl;
        }
    }
    void markTaskCompleted(int index) 
	{
        if(index>=1&&index<=tasks.size()) 
		{
            tasks[index-1].completed=true;
            cout<<"Task marked as completed!"<<endl;
        } 
		else {
            cout<<"Invalid task index!"<<endl;
        }
    }
    void removeTask(int index)
	{
        if(index>=1&&index<=tasks.size())
		{
            tasks.erase(tasks.begin()+index-1);
            cout<<"Task removed successfully!"<<endl;
        } else {
            cout<<"Invalid task index!"<<endl;
        }
    }
};
int main() 
{
    ToDoList todoList;
    int choice;
    do {
        cout<<"\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch (choice) 
		{
            case 1:
                {
                    string taskDescription;
                    cout<<"Enter task description: ";
                    cin.ignore();
                    getline(cin, taskDescription);
                    todoList.addTask(taskDescription);
                }
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                {
                    int taskIndex;
                    cout<<"Enter task index to mark as completed: ";
                    cin>>taskIndex;
                    todoList.markTaskCompleted(taskIndex);
                }
                break;
            case 4:
                {
                    int taskIndex;
                    cout<<"Enter task index to remove: ";
                    cin>>taskIndex;
                    todoList.removeTask(taskIndex);
                }
                break;
            case 5:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    } 
	while (choice != 5);
    return 0;
}

