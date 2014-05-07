#define OPEN_MAX	20

typedef struct _iobuf {
	int cnt; 	/* chars remaining */
	char *ptr;	/* next char */
	char *base;	/* buffer location */
	struct {
		unsigned int read : 1;	/* file opened for read */
		unsigned int write : 1;	/* for write */
		unsigned int unbuf : 1;	/* file without bufferizing */
		unsigned int eof : 1;	/* end of file */
		unsigned int err : 1;	/* error has been occured */
	} flag; 	/* file access mode */
	int fd; 	/* file descriptor */
} _FILE;

_FILE _iob[OPEN_MAX] = {	/* stdin,  stdout, stderr: */
	{ 0, (char *) 0, (char *) 0, {1}, 0 },
	{ 0, (char *) 0, (char *) 0, {0, 1}, 1 },
	{ 0, (char *) 0, (char *) 0, {0, 1, 1}, 2 }
};

_FILE *_fopen(char *, char *);

#define _stdin (&_iob[0])
#define _stdout (&_iob[1])
#define _stderr (&_iob[2])

int _fillbuf(_FILE *);
int _flushbuf(int, _FILE *);

#define _feof(p)	(((p)->flag & _EOF) != 0)
#define _ferror(p)	(((p)->flag & _ERR) != 0)
#define _fileno(p)	((p)->fd)

#define _getc(p)	(--(p)->cnt >= 0 \
		? (unsigned int) *(p)->ptr++ : _fillbuf(p))
#define _putc(x, p)	(--(p)->cnt >= 0 \
		? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define _getchar()	_getc(_stdin)
#define _putchar(x)	_putc((x), _stdout)

int getch(void);
void ungetch(int c);
