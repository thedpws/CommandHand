#pragma once



class CommandHand
{
public:
	const static int gs_height = 200;
	const static int gs_width = 400;
	const static bool debug = false;;
	const static bool rgb_d = false;
	const static bool blur_d = false;
	const static bool thresh_d = true;
	
	const static int max_thresh = 255;
	const static int thresh = 89;

	const static int ksize = 40;

	const static uchar lo_r = 152;
	const static uchar hi_r = 254;
	const static uchar lo_g = 79;
	const static uchar hi_g = 254;
	const static uchar lo_b = 0;
	const static uchar hi_b = 254;
	
	
	/*
	const static uchar lo_r = 164;
	const static uchar hi_r = 255;
	const static uchar lo_g = 115;
	const static uchar hi_g = 255;
	const static uchar lo_b = 83;
	const static uchar hi_b = 255;
	*/
	
	
	
};