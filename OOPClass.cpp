#include<iostream>

int main() {
	int x = 3, y = 7, z[5] = { 2, 4, 6, 8, 10 };
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
				x, y, z[0], z[1], z[2], z[3], z[4]);

	// First
	int *IX;
	IX = &x;
	*IX = 1;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	// Second
	IX = &z[2];
	y = *IX;
	*IX = 15;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	// Third
	x = *IX + 5;
	*IX = *IX - 5;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	// Fourth
	++ *IX;
	*IX += 1;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	// Fifth
	x = *(IX + 1);
	y = *IX;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	// Sixth
	IX = IX + 4;
	y = *IX;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	//Seventh
	IX = &x;
	IX += 1;
	x = *IX;
	printf("\nx= %d \ty= %d \tz[0]= %d \tz[1]= %d \tz[2]= %d \tz[3]= %d \tz[4]= %d \t",
		x, y, z[0], z[1], z[2], z[3], z[4]);

	return 0;
}