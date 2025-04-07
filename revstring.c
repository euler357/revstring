/* Reverse a string in-place using a c function */
/* Using two different methods */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function to reverse a string */
/* Using memory allocated from the heap */
void revstring(char *inString)
{
	/* Get the length of the string */
	/* Assumes null-terminated */
	int length=strlen(inString);	

	/* Allocate memory from the heap for the temp string */
	char *tempString=malloc(length+1);

	/* If we couldn't allocate memory then fail and return an error */
	if (tempString==NULL)
	{
		fprintf(stderr, "Malloc failed");
		abort();
	}

	/* Loop on the length of the string */
	/* and copy to the temp string in reverse order */
	for(int i=0;i<length;i++)
		tempString[length-i-1]=inString[i];

	/* Making sure that it's NULL terminated */
	tempString[length]=0;

	/* Copy the temp string back to the source */
	strcpy(inString,tempString);

	/* Free the memory allocated from the heap */
	free(tempString);
}

/* Function to reverse the string */
/* Using minimal extra memory */
void revstring2(char *inString)
{
	/* Get the length of the string */
	/* Assumes null-terminated */
	int length=strlen(inString);	
	char temp;

	/* Loop on the length of the string */
	/* and copy to the temp string in reverse order */
		for(int i=0;i<(length>>1);i++)
		{
			temp=inString[i];
			inString[i]=inString[length-i-1];
			inString[length-i-1]=temp;
		}
}

/* Main */
int main(void)
{
	/* Define a string */
	/* on the stack */
	char myString[]="This is my string";

	/* Print the input string */
	printf("Input String:\n%s\n",myString);

	/* Call the string reverse function */
	revstring(myString);
	
	/* Print the result */
	printf("\nMethod 1 (malloc):\n%s\n",myString);

	/* Call the string reverse function */
	/* Puts it back like it was */
	revstring(myString);
	
	/* Print the result */
	printf("%s\n",myString);

	/* Call the string reverse function */
	revstring2(myString);
	
	/* Print the result */
	printf("\nMethod 2 (minimal memory)\n%s\n",myString);
	
	/* Call the string reverse function */
	/* Puts it back like it was */
	revstring2(myString);
	
	/* Print the result */
	printf("%s\n",myString);

	/* Return no error */
	return 0;
}
