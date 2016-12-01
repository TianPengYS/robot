#include <math.h>

const float PI = 3.141592653;
float driver_radius = 1;
float platform_radius = 1;
float arm_length[2] = {1, 1};

float* inverse_kinematics(float *position_and_angle)
{
	float platform_position[6][3];
	float middle_position[6][3];
	float driver_position[6][3];
	int i;

	for (i = 0; i < 3; i++) {
		platform_position[i][0] = position_and_angle[0] + platform_radius * cos((0.5 + i * 1.0 / 3) * PI);
		platform_position[i][1] = position_and_angle[1] + platform_radius * sin((0.5 + i * 1.0 / 3) * PI);
		platform_position[i][2] = position_and_angle[2];
		platform_position[i][3] = position_and_angle[0] + platform_radius * cos((0.5 + i * 1.0 / 3) * PI);
		platform_position[i][4] = position_and_angle[1] + platform_radius * sin((0.5 + i * 1.0 / 3) * PI);
		platform_position[i][5] = position_and_angle[2];
	}

	for (i = 0; i < 3; i++) {
		driver_position[i][0] = driver_radius * cos((0.5 + i * 2.0 / 3) * PI);
		driver_position[i][1] = driver_radius * sin((0.5 + i * 2.0 / 3) * PI);
		driver_position[i][2] = 0;
	}
}

float* forward_kinematics(float *position, float r)
{
	float platform_position[3][3];
	float middle_position[3][3];
	float driver_position[3][3];
	int i;

	/*for (i = 0; i < 3; i++) {
		middle_position[i] = (r + arm_length[0] * cos(r[i])) * cos((0.5 + i * 2 / 3) * PI) ;
		middle_position[i] = (r + arm_length[0] * cos(r[i])) * cos((0.5 + i * 2 / 3) * PI) ;
		middle_position[i] = (r + arm_length[0] * cos(r[i])) * cos((0.5 + i * 2 / 3) * PI) ;
	}*/
}
