
#include <math.h>
#include "viterbi_declarations.h"



void CalculateMetricsDistances(float metric[ROWS1][MSG_SIZE],
		float distance[ROWS][MSG_SIZE + 1],
		unsigned char t, float const inputs[ROWS1][MSG_SIZE])
{
	short int  i;
	float temp1, temp2;

	// The function "CalculateMetricsDistances" creates trellis and computes the branch metrics
	// and the state metrics and performs Add-Compare- Select (ACS) operation

	for (i = 0; i < MSG_SIZE; ++i) {

		temp1 = abs(-1 - inputs[t][i]);
		temp2 = abs(+1 - inputs[t][i]);

		metric[0][i] = temp1;	// Metric for transition from state 0 to 0
		metric[1][i] = temp2;	// Metric for transition from state 0 to 1
		metric[2][i] = temp2;	// Metric for transition from state 1 to 0
		metric[3][i] = temp1;	// Metric for transition from state 1 to 1


		distance[0][i + 1] = fmin(distance[0][i] + metric[0][i], distance[1][i] + metric[2][i]);     //  Minimum distance to reach state 00 at time i
		distance[1][i + 1] = fmin(distance[0][i] + metric[1][i], distance[1][i] + metric[3][i]);  //  Minimum distance to reach state 01 at time i

	}

}


