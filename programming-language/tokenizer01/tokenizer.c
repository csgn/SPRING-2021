#include "alfred.h"

int main(int argc, char **argv)
{
  char *m_file_path = malloc(sizeof(char)+1);

  if (argc > 1)
      m_file_path = argv[1];
  else
  {
      printf("Enter file path: ");
      scanf("%s", m_file_path);

      if (strlen(m_file_path) <= 0)
      {
        free(m_file_path);
        printf("File path does not exist!\n");
        exit(true);
      }
  }

  FILE* m_stream = alfred_open(m_file_path, "r");
  char* m_source = alfred_read(m_stream);
  printf("%s\n", m_source);

  alfred_fit(m_source);
  alfred_parse(m_source);
  alfred_close(m_stream);
  free(m_source);
}
