def getDetails() -> None:
    numberOfProcesses = int(input('Enter number of processes: '))
    for i in range(0, numberOfProcesses):
        # reading data
        arrivalTime = int(input('Enter arrival time for process[%d] : ' %(i + 1)))
        burstTime = int(input('Enter burst time for process[%d] : ' %(i + 1)))
                
        processes.append([[arrivalTime,burstTime],{'Process ID': i, 'Arrival Time': arrivalTime, 'Burst Time': burstTime}]) # putting data in the processes array
        output.append({'Process ID': i, 'Arrival Time': arrivalTime, 'Burst Time': burstTime,'Completion Time':0, 'Turn Around Time': 0, 'Waiting Time': 0})
    # processes.sort(key=lambda process: process['Arrival Time'])
    output.sort(key=lambda process: process['Arrival Time'])

class ShortestJobFirst:
    def __init__(self, processes) -> None:
        self.processes = processes
        self.processCount = len(self.processes)
    
    def ganttChart(self) -> list:
        ganttChart = []
        processes.sort(key=lambda x:x[0])
        # print(processes)
        for process in self.processes:
            ganttChart.append(process[1])
        
        # for process in self.processes:
        #     minBurstTime = min(self.processes, key=lambda process: process['Burst Time'])
        #     if(process['Arrival Time'] == minBurstTime['Arrival Time']):
        #         if(process['Burst Time'] < minBurstTime['Burst Time']):
        #             ganttChart.append(process)
        #         else:
        #             ganttChart.append(minBurstTime)
        #     elif(process['Arrival Time'] < minBurstTime['Arrival Time'])
        print(ganttChart)
        return ganttChart

# this method formats the gantt chart properly
def printGanttChart(list) -> None:
    ganttChartOutput = []
    processID = ''
    startTime = ''
    stopTime = ''
    for i in range(0, len(list)):
        processID = str(list[i]['Process ID'])
        startTime = str(list[i]['Start Time'])
        stopTime = str(list[i]['Stop Time'])
        ganttChartOutput.append((processID, startTime, stopTime))
    print(ganttChartOutput)

# this method formats the output properly
def printOutput(list) -> None:
    processID = ''
    arrivalTime = ''
    burstTime = ''
    completionTime = ''
    turnAroundTime = ''
    waitingTime = ''

    print('Process ID | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time')
    for i in range(0, len(list)):
        processID = str(list[i]['Process ID'])
        arrivalTime = str(list[i]['Arrival Time'])
        burstTime = str(list[i]['Burst Time'])
        completionTime = str(list[i]['Completion Time'])
        turnAroundTime = str(list[i]['Turn Around Time'])
        waitingTime = str(list[i]['Waiting Time'])
        
        print(processID+'\t\t'+arrivalTime+'\t\t'+burstTime+'\t\t'+completionTime+'\t\t'+turnAroundTime+'\t\t'+waitingTime)


# DRIVER CODE
if __name__ == "__main__":
    processes = []  # is the process array in which all processes are stored
    output = []
    getDetails() # reading the details from user
    
    algorithm = ShortestJobFirst(processes)

    ganttChart = algorithm.ganttChart() # generate ganttChart
    print('\nGantt Chart: ')
    printGanttChart(ganttChart) # print ganttChart

    # Calculate 'Completion Time', 'Turn Around Time' and 'Waiting Time' of each process
    # algorithm.calculateCompletionTime(ganttChart)
    # algorithm.calculateTurnAroundTime()
    # algorithm.calculateWaitingTime()
    
    print('\n\nOutput: ')
    printOutput(output) # print details of each process

    # Calculate the average of waiting times
    # averageWaitingTime = algorithm.calculateAverageWaitingTime()
    print('\nAverage Waiting Time: ')
    # print(averageWaitingTime) # and print averageWaitingTime