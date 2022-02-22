# CPU Scheduling Algorithms: First Come First Serve

def getProcesses() -> list:
    processes = [] # List of all processes

    numberOfProcesses = int(input('Enter number of processes: '))

    for i in range(0, numberOfProcesses):
        # reading 'Arrival Time' and 'Burst Time'
        arrivalTime = int(input('Enter Arrival Time for process[%d]: '%(i + 1)))
        burstTime = int(input('Enter Burst Time for process[%d]: '%(i + 1)))
        
        # each process is treated as a dictionary
        process = {'Process ID': i, 'Arrival Time': arrivalTime, 'Burst Time': burstTime}
        
        processes.append(process)

    # sorting the processes by its arrival time
    # processes.sort(key=lambda process: process['Arrival Time'])

    # print(processes)
    return processes


class FCFS:

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

    def simulate(self) -> list:
        ganttChart = []
        
        readyQueue = self.processes
        readyQueue.sort(key=lambda process: process['Arrival Time'])

        # execute each process and generate ganttChart
        for process in readyQueue:
            
            # Check if there is an empty state
            while(process['Arrival Time'] > self.time):
                self.time += 1 # keep CPU empty
            
            gantt = self._executeProcess(process)
            ganttChart.append(gantt)

            # add the completion time
            process['Completion Time'] = gantt['Exit Time']

        # print(ganttChart)
        return ganttChart
    
    def _calculateTimes(self) -> int:
        sum = 0
        
        for process in self.processes:
            # Turn Around Time = Completion Time – Arrival Time || Turn Around Time = Exit time - Arrival time
            process['Turn Around Time'] = process['Completion Time'] - process['Arrival Time']
            # Waiting Time = Turn Around Time – Burst Time
            process['Waiting Time'] = process['Turn Around Time'] - process['Burst Time']
            
            # Sum of Average Waiting Time
            sum += process['Waiting Time']
        
        # Average Waiting Time
        avg = (sum / len(self.processes))
        return avg

    def _printFormattedOutput(self, ganttChart: list, averageWaitingTime: int) -> None:
        
        print()
        print('PID = Process ID')
        print('ST = Start Time')
        print('ET = Exit Time')
        
        print()
        print('PID\tST\tET')
        for gantt in ganttChart:
            id = str(gantt['Process ID'])
            st = str(gantt['Start Time'])
            et = str(gantt['Exit Time'])
            print(id + '\t' + st + '\t' + et)
        
        print()
        print('PID = Process ID')
        print('AT = Arrival Time')
        print('BT = Burst Time')
        print('CT = Completion Time')
        print('TAT = Turn Around Time')
        print('WT = Waiting Time')
        print('RT = Response Time')
        
        print()
        print('PID\tAT\tBT\tCT\tTAT\tWT\tRT')
        for process in self.processes:
            pid = str(process['Process ID'])
            at = str(process['Arrival Time'])
            bt = str(process['Burst Time'])
            ct = str(process['Completion Time'])
            tat = str(process['Turn Around Time'])
            wt = str(process['Waiting Time'])
            rt = str(process['Response Time'])
            print(pid + '\t' + at + '\t' + bt + '\t' + ct + '\t' + tat + '\t' + wt + '\t' + rt)
        
        print()
        print('Average Waiting Time = ' + str(averageWaitingTime))

    def execute(self) -> None:
        ganttChart = self.simulate()
        averageWaitingTime = self._calculateTimes()
        self._printFormattedOutput(ganttChart = ganttChart, averageWaitingTime = averageWaitingTime)

# Driver Code
if __name__ == "__main__":
    FCFS(processes = getProcesses()).execute()
