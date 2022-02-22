# Importing the matplotlib.pyplot
import matplotlib.pyplot as plt

# Declaring a figure "gnt"
fig, gnt = plt.subplots()

# Setting Y-axis limits
gnt.set_ylim(0, 1) # 0 to number of processes

# Setting X-axis limits
gnt.set_xlim(0, 10) # 0 to gantt chart's end time

# Setting labels for x-axis and y-axis
gnt.set_xlabel('Time')
gnt.set_ylabel('Process')

# Setting ticks on y-axis
gnt.set_yticks([10, 20]) # 
# Labelling tickes of y-axis
gnt.set_yticklabels(['', '']) # process ID

# Setting graph attribute
# gnt.grid(True)

gnt.broken_barh([(0, 4)], (8, 4), facecolors =('tab:orange'))
gnt.broken_barh([(4, 5)], (8, 4))
gnt.broken_barh([(9, 10)], (8, 4), facecolors =('tab:orange'))


plt.savefig("gantt1.png")

# import plotly.express as px
# import pandas as pd

# df = pd.DataFrame([
#     dict(Task="Job A", Start='2009-01-01', Finish='2009-02-28'),
#     dict(Task="Job B", Start='2009-03-05', Finish='2009-04-15'),
#     dict(Task="Job C", Start='2009-02-20', Finish='2009-05-30')
# ])

# fig = px.timeline(df, x_start="Start", x_end="Finish", y="Task")
# fig.update_yaxes(autorange="reversed") # otherwise tasks are listed from the bottom up
# fig.show()
