/*--- Author 
	  Hasheem Ahmed ---*/

// Iostream for cout cin
#include <iostream>

//Iomanip for the setw and setfill
#include <iomanip>
using namespace std;

// First Come First Serve Algorithm Class

class FCFS
{
public:

	// Variables
	int NumberOfProcess;
	int* Proc;
	int *AT;
	int *BT;
	int *CT;
	int *WT;
	int *TAT;


	//Default Constructor
	FCFS()
	{
		NumberOfProcess = 0;
		AT = BT = CT = WT = TAT = Proc =  NULL;
	}

	//Parameterized Constructor
	FCFS(int Process)
	{
		this->NumberOfProcess = Process;
		Proc = new int[Process];
		AT = new int[Process];
		BT = new int[Process];
		CT = new int[Process];
		WT = new int[Process];
		TAT = new int[Process];
	}

	// Input the arrival time and burst time values
	void ATinput()
	{
		cout << "Enter the Arrival and Burst time : ";
		for (int i = 0; i < NumberOfProcess; i++)
		{
			cout << "P" << i + 1 << " - \n";
			this->Proc[i] = i + 1;
			cout << "Arrival Time : ";
			cin >> this->AT[i];
			cout << "Burst Time : ";
			cin >> this->BT[i];
		}
	}

	// calculating the completion time
	void CalculatingCT()
	{
		CT[0] = BT[0];
		for(int i = 1; i < NumberOfProcess; i++)
		{
			this->CT[i] = this->CT[i - 1] + this->BT[i];
		}
	}


	// Calculating the waiting time
	void CalculatingWT()
	{
		for (int i = 0; i < NumberOfProcess; i++)
		{
			this->WT[i] = this->CT[i] - (this->AT[i] + this->BT[i]);
		}
	}


	// calculating turn around time
	void CalculatingTAT()
	{
		for (int i = 0; i < NumberOfProcess; i++)
		{
			this->TAT[i] = this->WT[i] + this->BT[i];
		}
	}

	// Swap function for Sorting Values using pass by reference
	void swap(int &x, int &y)
	{
		int temp = x;
		x = y;
		y = temp;
	}

	//Sorting the Arrival time values by BUBBLE SORT
	void SortingATandBT()
	{
		bool sort = true;
		while (sort)
		{
			sort = false;
			for (int i = 0; i < this->NumberOfProcess - 1; i++)
			{
				if (this->AT[i] > this->AT[i + 1])
				{
					swap(this->AT[i], this->AT[i + 1]);
					swap(this->BT[i], this->BT[i + 1]);
					swap(this->Proc[i], this->Proc[i + 1]);
					sort = true;
				}
			}
		}
	}

	// calculating the average waiting time
	float AvgWaitingTime()
	{
		float avgWaitingTime = 0;

		for (int i = 0; i < this->NumberOfProcess; i++)
		{
			avgWaitingTime += this->WT[i];
		}

		return avgWaitingTime/this->NumberOfProcess;
	}

};

// Main Function
int main()
{
	// User Input for Number of Process
	int Process;
	cout << "Enter Number of Process : ";
	cin >> Process;

	// making Object of the FCFS class and initializing the Number of process
	FCFS obj(Process);


	// Taking Input of the Arrival time and Burst time
	obj.ATinput();

	// Sorting the Arrival Time For the First Come First Serve - FCFS
	obj.SortingATandBT();

	// Calculating the Completion time, Waiting Time , Turn Around Time
	obj.CalculatingCT();
	obj.CalculatingWT();
	obj.CalculatingTAT();

    // Use to clear console
	system("cls");

	// MAking the Table for the output
	cout << setw(70) << setfill('-') << " \n";
	cout << setfill(' ') << "|              First Come First Serve - FCFS                       |\n";
	cout << setw(70) << setfill('-') << " \n";
	cout <<"|" << setfill(' ') << "Process    |    AT    |    BT    |    CT    |    WT    |    TAT   |\n";
	cout << setw(70) << setfill('-') << " \n";
	cout << setfill(' ');


	// Outputting the Values of AT, BT, Ct, WT, TAT
	for (int i = 0; i < obj.NumberOfProcess; i++)
	{
		cout << "|";
		cout << setw(10) << "P" << obj.Proc[i] << "|";
		cout << setw(10) << obj.AT[i] << "|";
		cout << setw(10) << obj.BT[i] << "|";
		cout << setw(10) << obj.CT[i] << "|";
		cout << setw(10) << obj.WT[i] << "|";
		cout << setw(10) << obj.TAT[i] << "|\n";
	}


	// Outputting Average Waiting Time
	cout << setw(70) << setfill('-') << " \n";
	cout << "|" << setw(56) << setfill(' ') <<" Average Waiting Time |" << setw(10) << obj.AvgWaitingTime() <<  "|\n";
	cout << setw(70) << setfill('-') << " \n";

	return 0;
}