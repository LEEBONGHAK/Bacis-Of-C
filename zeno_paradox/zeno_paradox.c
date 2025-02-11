﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
		Simulation of a Moving Object

		- Speed = 1.0 m/s
		- dt = 1.0s
		- Distance traveled during dt = Speed * dt

		- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
		- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
		- Step 3 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
		- ... ...
	*/

	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0;		// Elapsed time
	double dist = 0.0;		// Distance

	for (unsigned i = 1; i <= repeat_max; i++) {
		dist += speed * dt;	// dist = dist + speed * dt;
		time += dt;

		printf("Elapsed time = %.10fs, Distance = %.10f\n", time, dist);
	}

	printf("\n");

	/* 
		Zeno's Paradox

		- Step 1 : 1.0 * 1.0 = 1.0, 1.0
		- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
		- Step 3 : 1.0 * 0.25 = 1.0, 1.5 + 0.25 = 1.75
		- ... ...
	*/

	dt = 1.0;
	time = 0.0;
	dist = 0.0;

	for (unsigned i = 1; i <= repeat_max; i++) {
		dist += speed * dt;	// dist = dist + speed * dt;
		time += dt;
		// dt /= 2.0;
		dt *= 0.5;			// 곱하기가 나누기 보다 빠름


		printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);
	}

	// Note : infinite geometric series
	// 프로그램은 무한 급수를 표현하기 힘들다!

	return 0;
}