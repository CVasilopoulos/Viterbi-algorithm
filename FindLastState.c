
#include <math.h>
#include "viterbi_declarations.h"
#include "function_prototypes.h"


unsigned char FindLastState(float distance[ROWS][MSG_SIZE + 1])
{

	// The function "FindLastState" finds and returns the last state
	// of trellis with minimum state metric in order to perform traceback


	unsigned char idx = 0;
	float min_val;

   min_val = distance[0][MSG_SIZE];

   if (distance[1][MSG_SIZE] < min_val) {

	   min_val = distance[1][MSG_SIZE];
	   idx = 1;

	}

	return idx;

}
