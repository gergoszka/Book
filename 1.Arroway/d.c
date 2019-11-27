#include <stdio.h>
#include <unistd.h>
int
main (void)
{
  int i, egy_e, c = 10 * 1024 * 1024, ci = 0;
  unsigned char b;

  while (read (0, (void *) &b, sizeof (unsigned char)))
    {
      write (1, (void *) &b, sizeof (unsigned char));
      if (++ci == c)
        break;
    }
}