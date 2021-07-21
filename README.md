# Robo-Maze

Robo-Maze is a simple maze solving bot made during Dristi event organized by Kathmandu Engineering College.

## Components Used

1. Arduino Uno
1. Ultrasonic Sensor HC-SR04 *3
1. Motor Driver L298N
1. BO motor *4
1. LiPo battery

## Working

This bot uses three ultrasonic sensors to detect the presence of walls. If the forward distance between bot and wall is between a threshold value, the bot will compare the left and right proximity and rotates to the direction of higher proximity. If the distance bot and wall in any direction is greater then 100 cm the bot will stop as the bot will not be inside the maze. If non of the above conditoins matches, the bot will move forward.