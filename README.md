# Ping-Pong Using 2D Cordinate Geometry
Programmed a Ping-Pong Game in C++ in 2014

# 2D Cordinate Geometry:
   
Equation of a line in 2D Cordinate geomerty is Y = mX + c<br>
Where,<br>
m = Tan(theta)<br>
m is the slope of the line and theta is the anticlockwise angle the line makes with the positive x axis and,<br>
c is the intercept with the positive y axis.

# Ball Trajectory Calculation:

The trajectory of the ping-pong ball follows a specific equation of line which starts with slope -1 and a constant value for the intercept.<br>
When the ping-pong ball hits any wall, its trajectory is changed to simulate the the bouncing effect.<br>
If the ball was moving in one direction, when it hits a wall, it bounces and its direction is reversed and the slope of the line which forms the trajectory of the ball changes to -1/m from m, this creates a proper bouncing effect.

# Game Play:

The game starts off with a slow speed, your aim is to prevent the ball from touching the ground by bouncing it on a movable plank kept on the ground, the motion of the plank is restricted to left and right staying in contact with the ground.<br>
You get a point for every successfull bounce in the plank, and the speed of the ball increases after every 5 points, hence increasing the difficuly level of the game.
