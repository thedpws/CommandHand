#pragma once

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
	
	static void on_max_thresh_thresh_trackbar(int, void*);

	//default values for trackbars
public:
	static int runDebug();
	
	static const int d_min_r = 30, d_min_g = 30, d_min_b = 30;
	
	static const int d_max_r = 100, d_max_g = 100, d_max_b = 100;
};