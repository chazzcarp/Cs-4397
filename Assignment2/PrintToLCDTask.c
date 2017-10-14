#include <pob-eye.h>
#include "MovementDirection.h"
#include "Patterns.h"
#include "PrintToLCDTask.h"
#include "PrintLib.h"

void ExecutePrintToLCDTask(int movement_direction, int recognized_pattern, UInt8* ASCII_Buffer, UInt8* LCD_Buffer, GraphicBuffer LCD_Video_Buffer)
{
	switch(movement_direction)
	{
		case MOVE_FORWARD:
			PrintTextOnPobLCD(3, 1, "MOVING FORWARD", ASCII_Buffer, LCD_Buffer);
			
			if(recognized_pattern == IDP_TRIANGLE)
			{
				PrintTextOnPobLCD(4, 1, "CROSSING THE BRIDGE", ASCII_Buffer, LCD_Buffer);
			}
			
			break;
		case MOVE_BACKWARD:
			PrintTextOnPobLCD(3, 1, "MOVING BACKWARD", ASCII_Buffer, LCD_Buffer);
			break;
		case ROTATE_RIGHT:
			PrintTextOnPobLCD(3, 2, "TURNING RIGHT", ASCII_Buffer, LCD_Buffer);
			break;
		case ROTATE_LEFT:
			PrintTextOnPobLCD(3, 2, "TURNING LEFT", ASCII_Buffer, LCD_Buffer);
			break;
		case STOP_MOVING:
			PrintTextOnPobLCD(3, 4, "STOPPED", ASCII_Buffer, LCD_Buffer);
			break;
		default:
			PrintTextOnPobLCD(3, 4, "STOPPED", ASCII_Buffer, LCD_Buffer);
			break;
		
	}
	
	DrawLCD(&LCD_Video_Buffer);
}