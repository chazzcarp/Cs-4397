#include <pob-eye.h>
#include "JoystickInputTask.h"
#include "MovementDirection.h"

// joystick constants
#define JOYSTICK_X_AXIS 1
#define JOYSTICK_Y_AXIS 0

#define JOYSTICK_LOW_THRESHOLD 100
#define JOYSTICK_HIGH_THRESHOLD 200

UInt8 joystick_x, joystick_y;

// Execute movement based off the joystick input
UInt8 ExecuteJoystickInputTask()
{
	joystick_x = GetPortAnalog(JOYSTICK_X_AXIS);
	joystick_y = GetPortAnalog(JOYSTICK_Y_AXIS);
	
	if(joystick_y > JOYSTICK_HIGH_THRESHOLD)
		return MOVE_FORWARD;
	else if(joystick_y < JOYSTICK_LOW_THRESHOLD)
		return MOVE_BACKWARD;
	else if(joystick_x > JOYSTICK_HIGH_THRESHOLD)
		return ROTATE_RIGHT;
	else if(joystick_x < JOYSTICK_LOW_THRESHOLD)
		return ROTATE_LEFT;
	else
		return STOP_MOVING;
}
