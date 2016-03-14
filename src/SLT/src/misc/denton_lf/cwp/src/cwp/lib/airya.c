/* Copyright (c) Colorado School of Mines, 1990.
/* All rights reserved.                       */

/*
FUNCTION:  return approximation to the Airy function Ai(x)

PARAMETERS:
x			i value at which to evaluate Ai(x)

NOTES:
The approximation is derived from tables and formulas in Abramowitz
and Stegun, p. 475-477.

AUTHOR:  Dave Hale, Colorado School of Mines, 06/06/89
*/

#include <math.h>

float airya (float x)
{
	static float ap[101] = {
		0.35502, 0.35243, 0.34985, 0.34726, 0.34467,
		0.34209, 0.33951, 0.33693, 0.33435, 0.33177,
		0.32920, 0.32663, 0.32406, 0.32150, 0.31894,
		0.31639, 0.31384, 0.31130, 0.30876, 0.30623,
		0.30370, 0.30118, 0.29866, 0.29615, 0.29365,
		0.29116, 0.28867, 0.28619, 0.28372, 0.28126,
		0.27880, 0.27635, 0.27392, 0.27149, 0.26906,
		0.26665, 0.26425, 0.26186, 0.25947, 0.25710,
		0.25474, 0.25238, 0.25004, 0.24771, 0.24539,
		0.24308, 0.24078, 0.23849, 0.23621, 0.23394,
		0.23169, 0.22945, 0.22721, 0.22499, 0.22279,
		0.22059, 0.21841, 0.21624, 0.21408, 0.21193,
		0.20980, 0.20767, 0.20556, 0.20347, 0.20138,
		0.19931, 0.19726, 0.19521, 0.19318, 0.19116,
		0.18916, 0.18717, 0.18519, 0.18322, 0.18127,
		0.17933, 0.17741, 0.17549, 0.17360, 0.17171,
		0.16984, 0.16798, 0.16614, 0.16431, 0.16249,
		0.16069, 0.15890, 0.15713, 0.15536, 0.15362,
		0.15188, 0.15016, 0.14845, 0.14676, 0.14508,
		0.14341, 0.14176, 0.14012, 0.13850, 0.13689, 0.13529 };
	static float fp1[11] = {
		0.527027, 0.528783, 0.530601, 0.532488, 0.534448,
		0.536489, 0.538618, 0.540844, 0.543180, 0.545636, 0.548230 };
	static float fp2[11] = {
		0.548230, 0.549584, 0.550980, 0.552421, 0.553912,
		0.555456, 0.557058, 0.558724, 0.560462, 0.562280, 0.564190 };
	static float an1[101] = {
		0.35502, 0.35761, 0.36020, 0.36279, 0.36537,
		0.36796, 0.37054, 0.37312, 0.37560, 0.37827,
		0.38084, 0.38341, 0.38597, 0.38853, 0.39109,
		0.39364, 0.39618, 0.39871, 0.40124, 0.40376,
		0.40628, 0.40879, 0.41128, 0.41377, 0.41625,
		0.41872, 0.42118, 0.42363, 0.42606, 0.42849,
		0.43090, 0.43330, 0.43568, 0.43805, 0.44041,
		0.44275, 0.44508, 0.44739, 0.44968, 0.45196,
		0.45422, 0.45646, 0.45868, 0.46089, 0.46307,
		0.46523, 0.46738, 0.46950, 0.47159, 0.47367,
		0.47572, 0.47775, 0.47976, 0.48174, 0.48369,
		0.48562, 0.48752, 0.48939, 0.49124, 0.49306,
		0.49484, 0.49660, 0.49833, 0.50003, 0.50170,
		0.50333, 0.50493, 0.50650, 0.50803, 0.50953,
		0.51100, 0.51242, 0.51382, 0.51517, 0.51649,
		0.51777, 0.51901, 0.52021, 0.52137, 0.52249,
		0.52357, 0.52461, 0.52560, 0.52655, 0.52746,
		0.52832, 0.52914, 0.52991, 0.53064, 0.53132,
		0.53195, 0.53254, 0.53308, 0.53356, 0.53400,
		0.53439, 0.53473, 0.53501, 0.53525, 0.53543, 0.53556 };
	static float an2[91] = {
		 0.53556, 0.53381, 0.52619, 0.51227, 0.49170,
		 0.46425, 0.42986, 0.38860, 0.34076, 0.28680,
		 0.22740, 0.16348, 0.09614, 0.02670,-0.04333,
		-0.11232,-0.17850,-0.24003,-0.29509,-0.34190,
		-0.37881,-0.40438,-0.41744,-0.41718,-0.40319,
		-0.37553,-0.33477,-0.28201,-0.21885,-0.14741,
		-0.07026, 0.00967, 0.08921, 0.16499, 0.23370,
		 0.29215, 0.33749, 0.36736, 0.38003, 0.37453,
		 0.35076, 0.30952, 0.25258, 0.18256, 0.10293,
		 0.01778,-0.06833,-0.15062,-0.22435,-0.28512,
		-0.32914,-0.35351,-0.35652,-0.33734,-0.29713,
		-0.23802,-0.16352,-0.07831, 0.01210, 0.10168,
		 0.18428, 0.25403, 0.30585, 0.33577, 0.34132,
		 0.32177, 0.27825, 0.21372, 0.13285, 0.04170,
		-0.05270,-0.14290,-0.22159,-0.28223,-0.31959,
		-0.33029,-0.31311,-0.26920,-0.20205,-0.11726,
		-0.02213, 0.07495, 0.16526, 0.24047, 0.29347,
		 0.31910, 0.31465, 0.28023, 0.21886, 0.13623, 0.04024 };
	static float fn1[6] = {
		0.39752, 0.39781, 0.39809, 0.39838, 0.39866, 0.39894 };
	static float fn2[6] = {
		0.40028, 0.40002, 0.39975, 0.39949, 0.39921, 0.39894 };

	int ix,iy;
	float ax,frac,ai,sx,y,ay,f,f1,f2,oy;

	if (x>=0.0) {
		if (x<1.0) {
			ax = x*100.0;
			ix = ax;
			frac = ax-ix;
			ai = (1.0-frac)*ap[ix]+frac*ap[ix+1];
		} else {
			sx = sqrt(x);
			y = 1.5/(x*sx);
			if (y>0.5) {
				ay = 15.0-y*10.0;
				iy = ay;
				if (iy<0) iy = 0;
				else if (iy>9) iy = 9;
				frac = ay-iy;
				f = (1.0-frac)*fp1[iy]+frac*fp1[iy+1];
				ai = 0.5*exp(-1.0/y)*f/sqrt(sx);
			} else {
				ay = 10.0-y*20.0;
				iy = ay;
				if (iy<0) iy = 0;
				else if (iy>9) iy = 9;
				frac = ay-iy;
				f = (1.0-frac)*fp2[iy]+frac*fp2[iy+1];
				ai = 0.5*exp(-1.0/y)*f/sqrt(sx);
			}
		}
	} else {
		if (x>-10.0) {
			if (x>-1.0) {
				ax = -x*100.0;
				ix = ax;
				frac = ax-ix;
				ai = (1.0-frac)*an1[ix]+frac*an1[ix+1];
			} else {
				ax = (-x-1.0)*10.0;
				ix = ax;
				frac = ax-ix;
				ai = (1.0-frac)*an2[ix]+frac*an2[ix+1];
			}
		} else {
			sx = sqrt(-x);
			y = 1.5/(-x*sx);
			ay = 5.0-y*100.0;
			iy = ay;
			frac = ay-iy;
			f1 = (1.0-frac)*fn1[iy]+frac*fn1[iy+1];
			f2 = (1.0-frac)*fn2[iy]+frac*fn2[iy+1];
			oy = 1.0/y;
			ai = (f1*cos(oy)+f2*sin(oy))/sqrt(sx);
		}
	}
	return ai;
}



#ifdef TEST
main()
{
	int nx,i;
	float xmin,xmax,x,dx;

	scanf("%d %*[^\n]", &nx);
	scanf("%f %*[^\n]", &xmin);
	scanf("%f %*[^\n]", &xmax);

	for (i=0,x=xmin,dx=(xmax-xmin)/(nx-1); i<nx; i++,x+=dx)
		printf("ai[%f] = %f\n", x, airya(x));
}
#endif