#ifndef PRINT_TO_LCD_TASK_H_INCLUDED
#define PRINT_TO_LCD_TASK_H_INCLUDED

// Prints to the LCD.
void ExecutePrintToLCDTask(int movement_direction, int recognized_pattern, UInt8* ASCII_Buffer, UInt8* LCD_Buffer, GraphicBuffer LCD_Video_Buffer);

#endif // PRINT_TO_LCD_TASK_H_INCLUDED