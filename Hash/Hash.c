#include "basicLib_CloseHash.c"

int main()
{
	Dictionary D;
	READ_SET(&D);
	DELETE_SET(64,&D);
	PRINT_SET(D);
	return 0;
}