# lem_in

## introduction
A 42 School project about guiding ants through a maze.

Input has the amount of ants, rooms and their coordinates, links between the rooms, and comments/commands.

For example:

![ant_farm](https://github.com/Durinder/lem_in/blob/main/ant_farm.png)

which corresponds to:

![map](https://github.com/Durinder/lem_in/blob/main/map.png)

## rules
Goal is to get the ants from the start room **room below command ##start** to the end room **room below command ##end** in as few lines as possible.
* at the beginning all ants are in the ##start room
* each room except ##start and ##end can only contain one ant at a time
* one turn is one line, in which each ant can be moved from its current room to any connected room, which has to be empty
* formatting for output is Lx-y Lz-w Lr-o ..., where
- x, z, r is ant's number or identifier
- y, w, o is room's name to which the ant moves

## solution
I solved the problem by initializing input into a graph and using a primarily edmonds-karp type algorithm. In each iteration of adding flow to the graph, I calculated the amount of lines needed for solution using the paths optimally. Then after reaching max flow I chose the solution with the least amount of lines needed and proceeded to print the solution.

As edmonds-karp algorithm chooses the shortest augmenting path it can quite easily choose unoptimal pathing if augmenting through current flow reaches a room through BFS (bread-first search) later than some other route without any flow in it. So I modified the edmonds-karp algorithm by prioritizing augmenting paths that go through any currently marked paths. I did this simply by queueing any rooms with flow in them currently to the front of the queue and everything else to the back of the queue.

## optional flags
* -p prints the paths used for the solution
* -l prints the amount of lines for the given solution
