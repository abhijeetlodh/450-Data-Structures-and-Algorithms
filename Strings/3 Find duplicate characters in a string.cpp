/******************************************************************************


                     Abhijeet Lodh solving String from Love Babbar 450 DSA Sheet

                    Question: Find duplicate characters in a string

*******************************************************************************/
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256

	void charactersCount(char *str, int *count)
	{
		int i;
		for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	}

	void findDuplicates(char *str)
	{
		int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
		charactersCount(str, count);
		int i;
		for(i = 0; i < NO_OF_CHARS; i++){
		if(count[i] > 1)
            printf("%c, ", i);
		}
		free(count);
	cout << " are the duplicate strings";
	}

int main()
{
	char str[] = "ABBECCDEFFHZZ";
	findDuplicates(str);
	return 0;
}