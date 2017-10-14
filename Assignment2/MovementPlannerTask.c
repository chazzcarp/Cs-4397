#include <pob-eye.h>
#include "MovementPlannerTask.h"
#include "MovementDirection.h"
#include "Patterns.h"
//Ececuting movement based off the recognized pattern parameter.
UInt8 ExecuteMovementPlannerTask(UInt8 recognized_pattern)
{
	switch(recognized_pattern)
	{
		case IDP_CROSS:
			return MOVE_FORWARD;
		case IDP_CIRCLE:
			return ROTATE_LEFT;
		case IDP_TOWER:
			return STOP_MOVING;
		case IDP_TRIANGLE:
			return MOVE_FORWARD;
		default:
			return ROTATE_RIGHT;
	}
}
