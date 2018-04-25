#pragma once
#include "CommandHand.h"
class rgb_debug
{
private:
	static void on_min_r_thresh_trackbar(int, void *);
	
	static void on_max_r_thresh_trackbar(int, void *);
	
	static void on_min_g_thresh_trackbar(int, void *);
	
	static void on_max_g_thresh_trackbar(int, void *);
	
	static void on_min_b_thresh_trackbar(int, void *);
	
	static void on_max_b_thresh_trackbar(int, void *);

	static void on_ksize_thresh_trackbar(int, void*);

	static void on_thresh_thresh_trackbar(int, void*);

	//default values for trackbars
public:
	static int runDebug();
	
	static const int
		d_min_r = CommandHand::lo_r,
		d_min_g = CommandHand::lo_g,
		d_min_b = CommandHand::lo_b;
	
	static const int 
		d_max_r = CommandHand::hi_r, 
		d_max_g = CommandHand::hi_g, 
		d_max_b = CommandHand::hi_b;
};