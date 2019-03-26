#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include"head.h"
#define STR_MAX_LENGHT (256)

#define _STR_Len 80
char* Strcat_test(char* str){
	int len = _STR_Len;
	strcpy_s(str, len, "these ");
	strcat_s(str, len, "strings ");
	strcat_s(str, len ,"are ");	
	strcat_s(str, len, "concatenated.");
	puts(str);
	return str;
}

void Spilt_path_test(){
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	size_t sizeInCharacters = _STR_Len;

	/* _makepath(path_buffer, "g", "\\Testdir\\myexample\\", "testfile", "txt"); */
	_makepath_s(path_buffer, sizeInCharacters, "g", "\\Testdir\\myexample\\", "testfile", "txt");

	printf("\nPath created with _makepath_s(): %s\n", path_buffer);
	/* _splitpath(path_buffer, drive, dir, fname, ext); */
	_splitpath_s(path_buffer, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT); 

	printf("\nPath extracted with _splitpath_s():\n");
	printf(" Drive: %s\n", drive);
	printf(" Dir: %s\n", dir);
	printf(" Filename: %s\n", fname);
	printf(" Ext: %s\n", ext);	
}

void Sprintf_s_test()
{
	char buffer[200], s[] = "HelloWorld!", c = 'l';
	int i = 35, j;
	float fp = 1.7320534f;
	// Format and print various data:
	j = sprintf_s(buffer, sizeof(buffer), "A%s\n", s);
	j += sprintf_s(buffer + j, sizeof(buffer) - j, " C%c\n", c);
	j += sprintf_s(buffer + j, sizeof(buffer) - j, " Integer: %d\n", i);
	j += sprintf_s(buffer + j, sizeof(buffer) - j, " Real: %f\n", fp);
	printf_s("Output:\n%s\ncharacter count = %d\n", buffer, j);
	
	char drive[_MAX_DRIVE] = { 'ha' };
	char dir[_MAX_DIR] = { 'hb' };
	char fname[_MAX_FNAME] = { 'jc'};
	char ext[_MAX_EXT] = { 'a\0' };
	char str[_MAX_PATH] = { 'h\0' };
	char PN[STR_MAX_LENGHT];
	puts(drive);
	sprintf_s(PN, "%s%s%s", drive, dir, fname);
	puts(PN);
}

int main(void)
{
	
#ifdef _WIN32
	Sprintf_s_test();
#endif

#ifdef linux
	j=snprintf(buffer, sizeof(buffer), "%s\n", s); 
    	printf("%sn\n",buffer);
	printf("%d\n",j);
#endif

#ifdef _WIN32
	char str[_STR_Len];
	//Strcat_test(str);
	
	//Spilt_path_test();
#endif
	printf("Done!\n");
	return 0;
}
