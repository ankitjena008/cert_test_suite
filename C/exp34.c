/*
This noncompliant code example is derived from a real-world example taken from a vulnerable version of the libpng library 
as deployed on a popular ARM-based cell phone [Jack 2007]. The  libpng library allows applications to read, create, and manipulate PNG (Portable Network Graphics) 
raster image files. The libpng library implements its own wrapper to malloc() that returns a null pointer on error or on being passed a 0-byte-length argument.
This code also violates ERR33-C. Detect and handle standard library errors.
*/

// #include <png.h> /* From libpng */
#include <string.h>
#include <stdlib.h>
  
// void func(png_structp png_ptr, int length, const void *user_data) {
//   png_charp chunkdata;
//   chunkdata = (png_charp)png_malloc(png_ptr, length + 1);
//   /* ... */
//   memcpy(chunkdata, user_data, length);
//   /* ... */
//  }

 /*In this noncompliant code example, input_str is copied into dynamically allocated memory referenced by c_str. If malloc() fails, it returns a null pointer that is assigned to c_str. When c_str is dereferenced in memcpy(), the program exhibits undefined behavior.  Additionally, if input_str is a null pointer, the call to strlen() dereferences a null pointer, also resulting in undefined behavior.*/
void f(const char *input_str) {
  size_t size = strlen(input_str) + 1;
  char *c_str = (char *)malloc(size);
  memcpy(c_str, input_str, size);
  /* ... */
  free(c_str);
  c_str = NULL;
  /* ... */
}

int main() {
	const char* msg = "Happy birthday!";
	f(msg);
	return 0;
}