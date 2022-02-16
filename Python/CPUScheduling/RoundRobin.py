# CPU Scheduling Algorithms: Round Robin

def getProcesses() -> list:
    processes = [] # List of all processes

    numberOfProcesses = int(input('Enter number of processes: '))

    for i in range(0, numberOfProcesses):
        
        arrivalTime = int(input('Enter Arrival Time for process[%d]: '%(i + 1)))
        burstTime = int(input('Enter Burst Time for process[%d]: '%(i + 1)))
        
        # each process is treated as a dictionary
        process = {'Process ID': i, 'Arrival Time': arrivalTime, 'Burst Time': burstTime}
        
        processes.append(process)
    # sorting the processes by its arrival time
    processes.sort(key=lambda process: process['Arrival Time'])

    # print(processes)
    return processes

class RoundRobin:
    def __init__(self, processes: list) -> None:
        self.processes = processes
        self.time = 0 # time value
    
    def _executeProcess(self, process: dict) -> dict:
        remainingBurstTime = process['Burst Time']
        
        startTime = self.time
        
        # add the Response Time
        if 'Response Time' in process.keys():
            pass
        else:
            process['Response Time'] = startTime - process['Arrival Time']

        # simulate the execution
        while(remainingBurstTime > 0):
            remainingBurstTime -= 1
            self.time += 1
        
        endTime = self.time
        
        gantt = {'Process ID': process['Process ID'], 'Start Time': startTime, 'Exit Time': endTime}
        
        # print(gantt)
        return gantt