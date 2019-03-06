#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  
/*The setlocale() function will fail by returning a null pointer, for example, when the locale is not installed. The function may fail for other reasons as well, such as the lack of resources.  Depending on the sequence of characters pointed to by utf8, the subsequent call to mbstowcs() may fail or result in the function storing an unexpected sequence of wide characters in the supplied buffer wcs.*/
int func1(wchar_t *wcs, size_t n, const char *utf8,
                size_t *size) {
  if (NULL == size) {
    return -1;
  }
  setlocale(LC_CTYPE, "en_US.UTF-8");
  *size = mbstowcs(wcs, utf8, n);
  return 0;
}

/*In this noncompliant code example, temp_num, tmp2, and num_of_records are derived from a tainted source. Consequently, an attacker can easily cause calloc() to fail by providing a large value for num_of_records*/
enum { SIG_DESC_SIZE = 32 };
 
typedef struct {
  char sig_desc[SIG_DESC_SIZE];
} signal_info;
  
void func2(size_t num_of_records, size_t temp_num,
          const char *tmp2, size_t tmp2_size_bytes) {
  signal_info *start = (signal_info *)calloc(num_of_records,
                                          sizeof(signal_info));
 
  if (tmp2 == NULL) {
    /* Handle error */
  } else if (temp_num > num_of_records) {
    /* Handle error */
  } else if (tmp2_size_bytes < SIG_DESC_SIZE) {
    /* Handle error */
  }
 
  signal_info *point = start + temp_num - 1;
  memcpy(point->sig_desc, tmp2, SIG_DESC_SIZE);
  point->sig_desc[SIG_DESC_SIZE - 1] = '\0';
  /* ... */
  free(start);
}

/*This noncompliant code example calls realloc() to resize the memory referred to by p. However, if realloc() fails, it returns a null pointer and the connection between the original block of memory and p is lost, resulting in a memory leak.*/
void *p;
void func3(size_t new_size) {
  if (new_size == 0) {
    /* Handle error */
  }
  p = realloc(p, new_size);
  if (p == NULL) {
   /* Handle error */
  }
}

/*In this noncompliant code example, the fseek() function is used to set the file position to a location offset in the file referred to by file prior to reading a sequence of bytes from the file. However, if an I/O error occurs during the seek operation, the subsequent read will fill the buffer with the wrong contents.*/
size_t func4(FILE *file, long offset,
               void *buf, size_t nbytes) {
  if (fseek(file, offset, SEEK_SET) != 0) {
    /* Indicate error to caller */
    return 0;
  }
  return fread(buf, 1, nbytes, file);
}

/*In this noncompliant code example, snprintf() is assumed to succeed. However, if the call fails (for example, because of insufficient memory, as described in GNU libc bug 441945), the subsequent call to log_message() has undefined behavior because the character buffer is uninitialized and need not be null-terminated.*/
extern void log_message(const char *);
 
void func5(int i, int width, int prec) {
  char buf[40];
  snprintf(buf, sizeof(buf), "i = %*.*i", width, prec, i);
  log_message(buf);
  /* ... */
}

