// Zum Testen Makro händisch im Code setzen
// Bzw. für den Release Mode dieses Makro in Kommentar setzen
#ifndef NDEBUG
#define DBGPRINT(str) printf(str)
#else
#define DBGPRINT(str)
#endif
int main(int argc, char *argv[])
{
    DBGPRINT("Main started\n");
    // bleibt dauerhaft im Code
    // erzeugt im Relase-Mode jedoch keine ausführbaren Code
}
#define STRISUPPER(str)
({
    Int flag = 0;
    while (char *c = str)
    {
        if (c >= 65 && c <= 91)
        {
            flag = 1;
            break;
        }
        str++;
    }
    flag;
})

#define assert(x) ({if(!x)
    exit();
})