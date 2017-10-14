#include <pob-eye.h>
#include "TreadControllerTask.h"
#include "MovementDirection.h"

void ExecuteTreadControllerTask(UInt8 movement_direction)
{
	if((movement_direction == ROTATE_LEFT))
	{
		WaitUs(200000);
	}
	
	SetPortD(movement_direction);
}