#include <stdio.h>
#include <stddef.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "get_gles_proc_address.h"

#include "log.h"

__BEGIN_DECLS

typedef void (*PFN_glClear)(GLbitfield mask);

void glClear(GLbitfield mask) {
    PFN_glClear real_glClear;
    real_glClear = (PFN_glClear) core::GetGlesProcAddress("glClear");

    GAPID_INFO("######: glClear enter #######: arg: %d", mask)
    real_glClear(mask);
    GAPID_INFO("######: glClear leave")
}

__END_DECLS
