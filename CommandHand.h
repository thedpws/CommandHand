#pragma once



class CommandHand
{
public:

	//gs == "gesture space"
	//Gesture space is the area in the frame where the program looks for the gestures.
	const static int gs_height = 400;
	
	const static int gs_width = 500;

	const static int cs_height = 100;
	
	const static int cs_width = 300;

	//debug - set debug = true to open the debugging gui.
	//debugging gui has RGB sliders to fine-tune the opencv in-range function
	const static bool debug = false;
	
	const static int thresh = 62;

	const static int ksize = 20;

	//mins and maxs for opencv in-range function to create binary masks
	const static int lo_r = 240;
	
	const static int hi_r = 255;
	
	const static int lo_g = 165;
	
	const static int hi_g = 253;
	
	const static int lo_b = 159;
	
	const static int hi_b = 253;
	
	
	//settings for AZ's bedroom's lighting
	/*
	const static uchar lo_r = 164;
	
	const static uchar hi_r = 255;
	
	const static uchar lo_g = 115;
	
	const static uchar hi_g = 255;
	
	const static uchar lo_b = 83;
	
	const static uchar hi_b = 255;
	*/
	
	
	
};