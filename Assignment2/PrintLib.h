#ifndef RENDER_TASK_H_INCLUDED
#define RENDER_TASK_H_INCLUDED

void InitASCIIBuffer(UInt8* ASCII_Buffer);
void PrintTextOnPobLCD(int row, int col, char* string, UInt8* ASCII_Buffer, UInt8* Screen_Buffer);

#endif // RENDER_TASK_H_INCLUDED