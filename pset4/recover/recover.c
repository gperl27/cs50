// Recovers images from data file

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[]){
    
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover datafile\n");
        return 1;
    }
    
    // remember filename
    char *infile = argv[1];
    
    // open data file 
    FILE *data = fopen(infile, "r");
    if (data == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    BYTE buffer[512];
    
    char filename[8];
    
    //create a temp img file
    FILE* img = NULL; 
    
    // keep count of images
    int imageCounter = 0;
    
    while(fread(buffer, sizeof(buffer), 1, data)){
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {
                // close out previous image if not at beginning
                if(img != NULL){
                    fclose(img);
                }
                // rename image using image counter
                sprintf(filename, "%03i.jpg", imageCounter);
                img = fopen(filename, "w");
                imageCounter++;
            }
            
            // write to current image if something is there
            if(img != NULL)
                fwrite(buffer, sizeof(buffer), 1, img);
    }
    
    fclose(img);
    fclose(data);

    
    // All Clear
    return 0;
}