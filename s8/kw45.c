#include <stdio.h>     //fuer printf() size_t stderr
#include <string.h>    //fuer strcpy() memcpy() 
#include <stdlib.h>    //fuer malloc() free()

//Compilerschalter: -fsanitize=address -Wall

struct stream {
    char   *str;
    size_t  size_max;     //Größe des derzeit reservierten Speichers
    size_t  size_act;     //Benötigter Speicher
    size_t  alloc_size;   //Heap-Blöcke in vielfachen dieser Größe
} stream;

void stream_open(size_t alloc_size) {
    stream.str = NULL;
    stream.size_act=0;  //Tatsächliche Größe
    stream.size_max=0;  //Reservierte Speichergröße
    stream.alloc_size=alloc_size;
}

void stream_close( void ) {
    if(stream.str)
        free(stream.str);
    stream.str=NULL;
    stream.size_act=0;
    stream.size_max=0;
}

void stream_debug(void)
{
    unsigned char *ptr_start=(unsigned char *)stream.str;
    unsigned char *ptr_end  =(unsigned char *)stream.str+stream.size_act;
    printf("\n------------------------------------------\n");
    printf("size_max  =%8zu size_act  =%8zu \n"
           "alloc_size=%8zu buffer    =%p\n",
           stream.size_max,stream.size_act,
           stream.alloc_size,stream.str);
    if(stream.str) 
        //Je alloc_size eine Zeile ausgeben!
        for( ;ptr_start<ptr_end ; ptr_start++)
            printf("'%c':%02x %s",
                    *ptr_start>=' '?*ptr_start:'?',
                         *ptr_start,
                              ((ptr_start-(unsigned char*)stream.str)%stream.alloc_size)==(stream.alloc_size-1)?"\n":" ");
    printf("\n------------------------------------------\n");
}

typedef enum {STATUS_OK,STATUS_MALLOCFAILED} STATUS;

STATUS stream_append(const char *append) {
    if(stream.str==NULL) {
        stream.size_max= (((strlen(append)+1)/stream.alloc_size)+1)*stream.alloc_size;
        //62(+1+1)    -> (((       62     +1)/   64            )+1)* 64 =  (0+1)*64=64
        //63(+1+1)    -> (((       63     +1)/   64            )+1)* 64 =  (1+1)*64=64
        //64(+1+1)    -> (((       64     +1)/   64            )+1)* 64 =  (1+1)*64=128
        stream.str=malloc(stream.size_max);
        if(stream.str == NULL)
            return STATUS_MALLOCFAILED;
        strcpy(stream.str,append);
        strcat(stream.str,"\n"); 
        stream.size_act=strlen(stream.str)+1;
    } else {
        //Ihre Aufgabe
        //Hinweis
        //Vergrößerung des Speichers (sofern notwendig) wahlweise 
        //über malloc()+free() oder über realloc()
    }
    return STATUS_OK;
}

typedef enum {STREAM_MODE_LINE,STREAM_MODE_ALL} STREAM_MODE;
char *stream_get(STREAM_MODE mode) 
{
    //Ihre Aufgabe
    
    return NULL; //Für den Fehlerfall
}

const  char *HELP_STRING = 
    "Help\n"
    ">>help        --> Ohne Worte\n"
    ">>quit        --> Programm beenden\n"
    ">>apend xxx   --> xxx an Stream anhängen\n"
    ">>getl        --> Eine Zeile aus Stream auslesen\n"
    ">>geta        --> Gesamten Stream auslesen\n"
    ">>debug       --> Darstellung des Inhalts des Streams\n";

int main(int argc, char *argv[]){
    enum status {OK,KO_FGETS,KO_END} ret=OK;
    printf("File:"__FILE__ " erstellt am "__DATE__" um "__TIME__ " gestartet\n");
    stream_open(16);
    while(1) {
        char input[100];
        char *arg1,*arg2;
        
        if(fgets(input,sizeof input,stdin)==NULL) { 
            ret=KO_FGETS;
            break;
        } 
        arg1=strtok(input," \n");
        
        if(arg1==NULL)
            continue;
        else if(!strcasecmp(arg1,"help"))
            printf("%s",HELP_STRING);
        else if(!strcasecmp(arg1,"quit"))
            break;
        else if(!strcasecmp(arg1,"debug"))
            stream_debug();
        else if(!strcasecmp(arg1,"append")) {
            arg2=strtok(NULL,"\n");
            if(arg2!=NULL) {
                if(stream_append(arg2)!=STATUS_OK)
                    fprintf(stderr,"\e[31mstream_append() Error:\e[30m\n");
            }
            else
                fprintf(stderr,"\e[31mstream_append() Error:\e[30m Missing Operand\n");
        }
        else if(!strcasecmp(arg1,"getl")) {
            char *ret=stream_get(STREAM_MODE_LINE);
            if(ret!=NULL) {
                printf("<<%s>>\n",ret);
                free(ret);
            } else
                fprintf(stderr,"\e[31mstream_get() Error:\e[30m\n");
        }
        else if(!strcasecmp(arg1,"geta")) {
            char *ret=stream_get(STREAM_MODE_ALL);
            if(ret!=NULL) {
                printf("<<%s>>\n",ret);
                free(ret);
            } else
                fprintf(stderr,"\e[31mstream_get() Error:\e[30m\n");
        }
        else
            printf("Invalid Command\n");
    }
    stream_close();
    const char *retstring[]={
        [KO_FGETS]   ="Programm mangels Eingabe beendet",
        [OK]         ="Programm ordnungsgemäß beendet",
        [KO_END]     ="Unbekannter Rückgabewert",
    };
    printf("%s\n",retstring[ret>KO_END?KO_END:(ret<0?KO_END:ret)]);
    return (int)ret;
}