#include <pob-eye.h>
#include "pattern.h"
#include "PatternRecognizerTask.h"

UInt8 i, recognizedPatternCount;
Form recognizedPatterns[MAX_OF_FORM];

// Recognize patterns and return the patterns
UInt8 ExecutePatternRecognizerTask(UInt8* rgbFrame)
{
	GrabRGBFrame();
	BinaryRGBFrame(rgbFrame);
	
	recognizedPatternCount = IdentifyForm(rgbFrame, recognizedPatterns, pattern);
	
	for(i = 0; i < recognizedPatternCount; i++)
	{
		switch(recognizedPatterns[i].id)
		{
			case IDP_CROSS:
			case IDP_CIRCLE:
			case IDP_TOWER:
			case IDP_TRIANGLE:
				return recognizedPatterns[i].id;
			default:
				break;
		}
	}
	
	return 0;
}
