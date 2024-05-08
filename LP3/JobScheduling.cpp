#include<bits/stdc++.h>

using namespace std;

struct Job
{
	int job_id; // Corrected member name from 'id' to 'job_id'
	int profit;
	int deadline;
};

bool sortByProfit(const Job &job1, const Job &job2)
{
	return job1.profit > job2.profit;
}

void scheduleJob(vector<Job> &jobs) // Corrected parameter type from 'vector<int>' to 'vector<Job>'
{
	sort(jobs.begin(), jobs.end(), sortByProfit);

	int maxDeadline = 0;
	for(auto job : jobs)
	{
		maxDeadline = max(maxDeadline, job.deadline);
	}

	vector<int> slots(maxDeadline, -1);
	vector<Job> scheduledJobs; // Corrected variable name from 'scheduleJobs' to 'scheduledJobs'
	int totalProfit = 0;

	for(auto job : jobs)
	{
		for(int slot = job.deadline - 1; slot >= 0; slot--)
		{
			if(slots[slot] == -1)
			{
				slots[slot] = job.job_id;
				scheduledJobs.push_back(job);
				totalProfit += job.profit;
				break; // Added break statement to exit inner loop after scheduling the job
			}
		}
	}
	
	cout << "Scheduled Jobs : " << endl;
	cout << "----------------------------------------" << endl; // Added endl for line breaks
	cout << "Job_ID\tProfit\tDeadline" << endl; // Corrected format for header line
	cout << "----------------------------------------" << endl; // Added endl for line breaks
	for(auto job : scheduledJobs)
	{
		cout << job.job_id << "\t" << job.profit << "\t" << job.deadline << endl;
	}
	cout << "----------------------------------------" << endl; // Added endl for line breaks
	cout << "\tTotal Profit : " << totalProfit << endl;
	cout << "----------------------------------------" << endl; // Added endl for line breaks
}

int main()
{
	int n;
	cout << "Enter No of Jobs : ";
	cin >> n;

	vector<Job> jobs(n);
		
	cout << "\nEnter details of the job : " << endl; // Added endl for line breaks
	for(int i=0; i<n; i++)
	{
		cout << "Job " << (i+1) << endl;
		cout << "Enter the id of the job : ";
		cin >> jobs[i].job_id;
		cout << "Enter the profit of the job : ";
		cin >> jobs[i].profit;
		cout << "Enter the deadline of the job : ";
		cin >> jobs[i].deadline;
	}

	scheduleJob(jobs);
 
	return 0;
}
