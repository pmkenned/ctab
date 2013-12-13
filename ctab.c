#include "ctab.h"

void printt(const char * t[], int rs, int cs) {

    int r,c;

    char * line;
    int * max_len = malloc(sizeof(int)*cs);
    int line_len = 0;

    const int cp = 3; /* column padding */

    for(c=0; c<cs; c++) {
        max_len[c] = 0;
        for(r=0; r<rs; r++) {
            int l = strlen(t[r*cs+c])+cp;
            if (l > max_len[c])
                max_len[c] = l;
        }
        line_len += max_len[c];
    }

    line = malloc(sizeof(char)*(line_len+1));

    for(r=0; r<rs; r++) {

        int offset = 0;

        memset(line,' ',line_len);
        line[line_len] = '\0';

        for(c=0; c<cs; c++) {
            int sl = strlen(t[r*cs+c]);            /* does not include '\0' */
            strncpy(line + offset, t[r*cs+c], sl); /* does not copy '\0' */
            offset += max_len[c];
        }

        /* print line */
        printf("%s\n",line);
    }

    free(line);
    free(max_len);
    
}

const char ** contab(int rs, const char ** headers, const char * fmt, ...) {

    va_list argp;
    int cs = strlen(fmt);
    const char ** t = malloc(sizeof(char*)*(rs+1)*cs);
    int c;

        int r;
    va_start(argp, fmt);

    for(c = 0; c < cs; c++) {
        char p = fmt[c];
        char ** ss;
        int * is;
        char * buf; /* for ints */

        t[c] = headers[c];

        switch(p) {
            case 's':
                ss = va_arg(argp, char **);
                for(r=0; r<rs; r++) {
                    t[(r+1)*cs+c] = ss[r];
                }
                break;
            case 'c':
                is = va_arg(argp, int *);
                /* TODO */
                break;
            case 'i':
                is = va_arg(argp, int *);
                for(r=0; r<rs; r++) {
                    buf = malloc(20);
                    sprintf(buf,"%d", is[r]);
                    t[(r+1)*cs+c] = buf;
                }
                break;
        }
    }

    va_end(argp);

    return t;
}


