#include "test.h"

void eprint_result(int result)
{
    ioc_font_t font;
    int color = RED; 
    char *msg = "fail";

    if(result)
    {
        color = GREEN;
        msg = "pass";
    }

    (void) ioc_encode_font(
        &font,
        NONE,
        RED, 
        DEFAULT);

    (void) ioc_eprintf(
        &font,
        "%s\n",
        msg);   
}