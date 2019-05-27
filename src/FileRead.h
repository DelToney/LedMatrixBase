
#include <SPI.h>
#include <SD.h>

size_t readField(File* file, char* str, size_t size, char* delim);

void setupFileReader();