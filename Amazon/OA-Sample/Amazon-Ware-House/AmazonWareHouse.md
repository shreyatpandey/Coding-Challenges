You are managing operations at a large Amazon warehouse. 
Loaded trucks arrive at the warehouse sequentially and must be unloaded within a specific timeframe to ensure timely delivery. 
Your task is to determine the minimum number of dock bays needed to unload all trucks within the given timeframe.

Formally, given a scheduling array truckCargoSize of length n, 
where each unit in the array represents the amount of time in minutes that a dock bay 
will take to unload the cargo from the ith truck, and a second integer, maxTurnaroundTime, 
representing the total allowed time to unload all trucks, 
find the smallest number of dock bays d that will enable you to unload all trucks within maxTurnaroundTime minutes.

Notes:

As soon as a dock bay becomes available after unloading a truck, 
it can immediately start processing the next truck.
It is guaranteed that unloading all trucks is possible with some number of dock bays.
Only the start times of unloading need to be considered in order, not the finish times.

Example
n = 5
truckCargoSize = [3, 4, 3, 2, 3]
maxTurnaroundTime = 8
Attempting with two dock bays (d = 2):
Truck Processing Timeline for 2 Dock Bays
TimeAction0The first two trucks are assigned to the two dock bays.
The first dock bay finishes unloading the first truck and starts unloading the third truck.
The second dock bay finishes unloading the second truck and starts unloading the fourth truck.
Both dock bays finish unloading the third and fourth trucks. 
The first dock bay starts unloading the fifth truck.9The first dock bay completes unloading the fifth truck.

With two dock bays, all trucks are unloaded in 9 minutes, which exceeds the maxTurnaroundTime of 8 minutes.

Attempting with three dock bays (d = 3):

Truck Processing Timeline for 3 Dock Bays

TimeAction0The first three trucks are assigned to the three dock bays.3The first and third dock bays finish unloading the first and third trucks and start unloading the fourth and fifth trucks.4The second dock bay finishes unloading the second truck and remains idle as there are no more trucks to unload.5The first dock bay finishes unloading the fourth truck.6The third dock bay finishes unloading the fifth truck.

With three dock bays, all trucks are unloaded in 6 minutes, which is within the maxTurnaroundTime of 8 minutes. Hence, the minimum number of dock bays required is 3.

Function Description

Complete the function getMinimumDockBays in the editor below.

getMinimumDockBays has the following parameters:

int truckCargoSize[n]: the time in minutes for the dock bay to unload cargo from the ith truck.

long maxTurnaroundTime: the maximum allowed total unloading time.

Returns

int: the smallest number of dock bays d, to unload all the cargo within maxTurnaroundTime minutes.

Constraints

1≤n≤5×10**4

1≤maxTurnaroundTime≤10**15

1≤truckCargoSize[i]≤min(maxTurnaroundTime,10^9)
