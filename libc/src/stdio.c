#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <_stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp  > 0) ?  buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too man y characters\n");
	else
		buf[bufp++] = c;
}

#define PERMS 0666

_FILE *_fopen(char *name, char *mode)
{
	int fd;
	_FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if (!fp->flag.read && !fp->flag.write)
			break; /* found free place for the file */
	if (fp >= _iob + OPEN_MAX) /* no free place */
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else {
		fd = open(name, O_RDONLY, 0);
	}
	if (fd == -1)		/* file not found */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	if (*mode == 'r')
		fp->flag.read = 1;
	else
		fp->flag.write = 1;
	return fp;
}

int _fclose(_FILE *fp)
{
	fp->flag.read = 0;
	fp->flag.write = 0;
	fp->flag.unbuf = 0;
	fp->flag.eof = 0;
	fp->flag.err = 0;
	free(fp->base);
	fp->base = NULL;
	return close(fp->fd);
}

int _fillbuf(_FILE *fp)
{
	int bufsize;
	if (fp->flag.eof || fp->flag.err)
		return EOF;
	bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;
	if (fp->base == NULL)		/* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;			/* clouldn't create a buffer */
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag.eof = 1;
		else
			fp->flag.err = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

int _flushbuf(int c, _FILE *fp)
{
	int bufsize;
	int bw; 					/* bytes written */
	if (fp->flag.eof || fp->flag.err)
		return EOF;
	bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;

	if (fp->base == NULL) { /* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* clouldn't create a buffer */
		else
			if (write(fp->fd, &c, 1) != 1) /* we created buffer */
				return EOF; /* and write to fd one character */
	} else { /* buffer is ready for flushing */
		fp->ptr = fp->base;
		if (write(fp->fd, fp->ptr, bufsize) != bufsize) /* flush buffer */
			return EOF;
		if (write(fp->fd, &c, 1) != 1) /* and flush next character */
			return EOF;
	}

	return 0; /* on success */
}
