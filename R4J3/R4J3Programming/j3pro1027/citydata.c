#include <stdio.h>

int main(void) {
  FILE *fp = NULL;
  char data[128];

  fopen_s(&fp, "cityinfo.txt", "r");
  while (fgets(data, 128, fp) != NULL) {
    printf("%s", data);
  }
  fclose(fp);
  return 0;
}
