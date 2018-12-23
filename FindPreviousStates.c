

#include "viterbi_declarations.h"

void FindPreviousStates(unsigned char curr_state, float distance[ROWS][MSG_SIZE + 1],
								short int loop_start, float metric[ROWS1][MSG_SIZE],
									unsigned char decoded_message[ROWS1][MSG_SIZE], unsigned char t)
{

	unsigned char prev_state;
	short int i;

	for (i = loop_start; i >= 0; --i) {

			if (curr_state == 0) {

					if ((distance[0][i] + metric[0][i]) <= (distance[1][i] + metric[2][i]))

						prev_state = 0;

					else

						prev_state = 1;

					decoded_message[t][i] = 0;

			}

			else {

					if((distance[0][i] + metric[1][i]) <= (distance[1][i] + metric[3][i]))

						prev_state = 0;

					else

						prev_state = 1;

					decoded_message[t][i] = 1;

			}
			curr_state = prev_state;

	}


}


