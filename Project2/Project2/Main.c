#include"Main.h"

#define CHARACTER_CALLOC(count) (struct Character*) calloc(sizeof(struct Character), count)
#define CHARACTER_FREE(character) free(character)

int main(void)
{
	struct Character * a = CHARACTER_CALLOC(5);
	const char * names[] = { "Shizan", "Diablo", "OldBoy", "Alextraza", "Protobelt" };

	for (int i = 0; i < 5; i++)
	{ 
		Init(&a[i], names[i], BLUE );
	}

	for (int i = 0; i < 5; i++)
	{
		Init(&a[i], names[i], RED);
	}

	system("PAUSE");
	return 0;
	
	
}