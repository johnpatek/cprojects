#include "test.h"

void eprint_result(int result)
{
    ioc_font_t font;
    int color = RED; 
    char *msg = "FAIL";

    if(result)
    {
        color = GREEN;
        msg = "PASS";
    }

    (void) ioc_encode_font(
        &font,
        NONE,
        color, 
        DEFAULT);

    (void) ioc_eprintf(
        &font,
        "%s\n",
        msg);   
}