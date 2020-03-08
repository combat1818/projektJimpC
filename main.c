#include "pngCreator.h"

int main(int argc, char **argv)
{
    process_file();
    write_png_file("out.png");
    return 0;
}