#include <pob-eye.h>
#include "TreadControllerTask.h"
#include "MovementDirection.h"

// Wait one-fifth of a second before turning to let the robot move closer to the center of the path.
void ExecuteTreadControllerTask(UInt8 movement_direction)
{
	if((movement_direction == ROTATE_LEFT))
	{
		WaitUs(200000);
	}
	
	SetPortD(movement_direction);
}
