#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FN "foo"

int main() {
  int fd = open(FN, O_RDONLY);
  if (errno == ENOENT) {
    char *s = "creating new file";
    fd = open(FN,  O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    int bwritten = write(fd, s, strlen(s));
    printf("bytes written: %d errno: %d\n", bwritten, errno);
  } else {
    char buf[BUFSIZ];
    read(fd, buf, BUFSIZ);
    printf("file exists. it says: %s\n", buf);
  }
  close(fd);
}
