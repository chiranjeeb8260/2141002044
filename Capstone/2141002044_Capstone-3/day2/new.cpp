#include<iostream>
#include<fstream>
#include<sstream>
#include<thread>
#include<chrono>
using namespace std;

struct CPUData
{
long user,nice,system,idle,iowait,irq,softirq,steal,guest,guest_nice;
};

CPUData getCPUData(){

ifstream file("/proc/stat");

string line;
CPUData cpu={};

if(file.is_open()){
getline(file,line); //read first line
istringstream ss(line);

string cpuLabel;

ss >> cpuLabel >> cpu.user >> cpu.nice >> cpu.system >> cpu.idle >> cpu.iowait >> cpu.irq >> cpu.softirq >> cpu.steal >> cpu.guest >> cpu.guest_nice;
}
return cpu;

}

double calculateCPUUsage(CPUData prev,CPUData current)
{
long prevIdle=prev.idle+prev.iowait;
long currIdle=current.idle+current.iowait;
long prevTotal=prev.user+prev.nice+prev.system+prev.idle + prev.irq+prev.softirq+prev.steal;
long currTotal= current.user+current.nice+current.system+currIdle+current.irq+current.softirq+current.steal;

long totalDiff=currTotal - prevTotal;
long idleDiff=currIdle - prevIdle;
return (totalDiff-idleDiff)*100.0/totalDiff;
}

int main()
{
  CPUData prevData=getCPUData();
  
  this_thread::sleep_for(chrono::seconds(1)); 
  
  CPUData currData=getCPUData();
  
  double cpuUsage = calculateCPUUsage(prevData,currData);
  
  cout<<"CPU USAGE:"<<cpuUsage<<"%\n";
  

  
  CPUData cpu = getCPUData();
  std::cout<<"user Time:"<<cpu.user<<"\n";
  
  long cputime=cpu.user+cpu.nice+cpu.system+cpu.idle+cpu.irq+cpu.softirq+cpu.steal;
  std::cout<<"Total cpu Time:"<<cputime<<"\n";
  
  long idletime=cpu.idle+cpu.iowait;
  
  long cpuusage=((cputime-idletime)/cputime)*100;
    std::cout<<"cpu usage:"<<cpuusage<<"\n";
    
 return 0;
}
  
  
  
  
  
  
  
  
  
  
