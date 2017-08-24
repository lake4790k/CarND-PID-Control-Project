# Writeup for PID controller

## Dual controller design

The implementation of the PID controller (PID.cpp) is quite straightforward and I also added capping the control outpit to the [-1,1] range.

I used 2 PID controllers, one for the steering control and one for the throttle control. The error for the steering controller is the cte from the simulator. The throttle PID controllers error is the differene between the current speed and a target speed. The target speed is in the [minSpeed, maxSpeed] range and is dependent on the steering control, ie the sharper turn we are talking the slower we go and we are accelerating in the straights where the steering angle is around 0:

```
double targetSpeed = minSpeed + (1. - fabs(steer_value)) * (maxSpeed - minSpeed);
```

## Parameter tuning

The tuning of the parameters I performed manually because the simulator did not allow for too much automation, eg. when car leaves track simulation needs to be restarted and its not obvious when a lap is completed to try a new set of parameters. So I rather performed a manual twiddle procedure evaluating how the car behaved visually. The parameters I passed in as command line arguments, so I could quickly update the parameters by restarting the controller process with updated parameters while the simulation was still running.

I tried to make the control as humanlike as possible, ie. minimal oscilations, optimal turns and also go as fast as possible without leaving the track.

For the steering control these parameters resulted in stable controller that never left the track and drove at relatively higher speeds:

```
    double kp = 0.1;
    double kd = 2.5;
    double ki = 0.0;
    double minSpeed = 50;
    double maxSpeed = 80;
```

For the throttle control I did not do tuning, just used Kp=0.1 to follow the target speed.

## Discussion

I would have liked to increase the speed even more, but finding the right parameters manually seemed difficult. In the sharper turns either Kp was not enough to make the sudden turn, or when set higher resulted in generally more unstable control.

I think just reacting on the current cte is quite a limiting factor as we can't really see ahead as a human would who could prepare for the sharper turns well in advance.