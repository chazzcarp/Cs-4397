#include <pob-eye.h>

#include "MovementDirection.h"

#include "PatternRecognizerTask.h"
#include "MovementPlannerTask.h"
#include "JoystickInputTask.h"
#include "PrintToLCDTask.h"
#include "TreadControllerTask.h"

#define CAMERA_ANGLE 15

// Declare global variables.
GraphicBuffer LCD_Buffer_Video;
UInt8 LCD_Buffer[LCD_WIDTH * LCD_HEIGHT * BITS];
UInt8 ASCII_Buffer[LCD_WIDTH * LCD_HEIGHT * BITS];
UInt8* rgbFrame;

void InitPobProto()
{
	PobProto proto;

	// enable analog joystick input
	proto.porta = ALL_PORTA_AS_ANA;

	// make all pins of port c manage the servomotors
	proto.portc = RC7_AS_DO | RC6_AS_DO | RC3_AS_DO | RC2_AS_SERVO | RC1_AS_SERVO | RC0_AS_SERVO;

	// RD0, RD1, RD2, RD3: digital outputs to DC motor
	// RD4, RD5, RD6, RD7: digital inputs (what does this mean???)
	proto.portd = RD7_AS_DI | RD6_AS_DI | RD5_AS_DI | RD4_AS_DI | RD3_AS_DO | RD2_AS_DO | RD1_AS_DO | RD0_AS_DO;

	SetPobProto(&proto);
}
void Init()
{
	//Main Initialization
	InitPobeye2(); //initialize CPU
	InitPobProto(); //initialize motherboard
	InitI2C(I2C_100_KHZ); //initialize internal communication link (Camera)
	InitUART0(BR_230400); //initialize external communication link (USB)
	
	//LCD Initialization
	InitLCD();
	InitGraphicBuffer(&LCD_Buffer_Video, LCD_WIDTH, LCD_HEIGHT, ONE_BIT, LCD_Buffer);
	ClearGraphicBuffer(&LCD_Buffer_Video);
	DrawLCD(&LCD_Buffer_Video);
	InitASCIIBuffer(ASCII_Buffer);
	
	//Camera Initialization
	InitCameraPobeye2(); //initialize camera
	rgbFrame = GetRGBFrame(); //get pointer to camera frame
	
	//Servo Initializations
	SwitchOnAllServo(); //initialize all servos
	SetGlobalSpeed(0); //set all servos speed
	SetServoMotor(0, CAMERA_ANGLE); //set camera angle
}

int main()
{
	UInt8 recognizedPattern;
	UInt8 joystickDirection, plannedDirection, movementDirection;
	
	Init();
	
	while(1)
	{
		ClearGraphicBuffer(&LCD_Buffer_Video);
		
		recognizedPattern = ExecutePatternRecognizerTask(rgbFrame);
		joystickDirection = ExecuteJoystickInputTask();
		plannedDirection = ExecuteMovementPlannerTask(recognizedPattern);
		movementDirection = (joystickDirection == STOP_MOVING) ? plannedDirection : joystickDirection;
		
		ExecuteTreadControllerTask(movementDirection);
		
		ExecutePrintToLCDTask(movementDirection, recognizedPattern, ASCII_Buffer, LCD_Buffer, LCD_Buffer_Video);
		
	/*	if(plannedDirection == STOP_MOVING) {
			break;
		}
		*/
	}
	
	return 0;	
}
