Word count and line count will be more than wc if file ends in a newline.
Word count and line count are also innacurate on large files for some reason related to buffer size. My guess is that new line characters are getting counted twice after more data is read into the buffer, but i'm not sure why or how to fix this.

To compile: make or make all
To run: ./countln filename(s)
Alternate run: make run ARGS=filename(s)


