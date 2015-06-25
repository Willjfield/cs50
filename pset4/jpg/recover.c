/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // make vars with jpg signature
    uint8_t checkjpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
	uint8_t checkjpg2[4] = {0xff, 0xd8, 0xff, 0xe1};

	//make variable to keep track of whether file is open
	int open = 0;
	//make variable to keep track of jpegs created
	int jpgc = 0;
	//declare output file
	FILE* outp;
	//open raw file
    FILE* raw = fopen("card.raw", "r");
    //declare buffer size and check size
    int buffer[512];
    int check[4];
    //while there's data to be read
    //!!!///
    while(fread(buffer, 512, 1, raw)>0){
    	//for loop to fill check with first 4 bytes of buffer
    	for(int i=0;i<4;i++){
    		check[i]=buffer[i];
    	}
    	//memory compare the jpeg checks with the 4 bytes now in check, if it matches...
    	 //!!!///
 		if(memcmp(checkjpg1,check,4)==0||memcmp(checkjpg2,check,4)==0){
 			//declare 8 chars for filename
 			char filename[8];
 			//sprintf to create file with the filename and jpeg count
 			sprintf(filename,"%03d.jpg",jpgc);
			//if a file is not open
 			if(open==0){			
				//open the file that is called the current file name with write permissions
				outp = fopen(filename,"w");
				//write the current buffer to the outp (current file)
				fwrite(buffer,512,1,outp);
				//remember that a file is open
				open=1;
			}			
			//if a file is open
			if(open==1){
				//close the file 
				fclose(outp);
				//open a new file with the new filename
				outp = fopen(filename,"w");
				//write these 4 bytes from buffer into the new file
				fwrite(buffer,512,1,outp);
				//increment jpeg count
				jpgc++;
			}
		}	
		//if the bytes to not match jpeg initial bytes
 		else{
 			//if a file is open
 			if(open==1){
 				//write to the open file
 				fwrite(buffer,512,1,outp);
 			}
		}
	}	
//when there are no more bytes to read from the raw file, if an output file is open
if(outp){
    	//close it!
     fclose(outp);
 }
    	//close the raw
		fclose(raw);
		//exit the program
return 0;
}
