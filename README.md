# Navigation of Drones
A rectangular area must be navigated by drones.  
This area is divided up into a grid to simplify navigation.  
  
A drone's position is represented by a combination of x and y coordinates and a letter representing one of the four cardinal compass points.  
  
A simple string of letters is used to control a drone.  
The possible letters are 'L', 'R' and 'M'.  
'L' and 'R' make the drone spin 90 degrees left or right respectively, without moving from its current spot.  
'M' means move forward one grid point, and maintain the same heading.  
> e.g., move to East from (x, y) is (x+1, y).  

## Input
* The first line of the input is the upper-right coordinates of the area, to lower-left coordinates are assumed to be (0, 0).
  > Upper-right coordinates of the area (e.g., 5 5):  
* The second line of the input is count of drones.
  > Count of drones (e.g., 2):
* The rest of the input is information pertaining to the drones. Each drone has two lines of input.
  * The first line gives the drone's initial position.
     > 1 . drone's initial position (e.g., 1 2 N):
  * The second line is a series of instructions that tell the drone how to explore the area.
     > 1 . drone's movement series (e.g., LMLMLMLMM):

Assuming that each drone will be finished sequentially, which means that the second drone will not be able to start to move until the first one has finished moving.  

### Test input
```
Upper-right coordinates of the area (e.g., 5 5): 
5 5
Count of drones (e.g., 2): 
2
1 . drone's initial position (e.g., 1 2 N): 
1 2 N
1 . drone's movement series (e.g., LMLMLMLMM): 
LMLMLMLMM
2 . drone's initial position (e.g., 1 2 N): 
3 3 E
2 . drone's movement series (e.g., LMLMLMLMM): 
MMRMMRMRRM
```

## Output
The output for each drone should be its final position.
> 1 . drone's final position:   
1 3 N

### Test output
```
----------------------------------------------
1 . drone's final position: 
1 3 N
----------------------------------------------
----------------------------------------------
2 . drone's final position: 
5 1 E
----------------------------------------------

```

